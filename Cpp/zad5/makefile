zad5: wielomian.o main.o
	g++ -std=c++0x -Wall -Wextra wielomian.o main.o -o zad5

main.o: main.cpp
	g++ -std=c++0x -Wall -Wextra -c main.cpp

wielomian.o: wielomian.cpp wielomian.h
	g++ -std=c++0x -Wall -Wextra -c wielomian.cpp

clean:
	rm *.o zad5
