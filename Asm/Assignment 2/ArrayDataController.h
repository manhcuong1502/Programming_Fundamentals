//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Array
void print(Array& array){
    if (!array.size) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout <<"[";
    for(int i=0;i<array.size;i++){
        std::cout << array.arr[i].ID << " ";
    }
    std::cout <<"]" << endl;
}

void initArray (Array& array, int cap){
    //Init a new array with capacity equals to cap
    //TODO
    array.capacity = cap;
    array.arr = new Soldier[cap];
    array.size = 0;
}

bool insertAt(Array& array, Soldier element, int pos){
    //Insert element into a pos in the array
    //Return true if insert successfully, false otherwise
    //TODO
    
    if (array.arr == NULL || pos < 0 || pos > array.size) return false;
    if (array.size == array.capacity) array.capacity++;
    array.size++;
    Soldier* newArr = new Soldier[array.size];
    for (int i = 0; i < pos; i++) {
        newArr[i] = array.arr[i];
    }
    newArr[pos] = element;
    for (int i = pos + 1; i < array.size; i++) {
        newArr[i] = array.arr[i - 1];
    }
    delete[] array.arr;
    array.arr = newArr;
    return true;
}

bool removeAt (Array& array, int idx){
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise
    //TODO
    if (idx < 0 || idx >= array.size) return 0;
    Soldier* newArr = new Soldier[array.size - 1];
    for (int i = 0; i < idx; i++) {
        newArr[i] = array.arr[i];
    }
    for (int i = idx + 1; i < array.size; i++) {
        newArr[i - 1] = array.arr[i];
    }
    array.size--;
    delete[] array.arr;
    array.arr = newArr;
    return true;
}

bool removeFirstItemWithHP (Array& array, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    int i = 0;
    while (i < array.size && array.arr[i].HP != HP) {
        i++;
    }
    if (i == array.size) return 0;
    return removeAt(array, i);
}

void ensureCapacity(Array& array, int newCap){
    //Extend the capacity of the array
    //TODO
    return;
}

int indexOf(Array& array, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    for (int i = 0; i < array.size; i++) {
        if ((array.arr[i].HP == soldier.HP) && 
            (array.arr[i].ID == soldier.ID) && 
            (array.arr[i].isSpecial == soldier.isSpecial))
            return i;
    }
    return -1;
}

int size(Array& array){
    //Return size of the array
    //TODO
    return array.size; 
}

bool empty(Array& array){
    //Check whether the array is empty
    //TODO
    return !array.size;
}

string getIDAt(Array& array, int pos){
    //Get ID of the Soldier at pos
    //TODO
    if (pos < 0 || pos >= array.size) return "-1";
    return array.arr[pos].ID;
}

int getHPAt(Array& array, int pos){
    //Get HP of the Soldier at pos
    //TODO
    if (pos < 0 || pos >= array.size) return -1;
    return array.arr[pos].HP;
}

bool setHPAt(Array& array, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if (pos < 0 || pos >= array.size) return false;
    array.arr[pos].HP = HP;
    return true;
}

void clear(Array& array){
    //Delete all of the elements in array
    //TODO
    array.size = 0;
    array.capacity = 0;
    delete[] array.arr;
    array.arr = NULL;
}

bool contains (Array& array, Soldier soldier){
    //Check if array contains soldier
    //TODO
    if (indexOf(array, soldier) != -1) return true;
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* ArrayDataController_h */
