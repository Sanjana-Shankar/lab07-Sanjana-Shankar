# Makefile
##all: 
##game
##./games
##tests
##./tes.ts
	
	

examheap:examheap.cpp heap.cpp
	g++ --std=c++11 -Wall examheap.cpp heap.cpp -o examheap 

# -Wall: show all warnings 
#--std: Using C++11 notation 
#the complex is an executable file that is being created from complex.cpp and myprog.cpp 

clean:
	rm examheap

