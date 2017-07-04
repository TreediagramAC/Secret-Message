#ifndef REDACT_H
#define REDACT_H

#include <iostream>
using std::cin;using std::cout;using std::endl;
#include <string>
using std::string;
#include<vector>
using std::vector;
#include <algorithm>
using std::replace;

string redact_all_chars(const string &input);
string redact_alphabet_digits(const string &input);
string redact_words (const string &input,const vector<string>word_to_redact);
#endif
