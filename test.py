#!/usr/bin/python3 


import capy

a=capy.Circle(100,100,300)
b=capy.BaseObj(10,100,300,200)
r=capy.Rectangle(1000,1000,5000,5000)
print (a.toString(),b.toString(),r.toString())

a.move(1000,100)
b.inflate(100,100)
r.inflate(-500,-500)
print (a.toString(),b.toString(),r.toString())

s1=a.getSize()
print(s1.toString())

s2=b.getSize()
print(s2.toString())




pos1=a.getPos();
b.setPos(pos1)
print (a.toString(),b.toString())

b.move(100,100)
print (b.toString())

b.move(pos1)
print (b.toString())


s3=s1+s2
s4=s1-s2
print(s3.toString())
print(s4.toString())

