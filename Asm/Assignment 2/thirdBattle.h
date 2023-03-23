//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array& array, Soldier soldier){
    //Return true if push successfully, false otherwise
    //TODO
    return insertAt(array, soldier, array.size);
}

bool pop(Array& array){
    //Return true if pop successfully, false otherwise
    //TODO
    return removeAt(array, array.size - 1);
}

Soldier top(Array& array){
    //TODO
    if (array.arr == NULL) return Soldier();//return this if cannot get top
    return array.arr[array.size - 1];
}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier){
    //Return true if enqueue successfully, false otherwise
    //TODO
    return insertAt(list, soldier, list.size);
}

bool dequeue(SLinkedList& list){
    //Return true if dequeue successfully, false otherwise
    //TODO
    return removeAt(list,0);
}

Soldier front(SLinkedList& list){
    //TODO
    if (list.size == 0) return Soldier();//Return this if cannot get front
    return list.head->data;
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list){
    //TODO
    SoldierNode* newLs = NULL;
    int size = list.size;
    while (list.size != 0) {
        SoldierNode* newElement = new SoldierNode(list.head->data, newLs);
        newLs = newElement;
        dequeue(list);
    }
    list.head = newLs;
    list.size = size;
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////
template<class T>
void Swap(T& A, T& B) {
    T tmp = A;
    A = B;
    B = tmp;
}

SLinkedList merge(SLinkedList& list1, SLinkedList& list2){
    //TODO
    for (SoldierNode* i = list1.head; i->next != NULL; i = i->next) {
        SoldierNode* smallNode = i;
        for (SoldierNode* j = i->next; j != NULL; j = j->next) {
            if ((j->data.HP < smallNode->data.HP) ||
                j->data.HP == smallNode->data.HP && (j->data.isSpecial == false && smallNode->data.HP == true ||
                    (j->data.isSpecial == smallNode->data.HP && j->data.ID[0] < smallNode->data.ID[0]))) {
                smallNode = j;
            }
        }
        if (smallNode != i) {
            Swap<Soldier>(smallNode->data, i->data);
        }
    }

    for (SoldierNode* i = list2.head; i->next != NULL; i = i->next) {
        SoldierNode* smallNode = i;
        for (SoldierNode* j = i->next; j != NULL; j = j->next) {
            if ((j->data.HP < smallNode->data.HP) ||
                j->data.HP == smallNode->data.HP && (j->data.isSpecial == false && smallNode->data.HP == true ||
                                                    (j->data.isSpecial == smallNode->data.HP && j->data.ID[0] < smallNode->data.ID[0]))) {
                smallNode = j;
            }
        }
        if (smallNode != i) {
            Swap<Soldier>(smallNode->data, i->data);
        }
    }

    SLinkedList newSLL;
    SoldierNode* i = list1.head;
    SoldierNode* j = list2.head;
    while (i != NULL && j != NULL) {
        if ((j->data.HP < i->data.HP) ||
            j->data.HP == i->data.HP && (j->data.isSpecial == false && i->data.HP == true ||
                                         (j->data.isSpecial == i->data.HP && j->data.ID[0] < i->data.ID[0]))) {
            enqueue(newSLL, j->data);
            j = j->next;
        }
        else {
            enqueue(newSLL, i->data);
            i = i->next;
        }
    }

    while (i != NULL) {
        enqueue(newSLL, i->data);
        i = i->next;
    }
    while (j != NULL) {
        enqueue(newSLL, j->data);
        j = j->next;
    }
    return newSLL;
}

//You can write your own functions here

//End your own functions

#endif /* thirdBattle_h */
