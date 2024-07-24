CC = gcc
CFLAGS = -Wall -Wextra -g

all: server client

server: server.o sf_searchForFile.o sf_searchForString.o sf_displayFileContents.o
	$(CC) $(CFLAGS) -o server server.o sf_searchForFile.o sf_searchForString.o sf_displayFileContents.o

client: client.o
	$(CC) $(CFLAGS) -o client client.o

server.o: server.c server_functions.h loggers.h
	$(CC) $(CFLAGS) -c server.c -o server.o

sf_searchForFile.o: sf_searchForFile.c loggers.h
	$(CC) $(CFLAGS) -c sf_searchForFile.c -o sf_searchForFile.o

sf_searchForString.o: sf_searchForString.c loggers.h
	$(CC) $(CFLAGS) -c sf_searchForString.c -o sf_searchForString.o

sf_displayFileContents.o: sf_displayFileContents.c loggers.h
	$(CC) $(CFLAGS) -c sf_displayFileContents.c -o sf_displayFileContents.o

client.o: client.c
	$(CC) $(CFLAGS) -c client.c -o client.o

clean:
	rm -f server client *.o


