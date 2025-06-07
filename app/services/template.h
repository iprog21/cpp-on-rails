#pragma once
#include <string>
#include <fstream>
#include <sstream>

class Template {
    std::string content;
public:
    explicit Template(const std::string& path) {
        std::ifstream file(path);
        if (file) {
            std::ostringstream ss; ss << file.rdbuf();
            content = ss.str();
        }
    }

    void replace(const std::string& key, const std::string& value){
        std::string token = "{{" + key + "}}";
        size_t pos = 0;
        while((pos = content.find(token, pos)) != std::string::npos){
            content.replace(pos, token.length(), value);
            pos += value.length();
        }
    }

    std::string render() const { return content; }
};
