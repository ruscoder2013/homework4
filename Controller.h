#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include "SVGEditor.h"
#include "GraphicObject.h"

class Controller {
public:
    Controller(SvgEitor *editor) {
        this->editor = editor;
    }
    void openDocument(std::string path) {
        editor->openDocument(path);
    }
    void saveDocument(std::string path) {
        editor->saveDocument(path);
    }
    void createDocument() {
        editor->createDocument();
    }
    void removeObject(int id) {
        auto doc = editor->getCurrentDocument();
        if (doc)
            doc->RemoveObject(id);
    }
    void createCircle(int x, int y, int r) {
        auto doc = editor->getCurrentDocument();
        if (doc)
            doc->CreateCircle(x, y, r);
    }
    void createLine(int x1, int y1, int x2, int y2) {
        auto doc = editor->getCurrentDocument();
        if (doc)
            doc->CreateLine(x1, y1, x2, y2);
    }
    void createRectangle(int x, int y, int w, int h) {
        auto doc = editor->getCurrentDocument();
        if (doc)
            doc->CreateRectangle(x, y, w, h);
    }
private:
    SvgEitor *editor;
};

#endif