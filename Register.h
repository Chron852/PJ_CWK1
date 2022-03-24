
#ifndef MAIN_C_REGISTER_H
#define MAIN_C_REGISTER_H

#include "book_management.h"

void Registersurface(User *h,Book *b);
void Loaduser(char *filename,User *h);
int checkname(char *name,User *h);
int checkpass(char *pass);
void mainsurface(User *h,Book *b);

#endif //MAIN_C_REGISTER_H
