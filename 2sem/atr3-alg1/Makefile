UTIL=card.c deck.c
MAIN=main.c
BINARY=atr3

all:
	gcc -g $(UTIL) $(MAIN) -o $(BINARY) -lm
	# gcc -Wall -Werror -Wextra -g $(UTIL) $(MAIN) -o $(BINARY) -lm

run:
	./$(BINARY)


valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

zip:
	@zip -r $(BINARY).zip *
