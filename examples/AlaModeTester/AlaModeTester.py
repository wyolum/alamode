from serial import Serial
from time import sleep
from Tkinter import *

# add to Utilities to sys.path
import sys
sys.path.append('..')

from Lib.DS3231 import DS3231
from Lib.Adafruit_I2C import Adafruit_I2C

import time
import datetime

BAUD = 9600
alamode = Adafruit_I2C(42);

try:
    r = Tk()
    gui = True
except:
    gui = False
    
class TestButton:
    def __init__(self, text, test):
        if gui:
            self.button = Button(text=text, command=self.press, background='#FFFFFF', activebackground='#888888')
            self.button.pack()
        self.test = test
        self.press()

    def press(self):
        self.val = self.test()
        if gui:
            self.button.config(background=("#FFFFFF", "#00FF00")[self.val],
                               activebackground=("#888888", "#008800")[self.val])

def checkSD():
  sd_addr = 1;
  out = alamode.readList(sd_addr, 1)[0];
  out = out == 0
  print 'checkSD():', out
  return out

def checkSerial():
    ser = Serial('/dev/ttyS0', baudrate=9600, timeout=1)
    out = True
    msg = "0123456789ABCD"
    n = len(msg)

    ser.write(msg);
    time.sleep(.100);
    data = ser.read(n)
    print 'checkSerial() data:', data
    if len(data) != n:
        out = False
    else:
        out = data == msg
    return out;

def checkRTC():
    rtc = DS3231()
    date = range(7);
    rtc.ds3231.writeList(0, date);
    date[6] = 0;
    date1 = rtc.getTime()
    if date1.year != 2006:
        out = False
    else:
        now = datetime.datetime.now()
        rtc.setTime(now)
        date2 = rtc.getTime()
        out = now.year == date2.year
        print 'checkRCT() date:', date2
    return out

def checkI2C():
    out = True;
    ping_addr = 3;
    n_byte = 20;
    data_out = range(n_byte);
    
    alamode.writeList(ping_addr, data_out)
    data_in = alamode.readList(ping_addr, n_byte + ping_addr)[ping_addr:] # crazy hack becuase I can't get it to start reading from ping_addr
    for i in range(n_byte):
        if data_in[i] != data_out[i]:
            print 'data_out', data_out
            print '!='
            print 'data_in:', data_in
            out = False
            break
    print 'checkI2C():', out
    return out;

TestButton(text='SD', test=checkSD)
TestButton(text='Serial', test=checkSerial)
TestButton(text='RTC', test=checkRTC)
TestButton(text='I2C', test=checkI2C)

if gui:
    r.mainloop()
