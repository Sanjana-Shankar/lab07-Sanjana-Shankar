// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  /*
  vdata.resize(vdata.size()+1);
  int index = 0;
  for(int i = 0; i < vdata.size(); i++) {
    if(value <= vdata.at(i)) {
      index = i;
      break;
    }
  }

  for(int i = vdata.size()-1; i >= index; i--) {
    if(i == index) {
      vdata.at(i) = value;
      break;
    }
    vdata.at(i) = vdata.at(i-1);
  }
  */
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
  /*
  int lastElement = vdata.at(vdata.size()-1);
  vdata.resize(vdata.size()-1);
  for(int i = 0; i<vdata.size(); i++) {
    if(i == vdata.size()-1) {
      vdata.at(i) = lastElement;
      break;
    }
    vdata.at(i) = vdata.at(i+1);

  }
  */
  for(int i = 0; i<vdata.size()-1; i++) {
    vdata.at(i) = vdata.at(i+1);
  }
  vdata.resize(vdata.size()-1);

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
    