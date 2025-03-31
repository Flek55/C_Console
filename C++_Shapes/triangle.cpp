#include "triangle.h"

Triangle::Triangle(std::string name,
                   Coordinate coord1,
                   Coordinate coord2,
                   Coordinate coord3): Figure(name) {

    if (name == "")
        throw FigureException("Empty name!");


    float side1 = std::sqrt(std::pow(coord2.x - coord1.x, 2) + std::pow(coord2.y - coord1.y, 2));
    float side2 = std::sqrt(std::pow(coord3.x - coord2.x, 2) + std::pow(coord3.y - coord2.y, 2));
    float side3 = std::sqrt(std::pow(coord1.x - coord3.x, 2) + std::pow(coord1.y - coord3.y, 2));
    if (side1 >= side2 + side3 || side2 >= side1 + side3 || side3 >= side1 + side2) {
        throw FigureException("Inexistent triangle!");
    }
    this->coord1.x = coord1.x;
    this->coord1.y = coord1.y;
    this->coord2.x = coord2.x;
    this->coord2.y = coord2.y;
    this->coord3.x = coord3.x;
    this->coord3.y = coord3.y;
}

void Triangle::print() {
    std::cout << getType() << "\nName: " << name << "\nX1: " << coord1.x << " Y1: " << coord1.y
              << "\nX2: " << coord2.x << " Y2: " << coord2.y
              << "\nX3: " << coord3.x << " Y3: " << coord3.y << std::endl;
}

void Triangle::printPerimeter() {
    std::cout <<"Type:"<<getType()<<"\n  Name: "<<name<<"\n  Perimeter: "
              <<calculatePerimeter()<< std::endl;
}

float Triangle::calculatePerimeter() {
    float side1 = std::sqrt(std::pow(coord2.x - coord1.x, 2) + std::pow(coord2.y - coord1.y, 2));
    float side2 = std::sqrt(std::pow(coord3.x - coord2.x, 2) + std::pow(coord3.y - coord2.y, 2));
    float side3 = std::sqrt(std::pow(coord1.x - coord3.x, 2) + std::pow(coord1.y - coord3.y, 2));

    return side1 + side2 + side3;
}

std::string Triangle::getType() {
    return "Triangle";
}
