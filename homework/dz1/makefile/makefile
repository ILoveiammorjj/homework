all: hello

hello: main.o poww.o hello.o
	g++ main.o poww.o hello.o -o hello

main.o: main.cpp
	g++ -c main.cpp

poww.o: poww.cpp
	g++ -c poww.cpp

hello.o: hello.cpp
	g++ -c hello.cpp

clean:
	rm -rf *.o hello
