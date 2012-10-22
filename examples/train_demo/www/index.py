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
