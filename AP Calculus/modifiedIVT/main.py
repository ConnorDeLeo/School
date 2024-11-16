import numpy as np
import matplotlib.pyplot as plt
import tkinter as tk

linear_coeff = 0
quadratic_coeff = 0
exponential_coeff = 0
sinusoidal_coeff = 0
logarithmic_coeff = 0
polynomial_degree = 0

def randCoef():
    linear_coeff = np.random.uniform(-10, 10)  # Linear function coefficient
    quadratic_coeff = np.random.uniform(-2, 2)  # Quadratic function coefficient
    exponential_coeff = np.random.uniform(0.1, 2)  # Exponential function coefficient
    sinusoidal_coeff = np.random.uniform(0.5, 2)  # Sinusoidal function coefficient
    logarithmic_coeff = np.random.uniform(0.1, 2)  # Logarithmic function coefficient
    polynomial_degree = np.random.randint(2, 5)  # Random degree for the polynomial

# Define the functions with the randomly generated coefficients
def linear(x):
    return linear_coeff * x

def quadratic(x):
    return quadratic_coeff * x**2

def exponential(x):
    return exponential_coeff * np.exp(x)

def sinusoidal(x):
    return sinusoidal_coeff * np.sin(x)

def logarithmic(x):
    return logarithmic_coeff * np.log(x + 1)

def polynomial(x):
    coeffs = np.random.uniform(-2, 2, polynomial_degree + 1)
    return np.polyval(coeffs, x)

def genFuncVals():
    x_vals = np.linspace(-10, 10, 100)  # Generating x values for plotting
    linear_y = linear(x_vals)
    quadratic_y = quadratic(x_vals)
    exponential_y = exponential(x_vals)
    sinusoidal_y = sinusoidal(x_vals)
    logarithmic_y = logarithmic(x_vals)
    polynomial_y = polynomial(x_vals)

def plotFunc():
    plt.figure(figsize=(10, 8))
    plt.plot(x_vals, linear_y, label=f"Linear: f(x) = {linear_coeff}x")
    plt.plot(x_vals, quadratic_y, label=f"Quadratic: f(x) = {quadratic_coeff}x^2")
    plt.plot(x_vals, exponential_y, label=f"Exponential: f(x) = {exponential_coeff}e^x")
    plt.plot(x_vals, sinusoidal_y, label=f"Sinusoidal: f(x) = {sinusoidal_coeff}sin(x)")
    plt.plot(x_vals, logarithmic_y, label=f"Logarithmic: f(x) = {logarithmic_coeff}log(x+1)")
    plt.plot(x_vals, polynomial_y, label=f"Polynomial: Degree {polynomial_degree}")

    plt.scatter(0, 0, color='red', label='Origin (0,0)')
    plt.axhline(0, color='black',linewidth=0.5)
    plt.axvline(0, color='black',linewidth=0.5)
    plt.legend()
    plt.title("Random functions passing through the origin")
    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.grid(True)
    plt.show()

### THIS PORTION WAS DEVELOPED BY CONNOR DE LEO ###

if __name__ == "__main__":
    print("Engaging testing...")
    randCoef()
    genFuncVals()
    plotFunc()
