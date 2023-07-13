#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>

#include "Picture.h"
#include "Pixel.h"

using namespace std;

const string part1 = "output/part1.tga";
const string part2 = "output/part2.tga";
const string part3 = "output/part3.tga";
const string part4 = "output/part4.tga";
const string part5 = "output/part5.tga";
const string part6 = "output/part6.tga";
const string part7 = "output/part7.tga";
const string part8_r = "output/part8_r.tga";
const string part8_g = "output/part8_g.tga";
const string part8_b = "output/part8_b.tga";
const string part9 = "output/part9.tga";
const string part10 = "output/part10.tga";
const string car = "input/car.tga";
const string circles = "input/circles.tga";
const string layer1 = "input/layer1.tga";
const string layer2 = "input/layer2.tga";
const string layer_blue = "input/layer_blue.tga";
const string layer_green = "input/layer_green.tga";
const string layer_red = "input/layer_red.tga";
const string pattern1 = "input/pattern1.tga";
const string pattern2 = "input/pattern2.tga";
const string text = "input/text.tga";
const string text2 = "input/text2.tga";
vector<string> files = {part1, part2, part3, part4, part5, part6, part7, part8_r, part8_g, part8_b, part9, part10, car, circles, layer1, layer2, layer_blue, layer_green, layer_red, pattern1, pattern2, text, text2};
vector<string> methods = {"multiply", "subtract", "overlay", "screen", "combine", "flip", "onlyred", "onlygreen", "onlyblue", "addred", "addgreen", "addblue", "scalered", "scalegreen", "scaleblue"};

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
    Picture edit;
    edit.set_Picture_input(text2);
    edit.set_Picture_output(part10);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[((unsigned int)(main.width) * (unsigned int)(main.height)) - i - 1] = edit.array[i];
    }
    main.write_all();
}

void run_all_edits() {
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
}

bool hasEnding(const string& test) {
    string ending = ".tga";
    if(test.length() >= ending.length()) {
        return (0 == test.compare(test.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

void multiply(const string& out, const string& first, const string& second) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    Picture edit;
    edit.set_Picture_input(second);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i] * edit.array[i];
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void subtract(const string& out, const string& first, const string& second) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    Picture edit;
    edit.set_Picture_input(second);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i] - edit.array[i];
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void overlay(const string& out, const string& first, const string& second) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    Picture edit;
    edit.set_Picture_input(second);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].overlay(edit.array[i]);
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void screen(const string& out, const string& first, const string& second) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    Picture edit;
    edit.set_Picture_input(second);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].screen(edit.array[i]);
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void combine(const string& out, const string& first, const string& second, const string& third) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    Picture edit;
    edit.set_Picture_input(second);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].green = edit.array[i].green;
    }
    Picture edit2;
    edit2.set_Picture_input(third);
    edit2.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].blue = edit2.array[i].blue;
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void flip(const string& out, const string& first) {
    Picture main;
    main.set_Picture_input(first);
    main.set_Picture_output(out);
    main.read_all();
    Picture edit;
    edit.set_Picture_input(first);
    edit.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[((unsigned int)(main.width) * (unsigned int)(main.height)) - i - 1] = edit.array[i];
    }
    main.write_all();
}

void flip_itself(const string& only) {
    Picture main;
    main.set_Picture_input(only);
    main.read_all();
    Pixel* temp = new Pixel[(unsigned int)(main.width) * (unsigned int)(main.height)];
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        temp[i].blue = main.array[i].blue;
        temp[i].green = main.array[i].green;
        temp[i].red = main.array[i].red;
    }
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[((unsigned int)(main.width) * (unsigned int)(main.height)) - i - 1].red = temp[i].red;
        main.array[((unsigned int)(main.width) * (unsigned int)(main.height)) - i - 1].green = temp[i].green;
        main.array[((unsigned int)(main.width) * (unsigned int)(main.height)) - i - 1].blue = temp[i].blue;
    }
    delete[] temp;
    main.replace_output(only);
    main.write_all();
}

