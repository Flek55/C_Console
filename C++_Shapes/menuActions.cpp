#include "menuActions.h"
#include "circle.h"
#include "rectangle.h"
#include "application.h"
#include "triangle.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


void Menu::addFigure(std::vector<Figure*>& figLink) {
    int action = 0;
    std::cout << "Input Circle: 1\nInput Rectangle: 2\nInput Triangle: 3\nInput: ";
    try {
        std::cin >> action;
        if (std::cin.fail())
            throw InputException("Invalid number!");
        if(action == 1) {
            addCircle(figLink);
        }
        else if(action == 2) {
            addRectangle(figLink);
        }
        else if(action == 3) {
            addTriangle(figLink);
        }
    } catch (InputException e) {
        std::cout << "\n" << e.what() << std::endl;
        std::cin.clear();
        Application::clearInputBuffer();
    }
    Application::clearInputBuffer();
}



void Menu::addCircle(std::vector<Figure*>& figLink) {
    std::string name;
    Coordinate coord;
    float radius;
    try {
        std::cout << "\nEnter figure name:" << std::endl;
        std::cin >> name;
        std::cout << "\nEnter the oX coordinate of the center of the shape:" << std::endl;
        std::cin >> coord.x;
        if (std::cin.fail())
            throw InputException("Invalid coord!");

        std::cout << "\nEnter the oY coordinate of the center of the shape:" << std::endl;
        std::cin >> coord.y;
        if (std::cin.fail())
            throw InputException("Invalid coord!");

        std::cout << "\nEnter the radius of the shape:" << std::endl;
        std::cin >> radius;
        if (std::cin.fail())
            throw InputException("Invalid radius!");

        Circle* circle = new Circle(name, coord, radius);
        figLink.push_back(circle);
    } catch (InputException e) {
        std::cout << "\n" << e.what() << std::endl;
        std::cin.clear();
        Application::clearInputBuffer();
    } catch (FigureException e) {
        std::cout << "\n" << e.what() << std::endl;
        std::cin.clear();
        Application::clearInputBuffer();
    }
    //Application::clearInputBuffer();
}

void Menu::addRectangle(std::vector<Figure*>& figLink) {
    std::string name;
    Coordinate coord1, coord2;
    try {
        std::cout << "\nEnter figure name:" << std::endl;
        std::cin >> name;
        std::cout << "\nEnter oX for the point1:" << std::endl;
        std::cin >> coord1.x;
        if (std::cin.fail())
            throw InputException("Invalid coord!");
        std::cout << "\nEnter oY for the point1:" << std::endl;
        std::cin >> coord1.y;
        if (std::cin.fail())
            throw InputException("Invalid coord!");
        std::cout << "\nEnter oX for the point2:" << std::endl;
        std::cin >> coord2.x;
        if (std::cin.fail())
            throw InputException("Invalid coord!");
        std::cout << "\nEnter oY for the point2:" << std::endl;
        std::cin >> coord2.y;
        if (std::cin.fail())
            throw InputException("Invalid coord!");

        Rectangle* rectangle = new Rectangle(name, coord1, coord2);
        figLink.push_back(rectangle);
    } catch (FigureException e) {
        std::cout << "\n" << e.what() << std::endl;
        std::cin.clear();
        Application::clearInputBuffer();
    } catch (InputException e) {
        std::cout << "\n" << e.what() << std::endl;
        std::cin.clear();
        Application::clearInputBuffer();
    }
    //Application::clearInputBuffer();
}

