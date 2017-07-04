#include "redact.h"
#include <iostream>
using std::cin;using std::cout;using std::endl;
#include <string>
using std::string;
#include<vector>
using std::vector;
#include <algorithm>
using std::replace;

//Build function to encrypt all characters in input.
string redact_all_chars(const string &input){
  string mod = input;
  for(long c = 0 ; c<mod.length(); c++){
    mod[c] = '#';
  }
  return mod;
}

//Build function to encrypt all alphabet or digit characters in input.
string redact_alphabet_digits(const string &input){
  string mod = input;
  for (long c = 0; c < mod.length(); c++){
    if (isdigit(mod[c]) or isalpha(mod[c])){mod[c] = '#';}
  }
  return mod;
}

//Build function to encrypt all alphabet or digit characters in
//input if those characters composed a word in compared word list.
string redact_words (const string &input,const vector<string>word_to_redact){
  string mod = input;
  string redact_part;
  size_t start;
  long redact_part_length;
  for (long s=0; s<word_to_redact.size(); s++){
      redact_part = word_to_redact[s];
      redact_part_length = redact_part.length();
      while (mod.find(redact_part)!=string::npos){
        start = mod.find(redact_part);
        mod.replace(start,redact_part_length,redact_all_chars(redact_part));
      }
  }
  return mod;
}
