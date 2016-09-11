#!/usr/bin/env python

import rospy
import sys
import time
import math

from banana_serial import BananaSerial
from std_msgs.msg import Int16,Int32, Int64, Float32, String, Header, UInt64
from sensor_msgs.msg import Imu

class GYRO_Class(object):
	
	def __init__(self):
		print "Initializing"

		self._Counter = 0

		self._qx = 0
		self._qy = 0
		self._qz = 0
		self._qw = 0

		self._lx = 0
                self._ly = 0
                self._lz = 0	

		self._ax = 0
                self._ay = 0
                self._az = 0
		
		port = rospy.get_param("~port", "/dev/ttyUSB1")
		baudRate = int(rospy.get_param("~baudRate", 115200))

		rospy.loginfo("Starting with serial port: " + port + ", baud rate: " + str(baudRate))
		self._BananaSerial = BananaSerial(port, baudRate,  self._HandleReceivedLine)
		rospy.loginfo("Started serial communication")
		
		#Publisher for entire serial data
		self._SerialPublisher = rospy.Publisher('serial', String,queue_size=10)
		
                #Subscribers and Publishers of IMU data topic

		self.frame_id = '/IMU_link'

        	self.cal_buffer =[]
        	self.cal_buffer_length = 1000
        	self.imu_data = Imu(header=rospy.Header(frame_id="IMU_link"))
        	self.imu_data.orientation_covariance = [1e6, 0, 0, 0, 1e6, 0, 0, 0, 1e-6]
	        self.imu_data.angular_velocity_covariance = [1e6, 0, 0, 0, 1e6, 0, 0, 0, 1e6]
        	self.imu_data.linear_acceleration_covariance = [-1,0,0,0,0,0,0,0,0]
        	self.imu_pub = rospy.Publisher('imu_data', Imu,queue_size = 10)

	def _HandleReceivedLine(self,  line):
		self._Counter = self._Counter + 1
		self._SerialPublisher.publish(String(str(self._Counter) + ", in:  " + line))

		if(len(line) > 0):

			lineParts = line.split('\t')
			try:
			
				if(lineParts[0] == 'quat'):

					self._qx = float(lineParts[1])
					self._qy = float(lineParts[2])
					self._qz = float(lineParts[3])
					self._qw = float(lineParts[4])

				if(lineParts[0] == 'ypr'):

          				self._ax = float(lineParts[1])
          				self._ay = float(lineParts[2])
          				self._az = float(lineParts[3])

				if(lineParts[0] == 'areal'):

				  	self._lx = float(lineParts[1])
				  	self._ly = float(lineParts[2])
				  	self._lz = float(lineParts[3])

					imu_msg = Imu()
					h = Header()
					h.stamp = rospy.Time.now()
					h.frame_id = self.frame_id

					imu_msg.header = h

					#imu_msg.orientation_covariance = (1., )*9	
        				imu_msg.orientation_covariance = [1e6, 0, 0, 0, 1e6, 0, 0, 0, 1e-6]
					#imu_msg.angular_velocity_covariance = (1., )*9
        				imu_msg.angular_velocity_covariance = [1e6, 0, 0, 0, 1e6, 0, 0, 0, 1e6]
					#imu_msg.linear_acceleration_covariance = (1., )*9
        				imu_msg.linear_acceleration_covariance = [-1,0,0,0,0,0,0,0,0]

					imu_msg.orientation.x = self._qx
					#imu_msg.orientation.x = 0
					imu_msg.orientation.y = self._qy
					#imu_msg.orientation.y = 0
					imu_msg.orientation.z = self._qz
					#imu_msg.orientation.z = 0
					imu_msg.orientation.w = self._qw
					#imu_msg.orientation.w = 1

					imu_msg.angular_velocity.x = self._ax
					#imu_msg.angular_velocity.x = 0
					imu_msg.angular_velocity.y = self._ay
					#imu_msg.angular_velocity.y = 0
					imu_msg.angular_velocity.z = self._az
					#imu_msg.angular_velocity.z = 0

					#imu_msg.linear_acceleration.x = self._lx
					imu_msg.linear_acceleration.x = 0
					#imu_msg.linear_acceleration.y = self._ly
					imu_msg.linear_acceleration.y = 0
					#imu_msg.linear_acceleration.z = self._lz
					imu_msg.linear_acceleration.z = 0
					
					self.imu_pub.publish(imu_msg)

			except:
				rospy.logwarn("Error in Sensor values")
				rospy.logwarn(lineParts)
				pass

	def Start(self):
		rospy.logdebug("Starting")
		self._BananaSerial.Start()

	def Stop(self):
		rospy.logdebug("Stopping")
		self._BananaSerial.Stop()

if __name__ =='__main__':
	rospy.init_node('gyro_node',anonymous=True)
	gyro = GYRO_Class()
	try:
		gyro.Start()	
		rospy.spin()
	except rospy.ROSInterruptException:
		rospy.logwarn("Error in main function")

	gyro.Stop()



