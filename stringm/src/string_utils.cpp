#include "string_utils.hpp"
#include <algorithm>
#include <sstream>
#include <cctype>

namespace StringUtils {
    
    std::string toUpperCase(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }
    
    std::string toLowerCase(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
    
    std::string trim(const std::string& str) {
        size_t start = str.find_first_not_of(" \t\n\r");
        if (start == std::string::npos) return "";
        
        size_t end = str.find_last_not_of(" \t\n\r");
        return str.substr(start, end - start + 1);
    }
    
    std::string reverse(const std::string& str) {
        std::string result = str;
        std::reverse(result.begin(), result.end());
        return result;
    }
    
    bool startsWith(const std::string& str, const std::string& prefix) {
        return str.size() >= prefix.size() && 
               str.substr(0, prefix.size()) == prefix;
    }
    
    bool endsWith(const std::string& str, const std::string& suffix) {
        return str.size() >= suffix.size() && 
               str.substr(str.size() - suffix.size()) == suffix;
    }
    
    bool contains(const std::string& str, const std::string& substring) {
        return str.find(substring) != std::string::npos;
    }
    
    size_t countOccurrences(const std::string& str, const std::string& substring) {
        size_t count = 0;
        size_t pos = 0;
        while ((pos = str.find(substring, pos)) != std::string::npos) {
            ++count;
            pos += substring.length();
        }
        return count;
    }
    
    std::vector<std::string> split(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::stringstream ss(str);
        std::string token;
        
        while (std::getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    
    std::string join(const std::vector<std::string>& strings, const std::string& separator) {
        if (strings.empty()) return "";
        
        std::string result = strings[0];
        for (size_t i = 1; i < strings.size(); ++i) {
            result += separator + strings[i];
        }
        return result;
    }
    
    std::string replace(const std::string& str, const std::string& from, const std::string& to) {
        std::string result = str;
        size_t pos = 0;
        while ((pos = result.find(from, pos)) != std::string::npos) {
            result.replace(pos, from.length(), to);
            pos += to.length();
        }
        return result;
    }
}
