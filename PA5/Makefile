all: main.o linkedList.o
	c++ -std=c++14 -g main.o linkedList.o -o run.out
main.o: main.cpp linkedList.cpp linkedList.h
	c++ -std=c++14 -c -g main.cpp
linkedList.o: linkedList.cpp linkedList.h
	c++ -std=c++14 -c -g linkedList.cpp
run:
	make all
	./run.out
clean:
	rm *.o run
