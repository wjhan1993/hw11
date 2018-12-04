#include "array.h"
using namespace std;

// Constructor
// array is NULL pointer, size and count = 0
Array::Array(){
  array = NULL;
  Size = 0;
  capacity  = 0;
}

// copy constructor
Array::Array(const Array& y){

  // allocate int array 
  Size = y.size();
  array = (int*)malloc(Size * (sizeof(int)));

  // copy elements in Array y
  for (int i = 0;i < y.size();i++)
    array[i] = y[i];
  
  capacity = y.getCapacity();
}

// Array(int length,int* values)
Array::Array(int length,int* values){
  // allocate int array 
  Size = length;
  array = (int*)malloc(Size * (sizeof(int)));

  if (values != NULL){
    // copy elements in Array y
    for (int i = 0;i < Size;i++)
      array[i] = values[i];
  }
  capacity  = length; 
}

// destructor
Array::~Array(){
  cleanup();
}

// Initialize an array with size = s and assign all elements as v
Array::Array(int s,int v){
  Size = s;
  
  // allocate memeory for the array
  array = (int*)malloc(Size * (sizeof(int)));
  capacity = s;

  // initialize all elements as v
  for (int i = 0;i < Size;i++)
    array[i] = v;
  
}

// get size
int Array::size() const{
  return Size;
}

// append x to the end of the array
void Array::append(int x){
  // if the array is full, expand the capacity
  if (capacity){
     if (capacity == Size)
        this->expand();
   
    // append x to the end and update count
    array[Size++] = x;
  }
}

// append array y to the end of the array
void Array::append(const Array& y){
  if (capacity){
    // copy all elements in y 
    for (int i = 0;i < y.size();i++){
      // When array is full, expand the capacity
      if (Size == capacity)
        this->expand();
    
      array[Size++] = y[i];
    }
  }
}

// overload of =
Array& Array::operator=(const Array& y){
  if(this != &y){
    
    // clear the current array
    this->cleanup();

    // same as the copy constructor
    capacity = y.getCapacity();
    array = (int*)malloc(capacity *(sizeof(int)));

    Size = y.size();
    for (int i = 0;i < Size;i++)
      array[i] = y[i];
    
  }
  return *this;
}

// overload of []
int& Array::operator[](int index)const{

  // if the index is illegal, exit with status 0
  if (index < 0 or index >= capacity)
  {
    std::cout << "Error: Index " << index << " out of bound!"<< std::endl;
    exit(0);
  }
  else
    return array[index];
}

// get count
int Array::getCapacity() const{
  return capacity;
}

// double the arraysize when the array is full
void Array::expand(){

  
  // allocate a array with double size
  int *newArray = (int*)malloc(2 * capacity * sizeof(int));
  int newCapacity = 2 * capacity;

  // copy all elements
  for (int i = 0;i < Size;i++)
    newArray[i] = array[i];

  // clear up the current array
  this->cleanup();
  
  array = newArray;
  capacity = newCapacity;
  
}

// cleanup: release all memory associated with the array
void Array::cleanup(){
  if (array){
    free(array);
    array = NULL;
  }

}

// overload of +
Array& Array::operator+(const Array& y){
  
  // copy all elements in y 
  for (int i = 0;i < y.size();i++){

    // When array is full, expand the capacity
    if (capacity == Size)
      this->expand();
    
    array[Size++] = y[i];
  }

  return *this;
}

// printf function for Array (overload of <<) 
ostream& operator<<(ostream& os, Array& y)  
{
  os << "[";
  int i;
  for (i = 0;i < y.getCapacity() - 1;i++){
    os << y[i] << ", "; 
  }
  os << y[i] << "]";
  return os;
}
