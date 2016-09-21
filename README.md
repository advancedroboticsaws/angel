<h1 align="center">
  <img src="doc/AR.png" alt="AR"> 
  Instructions for fundamental testing on angel 
</h1>

<p align="center">
<b><a href="#overview">Overview</a></b>
|
<b><a href="#table-of-contents">Table of contents</a></b>
|
<b><a href="#preparing-for-testing">Preparing for testing</a></b>
|
<b><a href="#system-architecture">System architecture</a></b>
|
<b><a href="#module-test">Module test</a></b>
|
<b><a href="#function-test">Function test</a></b>
|
<b><a href="#team">Team</a></b>
|
<b><a href="#license">License</a></b>
</p>

## Overview

This is a guiding repository that gives you basic instructions of driving our robot system, **angel** for this case. 
Firmwares are included in this repository, placed under **mcu_control** folder. 

## Table of contents
* [**Preparing for testing**](#preparing-for-testing)
* [**System architecture**](#system-architecture)
* [**Module test**] (#module-test) 
  * [**Base driving test**](#base-driving-test)
  	* [**Step 1 Check hardware setups for base driving control**](#step1-check-hardware-setups-for-base-driving-control)
  	* [**Step 2 Upload firmware to vnh5019**](#step-2-upload-firmware-to-vnh5019)
  	* [**Step 3 Upload firmware to mega_base**](#step-3-upload-firmware-to-mega_base)
  	* [**Step 4 Drive angel base**](#step-4-drive-angel-base)
  * [**Laser scan test**](#laser-scan-test)
  	* [**Step 1 Check hardware setup to receive data from laser scanner**](#step-1-check-hardware-setup-to-receive-data-from-laser-scanner)
  	* [**Step 2 Launch rplidar**](#step-2-launch-rplidar)
  * [**Camera Joint control test--not done**](#camera-joint-control-test)
  	* [**Step 1 Check hardware setup to control camera position**](#step-1-check-hardware-setup-to-control-camera-position)
  	* [**Step 2 Uploading firmware to vnh5019 and control camera joint**](#step-2-upload-firmware-to-vnh5019-and-control-camera-joint)
  * [**Security Sening test**](#security-sensing-test)
  * [**Camera image topic test**](#camera-image-topic-test)	  
* [**Function test**](#function-test)
  * [**Tele-operation**](#tele-operation)
  * [**Auto ducking test**](#auto-ducking-test) 
* [**Appendix**](#appendix)

## Preparing for testing

1. Prepare your odroid XU4 board with ubuntu 14.04 on it.
2. Check odroid IP address. Type the following command on odroid board.
	
	```
	ifconfig
	``` 
	On angel-1.1, IP address should be `192.168.25.110` 
3. Download this repository and compile it on odroid by going though the following steps.
	
	```
	ssh odroid@[Odroid IP address]
	cd ~/catkin_ws/src
	git clone https://github.com/advancedroboticsaws/angel.git
	cd ~/catkin_ws
	catkin_make 
	```  

## System architecture

This section gives you an overview of our angel's design.

**Note: All files related to angel's hardware design are placed in the folder `/hardware design`.** 

* Overall block diagram

![System](doc/Angel%20system%20diagram.png)

* Schematic of base driver `vnh5019`

![vnh5019-1](doc/vnh5019-1st.jpg)

![vnh5019-2](doc/vnh5019-2nd.jpg)
  
## Module test

The following test requires ROS on any of your testing platform.

<p align="center">
<b><a href="#base-driving-test">Base driving test</a></b>
|
<b><a href="#laser-scan-test">Laser scan test</a></b>
|
<b><a href="#camera-joint-test">Camera joint test</a></b>
|
</p>

### Base driving test

Brief description of this test

* Requirements 
  * motor-control module
  * mega2560
  * Odroid XU4
  * ROS on odroid 
* Firmware upload instruction
* Left/right wheel spinning test with ROS.

<a name="base-driving-test-step1"></a>

#### Step 1 `Check hardware setups for base driving control`

Check all the hardware setup !!

Here we regard motor-control module as a motor **JGB37 3530B** + base driver **vnh5019**.
Also, both motor-control module must be connected to mega2560.

Mark the following checklist yourself when you finish each setup.

- [ ] Check your motor number. Make sure you installed the right one.
- [ ] Motor control modules are well connected. Each of them have correct wiring to their base driver.
- [ ] Left wheel motor control module connects to mega2560 correctly.  
- [ ] Right wheel motor control module connects to mega2560 correctly. 

**Note: If you are have any doubt, not sure what you remember when you set up all the hardwares and wirings, please review system diagrams and double check before going to next step.**

After you finish first step, you are about to make wheels spin.
There are two control boards that should have firmwares uploaded, `mega2560 & vnh5019`. 
Firmware uploading steps for both of them are slightly different. 
Instructions for each are separated as follows.

<a name="base-driving-test-step2"></a>

#### Step 2 `Upload firmware to vnh5019` 

Firmware for wheel spining test is placed in the folder.

```
/mcu_control/vnh5019_base/src
```

* upload `vnh5019_base.ino` to left/right wheel
	1. Please go to line 8 and 9. Uncomment one of these two lines according to which wheel you are about to do the uploading. 
	2. Open vnh5019_base.ino with Arduino IDE on your PC.
	3. Modify Arduino PWM Frequency in Arduino IDE. 
		Copy
		
		```
		/mcu_control/wiring.c
		```
		 to ~/arduino-1.6.5/hardware/arduino/avr/cores/arduino
		 Make sure the following code is on line 31 or 32 in wiring.c.   
		 
		 ```
		 #define MICROSECONDS_PER_TIMER0_OVERFLOW (clockCyclesToMicroseconds(8 * 256))
		 ```
	4. Set your upload target to **promini**
	5. Choose your **port** carefully.
	6. Go for it! Click upload!
		If you get any error when PC uploading,
		* Please look into the errors carefully.
		* Please check the port you choose.
		* Please make sure you have put all the libraries into the folder.
			If you get the message about library conflicts, please find out those files and delete the old one.   
	7. Go though the steps above again **for the other wheel**.

<a name="base-driving-test-step3"></a>

#### Step 3 `Upload firmware to mega_base` 

Firmware for mega2560 is inside the following folder.

```
/mcu_control/mega_base_ultrasonic_angelbot/src
```

* upload `mega_base_ultrasonic_angelbot.ino` to mega2560
	1. Open mega_base_ultrasonic_angelbot.ino with Arduino IDE on your PC.
	2. Libraries for the firmware is placed in	
	
		```
		/mcu_control/mega_base_ultrasonic_angelbot/lib
		``` 
	   Copy all contents inside and paste them to `%document%/arduino/libraries` folder on your PC.
	3. Make sure the following code is on line 31 or 32 in wiring.c.   
		 
		 ```
		 #define MICROSECONDS_PER_TIMER0_OVERFLOW (clockCyclesToMicroseconds(8 * 256))
		 ```
		 If you don't understand this step, please refer to step 2 above to find out. 
	4. Set your upload target to **mega2560**
	5. Choose your **port** carefully.
	6. Go for it! Click upload!
		If you get any error when PC uploading,
		* Please look into the errors carefully.
		* Please check the port you choose.
		* Please make sure you have put all the libraries into the folder.
			If you get the message about library conflicts, please find out those files and delete the old one.   
	
<a name="base-driving-test-step4"></a>

#### Step 4 `Drive angel base`

The following testing needs ROS on odroid! 
Make sure you have installed ROS on odroid XU4.
Be aware all the errors (red color format) while you installed ROS if there's any.

Please mark the following checklist yourself when you finish each.

- [ ] Make sure you have correct hardware setup and go through instructions above step by step.

	1. Be sure of the ip address.
	
		Open a terminal up on you PC and type
	
		```
		ssh odroid@192.168.25.110
		```
		to access to angel.
	2. Start the roscore up.
		Type the following command.
			
		``` 
		roscore
		```
	3. The next step should be starting communication between odroid and mega2560 through ROS.
		Open another termimal and do step1 to access into odroid then type:
		
		```
		rosrun rosserial_python serial_node.py _port:=/dev/ttyACM* _baud:=115200
		```
	4. Open another terminal and access into odroid by ssh commands (step1) then type:
		
		```
		rostopic list
		```   
		Check the topic list to make sure communication between mega2560 and your odroid is set.
	5. Send a command to drive each wheel. Type the following command
		
		```
		rostopic pub /cmd_wheel_angularVel angelbot/WheelCmd "speed1: 1.0 speed2: 1.0 driverstate: false" 
		```
		If you have no error, you may see something like this on the terimal
		
		```
		odroid@odroid:~$ rostopic pub /cmd_wheel_angularVel angelbot/WheelCmd "speed1: 1.0 speed2: 1.0 driverstate: false"
		publishing and latching message. Press ctrl-C to terminate 
		```   
	6. Make sure both wheel have spin in the correct direction with a reasonable speed.
	7. If you finish all the steps, send a 0 speed command and terminate command mode by typing ctrl-c.
	
<p align="right">
<b><img src="doc/AR.png" alt="AR">End of base driving test</b>
|
<a href="#">BACK TO TOP</a>
</p>

### Laser scan test

The laser scanner we used is **rplidar**. 
To be able to use it, the complete hardware setup should contain rplidar + transmission board.

<a name="laser-scan-test-step1"></a>

#### Step 1 `Check hardware setup to receive data from laser scanner`

Mark the following checklist yourself when you finish each setup.

- [ ] Check your data transmission board. Make sure you installed the right one.

**Note: If you have any doubt, not sure what you remember when you set up all the hardwares and wirings,
please review system diagrams or datasheet and double check before going to next step.**

<a name="laser-scan-test-step2"></a> 

#### Step 2 `Launch rplidar`

This test is to help you find out you if the rplidar you have is functional and your hardware setup is correct.
Before going through the steps below, please mark the following checklist yourself when you finish each setup.

- [ ] Check out if there is a folder named `rplidar_ros` in the /catkin/src/angel on odroid.

* Begin launching
	1. Open a terminal and type the following command.
		
		``` 
		roscore
		```
	2. The next step should be starting communication between odroid and rplidar through ROS.
		Open another termimal and type:
		
		```
		roslaunch angelbot rplidar.lanuch 
		```
		
		You will see something like this
		
		```
		started roslaunch server http://192.168.25.110:60968/

		SUMMARY
		========
		
		......
		......
		
		NODES
		  /
		    rplidarNode (rplidar_ros/rplidarNode)
		
		......
		......
		RPLidar health status : 0
		```
	3. Open another terminal and type:
		
		```
		rostopic list
		```   
		Check if there is a topic name **/scan**. 
	4. Type the following command to see if there is anything shows up.
		
		```
		rostopic echo /scan
		```   
		You will see something similar on your terminal:
		
		![laser scan sample](doc/laser_scan_sample.png)

<p align="right">
<b><img src="doc/AR.png" alt="AR">End of laser scan test</b>
|
<a href="#">BACK TO TOP</a>
</p>

### Camera Joint spinning test

<a name="camera-joint-spinning-step1"></a>

#### Step 1 `Check hardware setup to control camera position`

<a name="camera-joint-spinning-step2"></a>

#### Step 2 `Uploading firmware to vnh5019 and control camera joint`

```
/mcu_control/vnh5019_base/src
```

* upload `vnh5019_base.ino` to camera joint driver
	1. Look for line 8 and 9. Uncomment one of these two lines according to which rotating direction you are about to do the uploading. 
	2. Open vnh5019_base_test.ino with Arduino IDE on your PC.
	3. Modify Arduino PWM Frequency in Arduino IDE. 
		Copy
		
		```
		/mcu_control/wiring.c
		```
		 to ~/arduino-1.6.5/hardware/arduino/avr/cores/arduino
		 Make sure it has 
		 
		 ```
		 #define MICROSECONDS_PER_TIMER0_OVERFLOW (clockCyclesToMicroseconds(8 * 256))
		 ```
		 on line 31 or 32 in wiring.c.
	4. Set your upload target to **promini**
	5. Choose your **port** carefully.
	6. Go for it! Click upload!

### Security Sensing test

<a name="security-sensing-test-step1"></a>

#### Step 1 ``

### Camera image topic test

<a name="camera-image-topic-test-step1"></a>

#### Step 1 ``

<p align="right">
<b><img src="doc/AR.png" alt="AR">End of Module test</b>
|
<a href="#">BACK TO TOP</a>
</p>

## Function test 

<p align="center">
<b><a href="#tele-operation-test">Tele-operation test</a></b>
|
<b><a href="#auto-ducking-test">Auto ducking test</a></b>
</p>

### Tele-operation

1. Use ssh command to access to odroid

	```
	ssh odroid@192.168.25.110
	```
2. Launching sequence to drive angel around and scanning.
	
	```
	roslaunch angelbot angel_standalone_ekf.launch
	roslaunch angelbot dwa_gmapping_ekf.launch
	```
3. Check topics

	``` 
	rostopic list
	```
	Make sure /angelbot/cmd_vel is on the list.
4. Pick up your cell phone, go to play store download and install **teleop-indigo** app.
5. Open the app and type `http://192.168.25.110:11311` to access to angel.
6. Drive angel around by taping your finger on the screen.
7. Check if there is a map shows up.

### Auto ducking test



<p align="right">
<b><img src="doc/AR.png" alt="AR">End of Function test</b>
|
<a href="#">BACK TO TOP</a>
</p>

## Appendix

```
KERNEL=="ttyUSB*", ATTRS{idProduct}=="6001", ATTRS{idVendor}=="0403", ATTRS{devpath}=="1.1", SYMLINK+="imu"
KERNEL=="ttyACM*", ATTRS{idProduct}=="0042", ATTRS{idVendor}=="2341", ATTRS{devpath}=="1.2.1.1", SYMLINK+="mega_base"
KERNEL=="ttyUSB*", ATTRS{idProduct}=="6001", ATTRS{idVendor}=="0403", ATTRS{devpath}=="1.2.1.2", SYMLINK+="rplidar"
```

    
## Team 

[Weber Hsu](https://github.com/Weber-Hsu)
|
[CL Chu](https://github.com/clchuadrobot)
|
[William Chen](https://github.com/piliwilliam0306)
|
[Zach Wang](https://github.com/ChingHengWang)
|
[Eric Ko](https://github.com/EricWilliamKo)
|
[Muchun Yen](https://github.com/Muchun-Yen)
|
[Kevin Kuei](https://github.com/wennycooper)

## License
Copyright © 2016 Advanced Robotics Corporation

<p align="right">
<img src="doc/AR.png" alt="AR"><a href="#">BACK TO TOP</a>
</p>