// heap.cpp
// Sanjana Shankar

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  
  vdata.push_back(value);
  int temp = 0;
  for(int i = vdata.size()-1; i>0; i--) {
    if(vdata.at(i) <= vdata.at(i-1)) {
      temp = vdata.at(i-1);
      vdata.at(i-1) = vdata.at(i);
      vdata.at(i) = temp;
    }else {
      break;
    }
  }

}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  
  for(int i = 0; i<vdata.size()-1; i++) {
    vdata.at(i) = vdata.at(i+1);
  }
  vdata.pop_back();

}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata.at(0);
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if(vdata.size() == 0) {
    return true;
  }else {
    return false;
  }

}
    