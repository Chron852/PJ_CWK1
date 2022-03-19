
#ifndef MAIN_C_REGISTER_H
#define MAIN_C_REGISTER_H

#include "book_management.h"

void Registersurface(User *h,User *user,Book *b);
void Loaduser(User *h);
int checkname(char *name,User *h);
int checkpass(char *pass);
void mainsurface(User *user,User *h,Book *b);

#endif //MAIN_C_REGISTER_H
