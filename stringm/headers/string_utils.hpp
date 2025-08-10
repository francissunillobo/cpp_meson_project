#pragma once
#include <string>
#include <vector>

namespace StringUtils {
    // String manipulation
    std::string toUpperCase(const std::string& str);
    std::string toLowerCase(const std::string& str);
    std::string trim(const std::string& str);
    std::string reverse(const std::string& str);
    
    // String analysis
    bool startsWith(const std::string& str, const std::string& prefix);
    bool endsWith(const std::string& str, const std::string& suffix);
    bool contains(const std::string& str, const std::string& substring);
    size_t countOccurrences(const std::string& str, const std::string& substring);
    
    // String operations
    std::vector<std::string> split(const std::string& str, char delimiter);
    std::string join(const std::vector<std::string>& strings, const std::string& separator);
    std::string replace(const std::string& str, const std::string& from, const std::string& to);
}
