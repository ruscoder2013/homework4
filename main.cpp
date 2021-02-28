#include <iostream>
#include <string>
#include "Controller.h"
#include "SVGEditor.h"
#include "Observer.h"

class ConsoleView: public EditorObserver {
public:
    ConsoleView(SvgEitor *editor, Controller *controller) {
        this->controller = controller;
        editor->addObserver(this);
    }
    void start() {
        bool exit = false;
        while(!exit) {
            switch(getchar()) {
                case 'o': 
                    controller->openDocument("1");
                    break;
                case 'n': 
                    controller->createDocument();
                    break;
                case 's': 
                    controller->saveDocument("2");
                    break;
                case 'l': 
                    controller->createLine(0,0,0,0);
                    break;
                case 'c':
                    controller->createCircle(0,0,0);
                    break;
                case 'k':
                    controller->createRectangle(0,0,0,0);
                    break;
                case 'r': 
                    controller->removeObject(0);
                    break;
                case 'q': {
                    std::cout << "quite" << std::endl;
                    exit = true;
                    break;
                }
                default:
                    break;
            }
        }
    }
    void documentSaved(std::string path) override {
        (void)path;
        std::cout << "save document" << std::endl;
    }
    void createdCircle(const Circle* circle) {
        (void)circle;
        std::cout << "circle create" << std::endl; ;
    }
    void createdLine(const Line* line) {
        (void)line;
        std::cout << "line create" << std::endl;
    }
    void createdRectangle(const Rectangle* rectangle) {
        (void)rectangle;
        std::cout << "rect create" << std::endl;
    }
    void documentOpened(std::string path) {
        (void)path;
        std::cout << "document opened" << std::endl;
    }
    void documentCreated() {
        std::cout << "document created" << std::endl;
    }
    void removedGraphicObject(int id) {
        (void)id;
        std::cout << "remove object" << std::endl;
    }
private:
    Controller *controller;
};

int main() {
    
    SvgEitor model;

    Controller controller(&model);
    ConsoleView view(&model, &controller);
    view.start();
    
    return 0;
}