/* 
 * File:   main.cpp
 * Author: Michael Roessler
 *
 * Converts a number from any base from 2 to 36 to another base.
 * Letters A-F represent numbers 10-35 as a single digit.
 * 
 * Type conversion as:
 * > [from] [value] [to]
 * 
 * Example:
 * > 10 21 2
 * 10101
 * 
 * Example converts the decimal number 21 to binary and gets 10101.
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

/**
 * Determines the value of a digit where A=10 to Z=35.
 * 
 * @param val   The digit to be processed.
 * @return      The int value of the digit.
 */
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

/**
 * Reverse of the process function.
 * 
 * @param val   Decimal value of a digit.
 * @return      The value as a single digit 0-9/A-Z.
 */
char process2(std::string val) {
    char rVal;
    //std::cout << val << std::endl;
    if      (val == "10"){rVal = 'A';}
    else if (val == "11"){rVal = 'B';}
    else if (val == "12"){rVal = 'C';}
    else if (val == "13"){rVal = 'D';}
    else if (val == "14"){rVal = 'E';}
    else if (val == "15"){rVal = 'F';}
    else if (val == "16"){rVal = 'G';}
    else if (val == "17"){rVal = 'H';}
    else if (val == "18"){rVal = 'I';}
    else if (val == "19"){rVal = 'J';}
    else if (val == "20"){rVal = 'K';}
    else if (val == "21"){rVal = 'L';}
    else if (val == "22"){rVal = 'M';}
    else if (val == "23"){rVal = 'N';}
    else if (val == "24"){rVal = 'O';}
    else if (val == "25"){rVal = 'P';}
    else if (val == "26"){rVal = 'Q';}
    else if (val == "27"){rVal = 'R';}
    else if (val == "28"){rVal = 'S';}
    else if (val == "29"){rVal = 'T';}
    else if (val == "30"){rVal = 'U';}
    else if (val == "31"){rVal = 'V';}
    else if (val == "32"){rVal = 'W';}
    else if (val == "33"){rVal = 'X';}
    else if (val == "34"){rVal = 'Y';}
    else if (val == "35"){rVal = 'Z';}
    else if (stoi(val) < 10){rVal = val[0];}
    else {}
    //std::cout << rVal << ",";
    return rVal;
}

/**
 * Converts from any base(2-36) to decimal.
 * 
 * @param from  The base to convert from.
 * @param num   The number value to convert.
 * @return      Returns the decimal value.
 */
double x2dec(int from, std::string num) {
    double sum = 0;
    int subtr = 0;
    
    // Loop through each char
    for (int i = 0; i < num.length(); i++) {
        int x = process(num.at(num.length()-(i+1)));// Determine value of digit
        
        // Check if digit is valid
        if (x >= from) {// Print error if invalid but allow conversion to proceed
            std::cout << "Error in number value: " << num << std::endl;
            std::cout << "Value '" << num.at(num.length()-(i+1)) << "' is invalid in base-" << from << std::endl;
        }
        if (x >= 0) {// If digit is number value
            sum += x * std::pow(from, i-subtr);
        } else if (x == -1) {// If digit is '-'
            if ((i+1) == num.length()) {
                sum *= -1;
            } else {
                std::cout << "Error in number value: " << num << std::endl;
                std::cout << "Improper usage of '-'" << std::endl;
                sum = 0;// 0 if error
            }
            
            break;
        } else if (x == -2) {// If digit is '.' **Not yet working
            if (true/*subtr != 0*/) {
                std::cout << "Error in number value: " << num << std::endl;
                std::cout << "Improper usage of '.'" << std::endl;
                sum = 0;// 0 if error
                break;
            }
            //sum = sum / std::pow(from, i);
            //subtr = i+1;
        } else if (x == -3) {// If digit is unknown character
            std::cout << "Error in number value: " << num << std::endl;
            std::cout << "Unknown character '" << num.at(num.length()-(i+1)) << "'" << std::endl;
            sum = 0;// 0 if error
            break;
        }
    }
    //std::cout << sum << std::endl;
    return sum;
}

/**
 * Converts from decimal to any base(2-36).
 * 
 * @param num   Decimal number to convert.
 * @param to    The base to convert to.
 * @return      Returns the value in the converted base.
 */
std::string dec2x(double num, int to) {
    std::string digit, nextDigit = "", decDigit = "";
    int sum = 0;
    //float num = number;
    int numI = num;//Find way to split at the decimal point?
    /*if (num != numI) {
        std::cout << num << " " << numI << " " << (num-numI) << std::endl;
        int p = 1;
        while ((num-numI)*p != (int)((num-numI)*p)) {
            p *= 10;
        }
        decDigit = "." + dec2x((int)((num-numI)*10), to);
    }*/
    int rem = numI % to;
    num = numI - rem;
    while (numI >= to) {
        numI = numI - to;
        sum++;
    }
    if (sum >= to) {
        nextDigit = dec2x(sum, to);
    } else if (sum != 0) {
        nextDigit = std::to_string(sum).substr(0,1);
    }
    //std::cout << rem << std::endl;
    digit = process2(std::to_string(rem)/*.substr(0,1)*/);
    //std::cout << digit << std::endl;
    return nextDigit + digit + decDigit;
}

/**
 * Takes user input, prints output, then loops for more input.
 */
void userInput() {
    std::string num;
    int from, to;
    std::cout << "Type conversion as: " << std::endl;
    std::cout << "> [from] [value] [to]" << std::endl;
    while (true) {
        std::cout << "> ";
        if (!(std::cin >> from >> num >> to)) {// If input types are wrong
            std::cin.clear();
            std::cin.ignore(99999, '\n');
            std::cout << "Error in input" << std::endl;
            std::cout << "Type conversion as: " << std::endl;
            std::cout << "> [from] [value] [to]" << std::endl;
            std::cout << "[from] is the base of the value to convert from (2-36)." << std::endl;
            std::cout << "[value] is the number value to be converted." << std::endl;
            std::cout << "[to] is the base to convert to (2-36)." << std::endl;
        } else if (from < 2 || from > 36) {// If from isn't a supported base
            std::cout << "Error in [from] value: " << from << std::endl;
            std::cout << "[from] is the base of the value to convert from (2-36)." << std::endl;
        } else if (to < 2 || to > 36) {// If to isn't a supported base
            std::cout << "Error in [to] value: " << to << std::endl;
            std::cout << "[to] is the base to convert to (2-36)." << std::endl;
        } else {// If no errors then calculate
            std::cout << dec2x(x2dec(from, num), to) << std::endl;
        }
        
    }
}

int main(int argc, char** argv) {
    // If there are 3 args, calculate with that
    if (argc == 4) {
        std::cout << dec2x(x2dec(stoi(argv[1]), argv[2]), stoi(argv[3])) << std::endl;
    } else {// Else use console input
        userInput();
    }
    return 0;
}

