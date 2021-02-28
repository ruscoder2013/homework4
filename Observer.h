#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
#include <string>
#include <iostream>

class EditorObserver {
public:
    virtual void documentSaved(std::string path) = 0;
    virtual void documentOpened(std::string path) = 0;
    virtual void documentCreated() = 0;
    virtual void createdCircle(const Circle* circle) = 0;
    virtual void createdLine(const Line* line) = 0;
    virtual void createdRectangle(const Rectangle* Rectangle) = 0;
    virtual void removedGraphicObject(int id) = 0;
};

class DocumentObserver {
public:
    virtual void createdCircle(const Circle* circle) = 0;
    virtual void createdRectangle(const Rectangle* rectangle) = 0;
    virtual void createdLine(const Line* line) = 0;
    virtual void removedGraphicObject(int id) = 0;
};

class EditorObservable {
public:
    void addObserver(EditorObserver* observer) {
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
    void createdCircleNotify(const Circle* circle) {
        for(unsigned int i = 0; i < observers.size(); i++)
            observers[i]->createdCircle(circle);
    }
    void createdRectangleNotify(const Rectangle* rectangle) {
        for(unsigned int i = 0; i < observers.size(); i++)
            observers[i]->createdRectangle(rectangle);
    }
    void createdLineNotify(const Line* line) {
        for(unsigned int i = 0; i < observers.size(); i++)
            observers[i]->createdLine(line);
    }

    void removeGraphicObject(int id) {
        for(unsigned int i = 0; i < observers.size(); i++)
            observers[i]->removedGraphicObject(id);
    }
private:
    std::vector<EditorObserver*> observers;
};

class DocumentObservable {
public:
    void setObserver(DocumentObserver* observer) {
        this->observer = observer;
    }
    void CircleCreateNotify(const Circle* circle) {
        observer->createdCircle(circle);
    }
    void LineCreateNotify(const Line* line) {
        observer->createdLine(line);
    }
    void RectangleCreateNotify(const Rectangle* rect) {
        observer->createdRectangle(rect);
    }
    void GraphicObjectRemovedNotify(int id) {
        observer->removedGraphicObject(id);
    }
private:
    DocumentObserver* observer;
};

#endif