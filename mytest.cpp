/*
Name: Wei zhang weng
Date: 2/28/2021
Section: 5
email: wweng2@umbc.edu
Program name: mytest.cpp
Description: This program is used to the buffer class and the bufferlist class
*/
#include "buffer.h"
#include "bufferlist.h"
class Tester{
    public:
  bool BufferEnqueueDequeue(Buffer &buffer, int dataCount);
  bool BufferEnqueueFull(int size);
  bool BufferDequeueEmpty(int size);
  bool BufferCopyConstructor(const Buffer &buffer);
  void BufferEnqueuePerformance(int numTrials, int N);
  bool BufferContructorTest(int capacity);
  bool BufferAssigmentOpertor(const Buffer &buffer);
  bool BufferTestClear(int size, int datacount);
  bool BufferTestFull(int size, int dataCount);
  bool BufferTestEmpty(int size, int dataCount);

  // Bufferlist testing functions
  bool BufferListEnqueueDequeue(int dataCount);
  bool BufferListEnqueueFull(int size);
  bool BufferListDequeueEmpty(int size);
  bool BufferListCopyConstructor(const BufferList &bufferlist);
  void BufferListEnqueuePerformance(int numTrials, int N);
  bool BufferListContructorTest(int capacity);
  bool BufferListAssigmentOpertor(BufferList &bufferlist);
  bool BufferListTestClear(int size, int Nodes);


};
int main(){
    Tester tester;
    int bufferSize = 1000;
    Buffer buffer(bufferSize);
    BufferList bufferList(bufferSize);
    cout<<"Testing the Buffer class "<<endl;
    {// Testing the constructor
      cout<<"Testing the contructor"<<endl;
      // test tosee if it workings fine naturally
      cout<<"Testing the contrucotor in normal circumstances with a regular, non zero number"<<endl;
      if(tester.BufferContructorTest(bufferSize)){
	cout<<"Test passed"<<endl;
      }
      else{
	cout<<"Test failed"<<endl;
      }
    }
    {
	cout<<"Testing the zero put into the contrucotr to see if an array is made"<<endl;
	if(tester.BufferContructorTest(0)){
	  cout<<"Test passed"<<endl;
	}
	else{
	  cout<<"Test failed an array was made"<<endl;
	}
    }
    {
	cout<<"Testing the case of a negative number, checking to make sure it get turn into 0 and no array is made"<<endl;
	int negNum = -45;
	if(tester.BufferContructorTest(negNum)){
          cout<<"Test Passed"<<endl;
        }
        else{
          cout<<"Test failed an array was made "<<endl;
        }
    }
    
      
      cout<<"Now testing the enqueue and dequeue at the same time"<<endl;
    {
        //testing insertion/removal for 1 data item
        cout << "\nTest case: Buffer class: Inserting/removing 1 data item:\n";
        if (tester.BufferEnqueueDequeue(buffer, 1))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing insertion/removal for half data size
        cout << "\nTest case: Buffer class: Inserting/removing half data size:\n";
        if (tester.BufferEnqueueDequeue(buffer, bufferSize/2))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing insertion/removal for full data size
        cout << "\nTest case: Buffer class: Inserting/removing full data size:\n";
        if (tester.BufferEnqueueDequeue(buffer, bufferSize))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing insertion in a full buffer
        cout << "\nTest case: Buffer class: Throwing exception while inserting in full buffer:\n";
        if (tester.BufferEnqueueFull(1000))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
      //testing deletion in a empty queue
      cout << "\nTest case: Buffer class: Throwing exception while deleting when the array is empty"<<endl;
        if (tester.BufferDequeueEmpty(10))
	  cout << "\tTest passed!\n";
        else
	  cout << "\tTest failed!\n";
    }
       
        {
	  //Measuring the efficiency of insertion functionality
	  cout << "\nMeasuring the efficiency of insertion functionality:" << endl;
	  int M = 5;//number of trials
	  int N = 10;//original input size
	  tester.BufferEnqueuePerformance(M, N);
    }


    cout<<"Testing the copy constructor now"<<endl;
    {
      cout<<"Testing the normal function of the copy contrucotr"<<endl;
      // This will only return true is the constructor works and the copy is a deep copy
      Buffer buffer(100);
        if (tester.BufferCopyConstructor(buffer))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";

    }
    cout<<"Testing edge cases now"<<endl;
    {// Testing to see the edge case of empty array
      Buffer buffer(0);
      if (tester.BufferCopyConstructor(buffer))
	  cout << "\tTest passed!\n";
      else
	cout << "\tTest failed!\n";
    }
    // Testing to see the edge case of only one item in the array
    {  Buffer buffer(1);
        if (tester.BufferCopyConstructor(buffer))
	  cout << "\tTest passed!\n";
        else
	  cout << "\tTest failed!\n";
	
    }	
    {
        //testing Buffer class copy constructor with buffer size less than zero
        cout << "\nTest case: Buffer class: Copy constructor, negative buffer size:\n";
        Buffer buffer(-10);
        if (tester.BufferCopyConstructor(buffer))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    
    
    cout<<"Testing the Assigment operator now"<<endl;
    {
      cout<<"Testing the normal function of the assigment opertor"<<endl;
      // This will only return true is the constructor works and the copy is a deep copy
      Buffer buffer(1000);
      if (tester.BufferAssigmentOpertor(buffer)){
      cout << "\tTest passed!\n";
      }
      else{
	  cout << "\tTest failed!\n";
      }
    }
    cout<<"Testing edge cases now"<<endl;
    {// Testing to see the edge case of empty array
      Buffer buffer(0);
      if (tester.BufferAssigmentOpertor(buffer)){
	  
	
	cout << "\tTest passed!\n";
      }
      else{
	cout << "\tTest failed!\n";
      }
    }
    // Testing to see the edge case of only one item in the array
    {  Buffer buffer(1);
        if (tester.BufferAssigmentOpertor(buffer)){

          cout << "\tTest passed!\n";
	}
        else{
          cout << "\tTest failed!\n";
	}

    {
        //testing Buffer class copy constructor with buffer size less than zero
      cout << "\nTest case: Assgiment opertor assigment of a negative number"<<endl;
        Buffer buffer(-10);
        if (tester.BufferAssigmentOpertor(buffer)){

            cout << "\tTest passed!\n";
	}
        else{
            cout << "\tTest failed!\n";
	}
	}
    cout<<"Testing self assigment"<<endl;
    {
      Buffer buffer(10);

      buffer = buffer;
      cout<<"Expected out put: This is self assigment and such didn't work"<<endl;
    }
    
    cout<<"Testing the full function of buffer"<<endl;
    {
      int DefaultSize = 10;
      // Testing the full on a empty array
      if(tester.BufferTestFull(DefaultSize,0)){
	  cout<<"Test Pass on an empty array"<<endl;
	}
	else{
	  cout<<"Failed "<<endl;
	}
    	
    // Testing the full on an array with one thing in array
      if(tester.BufferTestFull(DefaultSize,1)){
	cout<<"Test Pass "<<endl;
        }
        else{
          cout<<"Failed "<<endl;
        }
      
	
      
    
        // Testing the full on an full aray
	  if(tester.BufferTestFull(DefaultSize,DefaultSize)){
	    cout<<"Test Pass "<<endl;
	  }
	  else{
	    cout<<"Failed "<<endl;
        }
	  
    }
    }
	

	cout<<"Testing the empty function now"<<endl;

	{
      int DefaultSize = 10;
      // Testing the empty on a empty array
      if(tester.BufferTestEmpty(DefaultSize,0)){
          cout<<"Test Pass on an empty array"<<endl;
        }
        else{
          cout<<"Failed "<<endl;
        }
        
    // Testing the empty on an array with one thing in array
      if(tester.BufferTestEmpty(DefaultSize,1)){
          cout<<"Test Pass on an empty array"<<endl;
        }
        else{
          cout<<"Failed "<<endl;
        }


      

        // Testing the empty on an full aray
          if(tester.BufferTestEmpty(DefaultSize,DefaultSize)){
            cout<<"Test Pass on an empty array"<<endl;
          }
          else{
            cout<<"Failed "<<endl;
        }


	    }
	    {
	cout<<"Testing the clear function now"<<endl;
	// Testing clear to see if it deletes everything in a full array
	  int DefualtBufferSize = 10;

	  if(tester.BufferTestClear(DefualtBufferSize,DefualtBufferSize)){
	    cout<<"Tested passed"<<endl;
	  }
	  else{
	    cout<<"Tested failed"<<endl;
	  }   
	 // Testing clear on a array with nothing in it
	
	
	if(tester.BufferTestClear(DefualtBufferSize,0)){
          cout<<"Test Pass on an empty array"<<endl;
        }
        else{
          cout<<"Failed "<<endl;
        }
        
    // Testing clear on an array with one thing in array
      if(tester.BufferTestClear(DefualtBufferSize,1)){
          cout<<"Test Pass on an empty array"<<endl;
        }
        else{
          cout<<"Failed "<<endl;
        }


	    }
	    
    {
        //an example of BufferList::dump()
        cout << "\nHere is an example of a linked list:" << endl;
        BufferList bufferList(5);
        for (int i=40;i>0;i--)
	  bufferList.enqueue(i);
        bufferList.dump();
    }
          
          
        cout<<"Testing the BufferList class "<<endl;
    {// Testing the constructor
      
      cout<<"Testing the contructor"<<endl;
      // test tosee if it workings fine naturally
      cout<<"Testing the contrucotor in normal circumstances with a regular, non zero number"<<endl;
      if(tester.BufferListContructorTest(bufferSize)){
        cout<<"Test passed"<<endl;
      }
      else{
        cout<<"Test failed"<<endl;
      }
    }
    {
        cout<<"Testing the zero put into the contrucotr to see if an array is made"<<endl;
        if(tester.BufferListContructorTest(0)){
          cout<<"Test passed"<<endl;
        }
        else{
          cout<<"Test failed an array was made"<<endl;
        }
    }
    {
        cout<<"Testing the case of a negative number, checking to make sure it get turn into 0 and no array is made"<<endl;
        int negNum = -45;
        if(tester.BufferListContructorTest(negNum)){
          cout<<"Test Passed"<<endl;
        }
        else{
          cout<<"Test failed an array was made "<<endl;
        }
    }

      cout<<"Now testing the enqueue and dequeue at the same time"<<endl;
      {

        //testing insertion/removal for 1 data item
        cout << "\nTest case: Buffer class: Inserting/removing 1 data item:\n";
        if (tester.BufferListEnqueueDequeue(1))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
      }
    {
        //testing insertion/removal for half data size
        cout << "\nTest case: Buffer class: Inserting/removing half data size:\n";
        if (tester.BufferListEnqueueDequeue(bufferSize/2))

	cout << "\tTest passed!\n";
	else
	  cout << "\tTest failed!\n";
	
    }
    {
        //testing insertion/removal for full data size
      cout << "\nTest case: Buffer class: Inserting/removing full data size:\n";
      if (tester.BufferListEnqueueDequeue( bufferSize))
            cout << "\tTest passed!\n";
        else
	  cout << "\tTest failed!\n";
    }
    {
        //testing insertion in a full buffer
      cout << "\nTest case: Buffer class: Throwing exception while inserting in full buffer:\n";
      if (tester.BufferListEnqueueFull(1000))
	cout << "\tTest passed!\n";
      else
            cout << "\tTest failed!\n";
    }
    {
      //testing deletion in a empty queue
      cout << "\nTest case: Buffer class: Throwing exception while deleting when the array is empty"<<endl;
        if (tester.BufferListDequeueEmpty(10))
          cout << "\tTest passed!\n";
        else
          cout << "\tTest failed!\n";
    }

        {
          //Measuring the efficiency of insertion functionality
          cout << "\nMeasuring the efficiency of insertion functionality:" << endl;
          int M = 5;//number of trials
          int N = 10;//original input size
          tester.BufferListEnqueuePerformance(M, N);
    }

	
    cout<<"Testing the copy constructor now"<<endl;
    {
      BufferList bufferList(10);

      cout<<"Testing the normal function of the copy contrucotr"<<endl;
      // This will only return true is the constructor works and the copy is a deep copy


        if (tester.BufferListCopyConstructor(bufferList))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";

    }
    
    cout<<"Testing edge cases now"<<endl;
    {// Testing to see the edge case of empty array
      BufferList bufferList(0);
      if (tester.BufferListCopyConstructor(bufferList))
          cout << "\tTest passed!\n";
      else
        cout << "\tTest failed!\n";
    }
    // Testing to see the edge case of only one item in the array
    {  BufferList bufferlist(1);
        if (tester.BufferListCopyConstructor(bufferlist))
          cout << "\tTest passed!\n";
        else
          cout << "\tTest failed!\n";

    }
    {
        //testing Buffer class copy constructor with buffer size less than zero
        cout << "\nTest case: Buffer class: Copy constructor, negative buffer size:\n";
        BufferList bufferList(-10);
        if (tester.BufferListCopyConstructor(bufferList))
            cout << "\tTest passed!\n";
        else
	  cout << "\tTest failed!\n";
    }

    
    cout<<"Testing the Assigment operator now"<<endl;
    {
      cout<<"Testing the normal function of the assigment opertor"<<endl;
      // This will only return true is the constructor works and the copy is a deep copy
      BufferList bufferList(1000);
      if (tester.BufferListAssigmentOpertor(bufferList)){
      cout << "\tTest passed!\n";
      }
      else{
          cout << "\tTest failed!\n";
      }
    }
    cout<<"Testing edge cases now"<<endl;

    cout<<"Testing edge cases now"<<endl;
    {// Testing to see the edge case of empty array
      BufferList bufferList(0);
      if (tester.BufferListAssigmentOpertor(bufferList)){


        cout << "\tTest passed!\n";
      }
      else{
        cout << "\tTest failed!\n";
      }
    }
    // Testing to see the edge case of only one item in the array
    {  BufferList bufferList(1);
        if (tester.BufferListAssigmentOpertor(bufferList)){

          cout << "\tTest passed!\n";
        }
        else{
          cout << "\tTest failed!\n";
        }

    {
        //testing Buffer class copy constructor with buffer size less than zero
      cout << "\nTest case: Assgiment opertor assigment of a negative number"<<endl;
        BufferList bufferList(-10);
        if (tester.BufferListAssigmentOpertor(bufferList)){

            cout << "\tTest passed!\n";
        }
        else{
            cout << "\tTest failed!\n";
        }
        }
    cout<<"Testing self assigment"<<endl;
    {
      BufferList bufferList(10);

      bufferList = bufferList;
      cout<<"Expected out put: This is self assigment and such didn't work"<<endl;
    }
            {
	    cout<<"Testing the clear function now"<<endl;
        // Testing clear to see if it deletes everything in a full array
	int DefualtBufferSize = 10;
	
	if(tester.BufferListTestClear(DefualtBufferSize,DefualtBufferSize)){
	cout<<"Tested passed"<<endl;
          }
          else{
	  cout<<"Tested failed"<<endl;
          }
	  // Testing clear on a array with nothing in it
	  
	  
        if(tester.BufferListTestClear(DefualtBufferSize,0)){
	cout<<"Test Pass on an empty array"<<endl;
        }
        else{
	cout<<"Failed "<<endl;
        }
	
	// Testing clear on an array with one thing in array
	if(tester.BufferListTestClear(DefualtBufferSize,1)){
	cout<<"Test Pass on an empty array"<<endl;
        }
        else{
          cout<<"Failed "<<endl;
	  }

	  }
    
	    return 0;
}
}
bool Tester::BufferContructorTest(int capacity){
  Buffer TestBuffer(capacity);
  if(capacity < 0 && TestBuffer.m_capacity == 0 ){
    return true;
  }
  else if(TestBuffer.m_capacity == capacity){
    return true;
  }
  else{
    return false;
  }
}
bool Tester::BufferEnqueueDequeue(Buffer &buffer, int dataCount){
 
  for(int i = 0 ; i < dataCount ; i ++){
    buffer.enqueue(1);
  }
  if(buffer.m_count == dataCount){
    for(int i = 0; i < dataCount ; i ++){
      buffer.dequeue();
    }
  
    if(buffer.m_count == 0){
      return true;
    }
    else{
      return false;
    }
    }
     else{
    return false;
  }
    
}
bool Tester::BufferDequeueEmpty(int size){
    Buffer aBuffer(size);
    try{
        //trying to insert in a full buffer
        aBuffer.dequeue();
    }
    catch(underflow_error &e){
        //the exception that we expect
        return true;
    }
    catch(...){
        //any other exception, this case is not acceptable
        return false;
    }
    //no exception thrown, this case is not acceptable
    return false;


}

bool Tester::BufferEnqueueFull(int size){
    Buffer aBuffer(size);
    for (int i=0;i<size;i++)
        aBuffer.enqueue(i);
    try{
        //trying to insert in a full buffer
        aBuffer.enqueue(size+1);
    }
    catch(overflow_error &e){
        //the exception that we expect
        return true;
    }
    catch(...){
        //any other exception, this case is not acceptable
        return false;
    }
    //no exception thrown, this case is not acceptable
    return false;

}
void Tester::BufferEnqueuePerformance(int numTrials, int N){
   const int a = 2;//scaling factor for input size
   double T = 0.0;//to store running times
   clock_t start, stop;//stores the clock ticks while running the program
  
   
   for (int k=0;k<numTrials-1;k++)
     {
       Buffer Abuffer(N);

        start = clock();

	Abuffer.enqueue(N);
	//the algorithm to be analyzed for efficiency
        stop = clock();
        T = stop - start;//number of clock ticks the algorithm took
        cout << "Inserting " << N * N << " members took " << T << " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;
        N = N * a;//increase the input size by the scaling factor
	Abuffer.clear();
     }
}
bool Tester::BufferCopyConstructor(const Buffer &buffer){
     Buffer copy(buffer);
    //the case of empty object
     if (buffer.m_count == 0 && copy.m_count == 0){ return true;
     }
    //the case that sizes are the same and the table pointers are not the same
    else if (buffer.m_count == copy.m_count && buffer.m_buffer != copy.m_buffer){
        for (int i=0;i<buffer.m_count;i++){
                if ((buffer.m_buffer[i] != copy.m_buffer[i]) || //check the value
                    (buffer.m_buffer[i] == copy.m_buffer[i])){        //check the ith pointer
                    return false;
                }
	}
    
        return true;
    }
    //everthing else
    else return false;
}


bool Tester::BufferAssigmentOpertor(const Buffer &buffer){
  Buffer copy(1);

  copy = buffer;
  
  //the case of empty object
     if (buffer.m_count == 0 && copy.m_count == 0){ return true;
     }
     //the case that sizes are the same and the table pointers are not the same
     else if (buffer.m_count == copy.m_count && buffer.m_buffer != copy.m_buffer){
       for (int i=0;i<buffer.m_count;i++){
	 if ((buffer.m_buffer[i] != copy.m_buffer[i]) || //check the value
                    (buffer.m_buffer[i] == copy.m_buffer[i])){        //check the ith pointer
	   return false;
	 }
       }
       
       return true;
     }
     //everthing else
    else return false;
     
     
}
bool Tester::BufferTestClear(int size,int datacount){
  Buffer aBuffer(size);
  for(int i = 0; i < datacount; i++){
    aBuffer.enqueue(i);
  }

  aBuffer.clear();
  if(aBuffer.m_count == 0){
    return true;
  }
  else{
    return false;
  }
}
bool Tester::BufferTestFull(int size, int dataCount){
  Buffer aBuffer(size);
  for(int i = 0; i < dataCount ; i++){
    aBuffer.enqueue(i);
  }

  if(dataCount == size){
    if(aBuffer.full()){
    return true;
    }
    else{
      return false;
	}
  }
  else if (dataCount != size){
    if(aBuffer.full() == false){
    return true;
    }
    else{
      return false;
        }
  }

  else{
    return false;
  }
}
bool Tester::BufferTestEmpty(int size, int dataCount){
    Buffer aBuffer(size);
    for(int i = 0; i < dataCount; i++){
    aBuffer.enqueue(i);
  }
    if( dataCount == 0){
      if(aBuffer.empty() != true){
	return false;
      }
      else{
	return true;
      }
    }
    else{
      if(aBuffer.empty() != false){
	  return false;
	}
	else{
	  return true;
	}
	
	}
}
 
// The function implmentation of the bufferlist
bool Tester::BufferListContructorTest(int capacity){
  BufferList TestBufferList(capacity);
  if(capacity < 1 && TestBufferList.m_minBufCapacity == capacity ){
    return false;
  }
  else if(TestBufferList.m_minBufCapacity  == capacity){
    return true;
  }
  else if( TestBufferList.m_minBufCapacity > capacity ){
    return true;
  }
  else{
    return false;
  }
}
 bool Tester::BufferListEnqueueDequeue(int datacount){

   BufferList bufferList(datacount);
  for(int i = 0 ; i < datacount ; i ++){
    bufferList.enqueue(1);
  }
  if(bufferList.m_cursor->m_count == datacount){
    for(int i = 0; i < datacount ; i ++){
      if(bufferList.dequeue() != i){
	return false;
      }
    }
    if(bufferList.m_cursor->m_count == 0){
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }


}
bool Tester::BufferListDequeueEmpty(int size){
    BufferList aBuffer(size);
    try{
        //trying to insert in a empty buffer
        aBuffer.dequeue();
    }
    catch(underflow_error &e){
        //the exception that we expect
        return false;
    }
    catch(...){
        //any other exception, this case is not acceptable
        return false;
	}
	return true;
 
}

bool Tester::BufferListEnqueueFull(int size){
    BufferList aBuffer(size);
    for (int i=0;i<size;i++)
        aBuffer.enqueue(i);
    try{
        //trying to insert in a full buffer
        aBuffer.enqueue(size+1);
    }
    catch(overflow_error &e){
        //the exception that we expect
        return false;
    }
    catch(...){
        //any other exception, this case is not acceptable
        return false;
    }
    //no exception thrown, this case is not acceptable
    return true;
}

void Tester::BufferListEnqueuePerformance(int numTrials, int N){
   const int a = 2;//scaling factor for input size
   double T = 0.0;//to store running times
   clock_t start, stop;//stores the clock ticks while running the program


   for (int k=0;k<numTrials-1;k++)
     {
       BufferList Abuffer(N);

        start = clock();

        Abuffer.enqueue(N);
        //the algorithm to be analyzed for efficiency
        stop = clock();
        T = stop - start;//number of clock ticks the algorithm took
        cout << "Inserting " << N << " members took " << T << " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;
        N = N * a;//increase the input size by the scaling factor
        Abuffer.clear();
     }
}
bool Tester::BufferListCopyConstructor(const BufferList &bufferList){
     BufferList copy(bufferList);
        //the case of empty object
     if (bufferList.m_listSize == 0 && copy.m_listSize == 0){ return true;
     }
    //the case that sizes are the same and the table pointers are not the same
    else if (bufferList.m_listSize == copy.m_listSize && bufferList.m_cursor != copy.m_cursor){
        for (int i=0;i<bufferList.m_listSize;i++){
                if (bufferList.m_cursor != copy.m_cursor || //check the value
                    bufferList.m_cursor->m_buffer[i] == copy.m_cursor->m_buffer[i]){        //check the ith pointer
                    return false;
                
        }

    }

        return true;
    }
    //everthing else
 else {return false;
 }
}


bool Tester::BufferListAssigmentOpertor(BufferList &bufferList){
 BufferList copy(1);

  copy = bufferList;

  if(copy.m_listSize == 0 && bufferList.m_listSize == 0){
  return true;
  }
  else{
    
    copy.clear();
  }
    try{
      bufferList.dequeue();

  }
  catch(underflow_error &e){
        //the exception that we expect
        return false;
	}
	catch(...){
        //any other exception, this case is not acceptable
        return false;
        }
        return true;

	}

  
  
  

bool Tester::BufferListTestClear(int size,int datacount){
  BufferList aBuffer(size);
  for(int i = 0; i < datacount; i++){
    aBuffer.enqueue(i);
  }

  aBuffer.clear();
  if(aBuffer.m_listSize == 0){
    
    return true;
  }
  else{
    return false;
  }
}

