OTP=-std=gnu++11 -O0 -Wall -Wextra -DCEMA

all: main.o parse.o gaussread.o gausswrite.o
	g++ $(OPT) main.o parse.o gaussread.o gausswrite.o gausscalc.o -o main.exe
main.o: main.cpp gauss.h
	g++ -c $(OPT) main.cpp -o main.o
parse.o: parse.cpp
	g++ -c $(OPT) parse.cpp -o parse.o
read.o: gaussread.cpp gauss.h
	g++ -c $(OPT) gaussread.cpp -o read.o	
gausswrite.o: gausswrite.cpp gausscalc.o gauss.h
	g++ -c $(OPT) gausswrite.cpp -o gausswrite.o
gausscalc.o: gausscalc.cpp gauss.h const.h
	g++ -c $(OPT) gausscalc.cpp -o gausscalc.o
clean:
	rm -f *.o
