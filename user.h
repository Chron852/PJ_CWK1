
#ifndef MAIN_C_USER_H
#define MAIN_C_USER_H


void usersurface(char *name,Book *b,User *h);
void borrowbook(Book *b,Book *u);
void returnbook(Book *b,Book *u);
void searchbookuser(Book *b,User *h,char *name);
void loaduserbook(Book *b,char *name);
int checkborrow(Book *u,char *title,char *author);
void storebook(char *name, Book *u);

#endif //MAIN_C_USER_H
