FLAGS = -Wall -Werror -ansi -pedantic

all: rshell 

rshell:
	([ ! -d bin ] && mkdir bin) || [ -d bin ]
	g++ $(FLAGS) src/main.cpp src/execute.h src/rshell.h -o bin/rshell