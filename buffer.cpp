#include "buffer.h"
/*
Name: Wei zhang weng
Date: 2/28/2021
Section: 5
email: wweng2@umbc.edu
Program name: buffer.cpp
Description: This program is used to make a buffer object that creates an array that allows for the user to store and delete items in the array
*/

Buffer::Buffer(int capacity){
    // **************************************
    // Implement the alternative constructor
    // No need to set m_next to nullptr, 
    // it will be handled by linked list,
    // because it is used by linked list
    // **************************************
  if(capacity < 1){// If the capacity used is less then 0 or negtaive then turn it to 0
    m_capacity = 0;
    cout<<"The capacity is zero and such nothing is allocated"<<endl;
    m_start = 0;
    m_end = 0;
    m_count = 0;
    m_buffer = nullptr;

  }
  else{
    m_capacity = capacity;  
    //Make an array nased on the user chosen size
    m_buffer = new int[m_capacity];
    m_start = 0;
    m_end = 0;
    m_count = 0;

  }


}

void Buffer::clear(){
    // ***********************************
    // Implement clear() function
    // No need to set m_next to nullptr, 
    // it will be handled by linked list,
    // because it is used by linked list
    // ***********************************
  if(m_capacity != 0){
    delete[] m_buffer;// Set everything to 0 and m_buffer ot nullptr for security reasons
    m_capacity = 0;
    m_count = 0;
    m_start = 0;
    m_end = 0;
    m_buffer = nullptr;
  }
  else{

    cout<<"This array is already empty and such nothing to clear"<<endl;
}
}
Buffer::~Buffer(){
    clear();
}

int Buffer::count(){return m_count;}

int Buffer::capacity(){return m_capacity;}

bool Buffer::full(){
    // **************************
    // Implement full() function
    // **************************
  if(m_count == m_capacity){// if the counts are equal to the capacity then return then its full
    return true;
  }
  else{
    return false;
  }
}

bool Buffer::empty(){
    // **************************
    // Implement empty() function
    // **************************
  if(m_count == 0){// If the m_count is 0 then nothing is in there and return true
    return true;
  }
  else{
    return false;
  }
}

void Buffer::enqueue(int data){
    // ********************************
    // Implement enqueue(...) function
    // ********************************
  if(full() != true){// If the array is not empty add the data to the end

    if(m_capacity!= 0){
      if(m_count  <  m_capacity){
	m_buffer[m_end] = data;
	m_count ++;
	  m_end++;
      }
      
      
    }
    else{
      cout<<"The array wan't maid and such nothing can be added"<<endl;
    }
  }
    else{
      throw overflow_error("This array is fulled");

    }
    
  
}
 
 int Buffer::dequeue(){
    // *****************************
    // Implement dequeue() function
    // *****************************
   if(empty() != true){
     
    int i = m_start;
    if(m_start + 1 > m_capacity){
      m_start ++;
    }
    m_start %= m_capacity;
    m_count --;
    return m_buffer[i];// prints out the deque data
   }
   else{
      throw underflow_error("This array is empty");
   }
  
 }

Buffer::Buffer(const Buffer & rhs){
    // *******************************
    // Implement the copy constructor
    // *******************************
  m_capacity = rhs.m_capacity;
  m_count = rhs.m_count;
  m_start = rhs.m_start;
  m_end = rhs.m_end;

  int i;
  if(m_capacity > 0){// When the capacity is not 0 and such anarray exist copy it
    m_buffer = new int[m_capacity];
    
  for(i = 0 ; i < m_count - 1; i++){
    m_buffer[i] = rhs.m_buffer[i];
  }
  }
 }

const Buffer & Buffer::operator=( const Buffer & rhs){
    // ******************************
    // Implement assignment operator
    // ******************************
  if(&rhs != this){

    clear();// Clear everything so that is an array exist but nothing is in it it will get rid of it

    m_capacity = rhs.m_capacity;
    m_count = rhs.m_count;
    m_start = rhs.m_start;
    m_end = rhs.m_end;
    
    int i;
    if(m_capacity > 0){
    m_buffer = new int[m_capacity];
    
    for(i = 0 ; i < m_count - 1; i++){
      m_buffer[i] = rhs.m_buffer[i];
    }
    }
  }
  else{
    cout<<"This is self assignment and such didn't work"<<endl;
  }
    return *this;
}

void Buffer::dump(){
    int start = m_start;
    int end = m_end;
    int counter = 0;
    cout << "Buffer size: " << m_capacity << " : ";
    if (!empty()){
        while(counter < m_count){
            cout << m_buffer[start] << "[" << start << "]" << " ";
            start = (start + 1) % m_capacity;
            counter++;
        }
        cout << endl;
    }
    else cout << "Buffer is empty!" << endl;
}
