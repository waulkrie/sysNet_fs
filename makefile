CFLAGS = -g -Wall -std=c++14
CC = g++
PROG_NAME=fs

objects = disk.o fileSystem.o inode.o main.o

.PHONY : all
all: $(PROG_NAME)

$(PROG_NAME): $(objects)
	$(CC) $(CFLAGS) -o $(PROG_NAME) $(objects)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

disk.o: disk.cpp
	$(CC) $(CFLAGS) -c disk.cpp

fileSystem.o: fileSystem.cpp
	$(CC) $(CFLAGS)  -c fileSystem.cpp

inode.o: inode.cpp
	$(CC) $(CFLAGS)  -c inode.cpp

.PHONY : clean
clean: 
	rm $(PROG_NAME) $(objects)
