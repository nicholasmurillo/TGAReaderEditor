#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#include "Picture.h"
#include "Pixel.h"

const string part1 = "ImageProcessing Summer 2023/output/part1.tga";
const string part2 = "ImageProcessing Summer 2023/output/part2.tga";
const string part3 = "ImageProcessing Summer 2023/output/part3.tga";
const string part4 = "ImageProcessing Summer 2023/output/part4.tga";
const string part5 = "ImageProcessing Summer 2023/output/part5.tga";
const string part6 = "ImageProcessing Summer 2023/output/part6.tga";
const string part7 = "ImageProcessing Summer 2023/output/part7.tga";
const string part8 = "ImageProcessing Summer 2023/output/part8.tga";
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

int main() {
    part1_edit();
    part2_edit();
    part3_edit();
    part4_edit();
    part5_edit();
    return 0;
}
