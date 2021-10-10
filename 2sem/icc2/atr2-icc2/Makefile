MAIN=main.c
BINARY=atr

all:
	gcc -g $(UTIL) $(MAIN) -o $(BINARY)

run:
	./$(BINARY)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

zip:
	@zip -r $(BINARY).zip *

