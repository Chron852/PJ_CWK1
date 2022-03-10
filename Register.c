#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Register.h"
#include "book_management.h"

void Loaduser(){
    FILE *f;
    user *users = (user *)malloc(sizeof(user));
    f=fopen("user.txt","r");
    fclose(f);
}

void Registersurface(){
    char name[100];

    printf("Please enter your username(5-10 letters):");

}