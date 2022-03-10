#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Register.h"
#include "book_management.h"

void Loaduser(User *user,User *h,User *p){
    /*FILE *f;
    char *c;
    int i,j,flag,count=0;
    f=fopen("user.txt","r");
    while (fgets(c,sizeof(*c),f)!=EOF) {
        i = 0;
        j = 0;
        flag = 0;
        while (c[i] != '\0') {
            if (c[i] == '\t') {
                flag = 1;
                p->username[i] = '\0';
                i++;
            } else if (flag == 0) {
                p->username[i] = c[i];
                i++;
            } else {
                p->password[j] = c[i];
                i++;
                j++;
            }
            p->password[j] = '\0';
        }
        count++;
        if(count == 1){
            user = p;
            h->next = user;
        }
        else{
            user->next = p;
            user = p;
        }
    }
    user->next =NULL;
    fclose(f);
    return;*/
}

void Registersurface(){
    char name[100];

    printf("Please enter your username:");

}