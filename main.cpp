#include <iostream>
#include <fstream>
#include <sstream>
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

#include "Header.h"
#include "Pixel.h"

int main() {
    Header temp;
    temp.set_Header_input("ImageProcessing Summer 2023/input/car.tga");
    if(temp.input.is_open()) {
        temp.read_all();
        temp.print();
    }
    return 0;
}
