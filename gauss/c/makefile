OTP=-std=gnu++11 -O0 -Wall -Wextra -DCEMA

all: main.o parse.o read.o print.o abs.o
	g++ $(OPT) main.o parse.o read.o print.o abs.o -o main.exe
main.o: main.cpp func.h
	g++ -c $(OPT) main.cpp -o main.o
parse.o: parse.cpp
	g++ -c $(OPT) parse.cpp -o parse.o
read.o: read.cpp func.h
	g++ -c $(OPT) read.cpp -o read.o	
print.o: print.cpp
	g++ -c $(OPT) print.cpp -o print.o
abs.o: abs.cpp
	g++ -c $(OPT) abs.cpp -o abs.o
clean:
	rm -f *.o
