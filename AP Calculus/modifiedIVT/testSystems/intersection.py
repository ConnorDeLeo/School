import numpy as np
import numpy.random as rand

"""
Function types: Constant, Linear, Quadratic, Exponential, Sinusoidal

f(x) = a
f(x) = ax + b
f(x) = ax^2 + b
f(x) = a^cx + b
f(x) = a(sin(cx)) + b
"""

# Generate x domain
xVal = np.linspace(-10, 10, 100)

def generateFunc(x):

    # Generate positive or negative coefficients
    a = 1 + (rand.radnint(9) * rand.choice([-1, 1]))
    b = 1 + (rand.radnint(9) * rand.choice([-1, 1]))
    c = 1 + (rand.radnint(9) * rand.choice([-1, 1]))

    # Select function type
    fType = rand.randint(5)

    if (fType == 0):
        # Constant
        return a
    elif (fType == 1):
        # Linear
        return a*x + b
    elif (fType == 2):
        # Quadratic
        return a*x**2 + c
    elif (fType == 3):
        # Exponential
        return a**(c*x) + b
    else:
        # Sinusoidal
        return a*(np.sin(c*x)) + b

def domainCheck():
    
    for i in range (50):


def intersectCheck():
    return NULL

func1 = chooseFunc()