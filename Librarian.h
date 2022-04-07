
#ifndef MAIN_C_LIBRARIAN_H
#define MAIN_C_LIBRARIAN_H

#include "book_management.h"

void librariansurface(User *h1,Book *b);//the interface of librarian
void list_books(Book *b);//to list the data of node b
int checkbook(char *title,char *author,Book *b);//to check if the book wants to be added exists before

#endif //MAIN_C_LIBRARIAN_H
