#ifndef APPLICATION_H
#define APPLICATION_H
#include <iostream>
#include <vector>
#include "figure.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "figureActionHandler.h"
#include "constants.h"


class Application {
private:
    ActionManager manager;
public:
    std::vector<Figure*> figLink;
    Application(std::vector<Figure*> figures);
    ~Application() = default;
    void doProgramLogic(enum Action action, std::vector<Figure*>& figLink);
    void handleFunc(enum Action action, std::vector<Figure*>& figLink);
    void showMenu();
    void reenterNumber();
    static void clearInputBuffer();
    void printNextAction();
    int calculateResult();
};

#endif // APPLICATION_H
