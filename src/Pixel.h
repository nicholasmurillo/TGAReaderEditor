//
// Created by nickm on 6/23/2023.
//

#ifndef PROJECT2_CELL_H
#define PROJECT2_CELL_H

#endif //PROJECT2_CELL_H

#include <iostream>
#include <fstream>
#include <string>

struct Pixel {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
    void read_blue(std::ifstream& other) {
        other.read(reinterpret_cast<char *>(&this->blue), sizeof(this->blue));
    }
    void read_green(std::ifstream& other) {
        other.read(reinterpret_cast<char *>(&this->green), sizeof(this->green));
    }
    void read_red(std::ifstream& other) {
        other.read(reinterpret_cast<char *>(&this->red), sizeof(this->red));
    }
    void read_pixel(std::ifstream& other) {
        this->read_blue(other);
        this->read_green(other);
        this->read_red(other);
    }
    void write_blue(std::ofstream& other) {
        other.write(reinterpret_cast<char *>(&this->blue), sizeof(this->blue));
    }
    void write_green(std::ofstream& other) {
        other.write(reinterpret_cast<char *>(&this->green), sizeof(this->green));
    }
    void write_red(std::ofstream& other) {
        other.write(reinterpret_cast<char *>(&this->red), sizeof(this->red));
    }
    void write_pixel(std::ofstream& other) {
        this->write_blue(other);
        this->write_green(other);
        this->write_red(other);
    }
    void screen(const Pixel& other) {
        float temp_green = 1 - ((float)this->green / 255);
        float temp_blue = 1 - ((float)this->blue / 255);
        float temp_red = 1 - ((float)this->red / 255);
        float other_temp_green = 1 - ((float)other.green / 255);
        float other_temp_blue = 1 - ((float)other.blue / 255);
        float other_temp_red = 1 - ((float)other.red / 255);
        temp_green *= other_temp_green;
        temp_blue *= other_temp_blue;
        temp_red *= other_temp_red;
        temp_green = (1 - temp_green) * 255;
        temp_blue = (1 - temp_blue) * 255;
        temp_red = (1 - temp_red) * 255;
        temp_green += 0.5f;
        temp_blue += 0.5f;
        temp_red += 0.5f;
        this->green = (unsigned char)temp_green;
        this->blue = (unsigned char)temp_blue;
        this->red = (unsigned char)temp_red;
    }
    void overlay(const Pixel& other) {
        float temp_green = (float)this->green / 255;
        float temp_blue = (float)this->blue / 255;
        float temp_red = (float)this->red / 255;
        float other_temp_green = (float)other.green / 255;
        float other_temp_blue = (float)other.blue / 255;
        float other_temp_red = (float)other.red / 255;
        if(other_temp_green <= 0.5f) {
            temp_green = 2 * other_temp_green * temp_green;
        } else {
            temp_green = 1 - temp_green;
            other_temp_green = 1 - other_temp_green;
            temp_green = 1 -(2 * temp_green * other_temp_green);
        }
        if(other_temp_blue <= 0.5f) {
            temp_blue = 2 * other_temp_blue * temp_blue;
        } else {
            temp_blue = 1 - temp_blue;
            other_temp_blue = 1 - other_temp_blue;
            temp_blue = 1 -(2 * temp_blue * other_temp_blue);
        }
        if(other_temp_red <= 0.5f) {
            temp_red = 2 * other_temp_red * temp_red;
        } else {
            temp_red = 1 - temp_red;
            other_temp_red = 1 - other_temp_red;
            temp_red = 1 -(2 * temp_red * other_temp_red);
        }
        temp_green *= 255;
        temp_blue *= 255;
        temp_red *= 255;
        temp_green += 0.5f;
        temp_blue += 0.5f;
        temp_red += 0.5f;
        this->green = (unsigned char)temp_green;
        this->blue = (unsigned char)temp_blue;
        this->red = (unsigned char)temp_red;
    }
    void operator-(const Pixel& other) {
        if(((int)this->blue - (int)other.blue) < 0) {
            this->blue = 0;
        } else {
            this->blue -= other.blue;
        }
        if(((int)this->green - (int)other.green) < 0) {
            this->green = 0;
        } else {
            this->green -= other.green;
        }
        if(((int)this->red - (int)other.red) < 0) {
            this->red = 0;
        } else {
            this->red -= other.red;
        }
    }
    void operator+(const Pixel& other) {
        if(((int)this->blue + (int)other.blue) > 255) {
            this->blue = 255;
        } else {
            this->blue += other.blue;
        }
        if(((int)this->green + (int)other.green) > 255) {
            this->green = 255;
        } else {
            this->green += other.green;
        }
        if(((int)this->red + (int)other.red) > 255) {
            this->red = 255;
        } else {
            this->red += other.red;
        }
    }
    void operator*(const Pixel& other) {
        float temp_green = (float)this->green / 255;
        float temp_blue = (float)this->blue / 255;
        float temp_red = (float)this->red / 255;
        float other_temp_green = (float)other.green / 255;
        float other_temp_blue = (float)other.blue / 255;
        float other_temp_red = (float)other.red / 255;
        temp_green *= other_temp_green;
        temp_blue *= other_temp_blue;
        temp_red *= other_temp_red;
        temp_green *= 255;
        temp_blue *= 255;
        temp_red *= 255;
        temp_green += 0.5f;
        temp_blue += 0.5f;
        temp_red += 0.5f;
        this->green = (unsigned char)temp_green;
        this->blue = (unsigned char)temp_blue;
        this->red = (unsigned char)temp_red;
    }
};