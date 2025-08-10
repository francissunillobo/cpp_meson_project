#include "math_utils.hpp"
#include <algorithm>
#include <numeric>
#include <cmath>
/**
 * @namespace MathUtils
 * @brief Namespace for mathematical utilities
 */
namespace MathUtils {
    
    double power(double base, double exponent) {
        return std::pow(base, exponent);
    }
    
    /*
    * @brief Calculates the square root of a number
    * @param number The number to calculate the square root of
    * @return The square root of the number
    */
    double squareRoot(double number) {
        return std::sqrt(number);
    }
    
    double absoluteValue(double number) {
        return std::abs(number);
    }
    
    double sine(double angle) {
        return std::sin(angle);
    }
    
    double cosine(double angle) {
        return std::cos(angle);
    }
    
    double tangent(double angle) {
        return std::tan(angle);
    }
    
    double mean(const std::vector<double>& numbers) {
        if (numbers.empty()) return 0.0;
        return sum(numbers) / numbers.size();
    }
    
    double median(std::vector<double> numbers) {
        if (numbers.empty()) return 0.0;
        
        std::sort(numbers.begin(), numbers.end());
        size_t size = numbers.size();
        
        if (size % 2 == 0) {
            return (numbers[size/2 - 1] + numbers[size/2]) / 2.0;
        } else {
            return numbers[size/2];
        }
    }
    
    double standardDeviation(const std::vector<double>& numbers) {
        if (numbers.size() <= 1) return 0.0;
        
        double avg = mean(numbers);
        double sum_squared_diff = 0.0;
        
        for (double num : numbers) {
            double diff = num - avg;
            sum_squared_diff += diff * diff;
        }
        
        return std::sqrt(sum_squared_diff / (numbers.size() - 1));
    }
    
    double sum(const std::vector<double>& numbers) {
        return std::accumulate(numbers.begin(), numbers.end(), 0.0);
    }
    
    bool isPrime(int number) {
        if (number <= 1) return false;
        if (number <= 3) return true;
        if (number % 2 == 0 || number % 3 == 0) return false;
        
        for (int i = 5; i * i <= number; i += 6) {
            if (number % i == 0 || number % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    
    int factorial(int number) {
        if (number < 0) return -1; // Error case
        if (number <= 1) return 1;
        
        int result = 1;
        for (int i = 2; i <= number; ++i) {
            result *= i;
        }
        return result;
    }
    
    int fibonacci(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
    
    double roundToDecimalPlaces(double number, int decimalPlaces) {
        double multiplier = std::pow(10.0, decimalPlaces);
        return std::round(number * multiplier) / multiplier;
    }
}
