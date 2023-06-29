//
// Created by nickm on 6/23/2023.
//

#ifndef PROJECT2_HEADER_H
#define PROJECT2_HEADER_H

#endif //PROJECT2_HEADER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream input;
ofstream output;

struct Picture {
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
#include "Pixel.h"
    Pixel* array = nullptr;
    void set_Picture_input(const string& fileName) {
        if(input.is_open()){
            input.close();
        }
        input.open(fileName.c_str(), ios_base::out | ios_base::binary);
    }
    void set_Picture_output(const string& fileName) {
        if(output.is_open()){
            output.close();
        }
        output.open(fileName.c_str(), ios_base::out | ios_base::binary);
    }
    void read_idLength() {
        input.read(reinterpret_cast<char *>(&this->idLength), sizeof(this->idLength));
    }
    void read_colorMapType() {
        input.read(reinterpret_cast<char *>(&this->colorMapType), sizeof(this->colorMapType));
    }
    void read_dataTypeCode() {
        input.read(reinterpret_cast<char *>(&this->dataTypeCode), sizeof(this->colorMapType));
    }
    void read_colorMapOrigin() {
        input.read(reinterpret_cast<char *>(&this->colorMapOrigin), sizeof(this->colorMapOrigin));
    }
    void read_colorMapLength() {
        input.read(reinterpret_cast<char *>(&this->colorMapLength), sizeof(this->colorMapLength));
    }
    void read_colorMapDepth() {
        input.read(reinterpret_cast<char *>(&this->colorMapDepth), sizeof(this->colorMapDepth));
    }
    void read_xOrigin() {
        input.read(reinterpret_cast<char *>(&this->xOrigin), sizeof(this->xOrigin));
    }
    void read_yOrigin() {
        input.read(reinterpret_cast<char *>(&this->yOrigin), sizeof(this->yOrigin));
    }
    void read_width() {
        input.read(reinterpret_cast<char *>(&this->width), sizeof(this->width));
    }
    void read_height() {
        input.read(reinterpret_cast<char *>(&this->height), sizeof(this->height));
    }
    void read_bitsPerPixel() {
        input.read(reinterpret_cast<char *>(&this->bitsPerPixel), sizeof(this->bitsPerPixel));
    }
    void read_imageDescriptor() {
        input.read(reinterpret_cast<char *>(&this->imageDescriptor), sizeof(this->imageDescriptor));
    }
    void read_Header() {
        this->read_idLength();
        this->read_colorMapType();
        this->read_dataTypeCode();
        this->read_colorMapOrigin();
        this->read_colorMapLength();
        this->read_colorMapDepth();
        this->read_xOrigin();
        this->read_yOrigin();
        this->read_width();
        this->read_height();
        this->read_bitsPerPixel();
        this->read_imageDescriptor();
    }
    void read_all_pixels() {
        auto* pix = new Pixel[(unsigned int)(this->width * this->height)];
        for(unsigned int i = 0; i < (unsigned int)(this->width * this->height); i++) {
            pix[i].read_pixel();
        }
        this->array = pix;
    }
    void read_all() {
        this->read_Header();
        this->read_all_pixels();
    }
    void write_idLength() {
        output.write(reinterpret_cast<char *>(&this->idLength), sizeof(this->idLength));
    }
    void write_colorMapType() {
        output.write(reinterpret_cast<char *>(&this->colorMapType), sizeof(this->colorMapType));
    }
    void write_dataTypeCode() {
        output.write(reinterpret_cast<char *>(&this->dataTypeCode), sizeof(this->dataTypeCode));
    }
    void write_colorMapOrigin() {
        output.write(reinterpret_cast<char *>(&this->colorMapOrigin), sizeof(this->colorMapOrigin));
    }
    void write_colorMapLength() {
        output.write(reinterpret_cast<char *>(&this->colorMapLength), sizeof(this->colorMapLength));
    }
    void write_colorMapDepth() {
        output.write(reinterpret_cast<char *>(&this->colorMapDepth), sizeof(this->colorMapDepth));
    }
    void write_xOrigin() {
        output.write(reinterpret_cast<char *>(&this->xOrigin), sizeof(this->xOrigin));
    }
    void write_yOrigin() {
        output.write(reinterpret_cast<char *>(&this->yOrigin), sizeof(this->yOrigin));
    }
    void write_width() {
        output.write(reinterpret_cast<char *>(&this->width), sizeof(this->width));
    }
    void write_height() {
        output.write(reinterpret_cast<char *>(&this->height), sizeof(this->height));
    }
    void write_bitsPerPixel() {
        output.write(reinterpret_cast<char *>(&this->bitsPerPixel), sizeof(this->bitsPerPixel));
    }
    void write_imageDescriptor() {
        output.write(reinterpret_cast<char *>(&this->imageDescriptor), sizeof(this->imageDescriptor));
    }
    void write_Header() {
        this->write_idLength();
        this->write_colorMapType();
        this->write_dataTypeCode();
        this->write_colorMapOrigin();
        this->write_colorMapLength();
        this->write_colorMapDepth();
        this->write_xOrigin();
        this->write_yOrigin();
        this->write_width();
        this->write_height();
        this->write_bitsPerPixel();
        this->write_imageDescriptor();
    }
    void write_all() {
        this->write_Header();
        for(unsigned int i = 0; i < (unsigned int)(this->width * this->height); i++) {
            this->array[i].write_pixel();
        }
    }
    Picture() {}
    Picture(const Picture& other) {
        this->idLength = other.idLength;
        this->colorMapType = other.colorMapType;
        this->dataTypeCode = other.dataTypeCode;
        this->colorMapOrigin = other.colorMapOrigin;
        this->colorMapLength = other.colorMapLength;
        this->xOrigin = other.xOrigin;
        this->yOrigin = other.yOrigin;
        this->width = other.width;
        this->height = other.height;
        this->bitsPerPixel = other.bitsPerPixel;
        this->imageDescriptor = other.imageDescriptor;
    }
    Picture operator=(const Picture& other) {
        this->idLength = other.idLength;
        this->colorMapType = other.colorMapType;
        this->dataTypeCode = other.dataTypeCode;
        this->colorMapOrigin = other.colorMapOrigin;
        this->colorMapLength = other.colorMapLength;
        this->xOrigin = other.xOrigin;
        this->yOrigin = other.yOrigin;
        this->width = other.width;
        this->height = other.height;
        this->bitsPerPixel = other.bitsPerPixel;
        this->imageDescriptor = other.imageDescriptor;
        return *this;
    }
    ~Picture() {
        delete[] array;
    }
};
