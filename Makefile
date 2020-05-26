install: main.o accept.o element.o fileHandler.o menu.o misc.o output.o searchModify.o view.o
	g++ main.o accept.o element.o fileHandler.o menu.o misc.o output.o searchModify.o view.o -std=c++11 -o output.exe
		
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
	
target: dependencies
	action
	
clean:
	del *.o || rm *.o
	del *.data || rm *.data