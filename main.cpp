#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#include "cmake-build-debug/ImageProcessing Summer 2023/src/Picture.h"
#include "cmake-build-debug/ImageProcessing Summer 2023/src/Pixel.h"

const string part1 = "ImageProcessing Summer 2023/output/part1.tga";
const string part2 = "ImageProcessing Summer 2023/output/part2.tga";
const string part3 = "ImageProcessing Summer 2023/output/part3.tga";
const string part4 = "ImageProcessing Summer 2023/output/part4.tga";
const string part5 = "ImageProcessing Summer 2023/output/part5.tga";
const string part6 = "ImageProcessing Summer 2023/output/part6.tga";
const string part7 = "ImageProcessing Summer 2023/output/part7.tga";
const string part8_r = "ImageProcessing Summer 2023/output/part8_r.tga";
const string part8_g = "ImageProcessing Summer 2023/output/part8_g.tga";
const string part8_b = "ImageProcessing Summer 2023/output/part8_b.tga";
const string part9 = "ImageProcessing Summer 2023/output/part9.tga";
const string part10 = "ImageProcessing Summer 2023/output/part10.tga";
const string car = "ImageProcessing Summer 2023/input/car.tga";
const string circles = "ImageProcessing Summer 2023/input/circles.tga";
const string layer1 = "ImageProcessing Summer 2023/input/layer1.tga";
const string layer2 = "ImageProcessing Summer 2023/input/layer2.tga";
const string layer_blue = "ImageProcessing Summer 2023/input/layer_blue.tga";
const string layer_green = "ImageProcessing Summer 2023/input/layer_green.tga";
const string layer_red = "ImageProcessing Summer 2023/input/layer_red.tga";
const string pattern1 = "ImageProcessing Summer 2023/input/pattern1.tga";
const string pattern2 = "ImageProcessing Summer 2023/input/pattern2.tga";
const string text = "ImageProcessing Summer 2023/input/text.tga";
const string text2 = "ImageProcessing Summer 2023/input/text2.tga";


void part1_edit() {
    Picture main;
    main.set_Picture_input(layer1);
    main.set_Picture_output(part1);
    main.read_all();
    Picture edit;
    edit.set_Picture_input(pattern1);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i] * edit.array[i];
    }
    main.write_all();
}

void part2_edit() {
    Picture main;
    main.set_Picture_input(car);
    main.set_Picture_output(part2);
    main.read_all();
    Picture edit;
    edit.set_Picture_input(layer2);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i] - edit.array[i];
    }
    main.write_all();
}

void part3_edit() {
    Picture main;
    main.set_Picture_input(layer1);
    main.set_Picture_output(part3);
    main.read_all();
    Picture edit;
    edit.set_Picture_input(pattern2);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i] * edit.array[i];
    }
    Picture edit2;
    edit2.set_Picture_input(text);
    edit2.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].screen(edit2.array[i]);
    }
    main.write_all();
}

void part4_edit() {
    Picture main;
    main.set_Picture_input(layer2);
    main.set_Picture_output(part4);
    main.read_all();
    Picture edit;
    edit.set_Picture_input(circles);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i] * edit.array[i];
    }
    Picture edit2;
    edit2.set_Picture_input(pattern2);
    edit2.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i] - edit2.array[i];
    }
    main.write_all();
}

void part5_edit() {
    Picture main;
    main.set_Picture_input(layer1);
    main.set_Picture_output(part5);
    main.read_all();
    Picture edit;
    edit.set_Picture_input(pattern1);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].overlay(edit.array[i]);
    }
    main.write_all();
}

void part6_edit() {
    Picture main;
    main.set_Picture_input(car);
    main.set_Picture_output(part6);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        if((unsigned int)main.array[i].green + 200 >= 255) {
            main.array[i].green = 255;
        } else {
            main.array[i].green += 200;
        }
    }
    main.write_all();
}

void part7_edit() {
    Picture main;
    main.set_Picture_input(car);
    main.set_Picture_output(part7);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        if(main.array[i].red * 4 >= 255) {
            main.array[i].red = 255;
        } else{
            main.array[i].red *= 4;
        }
        main.array[i].blue *= 0;
    }
    main.write_all();
}

void part8_edit() {
    Picture main;
    main.set_Picture_input(car);
    main.set_Picture_output(part8_r);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].green = main.array[i].red;
        main.array[i].blue = main.array[i].red;
    }
    main.write_all();
    main.set_Picture_input(car);
    main.set_Picture_output(part8_b);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].green = main.array[i].blue;
        main.array[i].red = main.array[i].blue;
    }
    main.write_all();
    main.set_Picture_input(car);
    main.set_Picture_output(part8_g);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].red = main.array[i].green;
        main.array[i].blue = main.array[i].green;
    }
    main.write_all();
}

void part9_edit() {
    Picture main;
    main.set_Picture_input(layer_red);
    main.set_Picture_output(part9);
    main.read_all();
    Picture green;
    green.set_Picture_input(layer_green);
    green.read_all();
    Picture blue;
    blue.set_Picture_input(layer_blue);
    blue.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].green = green.array[i].green;
        main.array[i].blue = blue.array[i].blue;
    }
    main.write_all();
}

void part10_edit() {
    Picture main;
    main.set_Picture_input(text2);
    main.set_Picture_output(part10);
    main.read_all();
    main.write_Header();
    Picture edit;
    edit.set_Picture_input(text2);
    edit.set_Picture_output(part10);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[((unsigned int)(main.width * main.height)) - i - 1] = edit.array[i];
    }
    main.write_all();
}

int main() {
    part1_edit();
    part2_edit();
    part3_edit();
    part4_edit();
    part5_edit();
    part6_edit();
    part7_edit();
    part8_edit();
    part9_edit();
    part10_edit();
    return 0;
}