# Instructions for fundamental testing on angel 

<h1 align="center">
  <img src="" alt="">
</h1>

<p align="center">
<b><a href="#overview">Overview</a></b>
|
<b><a href="#system-diagram">System diagram</a></b>
|
<b><a href="#license">License</a></b>
</p>

## Overview

This is a guiding repository that gives you basic instructions of driving our robot system, **angel** for this case. 
Firmwares are included in this repository, placed under **mcu_control** folder. 

## Table of contents
* [**System diagram**](#system-diagram)
* [**Module test**] (#module-test) (either or not ROS-based)
  * [**Base driving test**](#base-driving-test)
  * [**IMU sensing test**](#imu-sensing-test)
  * [**Laser scan test**](#laser-scan-test)
  * [**Charger test**](#charger-test)
  * [**Camera Joint spining test**](#camera-joint-spining-test)     
* [**Function test**](#function-test) (ROS-based)
  * [**Tele-operation**](#tele-operation) 
* [**Appendix**](#appendix)

## System diagram
In this section, we review angel's hardware architecture.

<p align="center">
<b><a href="#hardware-diagram">Hardware Diagram</a></b>
</p>

* Diagrams
  * Overall abstract diagram
  ![](https://github.com/advancedroboticsaws/angel/doc/Angel system diagram.doc)
  * Wiring diagram of modules
  
## Module test

The following test requires ROS on any of your testing platform.
<p align="center">
<b><a href="#base-driving-test">Base driving test</a></b>
|
<b><a href="#imu-sensing-test">IMU sensing test</a></b>
|
</p>

### Base driving test

<a name="base-driving-test-step1"></a>

#### Step 1 `Hardware setup`

Check all the hardware setup !!
Mark the following checklist yourself when you finish each setup.

- [ ] Motor control modules are well prepared. Each of them have correct wiring to their driver board.
- [ ] Left wheel motor control module connects to mega2560 correctly.  
- [ ] Right wheel motor control module connects to mega2560 correctly.
- [ ] 

<a name="base-driving-test-step2"></a>

#### Step 2 `Uploading firmwares to each control board.` 

There are two control board for driving angel, mega2560 & vnh5019.  
Firmware for mega2560 is inside **/mcu_control/mega_base** folder.
As for vnh5019, it is placed in **/mcu_control/mega_base** folder.
Firmware uploading steps to these control boards are slightly different. 
Instructions for each are separated as follows. 

Before uploading firmwares, please mark the following checklist yourself when you finish each setup.

- [ ] Make sure you got the latest firmware for vnh5019.
- [ ] Make sure you got the latest firmware for mega2560.
- [ ] 

##### Upload mega_base

 

<a name="base-driving-test-step3"></a>

#### Step 3 `ROS setup.`

Make sure you have installed ROS on your computer.
Be aware all the errors (red color format) while you installed ROS if there's any.


<a name="base-driving-test-step4"></a>

#### Step 4 

Command Left/Right wheel through ROS.
Open a terminal and start the roscore up.

Type the following command.

``` 
roscore
```

The next step should be starting communication between ROS and mega2560.

Open another termimal and type:
```
rosrun rosserial_python serial_node.py _port:=/dev/ttyACM* 
```

* Setup requirements 
  * motor-control module
  * mega2560
  * Odroid XU4 or PC
  * roscore & rosserial 
* Setup wiring diagram
* Firmware upload instruction
  * Firmware version check
  * rosserial port & baud rate configuration 
* Begin Testing
  * Left/right Wheel
  
<a name="base-driving-test-step5"></a>

#### Step 5 




### IMU sensing test

Inertia measurement unit, IMU, are very important for navigation on any of our system.
On angel case, MPU6050 is used. We also need a controller board, promini, to 
recieve its data. 

<a name="imu-sensing-test-step1"></a>

#### Step 1 `Hardware setup`

Check your wiring twice when you power on.

<a name="imu-sensing-test-step2"></a>

#### Step 2 `Upload firmwares and calibration`

<a name="imu-sensing-test-step3"></a>

#### Step 3 `validation`

* Setup requirements 
  *  mpu6050
  *  promini
* Setup wiring diagram
* Firmware upload instruction
  * Firmware version check
  * Serial port & baud rate configuration 
* Begin Testing

### Laser scan test

<a name="laser-scan-test-step1"></a>

#### Step 1 `Hardware setup`

### Camera Joint spining test

<a name="camera-joint-spining-step1"></a>

#### Step 1 `Hardware setup`
 
## Function test 



### Tele-operation

Pick up your cell phone, go to play store and download **teleop-indigo** app.

### Charger test

## Appendix
* ROS environment setup
    * ROS MASTER
    * ROS IP 


## License
Copyright © 2016 Advanced Robotics Corporation