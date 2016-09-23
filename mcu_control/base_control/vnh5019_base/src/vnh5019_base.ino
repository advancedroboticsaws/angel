/**
 *
 * @file vnh5019_base.ino
 * driver for vnh5019 board to control motor.
 * @brief Motor driver vnh5019.
 * @author will
 * @version 1.00
 *
 *
 **/

/**
 * Marco
 */
//#define ANDBOT 3
//#define RUGBY 4
#define ANGELBOT 5

#define RIGHT_WHEEL 2
#define LEFT_WHEEL 1

/**
 * Be very much aware!!  
 * For now, we actually use define "right_wheel" to left wheel.
 * And vice versa.
 * This is an issue to be solved either configing software or hardware.
 **/
//#define WHEEL_TYPE LEFT_WHEEL
#define WHEEL_TYPE RIGHT_WHEEL

#define encoder0PinA  2 /*! encoder A phrase */
#define encoder0PinB  3 /*! encoder B phrase */

#define motorIn1 6 /*! 328p -> vnh ; PWM */
#define InA 4 /*! 328p -> vnh ; Output for forward/reverse*/
#define InB 5 /*! 328p -> vnh ; Output for forward/reverse*/
#define EN 7 /*! 328p -> vnh ; Enable command*/

#define LOOPTIME 40
#define FeedbackTime 100
#define CurrentLimit 9000 //for metal0
#define MaxPWM 255

#if defined (ANDBOT)
  #define CPR 28 /*! count per rev */
  #define MaxSumError 2500 /*! limit integration */
  #define gear_ratio 65.5
  #define MaxSpeed 10.96
  #define Kp 0.9
  #define Ki 0.005
  #define Kd 0
#elif (ANGELBOT)
  #define CPR 64  /*! count per rev */
  #define MaxSumError 6000 /*! limit integration */
  #define gear_ratio 18.8 
  #define MaxSpeed 31 /*! to be determined? */
  #define Kp 0.9
  #define Ki 0.005
  #define Kd 0
#else
  #define CPR 64 
  #define MaxSumError 6000
  #define gear_ratio 18.8
  #define MaxSpeed 31 
  #define Kp 0.9
  #define Ki 0.005
  #define Kd 0
#endif

volatile long Encoderpos = 0; /*! counting encoder position */
volatile long unknownvalue = 0;

int pinAState = 0;
int pinAStateOld = 0;
int pinBState = 0;
int pinBStateOld = 0;

volatile int lastEncoded = 0;
unsigned long lastMilli = 0;  /*! loop timing */
unsigned long lastSend = 0;   /*! send timing */
long dT = 0; /*! differential time */

double omega_target = 0.0; /*! target angular velocity */
double omega_actual = 0; /*! actural angular velocity */

int PWM_val = 0;  /*! (25% = 64; 50% = 127; 75% = 191; 100% = 255) */

double sum_error, d_error=0; /*! feedback block */

//current sense
int analogPin = A0;
unsigned int current = 0;

//Motor Driver mode
bool driver_mode = false;

/**
 * Initializations of vnh5019 board.
 * Start serial port.
 */
void setup() 
{ 
 //Set PWM frequency for D5 & D6
 // set timer 0 divisor to     8 for PWM frequency of  7812.50 Hz
 TCCR0B = TCCR0B & B11111000 | B00000010;
 pinMode(encoder0PinA, INPUT);  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
 pinMode(encoder0PinB, INPUT);  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor

 attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2
 attachInterrupt(1, doEncoder, CHANGE);
 pinMode(InA, OUTPUT);  pinMode(InB, OUTPUT); 
//digitalWrite(EN, LOW);
 digitalWrite(EN, HIGH);
 Serial.begin (57600);
} 

/**
 * Main function
 *
 * @dot
 * digraph G {
 * readCmd -> CurrentMonitor;
 * }
 * @enddot
 */
