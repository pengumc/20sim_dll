#author: Michiel van der Coelen
#date 2013-XX-XX
#WINDOWS ONLY

#take .c from src, compile to .o in root, then link to dll in lib

NAME = testdll
CFLAGS = -fPIC -Isrc
CLIBS = 
CC = gcc
OBJECTS = $(NAME).o

.PHONY:all library

#build library
all:library

%.o:src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

library:lib/$(NAME).dll

lib/$(NAME).dll:$(OBJECTS)
	$(CC) -shared -Wall -o lib/$(NAME).dll $(CLIBS) $(OBJECTS)

clean:
	rm $(OBJECTS)