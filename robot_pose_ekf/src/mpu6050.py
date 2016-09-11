#!/usr/bin/env python

import rospy
import sys
import time
import math
import tf

from banana_serial import BananaSerial
from std_msgs.msg import Int16,Int32, Int64, Float32, String, Header, UInt64, Float64
from sensor_msgs.msg import Imu
from tf.transformations import quaternion_from_euler
from geometry_msgs.msg import *
#from tf.transformations import createQuaternionMsgFromYaw
degrees2rad = math.pi/180.0

class GYRO_Class(object):
	
	def __init__(self):
		print "Initializing"

		self._Counter = 0

		self._ax = 0
		
		port = rospy.get_param("~port", "/dev/ttyUSB1")
		baudRate = int(rospy.get_param("~baudRate", 115200))

		rospy.loginfo("Starting with serial port: " + port + ", baud rate: " + str(baudRate))
		self._BananaSerial = BananaSerial(port, baudRate,  self._HandleReceivedLine)
		rospy.loginfo("Started serial communication")
		
		#Publisher for entire serial data
		self._SerialPublisher = rospy.Publisher('serial', String,queue_size=10)
		
                #Subscribers and Publishers of IMU data topic

		self.frame_id = 'angelbot_mpu6050_link'

        	self.cal_buffer =[]
        	self.cal_buffer_length = 1000
        	self.imu_data = Imu(header=rospy.Header(frame_id="angelbot_mpu6050_link"))
		self.imu_data.orientation_covariance = [1e6, 0, 0, 0, 1e6, 0, 0, 0, 1e-6]
	        self.imu_data.angular_velocity_covariance = [1e6, 0, 0, 0, 1e6, 0, 0, 0, 1e6]
        	self.imu_data.linear_acceleration_covariance = [-1,0,0,0,0,0,0,0,0]
        	self.yaw_pub = rospy.Publisher('yaw_from_imu', Float64, queue_size = 10)
		self.imu_pub = rospy.Publisher('imu_data', Imu, queue_size = 10)

	def _HandleReceivedLine(self,  line):
		self._Counter = self._Counter + 1
		self._SerialPublisher.publish(String(str(self._Counter) + ", in:  " + line))

		if(len(line) > 0):

			lineParts = line.split('\t')
			try:

				if(lineParts[0] == 'yaw'):

          				self._ax = float(lineParts[1])

					yaw_msg = Float64()
					imu_msg = Imu()
					h = Header()
					h.stamp = rospy.Time.now()
					h.frame_id = self.frame_id

					imu_msg.header = h

					yaw_msg.data = self._ax
					q = quaternion_from_euler(0,0,self._ax*-degrees2rad)
					imu_msg.orientation.x = q[0]
					imu_msg.orientation.y = q[1]
					imu_msg.orientation.z = q[2]
					imu_msg.orientation.w = q[3]

					imu_msg.orientation_covariance = [1e6, 0, 0, 0, 1e6, 0, 0, 0, 1e-6]
        				imu_msg.angular_velocity_covariance = [1e6, 0, 0, 0, 1e6, 0, 0, 0, 1e6]
        				imu_msg.linear_acceleration_covariance = [-1,0,0,0,0,0,0,0,0]

					self.imu_pub.publish(imu_msg)
					self.yaw_pub.publish(yaw_msg)

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
