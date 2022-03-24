
#ifndef MAIN_C_LIBRARIAN_H
#define MAIN_C_LIBRARIAN_H

#include "book_management.h"

void librariansurface(User *h1,Book *b);
void list_books(Book *b);
int checkbook(char *title,char *author,Book *b);

#endif //MAIN_C_LIBRARIAN_H
