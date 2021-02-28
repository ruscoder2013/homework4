#ifndef GRAPHIC_OBJECT_H
#define GRAPHIC_OBJECT_H

#include <iostream>

class GraphicObject {
public:
    GraphicObject(int id) {
        this->id = id;
    }
    int getId() {
        return id;
    }
private:
    int id;
};

class Rectangle: public GraphicObject {
public:
    Rectangle(int id, int x, int y, int width, int height) : GraphicObject(id) {
        std::cout << "RectConstr" << id << x << y <<  width << height << std::endl;
    }
};

class Circle: public GraphicObject {
public:
    Circle(int id, int x, int y, int r) : GraphicObject(id) {
        std::cout << "CircleConstr" << id << x << y << r << std::endl;
    }
};

class Line: public GraphicObject {
public:
    Line(int id, int x1, int y1, int x2, int y2) : GraphicObject(id) {
        std::cout << "LineConstr" << id << x1 << y1 << x2 << y2 << std::endl;
    }
}; 

#endif