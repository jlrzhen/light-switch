import sys
import serial
import time

ser = serial.Serial('/dev/ttyUSB0', baudrate = 9600, timeout= 1)

if sys.argv[1] == 'on':
    time.sleep(2)
    ser.write(b'y')
    ser.close()
    exit()

if sys.argv[1] == 'off':
    time.sleep(2)
    ser.write(b'n')
    ser.close()
    exit()
