#include "io_utils.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace IOUtils {
    
    bool writeToFile(const std::string& filename, const std::string& content) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        file << content;
        file.close();
        return true;
    }
    
    std::string readFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return "";
        }
        
        std::string content;
        std::string line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        file.close();
        return content;
    }
    
    bool fileExists(const std::string& filename) {
        return std::filesystem::exists(filename);
    }
    
    std::vector<std::string> listFiles(const std::string& directory) {
        std::vector<std::string> files;
        try {
            for (const auto& entry : std::filesystem::directory_iterator(directory)) {
                if (entry.is_regular_file()) {
                    files.push_back(entry.path().filename().string());
                }
            }
        } catch (const std::exception& e) {
            std::cerr << "Error listing files: " << e.what() << std::endl;
        }
        return files;
    }
    
    bool createDirectory(const std::string& path) {
        try {
            return std::filesystem::create_directories(path);
        } catch (const std::exception& e) {
            std::cerr << "Error creating directory: " << e.what() << std::endl;
            return false;
        }
    }
    
    void printMessage(const std::string& message) {
        std::cout << "[IO] " << message << std::endl;
    }
    
    std::string getUserInput(const std::string& prompt) {
        std::cout << prompt << ": ";
        std::string input;
        std::getline(std::cin, input);
        return input;
    }
}
