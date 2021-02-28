#ifndef EXPORTER_H
#define EXPORTER_H

#include <string>
#include <iostream>
#include "SVGDocument.h"

enum  ExportExt { SVG, PDF };

class Exporter {
public:
    virtual void exporFile(std::string full_path) = 0;
    virtual void convert(SVGDocument *document) = 0;
};

class SvgExporter: public Exporter {
public:
    void exporFile(std::string full_path) { (void)full_path; }
    void convert(SVGDocument *document) {(void)document;}
};

class PdfExporter: public Exporter {
public:
    void exporFile(std::string full_path) {(void)full_path;}
    void convert(SVGDocument *document) {(void)document;}
};

#endif