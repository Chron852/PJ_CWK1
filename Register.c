#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Register.h"
#include "book_management.h"

void Loaduser(user *user){
    /*FILE *f;
    char *c;
    int i,j,flag,count=0;
    struct user h,p;

    f=fopen("user.txt","r");
    while (fgets(c,sizeof(*c),f)!=EOF) {
        i = 0;
        j = 0;
        flag = 0;
        while (c[i] != '\0') {
            if (c[i] == '\t') {
                flag = 1;
                user.username[i] = '\0';
                i++;
            } else if (flag == 0) {
                user.username[i] = c[i];
                i++;
            } else {
                user.password[j] = c[i];
                i++;
                j++;
            }
            user.password[j] = '\0';
        }
    }
    close(f);*/
    return;
}

void Registersurface(){
    char name[100];

    printf("Please enter your username:");
    while()

}