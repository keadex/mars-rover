#pragma once
#include <vector>
#include <string>

namespace Utils {
    class StringUtils{
        public:
            static std::vector<std::string> splitBySpace(std::string string);
            static std::string replaceAll(std::string str, const std::string& from, const std::string& to);

        private:
            StringUtils() {}
    };
}