#ifndef SVGEDITOR_H
#define SVGEDITOR_H
#include <string>
#include "SVGDocument.h"
#include "Observer.h"
#include <iostream>
#include "Exporter.h"
#include "Importer.h"


class SvgEitor: public EditorObservable, public DocumentObserver {
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
    
    void removedGraphicObject(int id) override {
        removeGraphicObject(id);
    }

    void createdCircle(const Circle* circle) override {
        (void)circle;
        createdCircleNotify(circle);
    }
    void createdRectangle(const Rectangle* rectangle) override {
        (void)rectangle;
        createdRectangleNotify(rectangle);
    }
    void createdLine(const Line* line) override {
        (void)line;
        createdLineNotify(line);
    }
    SVGDocument* getCurrentDocument() {
        return currentDocument;
    }
private:
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
    SVGDocument* currentDocument;    
};

#endif