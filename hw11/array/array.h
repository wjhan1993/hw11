#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <stdlib.h>
using namespace std;

class Array{
public:
  // Default constructor
  Array();

  // Array(int length,int* values)
  Array(int length, int* values);
  
  // copy constructor
  Array(const Array& y);

  // Destructor
  ~Array();

  // Initialize an array with size =s and assign all elements as v
  Array(int s,int v);

  // get size
  int size() const;

  // append x to the end of the array
  void append(int x);

  // append array y to the end of the array
  void append(const Array& y);

  // overload of =
  Array& operator=(const Array& y);
 
  // overload of []
  int& operator[](int index)const;

  friend ostream& operator<<(ostream& os, Array& y);  

  // get capacity
  int getCapacity()const;

  // overload of +
  Array& operator+(const Array& y);

  // release all memeory, called by the destructor 
  void cleanup();
  
private:
    // array stores all elements
    int* array;

    // size records the number of elements in the current array
    int Size;

    // capacity is the maximum volume of the array
    int capacity;

    // double the arraysize when the array is full
    void expand();
};


#endif
