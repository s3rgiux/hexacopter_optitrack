import pyxl320
from pyxl320 import xl320
from pyxl320 import ServoSerial, Packet, utils
import time

serial = ServoSerial('/dev/ttyUSB0')  # tell it what port you want to use
# serial = ServoSerial('/dev/tty.usbserial', fake=True)  # use a dummy serial interface for testing
serial.open()

angle1=158
angle2=140
angle3=230

time.sleep(0.1)
pkt = Packet.makeServoPacket(11, angle1)  # move servo 1 to angle1 degrees
try:
    ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
    time.sleep(0.1)
except:
    print("something happended")


pkt = Packet.makeServoPacket(12, angle2)  # move servo 1 to angle1 degrees
try:
    ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
    time.sleep(0.1)
except:
    print("something happended")

# pkt = Packet.makeServoPacket(13, angle3)  # move servo 1 to angle1 degrees
# try:
#     ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
#     time.sleep(0.1)
# except:
#     print("something happended")



pkt = Packet.makeServoPacket(21, angle1)  # move servo 1 to angle1 degrees
try:
    ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
    time.sleep(0.1)
except:
    print("something happended")


pkt = Packet.makeServoPacket(22, angle2)  # move servo 1 to angle1 degrees
try:
    ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
    time.sleep(0.1)
except:
    print("something happended")

# pkt = Packet.makeServoPacket(23, angle3)  # move servo 1 to angle1 degrees
# try:
#     ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
#     time.sleep(0.1)
# except:
#     print("something happended")




pkt = Packet.makeServoPacket(31, angle1)  # move servo 1 to angle1 degrees
try:
    ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
    time.sleep(0.1)
except:
    print("something happended")


pkt = Packet.makeServoPacket(32, angle2)  # move servo 1 to angle1 degrees
try:
    ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
    time.sleep(0.1)
except:
    print("something happended")

# pkt = Packet.makeServoPacket(33, angle3)  # move servo 1 to angle1 degrees
# try:
#     ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
#     time.sleep(0.1)
# except:
#     print("something happended")





pkt = Packet.makeServoPacket(41, angle1)  # move servo 1 to angle1 degrees
try:
    ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
    time.sleep(0.1)
except:
    print("something happended")


pkt = Packet.makeServoPacket(42, angle2)  # move servo 1 to angle1 degrees
try:
    ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
    time.sleep(0.1)
except:
    print("something happended")

# pkt = Packet.makeServoPacket(43, angle3)  # move servo 1 to angle1 degrees
# try:
#     ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
#     time.sleep(0.1)
# except:
#     print("something happended")



pkt = Packet.makeServoPacket(51, angle1)  # move servo 1 to angle1 degrees
try:
    ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
    time.sleep(0.1)
except:
    print("something happended")


pkt = Packet.makeServoPacket(52, angle2)  # move servo 1 to angle1 degrees
try:
    ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
    time.sleep(0.1)
except:
    print("something happended")

# pkt = Packet.makeServoPacket(53, angle3)  # move servo 1 to angle1 degrees
# try:
#     ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
#     time.sleep(0.1)
# except:
#     print("something happended")



pkt = Packet.makeServoPacket(61, angle1)  # move servo 1 to angle1 degrees
try:
    ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
    time.sleep(0.1)
except:
    print("something happended")


pkt = Packet.makeServoPacket(62, angle2)  # move servo 1 to angle1 degrees
try:
    ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
    time.sleep(0.1)
except:
    print("something happended")

# pkt = Packet.makeServoPacket(63, angle3)  # move servo 1 to angle1 degrees
# try:
#     ret = serial.sendPkt(pkt)  # send packet, I don't do anything with the returned status packet
#     time.sleep(0.1)
# except:
#     print("something happended")

