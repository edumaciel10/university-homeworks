MAIN = main.c
SOURCES = Aluno.c Arquivo.c
UTIL = Util.c
BINARY = main
NAME = ex0

all:
	gcc -Wall -g $(UTIL) $(SOURCES) $(MAIN) -o $(BINARY)

run:
	./$(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

zip:
	@zip -r $(NAME).zip *

clean:
	@rm *.o