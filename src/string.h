#ifndef GOP_STRING_H_
#define GOP_STRING_H_

#include <iostream>

// Mimic of std::string class
class String
{
 public:
  String();
  String(const char string[]);
  String(const String& string);   // Copy constructor

  ~String();

  // Operators
  String& operator +(const String& string);
  String& operator +(const char string[]);

  String& operator +=(const String& string);
  String& operator +=(const char string[]);

  String& operator =(const String& string);
  String& operator =(const char string[]);

  // CString conversion
  const char* ToCString() const;

  // Getters
  int Length() const;

 private:
  int capacity_;
  char* cstr_;

  char* tmp_;
  String* stmp_;
};

// Global operator for commutation
String& operator +(const char string1[], String& string2);

// Cout
std::ostream& operator <<(std::ostream& stream, const String& string);

#endif