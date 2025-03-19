# 📊 Newton-Raphson Root Finding Implementation in C

## 🔍 Overview

This repository contains a C implementation of the Newton-Raphson method for finding roots of polynomial equations. The Newton-Raphson method is a powerful numerical technique that uses derivative information to iteratively approximate the roots of a function with quadratic convergence under appropriate conditions.

## 🧮 Mathematical Background

The Newton-Raphson method is based on the following iteration formula:

$$x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}$$

Where:
- $x_n$ is the current approximation
- $f(x_n)$ is the function value at the current approximation
- $f'(x_n)$ is the derivative of the function at the current approximation
- $x_{n+1}$ is the next, more accurate approximation

This method works by approximating the function with its tangent line at the current guess and then using the x-intercept of this tangent line as the next approximation.

## ✨ Features

- 🧩 Supports polynomials of any degree
- 🔄 Iterative approximation with user-defined error tolerance
- 📈 Automatic calculation of polynomial derivatives
- 🔎 User-defined search range for roots
- 📝 Step-by-step output showing convergence progress

## 🚀 Usage

1. Compile the program using any C compiler:
   ```
   gcc newton_raphson.c -o newtonRaphson -lm
   ```

2. Run the executable:
   ```
   ./newtonRaphson
   ```

3. Follow the prompts:
   - Enter the number of terms in your polynomial
   - Enter each coefficient (starting from the highest degree term)
   - Specify a search range (bottom and top limits)
   - Set your desired error tolerance
   - Provide an initial guess within the specified range

4. The program will output each iteration's approximation and finally display the root when convergence is achieved.

## 📋 Example

For the polynomial $f(x) = x^3 - 2x^2 - 5$:

```
Enter number of terms: 4
Enter 1. item: 1    (coefficient of x^3)
Enter 2. item: -2   (coefficient of x^2)
Enter 3. item: 0    (coefficient of x^1)
Enter 4. item: -5   (coefficient of x^0)
Enter bottom limit: 2
Enter top limit: 3
Enter error ratio: 0.0001
Enter x parameter between of 2.00 - 3.00: 2.5
Candidate root 2.518364
Candidate root 2.514362
Candidate root 2.514292
The root of equation: 2.514292
```

## ⚠️ Limitations

- The method may diverge for certain starting points or functions
- Multiple roots require different starting points
- The method may struggle with roots of multiplicity greater than 1
- No built-in handling for complex roots

## 🔧 Technical Implementation

The code consists of three main components:

1. `findYPoint()`: Evaluates a polynomial at a given x-value
2. `findCandidateRoot()`: Implements the Newton-Raphson formula to calculate the next approximation
3. `main()`: Handles user input, derivative calculation, and the iteration loop

## 🤝 Contributing

Contributions to improve the implementation are welcome! Some potential enhancements:
- Add safeguards against division by zero
- Implement handling for multiple roots
- Add visualization of the convergence process
- Improve input validation and error handling

## 📚 Further Reading

To learn more about the Newton-Raphson method:
- [Numerical Methods for Engineers](https://www.amazon.com/Numerical-Methods-Engineers-Steven-Chapra/dp/007339792X)
- [Numerical Analysis](https://en.wikipedia.org/wiki/Numerical_analysis)
