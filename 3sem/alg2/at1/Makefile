MAIN=Main.c
UTIL=Student.c
BINARY=atr

all:
	gcc -Wall -g $(UTIL) $(MAIN) -o $(BINARY)

run:
	./$(BINARY)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

zip:
	@zip -r atr.zip *
