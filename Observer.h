#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
#include <string>
#include <iostream>

class Observer {
public:
    virtual void documentSaved(std::string path) = 0;
    virtual void documentOpened(std::string path) = 0;
    virtual void documentCreated() = 0;
    virtual void createdCircle(const Circle* circle) = 0;
    virtual void createdLine(const Line* line) = 0;
    virtual void createdRectangle(const Rectangle* Rectangle) = 0;
    virtual void removedGraphicObject(int id) = 0;
};

class Observable {
public:
    void addObserver(Observer* observer) {
        std::cout << "add" << std::endl;
        observers.push_back(observer);
        std::cout << "size = " << observers.size() << std::endl;
    }
    void documentSavedNotify(std::string path) {
        for(unsigned int i = 0; i < observers.size(); i++)
            observers[i]->documentSaved(path);
    }
    void documentOpenedNotify(std::string path) {
        for(unsigned int i = 0; i < observers.size(); i++)
            observers[i]->documentOpened(path);
    }
    void documentCreatedNotify() {
        for(unsigned int i = 0; i < observers.size(); i++)
            observers[i]->documentCreated();
    }
    void createdCircle(const Circle* circle) {
        for(unsigned int i = 0; i < observers.size(); i++)
            observers[i]->createdCircle(circle);
    }
    void createRectangle(const Rectangle* rectangle) {
        for(unsigned int i = 0; i < observers.size(); i++)
            observers[i]->createdRectangle(rectangle);
    }
    void createLine(const Line* line) {
        for(unsigned int i = 0; i < observers.size(); i++)
            observers[i]->createdLine(line);
    }

    void removeGraphicObject(int id) {
        for(unsigned int i = 0; i < observers.size(); i++)
            observers[i]->removedGraphicObject(id);
    }
private:
    std::vector<Observer*> observers;
};

class Observer2 {
public:
    virtual void createdCircleInDocument(const Circle* circle) = 0;
    virtual void createRectangleInDocument(const Rectangle* rectangle) = 0;
    virtual void createLineInDocument(const Line* line) = 0;
    virtual void removedGraphicObjectInDocument(int id) = 0;
};

class Observable2 {
public:
    void setObserver(Observer2* observer) {
        this->observer = observer;
    }
    void CircleCreateNotify(const Circle* circle) {
        observer->createdCircleInDocument(circle);
    }
    void LineCreateNotify(const Line* line) {
        observer->createLineInDocument(line);
    }
    void RectangleCreateNotify(const Rectangle* rect) {
        observer->createRectangleInDocument(rect);
    }
    void GraphicObjectRemovedNotify(int id) {
        observer->removedGraphicObjectInDocument(id);
    }
private:
    Observer2* observer;
};

#endif