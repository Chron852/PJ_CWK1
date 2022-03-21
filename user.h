
#ifndef MAIN_C_USER_H
#define MAIN_C_USER_H


void usersurface(char *name,Book *b,User *h);
void borrowbook(Book *b);
void returnbook(Book *b);
void searchbookuser(Book *b,User *h,char *name);
void loaduserbook(Book *b,char *name);

#endif //MAIN_C_USER_H
