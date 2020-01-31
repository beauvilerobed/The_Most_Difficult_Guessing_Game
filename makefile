output: main.o intro_to_outro_display.o
	g++ main.o intro_to_outro_display.o -o output

main.o: main.cpp
	g++ -c main.cpp

intro_to_outro_display.o: intro_to_outro_display.cpp intro_to_outro_display.h
	g++ -c intro_to_outro_display.cpp

clean: 
	rm *.o output