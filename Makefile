CFLAGS = -wall -std=c++11 -lcurses


run: run.out
	./run.out


run.out: main.o ship.o
	g++ $(CFLAG) main.o ship.o -o run.out 


main.o: main.cpp monster.h
	g++ -c $(CFLAG)  main.cpp


ship.o: ship.h ship.cpp
	g++ -c $(CFLAG)  ship.cpp

clean:
	rm run.out
	rm *.o
