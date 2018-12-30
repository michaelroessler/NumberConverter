/* 
 * File:   main.cpp
 * Author: Michael Roessler
 *
 * Created on December 23, 2018, 12:55 PM
 */

#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int process(char& val) {
    int rVal;
    //std::cout << val << ",";
    switch (val) {
        case 'a':case 'A': rVal = 10;break;
        case 'b':case 'B': rVal = 11;break;
        case 'c':case 'C': rVal = 12;break;
        case 'd':case 'D': rVal = 13;break;
        case 'e':case 'E': rVal = 14;break;
        case 'f':case 'F': rVal = 15;break;
        case 'g':case 'G': rVal = 16;break;
        case 'h':case 'H': rVal = 17;break;
        case 'i':case 'I': rVal = 18;break;
        case 'j':case 'J': rVal = 19;break;
        case 'k':case 'K': rVal = 20;break;
        case 'l':case 'L': rVal = 21;break;
        case 'm':case 'M': rVal = 22;break;
        case 'n':case 'N': rVal = 23;break;
        case 'o':case 'O': rVal = 24;break;
        case 'p':case 'P': rVal = 25;break;
        case 'q':case 'Q': rVal = 26;break;
        case 'r':case 'R': rVal = 27;break;
        case 's':case 'S': rVal = 28;break;
        case 't':case 'T': rVal = 29;break;
        case 'u':case 'U': rVal = 30;break;
        case 'v':case 'V': rVal = 31;break;
        case 'w':case 'W': rVal = 32;break;
        case 'x':case 'X': rVal = 33;break;
        case 'y':case 'Y': rVal = 34;break;
        case 'z':case 'Z': rVal = 35;break;
        case '-': rVal = -1;break;
        case '.': rVal = -2;break;
        default:
            if (isdigit(val)) {
                rVal = val - '0';
            } else {
                rVal = -3;
            }
    }
    //std::cout << rVal << ",";
    return rVal;
}

float x2dec(int from, std::string num) {
    float sum = 0;
    int subtr = 0;
    for (int i = 0; i < num.length(); i++) {
        int x = process(num.at(num.length()-(i+1)));
        //std::cout << x << ", ";
        if (x >= 0) {
            sum += x * std::pow(from, i-subtr);
            //std::cout <<sum<<" ";
        } else if (x == -1) {
            sum *= -1;
            break;
        } else if (x == -2) {
            if (subtr != 0) {
                std::cout << "Error in number value." << std::endl;
                break;
            }
            sum = sum / std::pow(from, i);
            subtr = i+1;
        } else if (x == -3) {
            
        }
    }
    //std::cout << std::endl;
    return sum;
}

//divide by "to" until less than zero
//maybe recursion
//*MAYBE CHAR BY CHAR*
std::string dec2x(int num, int to) {
    int sum = 0;
    //float num = number;
    float rem = num % to;
    num = num - rem;
    std::string digit, nextDigit = "";
    while (num >= to) {
        num = num - to;
        sum++;
    }
    if (sum >= to) {
        nextDigit = dec2x(sum, to);
    } else if (sum != 0) {
        nextDigit = std::to_string(sum).substr(0,1);
    }
    digit = std::to_string(rem).substr(0,1);
    return nextDigit + digit;
}

void userInput() {
    std::string num;
    int from, to;
    std::cout << "Type conversion as: " << std::endl;
    while (true) {
        std::cout << "> ";
        std::cin >> from >> num >> to;
        //std::cout << x2dec(from, num) << std::endl;
        std::cout << dec2x(x2dec(from, num), to) << std::endl;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    userInput();
    // x2dec(2, 10);
    return 0;
}

