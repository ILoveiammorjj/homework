OPT=g++ -c -std=gnu++11 -O0 -Wall -Wextra
all: main.o set.o operators.o
	g++ main.o set.o operators.o -o main.exe
main.o: main.cpp set.h operators.h
	$(OPT) main.cpp -o main.o
set.o: set.cpp set.h
	$(OPT) set.cpp -o set.o
operators.o: operators.cpp operators.h
	$(OPT) operators.cpp -o operators.o
clean:
	rm -f *.o
