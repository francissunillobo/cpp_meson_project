#pragma once
#include <string>
#include <vector>

namespace IOUtils {
    // File operations
    bool writeToFile(const std::string& filename, const std::string& content);
    std::string readFromFile(const std::string& filename);
    bool fileExists(const std::string& filename);
    
    // Directory operations
    std::vector<std::string> listFiles(const std::string& directory);
    bool createDirectory(const std::string& path);
    
    // Console operations
    void printMessage(const std::string& message);
    std::string getUserInput(const std::string& prompt);
}
