//
//  Queue.h
//  scs202hw4
//
//  Created by Zeynep Büsra Ziyagil on 3.08.2021.
//

#ifndef Queue_h
#define Queue_h
#include <string>
using namespace std;
const int MAX_QUEUE = 3747362;
typedef string QueueItemType;

class Queue{
public:
    Queue();  // default constructor
   // copy constructor and destructor are
   // supplied by the compiler

   // Queue operations:
   bool isEmpty() const;
   bool enqueue(QueueItemType newItem);
   bool dequeue();
   bool dequeue(QueueItemType& queueFront);
   bool getFront(QueueItemType& queueFront) const;

private:
  
   QueueItemType items[MAX_QUEUE];
   int           front;
   int           back;
   int           count;

};

#endif /* Queue_h */
