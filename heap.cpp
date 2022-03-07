// heap.cpp
// Sanjana Shankar

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  ChangePositionUp(vdata.size()-1);


}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  //int minimum = vdata.at(0);
  int lastElem = vdata.at(vdata.size()-1);
  vdata.at(0) = lastElem;
  vdata.pop_back();
  ChangePositionDown(0);
  

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

void Heap::ChangePositionUp(int index) {
  int parentIndex;
  while(withinRange(index) && withinRange((index-1)/2)) {
    parentIndex = (index - 1) / 2;
    if(vdata.at(index) >= vdata.at(parentIndex)) {
        return;
    }else {
      int temp = vdata.at(index);
      vdata.at(index) = vdata.at(parentIndex);
      vdata.at(parentIndex) = temp;
      index = parentIndex;
    }
  }

}


void Heap::ChangePositionDown(int index) {
  if(!withinRange(index)) {
    return;
  }
  int indexOfChild = (2*index) + 1;
  int currValue = vdata.at(index);
  int temp;
  while(withinRange(indexOfChild) && indexOfChild < vdata.size()) {
    int minimum = currValue;
    int minimumIndex = -1;
    for(int i = 0; i<2; i++) {
      if(i+indexOfChild < vdata.size()) {
        if(withinRange(i+indexOfChild) && (vdata.at(i+indexOfChild) < minimum)) {
          minimum = vdata.at(i+indexOfChild);
          minimumIndex = i+indexOfChild;
        }
      }
    }

    if(minimum == currValue) {
      return;
    }else {
      temp = vdata.at(index);
      vdata.at(index) = vdata.at(minimumIndex);
      vdata.at(minimumIndex) = temp;
      index = minimumIndex;
      indexOfChild = (2*index) + 1;
    }
  }
}

bool Heap::withinRange(int index) {
  if(index >= 0 && index < vdata.size()) {
    return true;
  }else {
    return false;
  }

}

void Heap::printHeap() {
  cout << "Heap size: " << vdata.size() << " ";
  for(long unsigned int i = 0; i<vdata.size(); i++) {
    cout << vdata.at(i) << " ";
  }
  cout << std::endl;
}
    