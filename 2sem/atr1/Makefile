UTIL=ponto.c caminho.c
MAIN=main.c
BINARY=atr

all:
	gcc -Wall -Werror -g $(UTIL) $(MAIN) -o $(BINARY) -lm

run:
	./$(BINARY)

zip:
	@zip -r $(BINARY).zip *
