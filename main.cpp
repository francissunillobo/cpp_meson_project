#include <iostream>
#include <vector>
#include "io_utils.hpp"
#include "string_utils.hpp"
#include "math_utils.hpp"

int main() {
    std::cout << "=== C++ Meson Multi-Module Demo ===" << std::endl << std::endl;
    
    // Demonstrate IO Utils
    std::cout << "=== IO Utilities Demo ===" << std::endl;
    IOUtils::printMessage("Testing IO utilities module");
    
    std::string testContent = "Hello from IO module!\nThis is a test file.";
    std::string testFile = "test_output.txt";
    
    if (IOUtils::writeToFile(testFile, testContent)) {
        IOUtils::printMessage("File written successfully");
    }
    
    if (IOUtils::fileExists(testFile)) {
        std::string content = IOUtils::readFromFile(testFile);
        std::cout << "File contents:\n" << content << std::endl;
    }
    
    // Demonstrate String Utils
    std::cout << "\n=== String Utilities Demo ===" << std::endl;
    std::string testString = "  Hello World from String Utils!  ";
    
    std::cout << "Original: '" << testString << "'" << std::endl;
    std::cout << "Trimmed: '" << StringUtils::trim(testString) << "'" << std::endl;
    std::cout << "Uppercase: '" << StringUtils::toUpperCase(testString) << "'" << std::endl;
    std::cout << "Lowercase: '" << StringUtils::toLowerCase(testString) << "'" << std::endl;
    std::cout << "Reversed: '" << StringUtils::reverse(StringUtils::trim(testString)) << "'" << std::endl;
    
    std::vector<std::string> words = StringUtils::split(StringUtils::trim(testString), ' ');
    std::cout << "Split into words: ";
    for (const auto& word : words) {
        std::cout << "[" << word << "] ";
    }
    std::cout << std::endl;
    
    std::cout << "Joined with '-': " << StringUtils::join(words, "-") << std::endl;
    std::cout << "Contains 'String': " << (StringUtils::contains(testString, "String") ? "Yes" : "No") << std::endl;
    
    // Demonstrate Math Utils
    std::cout << "\n=== Math Utilities Demo ===" << std::endl;
    
    double base = 2.0, exponent = 3.0;
    std::cout << base << "^" << exponent << " = " << MathUtils::power(base, exponent) << std::endl;
    std::cout << "sqrt(16) = " << MathUtils::squareRoot(16.0) << std::endl;
    std::cout << "sin(π/2) = " << MathUtils::sine(MathUtils::PI / 2) << std::endl;
    std::cout << "cos(0) = " << MathUtils::cosine(0) << std::endl;
    
    std::vector<double> numbers = {1.5, 2.8, 3.2, 4.1, 5.7, 6.3, 7.9};
    std::cout << "\nStatistical analysis of: ";
    for (double num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Mean: " << MathUtils::roundToDecimalPlaces(MathUtils::mean(numbers), 2) << std::endl;
    std::cout << "Median: " << MathUtils::roundToDecimalPlaces(MathUtils::median(numbers), 2) << std::endl;
    std::cout << "Standard Deviation: " << MathUtils::roundToDecimalPlaces(MathUtils::standardDeviation(numbers), 2) << std::endl;
    std::cout << "Sum: " << MathUtils::roundToDecimalPlaces(MathUtils::sum(numbers), 2) << std::endl;
    
    int testNum = 17;
    std::cout << "\n" << testNum << " is prime: " << (MathUtils::isPrime(testNum) ? "Yes" : "No") << std::endl;
    std::cout << "5! = " << MathUtils::factorial(5) << std::endl;
    std::cout << "10th Fibonacci number: " << MathUtils::fibonacci(10) << std::endl;
    
    std::cout << "\n=== Demo Complete ===" << std::endl;
    
    return 0;
}
