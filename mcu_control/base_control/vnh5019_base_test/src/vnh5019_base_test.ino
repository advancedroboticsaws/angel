
//#define ANDBOT 3
#define RUGBY 4

#define RIGHT_WHEEL 1
#define LEFT_WHEEL 2

//#define WHEEL_TYPE LEFT_WHEEL
#define WHEEL_TYPE RIGHT_WHEEL

#define encoder0PinA  2
#define encoder0PinB  3

#define motorIn1 6
#define InA 4
#define InB 5
#define EN 7

#define LOOPTIME 40
#define FeedbackTime 100
#define CurrentLimit 9000 //for metal0
#define MaxPWM 255

#if defined (ANDBOT)
  #define CPR 28
  #define MaxSumError 2500
  #define gear_ratio 65.5
  #define MaxSpeed 10.96
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

volatile long Encoderpos = 0;
volatile long unknownvalue = 0;

int pinAState = 0;
int pinAStateOld = 0;
int pinBState = 0;
int pinBStateOld = 0; 

volatile int lastEncoded = 0;
unsigned long lastMilli = 0;                    // loop timing 
unsigned long lastSend = 0;                    // send timing 
long dT = 0;

double omega_target = 0.0;
double omega_actual = 0;

int PWM_val = 0;                                // (25% = 64; 50% = 127; 75% = 191; 100% = 255)

double sum_error, d_error=0;

//current sense
int analogPin = A0;
unsigned int current = 0;

void setup() 
{ 
 //Set PWM frequency for D5 & D6
 // set timer 0 divisor to     8 for PWM frequency of  7812.50 Hz
 TCCR0B = TCCR0B & B11111000 | B00000010;
 pinMode(encoder0PinA, INPUT); 
 digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
 pinMode(encoder0PinB, INPUT); 
 digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor

 attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2
 attachInterrupt(1, doEncoder, CHANGE);
 pinMode(InA, OUTPUT); 
 pinMode(InB, OUTPUT); 
 pinMode(EN, OUTPUT);
 digitalWrite(EN, HIGH);
 Serial.begin (57600);
} 

void loop() 
{ 
  if (Serial.available() >= 4)  omega_target = Serial.parseFloat();
  CurrentMonitor();
  if((millis()-lastMilli) >= LOOPTIME)  
     {                                    // enter tmed loop
        dT = millis()-lastMilli;
        lastMilli = millis();

        getMotorData();                                                           // calculate speed

        PWM_val = (updatePid(omega_target, omega_actual));                       // compute PWM value from rad/s 
        
        if (omega_target == 0)  { PWM_val = 0;  sum_error = 0;}
        
        if (PWM_val <= 0)   { analogWrite(motorIn1,abs(PWM_val));  digitalWrite(InA, LOW);  digitalWrite(InB, HIGH); }
        if (PWM_val > 0)    { analogWrite(motorIn1,abs(PWM_val));  digitalWrite(InA, HIGH);   digitalWrite(InB, LOW);}
        printMotorInfo();
     }
}

void getMotorData()  
{                               
  static long EncoderposPre = 0;   
  if (WHEEL_TYPE == RIGHT_WHEEL)    
    omega_actual = ((Encoderpos - EncoderposPre)*(1000/dT))*2*PI/(CPR*gear_ratio);  //ticks/s to rad/s
  else  //left wheel
    omega_actual = -(((Encoderpos - EncoderposPre)*(1000/dT))*2*PI/(CPR*gear_ratio));  //ticks/s to rad/s
  EncoderposPre = Encoderpos;                 
}

void CurrentMonitor()
{
    current = analogRead(analogPin) * 34;  // 5V / 1024 ADC counts / 144 mV per A = 34 mA per count
    //if (current > CurrentLimit)  digitalWrite(EN, LOW);
}

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
  if (WHEEL_TYPE == RIGHT_WHEEL)  calculated_pidTerm = pidTerm/(double(MaxSpeed)/double(MaxPWM));
  else                            calculated_pidTerm = -pidTerm/(double(MaxSpeed)/double(MaxPWM));
  constrained_pidterm = constrain(calculated_pidTerm, -MaxPWM, MaxPWM);
  
  return constrained_pidterm;
}


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

void printMotorInfo()  
{                                                                      
   Serial.print(" target:");                  Serial.print(omega_target);
   Serial.print(" actual:");                  Serial.print(omega_actual);
   Serial.print("  dT:");                  Serial.print(dT);
   Serial.print("  sum_err:");                  Serial.print(sum_error);
   Serial.print("  Current:");                  Serial.print(current);
   Serial.print("  PWM_val:");                  Serial.print(PWM_val);

   Serial.println();
}


