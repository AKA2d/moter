all:
	gcc -Ofast moter.c -o ./bin/moter

debug:
	gcc moter.c -o ./bin/moter