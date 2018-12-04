#include "array.h"
#include <cstdio>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{

  int origin[10] = {-10,-8,-6,-4,-2,0,2,4,6,8};
  
  Array arr(8,origin);

  Array rtoo(5,1);
 
  for(int i = 0; i < rtoo.size(); i++)
    rtoo[i] = i * 2;
   

  cout << "arr = " << arr << endl;
  cout << "rtoo = " << rtoo << endl; 

  
  Array newArray;
  newArray = rtoo;

  cout << "newArray = " << newArray << endl;

  // append three integers to newArray 
  newArray.append(1);
  newArray.append(10);
  newArray.append(15);
  cout << "newArray size = " << newArray.size() << " and newArray =  "\
       << newArray;

  // copy constructor
  Array newArraytoo(newArray);
  newArraytoo[0] = -100;
  cout << "newArraytoo = " << newArraytoo;

  // overload of +
  newArraytoo = newArray + arr;

  cout << "After adding, newArraytoo = newArray + arr :" << newArray << endl;
  
  // index out-bound
  for(int i = -2; i < newArray.size(); i++){
    printf(" arr[%d] = %d\n", i, arr[i]);
  }
  return(0);
}

