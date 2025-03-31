#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"
#include "coord.h"

class Triangle: public Figure{
private:
    Coordinate coord1;
    Coordinate coord2;
    Coordinate coord3;
public:
    Triangle(std::string name,
             Coordinate coord1,
             Coordinate coord2,
             Coordinate coord3);
    void print() override;
    void printPerimeter() override;
    float calculatePerimeter() override;
    std::string getType() override;
};

#endif // TRIANGLE_H
