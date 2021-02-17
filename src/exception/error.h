#pragma once
#include <string>

namespace Error {
    static const std::string ERROR_INVALID_CARDINAL_DIRECTION_CHAR = "Invalid Cardinal Direction character";
    static const std::string ERROR_INVALID_CARDINAL_DIRECTION_NUMBER = "Invalid Cardinal Direction number";
    static const std::string ERROR_INVALID_CARDINAL_DIRECTION_STRING = "Invalid Cardinal Direction string";

    static const std::string ERROR_INVALID_PLATEAU_SIZE = "Invalid mission input. Incorrect plateau size.";
    static const std::string ERROR_INVALID_POSITION = "Invalid mission input. Incorrect position.";
    static const std::string ERROR_INVALID_COMMAND = "Invalid mission input. Invalid command.";

    static const std::string ERROR_INVALID_ROVER_X_POSITION = "Invalid rover 'x' position";
    static const std::string ERROR_INVALID_ROVER_Y_POSITION = "Invalid rover 'y' position";

}