void loop() 
{       
  readCmd_wheel_angularVel(); /*! command from mega */
  CurrentMonitor();
  if((millis()-lastMilli) >= LOOPTIME)  
     {                                    // enter tmed loop
        dT = millis()-lastMilli;
        lastMilli = millis();
        
        getMotorData();                                                        // calculate speed

        PWM_val = (updatePid(omega_target, omega_actual));                       // compute PWM value from rad/s 
        if ((omega_target == 0) && (driver_mode == true))  { PWM_val = 0;  sum_error = 0;  digitalWrite(EN, HIGH); }
        //if (omega_target == 0)  { PWM_val = 0;  sum_error = 0;  }
        
        //if (PWM_val <= 0)   { analogWrite(motorIn1,abs(PWM_val));  digitalWrite(InA, LOW);  digitalWrite(InB, HIGH); }
        //if (PWM_val > 0)    { analogWrite(motorIn1,abs(PWM_val));  digitalWrite(InA, HIGH);   digitalWrite(InB, LOW);}
	      if (PWM_val < 0)         { analogWrite(motorIn1,abs(PWM_val));  digitalWrite(InA, LOW);  digitalWrite(InB, HIGH); }
        else if (PWM_val > 0)    { analogWrite(motorIn1,abs(PWM_val));  digitalWrite(InA, HIGH);   digitalWrite(InB, LOW);}
        else                     { digitalWrite(InA, LOW);   digitalWrite(InB, LOW);} //for brake
     }
     
  if((millis()-lastSend) >= FeedbackTime)    
     {                                    // enter tmed loop
        lastSend = millis();
        sendFeedback_wheel_angularVel(); //send actually speed to mega
        printMotorInfo();
     }
     
}

/**
 * Read cmd [velocity] from mega2560.
 */
void readCmd_wheel_angularVel()
{
  int target_receive;
  if (Serial.available() >= 4) 
  {
    char rT = (char)Serial.read(); //read target speed from mega
          if(rT == '{')
            {
              char commandArray[3];
              Serial.readBytes(commandArray,3);
              byte rH=commandArray[0];  byte rL=commandArray[1];  char rP=commandArray[2];
              if(rP=='}') //B01111101 motor driver on         
                {
                  target_receive = (rH<<8)+rL; 
                  omega_target = double (target_receive*((double(MaxSpeed)/32767)));  //convert received 16 bit integer to actual speed
                  driver_mode = true;
                }
              if(rP=='|') //B01111100 motor driver off         
                {
                  target_receive = (rH<<8)+rL; 
                  omega_target = double (target_receive*((double(MaxSpeed)/32767)));  //convert received 16 bit integer to actual speed
                  driver_mode = false;
                }  
            }
  }         
}

/**
 * Send feedback to calculate cmd for next sampling time.
 */
void sendFeedback_wheel_angularVel()
{
  //getMotorData();
  byte current_send;
  int actual_send = int(omega_actual/(double(MaxSpeed)/32767)); //convert rad/s to 16 bit integer to send
  //max current is 20400mA 20400/255 = 80
  current_send = current/80; 
  byte buf[5];
  buf[0] = '{'; //send start byte
  buf[1] = highByte(actual_send);  buf[2] = lowByte(actual_send);  //send low byte
  buf[3] = current_send;  //send current value
  buf[4] = '}'; //send stop byte 
  Serial.write(buf, sizeof(buf));
}

/**
 * Get Encoder data of each wheel.
 * actual anglar velocity = diff(Encoderpos) * 1000 / dT
 */
void getMotorData()  
{                               
  static long EncoderposPre = 0;   
  if (WHEEL_TYPE == LEFT_WHEEL)  omega_actual = ((Encoderpos - EncoderposPre)*(1000/dT))*2*PI/(CPR*gear_ratio);  //ticks/s to rad/s
  else                            omega_actual = -(((Encoderpos - EncoderposPre)*(1000/dT))*2*PI/(CPR*gear_ratio));  //ticks/s to rad/s
  EncoderposPre = Encoderpos;                 
}

