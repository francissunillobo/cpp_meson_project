#pragma once
#include <vector>
#include <cmath>

namespace MathUtils {
    // Basic operations
    double power(double base, double exponent);
    double squareRoot(double number);
    double absoluteValue(double number);
    
    // Trigonometric functions
    double sine(double angle);
    double cosine(double angle);
    double tangent(double angle);
    
    // Statistical functions
    double mean(const std::vector<double>& numbers);
    double median(std::vector<double> numbers);
    double standardDeviation(const std::vector<double>& numbers);
    double sum(const std::vector<double>& numbers);
    
    // Utility functions
    bool isPrime(int number);
    int factorial(int number);
    int fibonacci(int n);
    double roundToDecimalPlaces(double number, int decimalPlaces);
    
    // Constants
    constexpr double PI = 3.14159265358979323846;
    constexpr double E = 2.71828182845904523536;
}
