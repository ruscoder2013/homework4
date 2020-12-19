#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <list>

class VectorEditor {
public:
    VectorEditor() {
        
    }
    void CreateDocumnet() {
        std::cout << "create document" << std::endl;
    }
    void SaveDocument() {
        std::cout << "save document" << std::endl;
    }
    void OpenDocument() {
        std::cout << "open document" << std::endl;
    }
};

class IGraphicObject {
public:
    virtual void draw() = 0;
    long long getId()
    
};

class Document {
public:
    Document() {
        
    }
    
private:
    std::string path;
    std::string name;
};

class Model {
public:
    Model() {
        
    }
    void OpenFile() {
        editor.OpenFile();
    }
    void NewFile() {
        editor.OpenDocument();
    }
    void SaveFile() {
        std::cout << "save file" << std::endl;
    }
    void CreateGraphicObject() {
        std::cout << "create graphic object" << std::endl;
    }
    void RemoveGraphicObject() {
        std::cout << "remove gobject" << std::endl;
    }
private:
    VectorEditor editor;
};


class Controller {
public:
    Controller(Model *model) {
        this->model = model;
    }
    void OpenFile() {
        model->OpenFile();
    }
    void NewFile() {
        model->NewFile();
    }
    void SaveFile() {
        model->SaveFile();
    }
    void CreateGraphicObject() {
        model->CreateGraphicObject();
    }
    void RemoveGraphicObject() {
        model->RemoveGraphicObject();
    }
private:
    Model *model;
};

int main() {
    bool exit = false;
    Model model;
    Controller controller(&model);
    while(!exit) {
        switch(auto c = getchar()) {
            case 'o': 
                controller.OpenFile();
                break;
            case 'n': 
                controller.NewFile();
                break;
            case 's': 
                controller.SaveFile();
                break;
            case 'g': 
                controller.CreateGraphicObject();
                break;
            case 'r': 
                controller.RemoveGraphicObject();
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
    return 0;
}