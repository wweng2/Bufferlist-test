#include "bufferlist.h"
#include "buffer.h"
/*
Name: Wei zhang weng
Date: 2/28/2021
Section: 5
email: wweng2@umbc.edu
Program name: bufferlist.cpp
Description: This program is used to make a bufferlist object that creates an linked list of the buffer object that has an array in each and such can let the user add and dequeue numbers
*/

BufferList::BufferList(int minBufCapacity){
  
    // **************************************
    // Implement the alternative constructor
    // **************************************
  if(minBufCapacity < 1){// If the user chosen one is less then 1 then use the default version
  m_cursor = new Buffer(DEFAULT_MIN_CAPACITY);
  m_listSize = 1;
  m_cursor->m_next = m_cursor;
  m_minBufCapacity = DEFAULT_MIN_CAPACITY;
  }
 else{
   m_cursor= new Buffer(minBufCapacity);
   m_listSize = 1;
   m_cursor->m_next = m_cursor;
   m_minBufCapacity = minBufCapacity;
   
   
 }

}
BufferList::~BufferList(){
    clear();
    
}

void BufferList::clear(){
    // *****************************
    // Implement clear() function
    // *****************************

  Buffer* old;
  if(m_listSize > 0){
 
    while(m_listSize != 0){
      old = m_cursor;
      m_cursor = m_cursor->m_next;
      if(old->m_capacity != 0){
	old->clear();
      }
      delete old;
      m_listSize --;
    }
  }

  
  else{
    cout<<"There is nothing to delete"<<endl;
  }
  
  m_listSize = 0;
  }

void BufferList::enqueue(const int& data) {
    // ****************************************************************************
    // Implement enqueue(...) function
    // we always insert at the back, that would be the cursor
    // if the current cursor is full we create a new node as cursor then we insert
    // ****************************************************************************
  try{// Does the eque and if something happens then , the exceotion will be cached
    m_cursor->enqueue(data);
  }
 
  catch(overflow_error &e){
    
    if (m_cursor->m_capacity * INCREASE_FACTOR < m_minBufCapacity * MAX_FACTOR ){
    
      m_cursor->m_next = new Buffer(m_minBufCapacity * INCREASE_FACTOR); 
  }
    else{
      m_cursor->m_next = new Buffer(m_minBufCapacity);
    }
    

    Buffer* next = m_cursor->m_next;
    m_cursor = m_cursor->m_next;
    m_cursor->m_next = next;
    m_listSize ++;
      
      }

  

}

int BufferList::dequeue() {
    // *****************************
    // Implement dequeue() function
      // *****************************
  Buffer *oldest = m_cursor->m_next;
  if(oldest->empty() != true){
     return oldest->dequeue();
  }
  else{
 try{
    oldest->dequeue();
   
  }
  catch(underflow_error &a){
    if(oldest->m_next != m_cursor){
    Buffer *SecondOldest = oldest->m_next;
    m_cursor->m_next = SecondOldest;// REplaces the m_next of oldest
    return SecondOldest->dequeue();// Ger rid of data here 
    oldest->clear();
    delete oldest;
    m_listSize --;
    }
    else{
      delete oldest;
      cout<<"This was the last one in the linked list nothing is left"<<endl;
      m_listSize --;
    }
  }
  }


}
BufferList::BufferList(const BufferList & rhs){
    // *******************************
    // Implement the copy constructor
    // *******************************
  m_cursor = rhs.m_cursor;
  m_listSize = rhs.m_listSize;

  Buffer* original = rhs.m_cursor;
  int count = m_listSize;

  while(count != 0){// Get the linked list in rhs and move up one on each thing to get the next thing
    m_cursor->m_next = original->m_next;
    m_cursor = m_cursor->m_next;
    original = original->m_next;
    count --;
  }


  

  
 }

const BufferList & BufferList::operator=(const BufferList & rhs){
    // ******************************
    // Implement assignment operator
    // ******************************
  if(this != &rhs){// Self assigment protection will no do nothing if it's self assigment
   
      clear();
    
    m_cursor = rhs.m_cursor;
    m_listSize = rhs.m_listSize;
    Buffer* original = rhs.m_cursor;
    
    int count = m_listSize;
  
    while(count != 0){// Copy the entire thing over
      m_cursor->m_next = original->m_next;
      m_cursor = m_cursor->m_next;
      original = original->m_next;
      count --;
    }
  }
  else{
    cout<<"This was self assigment and such didn't did do anything"<<endl;
  }

  return *this;





}

void BufferList::dump(){
    Buffer* temp = m_cursor->m_next;
    for(int i=0;i<m_listSize;i++){
        temp->dump();
        temp = temp->m_next;
        cout << endl;
    }
    cout << endl;
}

