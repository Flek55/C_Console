#include "figureException.h"

FigureException::FigureException(const std::string message) {
    this->message = message;
}

const char* FigureException::what() const noexcept {
    return message.c_str();
}


InputException::InputException(const std::string message) {
    this->message = message;
}

const char* InputException::what() const noexcept {
    return message.c_str();
}
