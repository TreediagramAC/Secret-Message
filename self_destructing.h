#ifndef SELF_DESTRUCTING_H
#define SELF_DESTRUCTING_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <ios>
#include <iostream>
using std::endl;
#include<sstream>
using std::ostream;
using std::istream;

class SelfDestructingMessage {
private:
  vector<string> messages_;
  long number_of_allowed_views_;
  vector <long> readable_;
public:
  // constructors
    SelfDestructingMessage()=default;
    SelfDestructingMessage(vector<string> m, long n) {
      messages_=m;
      number_of_allowed_views_=n;
      for (long i=0;i<messages_.size();i++){
        readable_.push_back(n);
      }
    };
  // getters
    vector<string> messages() const {return messages_;}
    long number_of_allowed_views() const {return number_of_allowed_views_;}
    vector<long> readable() const {return readable_;}
  // setters
    void messages(vector<string> val) {messages_ = val;}
    void number_of_allowed_views(long val) {number_of_allowed_views_ = val;}
    void readable(vector<long>val){readable_ = val;}
  // members
    long size();
    vector<string> get_redacted();
    long number_of_views_remaining(long);
    string & operator[](long);
    SelfDestructingMessage(  SelfDestructingMessage& );
    SelfDestructingMessage& operator=( SelfDestructingMessage&);
    void add_array_of_lines(const string[],long );

  //friend
    friend ostream& operator<< (ostream&, const SelfDestructingMessage& );
    friend istream& operator>> (istream&,  SelfDestructingMessage& );


};

#endif
