#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * Evaluates a polynomial function at a given point x
 * 
 * This function calculates the y-value of a polynomial equation at a specific x-value.
 * The polynomial is represented as an array of coefficients where:
 * equation[0] is the coefficient of x^(size-1)
 * equation[1] is the coefficient of x^(size-2)
 * ... and so on, with equation[size-1] being the constant term.
 * 
 * @param x The x-value at which to evaluate the polynomial
 * @param equation Array of coefficients representing the polynomial
 * @param size Number of terms in the polynomial
 * @return The y-value of the polynomial at point x
 */
float findYPoint(float x, float equation[], int size){
    float y = 0;

    for (int i = 0; i < size; i++)
    {
        y += equation[i] * pow(x, size - i - 1);
    }

    return y;
}

/**
 * Calculates the next candidate root using Newton-Raphson method
 * 
 * This function implements the core Newton-Raphson formula: x_(n+1) = x_n - f(x_n)/f'(x_n)
 * However, the implementation appears to have an issue. The slope calculation should use 
 * the derivative equation, not the original equation. The actual implementation calculates
 * a linear approximation using y = mx + b form and solves for the x-intercept.
 * 
 * @param x Current x-value in the iteration
 * @param y The function value at the current x (f(x))
 * @param equation Array of coefficients representing the derivative of the original polynomial
 * @param size Number of terms in the derivative polynomial
 * @return The next candidate root approximation
 */
float findCandidateRoot(float x, float y, float equation[], int size){
    float slope = 0;

    for (int i = 0; i < size; i++)
    {
        slope +=equation[i] * pow(x, size - i - 1);
    }

    float fixedNumber = y - (slope * x);

    float candidateRoot = (-fixedNumber) / slope;

    return candidateRoot;
}

/**
 * Main function implementing the Newton-Raphson method for finding polynomial roots
 * 
 * The Newton-Raphson method is an iterative technique for finding the roots of a function.
 * It uses the formula: x_(n+1) = x_n - f(x_n)/f'(x_n)
 * 
 * This program:
 * 1. Takes user input for a polynomial equation coefficients
 * 2. Calculates the derivative of the polynomial
 * 3. Takes a starting x-value and error tolerance
 * 4. Iteratively applies the Newton-Raphson formula until convergence
 * 5. Reports the final root approximation
 * 
 * @return EXIT_SUCCESS if program runs successfully, EXIT_FAILURE otherwise
 */
int main(){
    system("cls");  // Clear the console screen (Windows-specific)

    int numberOfTerms;

    printf("Enter number of terms: ");
    scanf("%d", &numberOfTerms);

    // Dynamically allocate memory for the polynomial equation coefficients
    float *equation = (float *)malloc(numberOfTerms * sizeof(float));
    if (equation == NULL) {
        printf("Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // Get user input for each coefficient
    for (int i = 0; i < numberOfTerms; i++)
    {
        printf("Enter %d. item: ", i + 1);
        scanf("%f", &equation[i]);
    }

    // Get search range limits for the root
    float bottomLimit;
    float topLimit;

    printf("Enter bottom limit: ");
    scanf("%f", &bottomLimit);

    printf("Enter top limit: ");
    scanf("%f", &topLimit);

    // Get desired error tolerance (convergence criterion)
    float myErrorRatio;

    printf("Enter error ratio: ");
    scanf("%f", &myErrorRatio);

    float errorRatio = 1.0;  // Initialize error to a value larger than typical error ratios

    float xParameter;  // Starting x-value for Newton-Raphson iteration

    // Calculate the derivative of the polynomial
    // For a polynomial of degree n, the derivative has degree n-1
    float *derivativeEquation = (float *)malloc((numberOfTerms - 1) * sizeof(float));
    if (derivativeEquation == NULL) {
        printf("Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // Apply the power rule: d/dx(ax^n) = a*n*x^(n-1)
    for (int i = 0; i < numberOfTerms - 1; i++)
    {
        derivativeEquation[i] = equation[i] * (numberOfTerms - i - 1); 
    }

    // Get initial x-value within the specified limits
    printf("Enter -x parameter between of %.2f - %.2f: ", bottomLimit, topLimit);
    scanf("%f", &xParameter);

    float candidateRoot = 0;

    // Newton-Raphson iteration loop
    // Continue until error is less than or equal to desired tolerance
    do{
        // Calculate y-value at current x
        float yPoint = findYPoint(xParameter, equation, numberOfTerms);

        // Calculate next approximation using Newton-Raphson formula
        candidateRoot = findCandidateRoot(xParameter, yPoint, derivativeEquation, numberOfTerms - 1);
        
        printf("Candidate root %f \n", candidateRoot);

        // Calculate absolute error between current and previous approximation
        errorRatio = fabs(candidateRoot - xParameter);

        // Update x for next iteration
        xParameter = candidateRoot;

    }while(errorRatio > myErrorRatio);

    // Display final root approximation
    printf("The root of equation: %f", candidateRoot);
    
    // Free dynamically allocated memory
    free(equation);
    free(derivativeEquation);
    return 0;
}