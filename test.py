#!/usr/bin/python3 

import capy

a=capy.Circle(100,100,300)
b=capy.BaseObj(10,100,300,200)
print (a.toString(),b.toString())

a.move(1000,100)
b.inflate(100,100)
print (a.toString(),b.toString())

s1=a.getSize()
print(s1.toString())

s2=b.getSize()
print(s2.toString())

#error
s3=s1+s2

