#include "figureActionHandler.h"


void ActionExitHandler::handleAction(std::vector<Figure*>& figLink) {}

void ActionAddHandler::handleAction(std::vector<Figure*>& figLink) {
    menu.addFigure(figLink);
}

void ActionListHandler::handleAction(std::vector<Figure*>& figLink) {
    menu.showAllFigures(figLink);
}

void ActionListWithPerimeterHandler::handleAction(std::vector<Figure*>& figLink) {
    menu.showAllFiguresPerimeters(figLink);
}

void ActionDisplayPerimeterHandler::handleAction(std::vector<Figure*>& figLink) {
    menu.showSumOfAllPerimeters(figLink);
}

void ActionSortByPerimeterHandler::handleAction(std::vector<Figure*>& figLink) {
    menu.sortFiguresByPerimeter(figLink);
}

void ActionRemoveByNumberHandler::handleAction(std::vector<Figure*>& figLink) {
    menu.removeFigureByNumber(figLink);
}

void ActionRemoveByPerimeterHandler::handleAction(std::vector<Figure*>& figLink) {
    menu.removeFigureByPerimeter(figLink);
}

ActionManager::ActionManager() {
    actionHandlers[ADD] = std::make_unique<ActionAddHandler>();
    actionHandlers[LIST] = std::make_unique<ActionListHandler>();
    actionHandlers[LIST_WITH_PERIMETER] = std::make_unique<ActionListWithPerimeterHandler>();
    actionHandlers[PERIMETER_SUM] = std::make_unique<ActionDisplayPerimeterHandler>();
    actionHandlers[SORT] = std::make_unique<ActionSortByPerimeterHandler>();
    actionHandlers[DELETE_BY_NUM] = std::make_unique<ActionRemoveByNumberHandler>();
    actionHandlers[DELETE_BY_PERIMETER] = std::make_unique<ActionRemoveByPerimeterHandler>();
    actionHandlers[EXIT] = std::make_unique<ActionExitHandler>();
}

void ActionManager::executeHandling(int action, std::vector<Figure*>& figLink) {
    actionHandlers[action]->handleAction(figLink);
}
