#include "application.h"

using namespace std;

int main() {
    std::vector<Figure*> figures;
    Application app = Application(figures);
    return app.calculateResult();
}
