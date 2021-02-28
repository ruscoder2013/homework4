#ifndef SVGDOCUMENT_H
#define SVGDOCUMENT_H

#include <vector>
#include <iostream>
#include "GraphicObject.h"
#include "Observer.h"

class SVGDocument: public Observable2 {
public:
    int CreateCircle(int x, int y, int r) {
        int id = GenerateID();
        auto c = new Circle(id, x, y, r);
        graphicObjects.push_back(c);
        CircleCreateNotify(c);
        return id;
    }
    int CreateLine(int x1, int y1, int x2, int y2) {
        int id = GenerateID();
        auto l = new Line(id, x1, y1, x2, y2);
        LineCreateNotify(l);
        return id;
    }
    int CreateRectangle(int x, int y, int w, int h) {
        int id = GenerateID();
        auto r = new Rectangle(id, x, y, w, h);
        RectangleCreateNotify(r);
        return id;
    }
    void RemoveObject(int id) {
        // remove object from graphicObjects;
        GraphicObjectRemovedNotify(id);
    }
    int GenerateID() {return 0;}
private:
    std::vector<GraphicObject*> graphicObjects; 
};

#endif