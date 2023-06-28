//
// Created by nickm on 6/23/2023.
//

#ifndef PROJECT2_HEADER_H
#define PROJECT2_HEADER_H

#endif //PROJECT2_HEADER_H

struct Header {
    ifstream input;
    ofstream output;
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
    void read_all() {
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
    void write_all() {
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
    void set_Header_input(const string& fileName) {
        this->input.open(fileName.c_str(), ios_base::out | ios_base::binary);
    }
    void set_Header_output(const string& fileName) {
        this->output.open(fileName.c_str(), ios_base::out | ios_base::binary);
    }
    void print() {
        cout << "idLength = " << (int)this->idLength << endl;
        cout << "colorMapType = " << (int)this->colorMapType << endl;
        cout << "dataTypeCode = " << (int)this->dataTypeCode << endl;
        cout << "colorMapOrigin = " << this->colorMapOrigin << endl;
        cout << "colorMapLength = " << this->colorMapLength << endl;
        cout << "colorMapDepth = " << (int)this->colorMapDepth << endl;
        cout << "xOrigin = " << this->xOrigin << endl;
        cout << "yOrigin = " << this->yOrigin << endl;
        cout << "width = " << this->width << endl;
        cout << "height = " << this->height << endl;
        cout << "bitsPerPixel = " << (int)this->bitsPerPixel << endl;
        cout << "imageDescriptor = " << (int)this->imageDescriptor << endl;
    }
    Header() {}
    Header(const Header& other) {
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
    Header operator=(const Header& other) {
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
    ~Header() {}
};
