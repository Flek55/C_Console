#include "circle.h"

Circle::Circle(std::string name, Coordinate centerCoord, float radius): Figure(name) {
    if (name == "")
        throw FigureException("Empty name!");

    if (radius <= 0)
        throw FigureException("Incorrect radius value!");

    this->centerCoord.x = centerCoord.x;
    this->centerCoord.y = centerCoord.y;
    this->radius = radius;
}

void Circle::print() {
    std::cout<<getType()<<"\nName: "<<name<<"\nX: "<<centerCoord.x<<" Y: "<<centerCoord.y<<"\nRadius: "<<radius<<std::endl;
}

void Circle::printPerimeter() {
    std::cout <<"Type:"<<getType()<<"\n  Name: "<<name<<"\n  Perimeter: "
              <<calculatePerimeter()<< std::endl;
}

float Circle::calculatePerimeter() {
    return TWO * M_PI * radius;
}

std::string Circle::getType() {
    return "Circle";
}
