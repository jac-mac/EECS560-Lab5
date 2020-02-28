lab5: main.o Executive.o Hash.o
	g++ -std=c++11 -g -Wall main.o Executive.o Hash.o -o lab5

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Hash.o
	g++ -std=c++11 -g -Wall -c Executive.cpp

Hash.o: Hash.h Hash.cpp
	g++ -std=c++11 -g -Wall -c Hash.cpp

clean:
	rm *.o lab5
