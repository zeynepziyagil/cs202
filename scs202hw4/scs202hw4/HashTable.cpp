//
//  HashTable.cpp
//  scs202hw4
//
//  Created by Zeynep Büsra Ziyagil on 3.08.2021.
//

#include <stdio.h>

#include "HashTable.h"
#include <iostream>
#include <string>

using namespace std;


/* Hash the given food item to an index in which
*  the item is supposed to be placed in arr
*/
int HashTable::hash(string &itemName) {
    int hashVal = 0;

    for (int i = 0; i < itemName.length(); i++)
        hashVal = 37 * hashVal + itemName[i];

    hashVal %= 11;

    if (hashVal < 0)
        hashVal += 11;
    
    return hashVal;
}

void HashTable::insert(string itemName, int amount) {
    if (size >= 11) { 
        cout<<"Table already full, cannot insert element."<<endl;
        return;
    }
    //find the index to insert item.
    int insertIndex = hash(itemName);

    if (occupied[insertIndex] || deleted[insertIndex]) {
        if (arr[insertIndex].getName() == itemName) {
            cout<<"Item already on table."<<endl;
            return;
        }
        //do probing & set insertIndex to new insertIndex
        //insert in the proper place & return from .
        int newIndex = (insertIndex + 1) % 11;
        for (int i = 2; (newIndex != insertIndex) && (isOccupied(newIndex) || isDeleted(newIndex)); i++) {
            newIndex = (insertIndex + i * i) % 11;
        }
        if (newIndex == insertIndex) {
            cout<<"Table is full, cannot insert element."<<endl;
            return;
        }
        //insert into newIndex
        occupied[newIndex] = true;
        deleted[newIndex] = false;
        arr[newIndex] = FoodItem(itemName, amount);
    } else {
        //if we come here then the index is freely available so we
        //put it in its corresponding place
        occupied[insertIndex] = true;
        deleted[insertIndex] = false;
        arr[insertIndex] = FoodItem(itemName, amount);
        size++;
    }
}

void HashTable::deleteItem(string itemName) {
    //find index of item in table
    int index = hash(itemName);
    if (occupied[index]) {
        deleted[index] = true;
        occupied[index] = false;
        size--;
    } else {
        cout<<"Item not on the list, cannot be deleted."<<endl;
    }
}

void HashTable::findItem(string itemName) {
    //first find index of item
    int index = hash(itemName);

    if (isOccupied(index)) {
        if (arr[index].getName() == itemName) {
            cout<<"Item found. Name: "<<arr[index].getName();
            cout<<" - Count: "<<arr[index].getAmount()<<endl;
        } else {
            //look for item via probing.
        }
    }
    
    //check if deleted
    if (isDeleted(index)) {
        //look for item via probing
    }
    //guess we're done?
}

void HashTable::printTable() {
    for (int i = 0; i < 11; i++) {
        cout<<i<<": ";
        if (occupied[i]) {
            cout<<arr[i].getName()<<" = "<<arr[i].getAmount()<<endl;
        } else {
            cout<<"-"<<endl;
        }
    }
}
HashTable::HashTable(){
  for (int i = 0; i < SIZE; i++)
    hashlist[i] = nullptr;
}


HashTable::~HashTable(){
  Node* temp;
  for (int i = 0; i < SIZE; i++){
    while(hashlist[i]){
      temp = hashlist[i];
      hashlist[i] = hashlist[i]->next;
      delete temp;
    }
  }
}


int HashTable::hash(const string &key, int tableSize)
{
       int hashVal = 0;
        
       for (int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + key[i];
       hashVal %=tableSize;
       if (hashVal < 0)   /* in case overflows occurs */
        hashVal += tableSize;

       return hashVal;
}

void HashTable::insert(string key, int value){
  int hashKey = hash(key,SIZE);
  Node* newNode = new Node;
  newNode->value = value;
  newNode->key = key;
  newNode->next = hashlist[hashKey];
  hashlist[hashKey] = newNode;
}
 

int HashTable::retrieve(string key){
  int val = hash(key,SIZE);
  int indexx =-1;
  Node* temp = hashlist[val];
  bool found = false;
  while(temp && !found){
    if (temp->key == key){
        indexx= temp->value;
      found = true;
    }
    temp = temp->next;
  }
    return indexx;
}

string HashTable::getFromValue(int index){
    
    Node* temp;
    string str= "";
    bool found = false;
    for (int i = 0; i < SIZE; i++){
        temp = hashlist[i];
        while(temp && !found){
            if (temp->value == index){
                str = temp->key;
              found = true;
            }
        temp = temp->next;
      }
        if(found){break;}
    }
    return str;
}

