#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/*
ofstream part1("ImageProcessing Summer 2023/output/part1.tga", ios_base::out | ios_base::binary);
ofstream part2("ImageProcessing Summer 2023/output/part2.tga", ios_base::out | ios_base::binary);
ofstream part3("ImageProcessing Summer 2023/output/part3.tga", ios_base::out | ios_base::binary);
ofstream part4("ImageProcessing Summer 2023/output/part4.tga", ios_base::out | ios_base::binary);
ofstream part5("ImageProcessing Summer 2023/output/part5.tga", ios_base::out | ios_base::binary);
ofstream part6("ImageProcessing Summer 2023/output/part6.tga", ios_base::out | ios_base::binary);
ofstream part7("ImageProcessing Summer 2023/output/part7.tga", ios_base::out | ios_base::binary);
ofstream part8("ImageProcessing Summer 2023/output/part8.tga", ios_base::out | ios_base::binary);
ofstream part9("ImageProcessing Summer 2023/output/part9.tga", ios_base::out | ios_base::binary);
ofstream part10("ImageProcessing Summer 2023/output/part10.tga", ios_base::out | ios_base::binary);
 */

#include "Picture.h"
#include "Pixel.h"

const string car = "ImageProcessing Summer 2023/input/car.tga";
const string layer1 = "ImageProcessing Summer 2023/input/layer1.tga";
const string pattern1 = "ImageProcessing Summer 2023/input/pattern1.tga";
const string layer2 = "ImageProcessing Summer 2023/input/layer2.tga";
const string pattern2 = "ImageProcessing Summer 2023/input/pattern2.tga";

int main() {
    Picture main;
    main.set_Picture_input(layer1);
    main.read_all();
    Picture part1;
    part1.set_Picture_input(pattern1);
    part1.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i] * part1.array[i];
    }
    return 0;
}
