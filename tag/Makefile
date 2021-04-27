MYLIBDIR = ../mylib
MYLIB = $(MYLIBDIR)/mylib.a

CFLAGS = -I$(MYLIBDIR)

all:	server client

server:	server.o session.o
	$(CC) -o $@ $^ $(MYLIB) -lncurses

client:	client.o session.o
	$(CC) -o $@ $^ $(MYLIB) -lncurses

server.o client.o:	tag.h session.h 

clean:
	$(RM) server client *.0 *~