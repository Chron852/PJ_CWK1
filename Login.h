
#ifndef MAIN_C_LOGIN_H
#define MAIN_C_LOGIN_H

#include "book_management.h"
#include<stdio.h>
void Loginsurface(User *h,Book *b);//the interface of login
int check(char *a,char *b);//same as strcmp but to avoid '\0' loss
int checkTpass(char *pass,User *h,char *name);//check the password belongs to the user or not
#endif //MAIN_C_LOGIN_H