void Menu::addTriangle(std::vector<Figure*>& figLink) {
    std::string name;
    Coordinate coord1, coord2, coord3;
    try {
        std::cout << "\nEnter figure name:" << std::endl;
        std::cin >> name;
        std::cout << "\nEnter the point1 oX:" << std::endl;
        std::cin >> coord1.x;
        if (std::cin.fail())
            throw InputException("Invalid coord!");
        std::cout << "\nEnter the point1: oY" << std::endl;
        std::cin >> coord1.y;
        if (std::cin.fail())
            throw InputException("Invalid coord!");
        std::cout << "\nEnter the point2: oX" << std::endl;
        std::cin >> coord2.x;
        if (std::cin.fail())
            throw InputException("Invalid coord!");
        std::cout << "\nEnter the point2: oY" << std::endl;
        std::cin >> coord2.y;
        if (std::cin.fail())
            throw InputException("Invalid coord!");
        std::cout << "\nEnter the point3: oX" << std::endl;
        std::cin >> coord3.x;
        if (std::cin.fail())
            throw InputException("Invalid coord!");
        std::cout << "\nEnter the point3: oY" << std::endl;
        std::cin >> coord3.y;
        if (std::cin.fail())
            throw InputException("Invalid coord!");
        Triangle* triangle = new Triangle(name, coord1, coord2, coord3);
        figLink.push_back(triangle);
    } catch (FigureException e) {
        std::cout << "\n" << e.what() << std::endl;
        std::cin.clear();
        Application::clearInputBuffer();
    } catch (InputException e) {
        std::cout << "\n" << e.what() << std::endl;
        std::cin.clear();
        Application::clearInputBuffer();
    }
    //Application::clearInputBuffer();
}

void Menu::showAllFigures(std::vector<Figure*>& figLink) {
    int count = 1;
    for (const auto& obj : figLink) {
        std::cout << count << ")\n";
        obj->print();
        count++;
    }
    if (figLink.empty())
        std::cout << "No figures!" << std::endl;
    std::cout << std::endl;
}

void Menu::showAllFiguresPerimeters(std::vector<Figure*>& figLink) {
    int count = 1;
    for (const auto& obj : figLink) {
        std::cout << count << ")";
        obj->printPerimeter();
        count++;
    }
    if (figLink.empty())
        std::cout << "No figures!" << std::endl;
    std::cout << std::endl;
}

void Menu::showSumOfAllPerimeters(std::vector<Figure*>& figLink) {
    float sum = 0;
    for (const auto& obj : figLink) {
        sum += obj->calculatePerimeter();
    }
    if (figLink.empty())
        std::cout << "No figures!" << std::endl;
    std::cout << "Sum of Perimeters: " << sum << std::endl;
}

int Menu::compareFiguresByPerimeter(Figure* a, Figure* b) {
    return a->calculatePerimeter() < b->calculatePerimeter();
}

void Menu::sortFiguresByPerimeter(std::vector<Figure*>& figLink) {
    if (!figLink.empty())
        std::sort(figLink.begin(), figLink.end(), compareFiguresByPerimeter);
    else
        std::cout << "List is empty!" << std::endl;
}

void Menu::removeFigureByNumber(std::vector<Figure*>& figLink) {
    unsigned long index;
    if (!figLink.empty()) {
        std::cout << "Enter the number of the figure to remove (1 to " << figLink.size() << "): ";
        std::cin >> index;

        if (index < 1 || index > figLink.size()) {
            std::cout << "Invalid number. Please enter a number between 1 and " << figLink.size() << "." << std::endl;
        } else {
            delete figLink[index - 1];
            figLink.erase(figLink.begin() + (index - 1));

            std::cout << "Figure " << index << " has been removed." << std::endl;
        }
    } else
        std::cout << "List is empty!" << std::endl;
    std::cin.clear();
    Application::clearInputBuffer();
}

void Menu::removeFigureByPerimeter(std::vector<Figure*>& figLink) {
    unsigned long perimeter;
    if (!figLink.empty()) {
        std::cout << "Enter the number: ";
        try {
            std::cin >> perimeter;
            if (std::cin.fail())
                throw InputException("Input a number!");
            for (auto obj = figLink.begin(); obj != figLink.end();) {
                if(perimeter < (*obj)->calculatePerimeter()) {
                    delete *obj;
                    obj = figLink.erase(obj);
                } else {
                    obj++;
                }
            }
        } catch (InputException e) {
            std::cout << "\n" << e.what() << std::endl;
            std::cin.clear();
            Application::clearInputBuffer();
        }
    } else
        std::cout << "List is empty!" << std::endl;
}
