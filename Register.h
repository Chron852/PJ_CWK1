
#ifndef MAIN_C_REGISTER_H
#define MAIN_C_REGISTER_H

#include "book_management.h"

void Registersurface(User *h,Book *b);//the interface of register
void Loaduser(char *filename,User *h);//to load all the user from txt
int checkname(char *name,User *h);//to check if the username exists before and check if the username is valid
int checkpass(char *pass);//check the passcode is valid
void mainsurface(User *h,Book *b);//the interface of main

#endif //MAIN_C_REGISTER_H
