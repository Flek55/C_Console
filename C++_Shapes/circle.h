#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"
#include "coord.h"

class Circle: public Figure {
private:
    Coordinate centerCoord;
    float radius;
    float perimeter;
public:
    Circle(std::string name, Coordinate centerCoord, float radius);
    void print() override;
    void printPerimeter() override;
    float calculatePerimeter() override;
    std::string getType() override;
};

#endif // CIRCLE_H
