#include "sstring.h"

#include <cstring>

/// *** PUBLIC *** ///
String::String()
{
  cstr_ = new char[19];
  capacity_ = 19;

  cstr_[0] = '\0';    // String initialized to 0 length

  tmp_ = NULL;
  stmp_ = NULL;
}

String::String(const char string[])
{
  int len = strlen(string) + 1;
  capacity_ = len;

  cstr_ = new char[len];
  strcpy(cstr_, string);

  tmp_ = NULL;
  stmp_ = NULL;
}

String::String(const String& string) : String(string.ToCString()) { }

String::~String()
{
  delete []cstr_;   // Free heap
  if(tmp_)    // Check if used
    delete []tmp_;
  if(stmp_)
    delete stmp_;
}

// Operators
String& String::operator +(const String& string) { return operator+(string.ToCString()); }
String& String::operator +(const char string[])
{
  tmp_ = new char[strlen(string) + strlen(cstr_) + 1];
  strcpy(tmp_, cstr_);
  strcat(tmp_, string);
  stmp_ = new String(tmp_);
  return *stmp_;
}

String& String::operator +=(const String& string) { return operator+=(string.ToCString()); }
String& String::operator +=(const char string[])
{
  operator+(string);
  operator=(tmp_).ToCString();
  return *this;
}

String& String::operator =(const String& string) { return operator=(string.ToCString()); }
String& String::operator =(const char string[])
{
  int len = strlen(string) + 1;
  if(capacity_ < len)   // If there's not enough space for our new string
  {
    delete []cstr_;
    cstr_ = new char[len];
  }
  capacity_ = len;

  strcpy(cstr_, string);
  return *this;
}

// CString conversion
const char* String::ToCString() const { return cstr_; }

// Getters
int String::Length() const { return strlen(cstr_); }

/// *** GLOBAL *** ///
// Global operator
String& operator +(const char string1[], String& string2) 
{
  String tmp = string1;
  string2 = tmp + string2;
  return string2;
}

// Cout
std::ostream& operator <<(std::ostream& stream, const String& string)
{
  stream << string.ToCString();
  return stream;
}