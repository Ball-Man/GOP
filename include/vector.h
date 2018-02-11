#ifndef GOP_VECTOR_H_
#define GOP_VECTOR_H_

#include <cstdint>

// Mimic of the standard vector class
template <class T>
class Vector
{
 public:
  Vector()
  {
    array_ = new T[32];

    capacity_ = 32;
    length_ = 0;
  }

  Vector(int n, const T array[])
  {
    array_ = new T[CalcCapacity(n)];
    for(int i = 0; i < n; i++)
      array_[i] = array[i];

    capacity_ = CalcCapacity(n);  // Double the length, ready for future pushes 
    length_ = n;
  }

  Vector(int n, const T& el)
  {
    array_ = new T[CalcCapacity(n)];
    for(int i = 0; i < n; i++)
      array_[i] = el;

    capacity_ = CalcCapacity(n); // Double the length, ready for future pushes
    length_ = n;
  }

  Vector(const Vector<T>& vector) // Copy constructor
  {
    array_ = new T[vector.Capacity()];
    length_ = vector.Length();
    capacity_ = vector.Capacity();

    for(int i = 0; i < vector.Length(); i++)
      array_[i] = vector[i];
  }

  ~Vector()
  {
    delete []array_;
  }

  // Access operator
  T& operator [](int index) const { return array_[index]; }

  // Add elements
  void Push(const T& el) { Insert(el, length_); }

  void Insert(const T& el, int index)
  {
    if(capacity_ <= length_)  // If there's not enough space...
    {
      T* tmp = new T[capacity_ * 2];  // New vector with more capacity
      for(int i = 0; i < length_; i++)
        tmp[i] = array_[i];

      delete []array_;
      array_ = tmp;

      capacity_ *= 2;
    }
    
    for(int i = length_++; i > index; i--)
      array_[i] = array_[i - 1];

    array_[index] = el;
  }

  // Remove elements
  const T& Pop() { return array_[--length_]; }

  void Erase(int index)
  {
    length_--;
    for(int i = index; i < length_; i++)
      array_[i] = array_[i + 1];
  }

  void Clear() { length_ = 0; }

  // Getters
  int Length() const { return length_; }
  int Capacity() const { return capacity_; }

  T& First() const { return array_[0]; }
  T& Last() const { return array_[length_ - 1]; }

 private:
  uint32_t CalcCapacity(uint32_t length) const
  {
    uint32_t i = 1;
    while(length)
    {
      length >>= 1;
      i <<= 1; 
    }
    return i;
  }

  T* array_;

  int length_;
  int capacity_;
};

#endif