#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Register.h"
#include "book_management.h"

void Loaduser(User *user,User *h,User *p){
    FILE *f;
    char c;
    int i,flag,count=0;
    f = fopen("user.txt","r");
    c = fgetc(f);
    while (c != EOF) {
        i = 0;
        flag = 0;
        while (c != '\n') {
            c = fgetc(f);
            if (c == '\t') {
                flag = 1;
                p->username[i] = '\0';
                i = 0;
            } else if (flag == 0) {
                p->username[i] = c;
                i++;
            } else {
                p->password[i] = c;
                i++;
            }
        }
        p->password[i] = '\0';
        p->Plibrarynum = count;
        count++;
        if(count == 1){
            user = p;
            h->next = user;
        }
        else{
            user->next = p;
            user = p;
        }
        c = fgetc(f);
    }
    user->next = NULL;
}

void Registersurface(){
    char name[100];

    printf("Please enter your username:");

}