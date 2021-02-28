#ifndef SVGEDITOR_H
#define SVGEDITOR_H
#include <string>
#include "SVGDocument.h"
#include "Observer.h"
#include <iostream>
#include "Exporter.h"
#include "Importer.h"


class SvgEitor: public Observable, public Observer2 {
public:
    SvgEitor() {
        currentDocument = nullptr;
    }
    void openDocument(std::string path) {
        Importer *importer;
        switch (getImportExt(path)) 
        {
        case ImportExt::SVG_I:
            importer = new SvgImporter();
            break;
        case ImportExt::AI:
            importer = new AiImporter();
            break;
        default:
            break;
        }
        importer->load(path);
        currentDocument = new SVGDocument();
        currentDocument->setObserver(this);
        importer->convertToSvg(currentDocument);
    }
    void saveDocument(std::string path) {
        if(currentDocument==nullptr) return;
        Exporter *exporter;
        switch (getExportExt(path)) 
        {
        case ExportExt::SVG:
            exporter = new SvgExporter();
            break;
        case ExportExt::PDF:
            exporter = new PdfExporter();
            break;
        default:
            break;
        }
        
        exporter->convert(currentDocument);
        exporter->exporFile(path);
        documentSavedNotify(path);
    }
    void createDocument() {
        if(currentDocument==nullptr)
            delete currentDocument;
        currentDocument = new SVGDocument();
        currentDocument->setObserver(this);
        documentCreatedNotify();
    }
    
    void removedGraphicObjectInDocument(int id) override {
        removeGraphicObject(id);
    }

    void createdCircleInDocument(const Circle* circle) override {
        (void)circle;
        createdCircle(circle);
    }
    void createRectangleInDocument(const Rectangle* rectangle) override {
        (void)rectangle;
        createRectangle(rectangle);
    }
    void createLineInDocument(const Line* line) override {
        (void)line;
        createLine(line);
    }

    ExportExt getExportExt(std::string path) {
        // todo
        (void)path;
        return ExportExt::PDF;
    }
    ImportExt getImportExt(std::string path) {
        // todo 
        (void)path;
        return ImportExt::AI;
    }
    SVGDocument* getCurrentDocument() {
        return currentDocument;
    }
private:
    SVGDocument* currentDocument;    
};

#endif