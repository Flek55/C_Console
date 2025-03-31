#ifndef MENUACTIONS_H
#define MENUACTIONS_H
#include "coord.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Menu {
public:
    Menu() {};
    ~Menu() = default;
    void addFigure(std::vector<Figure*>& figLink);
    void addCircle(std::vector<Figure*>& figLink);
    void addRectangle(std::vector<Figure*>& figLink);
    void outputCircle(std::vector<Figure*>& figLink, int n);
    void outputRectangle(std::vector<Figure*>& figLink, int n);
    void outputTriangle(std::vector<Figure*>& figLink, int n);
    void addTriangle(std::vector<Figure*>& figLink);
    void showAllFigures(std::vector<Figure*>& figLink);
    void showAllFiguresPerimeters(std::vector<Figure*>& figLink);
    void showSumOfAllPerimeters(std::vector<Figure*>& figLink);
    static int compareFiguresByPerimeter(Figure* a, Figure* b);
    void sortFiguresByPerimeter(std::vector<Figure*>& figLink);
    void removeFigureByNumber(std::vector<Figure*>& figLink);
    void removeFigureByPerimeter(std::vector<Figure*>& figLink);
};



#endif // MENUACTIONS_H