void only_red(const string& out, const string& first) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].blue = main.array[i].red;
        main.array[i].green = main.array[i].red;
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void only_green(const string& out, const string& first) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].red = main.array[i].green;
        main.array[i].blue = main.array[i].green;
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void only_blue(const string& out, const string& first) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        main.array[i].red = main.array[i].blue;
        main.array[i].green = main.array[i].blue;
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void add_red(const string& out, const string& first, int second) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        if((unsigned int)main.array[i].red + second >= 255) {
            main.array[i].red = 255;
        } else {
            main.array[i].red += second;
        }
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void add_green(const string& out, const string& first, int second) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        if((unsigned int)main.array[i].green + second >= 255) {
            main.array[i].green = 255;
        } else {
            main.array[i].green += second;
        }
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void add_blue(const string& out, const string& first, int second) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        if((unsigned int)main.array[i].blue + second >= 255) {
            main.array[i].blue = 255;
        } else {
            main.array[i].blue += second;
        }
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void scale_red(const string& out, const string& first, int second) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        if(main.array[i].red * second >= 255) {
            main.array[i].red = 255;
        } else{
            main.array[i].red *= second;
        }
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void scale_green(const string& out, const string& first, int second) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        if(main.array[i].green * second >= 255) {
            main.array[i].green = 255;
        } else{
            main.array[i].green *= second;
        }
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

void scale_blue(const string& out, const string& first, int second) {
    Picture main;
    main.set_Picture_input(first);
    main.read_all();
    for(unsigned int i = 0; i < (unsigned int)(main.width * main.height); i++) {
        if(main.array[i].blue * second >= 255) {
            main.array[i].blue = 255;
        } else{
            main.array[i].blue *= second;
        }
    }
    if(out == first) {
        main.replace_output(out);
    } else {
        main.set_Picture_output(out);
    }
    main.write_all();
}

