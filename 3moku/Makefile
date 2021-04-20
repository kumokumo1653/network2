MYLIBDIR = ../mylib
MYLIB = $(MYLIBDIR)/mylib.a

CFLAGS = -I$(MYLIBDIR)

all:	server client

server:	server.o goban.o
	$(CC) -o $@ $^ $(MYLIB)

client:	client.o goban.o
	$(CC) -o $@ $^ $(MYLIB)

server.o client.o:	goban.h

clean:
	$(RM) server client *.0 *~