//
//  Queue.cpp
//  scs202hw4
//
//  Created by Zeynep Büsra Ziyagil on 3.08.2021.
//

#include <stdio.h>
#include "Queue.h"
// default constructor
Queue::Queue():front(0), back(MAX_QUEUE-1), count(0){

}
bool Queue::isEmpty() const {

    return (count == 0);

}
bool Queue::enqueue(QueueItemType newItem) {
 
    if (count == MAX_QUEUE)
        return false;

    else{
        // queue is not full; insert item
        back = (back+1) % MAX_QUEUE;
        items[back] = newItem;
        ++count;

        return true;
    }

}
bool Queue::dequeue(){

    if (isEmpty())
        return false;

    else {
        // queue is not empty; remove front
        front = (front+1) % MAX_QUEUE;
        --count;

        return true;
    }

}
bool Queue::dequeue(QueueItemType& queueFront) {

    if (isEmpty())
        return false;

    else{
        // queue is not empty;
        // retrieve and remove front
        queueFront = items[front];
        front = (front+1) % MAX_QUEUE;
        --count;

        return true;
   }

}
bool Queue::getFront(QueueItemType& queueFront)const {

    if (isEmpty())
        return false;

    else{
        // queue is not empty; retrieve front
        queueFront = items[front];

        return true;
    }

}
