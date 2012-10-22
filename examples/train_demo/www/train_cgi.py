#!/usr/bin/env python
# -*- coding: UTF-8 -*-

# enable debugging
import cgitb
cgitb.enable()
import cgi
import serial


form = cgi.FieldStorage()

print "Content-Type: text/html;charset=utf-8"
print

print open("interface.form").read()
ser = serial.Serial('/dev/ttyAMA0', 9600)
if form.has_key("SPEED"):
   val = form["SPEED"].value
   print "SPEED", val, ser.write(val)
if form.has_key("GO"):

   val = form["GO"].value
   if val == 'GO':
     print ser.write("f")
   elif val == "REVERSE":
     print ser.write("b")
   else:
     print ser.write("s")
