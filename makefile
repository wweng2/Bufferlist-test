CXX = g++
CXXFLAGS = -Wall -g

mytest: buffer.o bufferlist.o mytest.cpp
	$(CXX) $(CXXFLAGS) buffer.o bufferlist.o mytest.cpp -o mytest

buffer.o: buffer.h buffer.cpp
	$(CXX) $(CXXFLAGS) -c buffer.cpp

bufferlist.o: bufferlist.h bufferlist.cpp
	$(CXX) $(CXXFLAGS) -c bufferlist.cpp


clean:
	rm *.o*
	rm *~


run:
	./mytest


val:
	valgrind ./mytest
