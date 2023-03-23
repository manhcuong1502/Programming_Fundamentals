//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Singly Linked List
void print(SLinkedList& list){
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head){
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL"<<endl;
}

bool insertAt (SLinkedList& list, Soldier element, int pos){
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise
    //TODO
    if (pos < 0 || pos > list.size) return false;
    if (pos == 0) {
        SoldierNode* newElement = new SoldierNode(element, list.head);
        list.head = newElement;
    }
    else {
        SoldierNode* tmp = list.head;
        while (pos != 1) {
            tmp = tmp->next;
            pos--;
        }
        SoldierNode* newElement = new SoldierNode(element, tmp->next);
        tmp->next = newElement;
    }
    list.size++;
    return true;
}

bool removeAt (SLinkedList& list, int idx){
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO
    if (idx < 0 || idx >= list.size) return false;
    if (idx == 0) {
        SoldierNode* tmp = list.head;
        list.head = list.head->next;
        delete tmp;
    }
    else {
        SoldierNode* tmp = list.head;
        while (idx != 1) {
            tmp = tmp->next;
            idx--;
        }
        SoldierNode* del = tmp->next;
        tmp->next = del->next;
        delete del;
    }
    list.size--;
    return true;
}

bool removeFirstItemWithHP (SLinkedList& list, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    int pos = 0;
    SoldierNode* tmp = list.head;
    while (pos < list.size && tmp->data.HP == HP) {
        pos++;
        tmp = tmp->next;
    }
    if (pos == list.size) return false;
    removeAt(list, pos);
    return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    int idx = 0;
    SoldierNode* tmp = list.head;
    while (tmp != NULL) {
        if (tmp->data.HP == soldier.HP &&
            tmp->data.ID == soldier.ID &&
            tmp->data.isSpecial == soldier.isSpecial)
            return idx;
        idx++;
        tmp = tmp->next;
    }
    return -1;
}

int size(SLinkedList& list){
    //Return size of the list
    //TODO
    return list.size;
}

bool empty(SLinkedList& list){
    //Check whether the list is empty
    //TODO
    return !list.size;
}

void clear(SLinkedList& list){
    //Delete all of the elements in list
    //TODO
    do {
        SoldierNode* tmp = list.head;
        list.head = tmp->next;
        delete tmp;
        list.size--;
    } while (list.size != 0);
}

string getIDAt(SLinkedList& list, int pos){
    //Get ID of the Soldier at pos
    //TODO
    if (pos < 0 || pos >= list.size) return "-1";
    SoldierNode* tmp = list.head;
    while (pos != 0) {
        tmp = tmp->next;
        pos--;
    }
    return tmp->data.ID;
}

int getHPAt(SLinkedList& list, int pos){
    //Get HP of the Soldier at pos
    //TODO
    if (pos < 0 || pos >= list.size) return -1;
    SoldierNode* tmp = list.head;
    while (pos != 0) {
        tmp = tmp->next;
        pos--;
    }
    return tmp->data.HP;
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if (pos < 0 || pos >= list.size) return false;
    SoldierNode* tmp = list.head;
    while (pos != 0) {
        tmp = tmp->next;
        pos--;
    }
    tmp->data.HP = HP;
    return true;
}

bool contains (SLinkedList& list, Soldier soldier){
    //Check if array contains soldier
    //TODO
    if (indexOf(list, soldier) != -1) return true;
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */
