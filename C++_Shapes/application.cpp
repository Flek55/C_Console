#include "application.h"


using namespace std;

Application::Application(std::vector<Figure*> figures):figLink(figures) {}

int Application::calculateResult() {
    enum Action action = ADD;
    doProgramLogic(action, figLink);
    return 0;
}

void Application::doProgramLogic(enum Action action, std::vector<Figure*>& figLink) {
    while (action != EXIT) {
        showMenu();
        if (scanf("%d", &action) != 1) {
            reenterNumber();
            getchar();
            clearInputBuffer();
        } else {
            int x = (int)action;
            if (x >= 0 && x <= SEVEN)
                handleFunc(action, figLink);
        }
        printNextAction();
    }
}

void Application::handleFunc(enum Action action, std::vector<Figure*>& figLink) {
    manager.executeHandling(action, figLink);
}

void Application::showMenu() {
    cout << "---------------MAIN MENU---------------\n";
    cout << "1. Add figure" << endl;
    cout << "2. List numbered figures" << endl;
    cout << "3. List numbered figures with perimeter" << endl;
    cout << "4. Display perimeter sum" << endl;
    cout << "5. Sort figures by perimeter" << endl;
    cout << "6. Remove figure by number" << endl;
    cout << "7. Remove figures by perimeter" << endl;
    cout << "0. Exit" << endl;
    cout << "Input number: ";
}

void Application::reenterNumber() {
    cout << "Input a number from 0 to 7!" << endl;
}

void Application::printNextAction() {
    cout << endl;
}

void Application::clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
