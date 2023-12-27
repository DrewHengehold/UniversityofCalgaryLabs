// ENSF 337- lab 7 - Exercise D
//  simpleVector.cpp
// Student functions written by Drew Hengehold
/*
 NOTES ON MEMORY ALLOCATION POLICIES FOR SimpleVector OBJECT:
 
 - If vector objects are supposed to be empty storageM will be NULL and the values
   of sizeM and capacityM must be set to zero.
 - If the objects of vector are supposed to be initialize with supplied values of
   an array, the size a and values in the dynamically memory space for storageM
   must be identical to the size and values in the supplied array. And, the
   values of sizeM and capacityM should be both set to the exact size of array.
 
- If any member function need to resize the vector, it should check the values of
  sizeM and capacityM:
  - If sizeM is equal to capacityM and vector is empty (i.e. capaictyM is equal to
    zero), capcityM should be changed to 2.
  - Otherwise, if sizeM is equal to capacityM, and capacityM is not zero (i.e.
    vector is NOT empty), the value of capacityM should be doubled up
  EXAMPLE: if capacityM is 5 and sizeM is also 5:
     1. the value of capacityM should be changed to 10.
     2. the dynamically allocated memory space for storageM should be reallocated
        to 10.
     3. The current values in the vector should be preserved and any unnecessary
        dynamically allocated memory must to deallocated.
*/

#include "simpleVector.h"
#include <cassert>
using namespace std;

SimpleVector::SimpleVector(const TYPE *arr, int n) {
    storageM = new TYPE[n];
    sizeM = n;
    capacityM = n;
    for(int i =0; i < sizeM; i++)
        storageM[i] = arr[i];
}

TYPE& SimpleVector::at(int i) {
    assert(i >= 0 && i < sizeM);
    return storageM[i];
}

const TYPE& SimpleVector::at(int i)const {
    assert(i >= 0 && i < sizeM);
    return storageM[i];
}


// The followng member function should follow the above-mentioned memory
// management policy to resize the vector, if necessary. More specifically:
//   - If sizeM < capacityM it doesn't need to make any changes to the size of
//     allocated memory for vector
//   - Otherwise it follows the above-mentioned memory policy to create additionl
//     memory space and adds the new value, val, to the end of the current vector
//     and increments the value of sizeM by 1
void SimpleVector::push_back(TYPE val) {
    if(sizeM == capacityM){
        int new_capacity = (capacityM == 0) ? 2:2 *capacityM;
        TYPE *new_storage = new TYPE[new_capacity];
        for(int i = 0; i < size(); i++)
            new_storage[i] = storageM[i];
        delete[] storageM;
        storageM = new_storage;
    }
    storageM[sizeM] = val;
    sizeM++;
}

SimpleVector::SimpleVector(const SimpleVector& source) {
    sizeM= 0;
    capacityM = 0;
    storageM = 0;
    
    TYPE *storage = new TYPE[source.size()];
    for(int i = 0; i < source.size(); i++)
        storage[i] = source.storageM[i];
    storageM = storage;
    sizeM = capacityM = source.size();
    
}

SimpleVector& SimpleVector::operator= (const SimpleVector& rhs ){
    if(this != &rhs){
        TYPE *storage = new TYPE[rhs.size()];
        for(int i = 0; i < rhs.size(); i++)
            storage[i] = rhs.storageM[i];
        delete[] storageM;
        storageM = storage;
        sizeM = capacityM = rhs.size();
    }
    
    return *this;
}
