OBJS = main.o intro_to_outro_display.o
CXX = g++

output: $(OBJS)
	$(CXX) -o output $(OBJS)

$(OBJS): intro_to_outro_display.cpp intro_to_outro_display.h

clean: 
	rm *.o output