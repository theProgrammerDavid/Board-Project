install: main.o accept.o element.o fileHandler.o menu.o misc.o output.o searchModify.o view.o
	g++ main.o accept.o element.o fileHandler.o menu.o misc.o output.o searchModify.o view.o -o output.exe
		
main.o: main.cpp
	g++ -c main.cpp
	
target: dependencies
	action
	
clean:
	del *.o 