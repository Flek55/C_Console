#ifndef FIGUREEXCEPTION_H
#define FIGUREEXCEPTION_H
#include <iostream>

class FigureException: std::exception {
private:
    std::string message;
public:
    FigureException(const std::string message);

    const char* what() const noexcept override;
};

class InputException: std::exception {
private:
    std::string message;
public:
    InputException(const std::string message);

    const char* what() const noexcept override;
};

#endif // FIGUREEXCEPTION_H
