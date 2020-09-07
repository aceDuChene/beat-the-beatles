/************************************************************************
 * Function name: validateInput
 * Author: Danielle DuChene
 * Date: 12-10-2019
 * Description: Takes in a min and max integer and checks user input
 *    to see if it is an integer and is between those values. Also has
 *    functions to check for various char inputs.
 * *********************************************************************/
#ifndef VALIDATEINPUT_HPP
#define VALIDATEINPUT_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <fstream>

#include "validateInput.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::numeric_limits;
using std::streamsize;
using std::isalpha;
using std::ifstream;

const int validateInteger(int min, int max);
char validateChar(bool);
char validateAlpha();
char validateABC();
char validateABCD();
void clrscr();
void readFile(string inName);

#endif