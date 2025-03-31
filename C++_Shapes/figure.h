#ifndef FIGURE_H
#define FIGURE_H
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "figureException.h"
#include "constants.h"


class Figure {
protected:
    std::string name;
public:
    virtual void print() = 0;
    virtual ~Figure() = default;
    virtual void printPerimeter() = 0;
    virtual float calculatePerimeter() = 0;
    virtual std::string getType() = 0;
    Figure(std::string name);
};

#endif // FIGURE_H
