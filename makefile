# code details

EXE = ./library
SRC = main.c Librarian.c user.c Register.c Login.c book_management.c

# generic build details

CC =	gcc
CFLAGS= -std=c99 -Wall
CLINK=

# compile to object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
# buile executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE)

# clean up and remove object code and excutable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o: main.c Register.h Login.h book_management.h
Register.o: Register.c Register.h book_management.h
user.o: user.c book_management.h user.h Librarian.h Register.h Login.h
Login.o: Login.c Login.h Register.h book_management.h Librarian.h user.h
Librarian.o: Librarian.c Login.h book_management.h Register.h
book_management.o: book_management.c book_management.h Librarian.h Login.h
