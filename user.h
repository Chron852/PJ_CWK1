
#ifndef MAIN_C_USER_H
#define MAIN_C_USER_H


void usersurface(char *name,Book *b,User *h);//the interface of user
void borrowbook(Book *b,Book *u);//the function to borrow book
void returnbook(Book *b,Book *u);//the function to return book
void searchbookuser(Book *b,User *h);//the search function especially for the user
void loaduserbook(Book *b,char *name);//the function to load books that user borrowed
int checkborrow(Book *u,char *title,char *author);//to check if the book user has borrowed
void storebook(char *name, Book *u);//store all the book user has borrowed into txt

#endif //MAIN_C_USER_H
