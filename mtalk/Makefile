MYLIBDIR = ../mylib
MYLIB = $(MYLIBDIR)/mylib.a

OBJS1 = server.o sessionman.o
OBJS2 = client.o session.o
CFLAGS = -I$(MYLIBDIR)

all:	server client

server:	$(OBJS1)
	$(CC) -o $@ $^ $(MYLIB) -lncurses

client:	$(OBJS2)
	$(CC) -o $@ $^ $(MYLIB) -lncurses

server.o:	sessionman.h

client.o:	session.h

clean:
	$(RM) server client $(OBJS1) $(OBJS2) *~
