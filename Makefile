FLAGS = -Wall -ansi -pedantic

all: rshell

rshell:
	([ ! -d bin ] && mkdir bin) || [ -d bin ]
	g++ $(FLAGS) src/main.cpp src/execute.h src/EC.h src/istest.h -o bin/rshell
