#ifndef IMPORTER_H
#define IMPORTER_H

#include <string>
#include <iostream>
#include "SVGDocument.h"

enum  ImportExt { SVG_I, AI };

class Importer {
public:
    virtual void load(std::string full_path) = 0;
    virtual void convertToSvg(SVGDocument* document) = 0;
};

class SvgImporter: public Importer {
public:
    void load(std::string full_path) {(void)full_path;}
    virtual void convertToSvg(SVGDocument* document) {(void)document;}
};

class AiImporter: public Importer {
public:
    void load(std::string full_path) {(void)full_path;}
    virtual void convertToSvg(SVGDocument* document) {(void)document;}
};

#endif