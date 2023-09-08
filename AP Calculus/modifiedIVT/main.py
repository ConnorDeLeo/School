import random as rand
import string
import os
import tkinter as tk

def func(domain, func):
    x = (domain, domain + 50)

    if func == 1:
        y = rand(0,100)
    elif func == 2:
        y = (rand(-1,1) * x) + rand(0,16)
    elif func == 3:
        degree = rand(2,5)
        
        if degree == 2:
            y = (rand(1,16) * pow(x, 2)) + (rand(0,16) * x) + rand(0,16)
        elif degree == 3:
            y = (rand(1,16) * pow(x, 3)) + (rand(0,16) * pow(x, 2)) + (rand(0,16) * x) + rand(0,16)
        elif degree == 4:
            y = (rand(1,16) * pow(x, 4)) + (rand(0,16) * pow(x, 3)) + (rand(0,16) * pow(x, 2)) + (rand(0,16) * x) + rand(0,16)
        elif degree == 5:
            y = (rand(1,16) * pow(x, 5)) + (rand(0,16) * pow(x, 4)) + (rand(0,16) * pow(x, 3)) + (rand(0,16) * pow(x, 2)) + (rand(0,16) * x) + rand(0,16)

def checker():
    print("Checker")

