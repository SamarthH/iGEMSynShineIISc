import serial
import sys
import time

ser=serial.Serial(input(),baudrate=9600,timeout=1)


def msgReceived():
    pass


def error():
    pass

def __xor__(arr):
    if len(arr) is 0:
        return None
    sum=0
    for i in range(len(arr)):
        sum^=arr[i]
    return sum

def serialListenError():
    while(ser.in_waiting):
        ser.read_until('\n')
    ser.write(b"ERROR")

def sendMsg(msg):
    a=chr(__xor__([ord(char) for char in msg]))
    b=chr(sum([ord(char) for char in msg])%256)

    while(True): 
        ser.write(("ST"+msg+a+b+'\r\n').encode('ascii'))
        time.sleep(0.01)
        if ser.in_waiting:
            if ser.read()=='C':
                if ser.read()=='N':
                    if ser.read()=='F':
                        if ser.read()==a:
                            break
        while ser.in_waiting:
            ser.read()

def listener():
    ser.flush()
    if ser.in_waiting:
        run=True
        if ser.in_waiting:
            run = True
        if ser.read()=='S':
            if ser.read()=='T':
                Str=''
                while (run and ser.in_waiting):
                    c=ser.read()
                    if c!='\r':
                        Str+=c
                    else:
                        run=False
                        ser.read_until('\n')
                        if c is '\n':
                            run = False
                if run is True:
                    serialListenError()
                    return None
                n=len(Str)
                msg=Str[0:n-2]
                a=chr(__xor__([ord(char) for char in msg]))
                b=chr(sum([ord(char) for char in msg])%256)
                if (Str[n-1]==b) and (Str[n-2]==a):
                    ser.write(('CNF'+a).encode('ascii'))
                # The msg received is a bit different. Will implement later
                    msgReceived()
                    return None
                else:
                    serialListenError()
            else:
                serialListenError()
                return None    

while 1:
    listener()
    time.sleep(0.1)




