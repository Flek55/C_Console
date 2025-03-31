#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"
#include "coord.h"

class Rectangle: public Figure {
private:
    Coordinate leftUpperCoord;
    Coordinate rightBottomCoord;
public:
    Rectangle(std::string name, Coordinate leftUpperCoord,
              Coordinate rightBottomCoord);
    void print() override;
    void printPerimeter() override;
    float calculatePerimeter() override;
    std::string getType() override;
};

#endif // RECTANGLE_H
