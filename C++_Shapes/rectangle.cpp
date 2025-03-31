#include "rectangle.h"

Rectangle::Rectangle(std::string name, Coordinate leftUpperCoord, Coordinate rightBottomCoord): Figure(name) {
    if (name == "")
        throw FigureException("Empty name!");

    if (leftUpperCoord.x >= rightBottomCoord.x || leftUpperCoord.y <= rightBottomCoord.y)
        throw FigureException("Incorrect point values!");

    this->leftUpperCoord.x = leftUpperCoord.x;
    this->leftUpperCoord.y = leftUpperCoord.y;
    this->rightBottomCoord.x = rightBottomCoord.x;
    this->rightBottomCoord.y = rightBottomCoord.y;
}

void Rectangle::print() {
    std::cout<<getType()<<"\nName: "<<name<<"\nLeft Upper X:"<<leftUpperCoord.x<<" Left Upper Y:"<<leftUpperCoord.y
              <<"\nRight Bottom X: "<<rightBottomCoord.x<<"Right Bottom Y: "<<rightBottomCoord.y<<std::endl;
}

void Rectangle::printPerimeter() {
    std::cout <<"Type:"<<getType()<<"\n  Name: "<<name<<"\n  Perimeter: "
              <<calculatePerimeter()<< std::endl;
}

float Rectangle::calculatePerimeter() {
    float width = std::abs(rightBottomCoord.x - leftUpperCoord.x);
    float height = std::abs(leftUpperCoord.y - rightBottomCoord.y);

    return TWO * (width + height);
}

std::string Rectangle::getType() {
    return "Rectangle";
}
