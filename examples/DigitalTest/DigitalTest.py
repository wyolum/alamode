#$Id: buttontk.py,v 1.2 2004/03/17 04:29:31 mandava Exp $
#this is a simple program which creates buttons.
import time
import serial
import Tkinter
from Tkinter import *
root =Tk()
root.title('DigitalControl')
Label(text='Toggle Buttons').pack(pady=15)

#button are labels that react to mouse and keyboard events.
#in this case the button is packed to be at the bottom of the root or
#toplevel widget.

ser = serial.Serial('/dev/ttyS0', baudrate=9600, timeout=1)
class DigiPin:
    def __init__(self, pin, state):
        assert 1 < pin, "bad pin %d, must be greater than 1" % pin
        self.pin = pin
        self.state = state
        ser.write("00pm00%02dOUTP;" % self.pin)
        self.send()
    def toggle(self):
        self.state = not self.state
        self.send()
    def send(self):
        cmd = "00dw00%02d%s;" % (self.pin, (' LOW', 'HIGH')[self.state])
        ser.write(cmd)

class DigiButton:
    def __init__(self, pin):
        self.pin = DigiPin(pin, False)
        self.tkbutton = Button(text='PIN %d' % i, command=self.toggle, background="#FFFFFF", activebackground="#888888") 
        self.tkbutton.pack(side=BOTTOM)
    def toggle(self):
        self.pin.toggle()
        print self.pin.pin, self.pin.state
        self.tkbutton.config(background=("#FFFFFF", "#00FF00")[self.pin.state],
                             activebackground=("#888888", "#008800")[self.pin.state])


buttons = [DigiButton(i) for i in range(2, 14)]

def binary_count():
    state = buttons[0].pin.state
    count = 0
    for i in range(2):
        for j in range(2):
            for k in range(2):
                for l in range(2):
                    buttons[-4].toggle()
                    time.sleep(.2)
                buttons[-3].toggle()
            buttons[-2].toggle()
        buttons[-1].toggle()
Button(text='BIN Count', command=binary_count, background="#FFFFFF", activebackground="#888888").pack(side=BOTTOM) 
root.mainloop()


