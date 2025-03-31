#ifndef FIGUREACTIONHANDLER_H
#define FIGUREACTIONHANDLER_H
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include "figure.h"
#include "menuActions.h"


enum Action {
    EXIT,
    ADD,
    LIST,
    LIST_WITH_PERIMETER,
    PERIMETER_SUM,
    SORT,
    DELETE_BY_NUM,
    DELETE_BY_PERIMETER,
};

class FigureActionHandler {
protected:
    Menu menu = Menu();
public:
    virtual ~FigureActionHandler() = default;
    virtual void handleAction(std::vector<Figure*>& figLink) = 0;
};

class ActionExitHandler: public FigureActionHandler {
public:
    void handleAction(std::vector<Figure*>& figLink) override;
};

class ActionAddHandler: public FigureActionHandler {
public:
    void handleAction(std::vector<Figure*>& figLink) override;
};

class ActionListHandler: public FigureActionHandler {
public:
    void handleAction(std::vector<Figure*>& figLink) override;
};

class ActionListWithPerimeterHandler: public FigureActionHandler {
public:
    void handleAction(std::vector<Figure*>& figLink) override;
};

class ActionDisplayPerimeterHandler: public FigureActionHandler {
public:
    void handleAction(std::vector<Figure*>& figLink) override;
};

class ActionSortByPerimeterHandler: public FigureActionHandler {
public:
    void handleAction(std::vector<Figure*>& figLink) override;
};

class ActionRemoveByNumberHandler: public FigureActionHandler {
public:
    void handleAction(std::vector<Figure*>& figLink) override;
};

class ActionRemoveByPerimeterHandler: public FigureActionHandler {
public:
    void handleAction(std::vector<Figure*>& figLink) override;
};


class ActionManager {
private:
    std::unordered_map<int, std::unique_ptr<FigureActionHandler>> actionHandlers;

public:
    ActionManager();
    void executeHandling(int action, std::vector<Figure*>& figLink);
};

#endif // FIGUREACTIONHANDLER_H
