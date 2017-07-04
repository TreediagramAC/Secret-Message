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

#include "self_destructing.h" //Include header file.
#include "redact.h" //Include hearder file, which is build by own and used to encrpyt messages.

//Build function to get how many messages are there in messages vector.
long SelfDestructingMessage::size(){
  long size = messages_.size();
  return size;
}

//Build function to make up of each message in redacted form. Redact all alphabetic and digit characters.
vector<string> SelfDestructingMessage::get_redacted(){
  vector<string> mod;
  for (long i=0; i<messages_.size();i++){
    mod.push_back(redact_alphabet_digits(messages_[i]));
  }
  return mod;
}

//Build function to get the number of views remaining for that specific message.
long SelfDestructingMessage::number_of_views_remaining(long index){
  long remains;
  remains = readable_[index];
  return remains;
}

//Mod operator to return a const reference to the message string that was indexed.
string & SelfDestructingMessage::operator[](long index){
  if (index<0 or index>messages_.size()-1){//Check if index is legal.
    throw std::out_of_range("");
  }
  else{
    if(readable_[index]==0){//Check if that specific message is still readble.
      throw std::invalid_argument("");
    }
    else{
      readable_[index]-= 1;//Reduce message's read remaining by one.
      return messages_[index];
    }
  }
}

//Mod operator to display each line of the message (in redacted form) is prefixed by
//the number of views remaining, and should be inserted to the ostream.
ostream & operator<< (ostream&out, const SelfDestructingMessage& sdm){
  if (sdm.readable_[i]<10){
      out<<"0"<<sdm.readable_[i]<<": "<<redact_alphabet_digits(sdm.messages_[i])<<'\n';
    }
    else{
      out<<sdm.readable_[i]<<": "<<redact_alphabet_digits(sdm.messages_[i])<<'\n';
    }
  }
  return out;
}

//This class should transfers all the views remaining to the copy, and zero out the original.
SelfDestructingMessage::SelfDestructingMessage( SelfDestructingMessage& origin ){
    messages_ = origin.messages_ ;
    number_of_allowed_views_ = origin.number_of_allowed_views_ ;
    readable_ =  origin.readable_ ;
    for(long i=0;i<origin.readable_.size();i++){
      origin.readable_[i] = 0;
    }
  }

//This modded operator should transfer the views remaining to the left-hand-side like with the
//copy constructor. This is also to prevent copy abuse.
SelfDestructingMessage& SelfDestructingMessage::operator=( SelfDestructingMessage & assignment){
  messages_ = assignment.messages_ ;
  number_of_allowed_views_ = assignment.number_of_allowed_views_ ;
  readable_ =  assignment.readable_ ;
  for(long i=0;i<assignment.readable_.size();i++){
    assignment.readable_[i] =0;
  }
  return *this;
}

//This modded operator should extract a line from the istream and append it
//to the message list
istream& operator>> (istream& in,  SelfDestructingMessage& sdm){
  string ss;
  getline(in,ss);
  sdm.messages_.push_back(ss);
  sdm.readable_.push_back(sdm.number_of_allowed_views_);
}

//Build a function to add each string to the list of messages
void SelfDestructingMessage::add_array_of_lines(const string messages_to_be_added[],long the_size_of_the_array){
  for(long i =0; i<the_size_of_the_array;i++){
    messages_.push_back(messages_to_be_added[i]);
    readable_.push_back(number_of_allowed_views_);
  }
}