int main(int argc, const char** argv) {
    run_all_edits();
    if(argc == 1) {
        cout << "Project 2: Image Processing, Summer 2023" << endl << endl;
        cout << "Usage:" << endl << "\t./project2.out [output] [firstImage] [method] [...]";
        return 0;
    }
    if(argc == 2) {
        if(strcmp(argv[1], "--help") == 0) {
            cout << "Project 2: Image Processing, Summer 2023" << endl << endl;
            cout << "Usage:" << endl << "\t./project2.out [output] [firstImage] [method] [...]";
            return 0;
        }
        cout << "Invalid file name." << endl;
    }
    if(argc > 2) {
        if(not hasEnding(argv[2])) {
            cout << "Invalid file name." << endl;
            return 0;
        }
        if(find(files.begin(), files.end(), argv[2]) == files.end()) {
            cout << "File does not exist." << endl;
            return 0;
        }
        for(unsigned int i = 3; i < argc; i++) {
            if(strcmp(argv[i], "multiply") == 0) {
                if(argc == i + 1) {
                    cout << "Missing argument." << endl;
                    return 0;
                }
                if(not hasEnding(argv[i - 1])) {
                    cout << "Invalid file name." << endl;
                }
                if((argc >= i + 1) && (not hasEnding(argv[i + 1]))) {
                    cout << "Invalid file name." << endl;
                }
                if(i == 3) {
                    multiply(argv[1], argv[2], argv[4]);
                } else {
                    multiply(argv[1], argv[1], argv[i + 1]);
                }
            }
            else if(strcmp(argv[i], "subtract") == 0) {
                if(argc == i + 1) {
                    cout << "Missing argument." << endl;
                    return 0;
                }
                if(not hasEnding(argv[i - 1])) {
                    cout << "Invalid file name." << endl;
                }
                if((argc >= i + 1) && (not hasEnding(argv[i + 1]))) {
                    cout << "Invalid file name." << endl;
                }
                if(i == 3) {
                    subtract(argv[1], argv[2], argv[4]);
                } else {
                    subtract(argv[1], argv[1], argv[i + 1]);
                }
            }
            else if(strcmp(argv[i], "overlay") == 0) {
                if(argc == i + 1) {
                    cout << "Missing argument." << endl;
                    return 0;
                }
                if(not hasEnding(argv[i - 1])) {
                    cout << "Invalid file name." << endl;
                }
                if((argc >= i + 1) && (not hasEnding(argv[i + 1]))) {
                    cout << "Invalid file name." << endl;
                }
                if(i == 3) {
                    overlay(argv[1], argv[2], argv[4]);
                } else {
                    overlay(argv[1], argv[1], argv[i + 1]);
                }
            }
            else if(strcmp(argv[i], "screen") == 0) {
                if(argc == i + 1) {
                    cout << "Missing argument." << endl;
                    return 0;
                }
                if(not hasEnding(argv[i - 1])) {
                    cout << "Invalid file name." << endl;
                }
                if((argc >= i + 1) && (not hasEnding(argv[i + 1]))) {
                    cout << "Invalid file name." << endl;
                }
                if(i == 3) {
                    screen(argv[1], argv[2], argv[4]);
                } else {
                    screen(argv[1], argv[1], argv[i + 1]);
                }
            }
            else if(strcmp(argv[i], "combine") == 0) {
                if(argc <= i + 2) {
                    cout << "Missing argument." << endl;
                    return 0;
                }
                if(i == 3) {
                    combine(argv[1], argv[2], argv[4], argv[5]);
                } else {
                    combine(argv[1], argv[1], argv[i + 1], argv[i + 2]);
                }
            }
            else if(strcmp(argv[i], "flip") == 0) {
                if(i == 3) {
                    flip(argv[1], argv[2]);
                } else {
                    flip_itself(argv[1]);
                }
            }
            else if(strcmp(argv[i], "onlyred") == 0) {
                if(i == 3) {
                    only_red(argv[1], argv[2]);
                } else {
                    only_red(argv[1], argv[1]);
                }
            }
            else if(strcmp(argv[i], "onlygreen") == 0) {
                if(i == 3) {
                    only_green(argv[1], argv[2]);
                } else {
                    only_green(argv[1], argv[1]);
                }
            }
            else if(strcmp(argv[i], "onlyblue") == 0) {
                if(i == 3) {
                    only_blue(argv[1], argv[2]);
                } else {
                    only_blue(argv[1], argv[1]);
                }
            }
            else if(strcmp(argv[i], "addred") == 0) {
                if(argc == i + 1) {
                    cout << "Missing argument." << endl;
                    return 0;
                }
                try{
                    if(i == 3) {
                        add_red(argv[1], argv[2], stoi(argv[4]));
                    } else {
                        add_red(argv[1], argv[1], stoi(argv[i + 1]));
                    }
                } catch(invalid_argument) {
                    cout << "Invalid argument, expected number." << endl;
                }
            }
            else if(strcmp(argv[i], "addgreen") == 0) {
                if(argc == i + 1) {
                    cout << "Missing argument." << endl;
                    return 0;
                }
                try{
                    if(i == 3) {
                        add_green(argv[1], argv[2], stoi(argv[4]));
                    } else {
                        add_green(argv[1], argv[1], stoi(argv[i + 1]));
                    }
                } catch(invalid_argument) {
                    cout << "Invalid argument, expected number." << endl;
                }
            }
            else if(strcmp(argv[i], "addblue") == 0) {
                if(argc == i + 1) {
                    cout << "Missing argument." << endl;
                    return 0;
                }
                try{
                    if(i == 3) {
                        add_blue(argv[1], argv[2], stoi(argv[4]));
                    } else {
                        add_blue(argv[1], argv[1], stoi(argv[i + 1]));
                    }
                } catch(invalid_argument) {
                    cout << "Invalid argument, expected number." << endl;
                }
            }
            else if(strcmp(argv[i], "scalered") == 0) {
                if(argc == i + 1) {
                    cout << "Missing argument." << endl;
                    return 0;
                }
                try{
                    if(i == 3) {
                        scale_red(argv[1], argv[2], stoi(argv[4]));
                    } else {
                        scale_red(argv[1], argv[1], stoi(argv[i + 1]));
                    }
                } catch(invalid_argument) {
                    cout << "Invalid argument, expected number." << endl;
                }
            }
            else if(strcmp(argv[i], "scalegreen") == 0) {
                if(argc == i + 1) {
                    cout << "Missing argument." << endl;
                    return 0;
                }
                try{
                    if(i == 3) {
                        scale_green(argv[1], argv[2], stoi(argv[4]));
                    } else {
                        scale_green(argv[1], argv[1], stoi(argv[i + 1]));
                    }
                } catch(invalid_argument) {
                    cout << "Invalid argument, expected number." << endl;
                }
            }
            else if(strcmp(argv[i], "scaleblue") == 0) {
                if(argc == i + 1) {
                    cout << "Missing argument." << endl;
                    return 0;
                }
                try{
                    if(i == 3) {
                        scale_blue(argv[1], argv[2], stoi(argv[4]));
                    } else {
                        scale_blue(argv[1], argv[1], stoi(argv[i + 1]));
                    }
                } catch(invalid_argument) {
                    cout << "Invalid argument, expected number." << endl;
                }
            } else if(find(methods.begin(), methods.end(), argv[i]) == methods.end()) {
                cout << "Invalid method name." << endl;
            } else {
                continue;
            }
        }
    }
    return 0;
}