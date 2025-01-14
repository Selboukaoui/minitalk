CC = gcc
CFLAGS = -Wall -Wextra -Werror


printflib = printf/libftprintf.a
LIBS = -Lprintf -lftprintf

all: server client server_bonus client_bonus
mandatory: server client
bonus: client_bonus server_bonus

server: server.c $(printflib)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

client: client.c $(printflib)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)


client_bonus: client_bonus.c $(printflib)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

server_bonus: server_bonus.c $(printflib)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

$(printflib):
	make -C printf

clean:
	rm -f *.o
	make -C printf clean

fclean: clean
	rm -f server client server_bonus client_bonus
	make -C printf fclean

re: fclean all

.PHONY: clean 