/**
 * Limit current flow. (new development)
 */
void CurrentMonitor()
{
  current = analogRead(analogPin) * 34;  // 5V / 1024 ADC counts / 144 mV per A = 34 mA per count
  //if ((current > CurrentLimit) || (driver_mode == false))  digitalWrite(EN, LOW);
}

/**
 * Implement PID control.
 * @param[in] targetValue
 * @param[in] currentValue
 * @return constrained_pidterm
 */
double updatePid(double targetValue,double currentValue)   
{              
  static double last_error=0;                 
  double calculated_pidTerm, constrained_pidterm, error, pidTerm;        
    
  error = targetValue - currentValue; 

  sum_error = sum_error + error * dT;
  // Added by KKuei to bound sum_error range
  sum_error = constrain(sum_error, -MaxSumError, MaxSumError);
  
  d_error = (error - last_error) / dT;
  pidTerm = Kp * error + Ki * sum_error + Kd * d_error;   
                       
  last_error = error;  
  if (WHEEL_TYPE == LEFT_WHEEL)  calculated_pidTerm = pidTerm/(double(MaxSpeed)/double(MaxPWM));
  else                            calculated_pidTerm = -pidTerm/(double(MaxSpeed)/double(MaxPWM));
  constrained_pidterm = constrain(calculated_pidTerm, -MaxPWM, MaxPWM);
  
  return constrained_pidterm;
}

/**
 * Read encoder.\n
 * Read pin 2 & pin 3 State.
 *
 * @dot
 * digraph {
 * label="read encoder flow"
 *
 * start[shape="box", style="rounded"]
 * end[shape="box", style="rounded"]
 *
 * pinAZeroState[shape="diamond",style=""]
 * pinBZeroState[shape="diamond",style=""]
 * pinAZeroStateOld[shape="diamond",style=""]
 * pinBZeroStateOld[shape="diamond",style=""]
 *
 * start -> pinAZeroState;
 * start -> pinBZeroState;
 * pinAZeroState -> end[label="YES"];
 * pinBZeroState -> end[label="YES"];
 * }
 * @enddot
 */
void doEncoder() {

  pinAState = digitalRead(2);
  pinBState = digitalRead(3);

  if (pinAState == 0 && pinBState == 0) {
    if (pinAStateOld == 1 && pinBStateOld == 0) // forward
      Encoderpos ++;
    if (pinAStateOld == 0 && pinBStateOld == 1) // reverse
      Encoderpos --;
  }
  if (pinAState == 0 && pinBState == 1) {
    if (pinAStateOld == 0 && pinBStateOld == 0) // forward
      Encoderpos ++;
    if (pinAStateOld == 1 && pinBStateOld == 1) // reverse
      Encoderpos --;
  }
  if (pinAState == 1 && pinBState == 1) {
    if (pinAStateOld == 0 && pinBStateOld == 1) // forward
      Encoderpos ++;
    if (pinAStateOld == 1 && pinBStateOld == 0) // reverse
      Encoderpos --;
  }

  if (pinAState == 1 && pinBState == 0) {
    if (pinAStateOld == 1 && pinBStateOld == 1) // forward
      Encoderpos ++;
    if (pinAStateOld == 0 && pinBStateOld == 0) // reverse
      Encoderpos --;
  }
  pinAStateOld = pinAState;
  pinBStateOld = pinBState;
}

/**
 * Serial transmission for motor status.
 */
void printMotorInfo()  
{                                                                      
   Serial.print(" target:");                  Serial.print(omega_target);
   Serial.print(" actual:");                  Serial.print(omega_actual);
   Serial.print("  dT:");                     Serial.print(dT);
   Serial.print("  sum_err:");                Serial.print(sum_error);
   Serial.print("  Current:");                Serial.print(current);
   Serial.print("  PWM_val:");                Serial.print(PWM_val);
   Serial.print("  Encoderpos:");                Serial.print(Encoderpos);

   Serial.println();
}


