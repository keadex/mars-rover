#include "Utils.h"
#include <sstream>
#include <iterator>

std::vector<std::string> Utils::StringUtils::splitBySpace(std::string string){
    std::istringstream iss(string);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
    return results;
}

std::string Utils::StringUtils::replaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}