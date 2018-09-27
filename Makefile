mastermind: mastermind.o response.o code.o main.o
	g++ mastermind.o response.o code.o main.o -o mastermind

mastermind.o: mastermind.cpp
	g++ -Wall -c mastermind.cpp

response.o: response.cpp
	g++ -Wall -c response.cpp

main.o: main.cpp
	g++ -Wall -c  main.cpp 

code.o: code.cpp code.h
	g++ -Wall -c code.cpp

clean:
	rm mastermind.o response.o code.o main.o mastermind

