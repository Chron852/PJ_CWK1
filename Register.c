#include<stdio.h>
#include "Register.h"
#include "book_management.h"
#include "Login.h"

int checkname(char *name,User *h){
    User *k;
    int j,flag = 0;
    k = h;
    while(k->next != NULL){
        k = k->next;
        j = 0;
        while(name[j] != '\0' && k->username[j] != '\0'){
            if(name[j] == k->username[j]){
                j++;
            }
            else{
                break;
            }
        }
        if(name[j] == '\0' && k->username[j] == '\0'){
            flag = 1;
            break;
        }
    }
    return flag;
}

void Registersurface(User *h,FILE *f){
    char *name,*pass,c,name1[100],pass1[100];
    int i = 0;
    printf("Please enter your username:");
    c = getchar();
    while( c != '\n'){
        name1[i] = c;
        i++;
        c = getchar();
    }
    name = name1;
    name[i] = '\0';
    while(checkname(name,h) == 1){
        printf("username exists!\nPlease retype:");
        i = 0;
        c = getchar();
        while( c != '\n'){
            name1[i] = c;
            i++;
            c = getchar();
        }
        name = name1;
        name[i] = '\0';
    }
    printf("Please enter your passcode:");
    c = getchar();
    i = 0;
    while( c != '\n'){
        pass1[i] = c;
        i++;
        c = getchar();
    }
    pass = pass1;
    pass[i] = '\0';
    fputs(name,f);
    fputc('\t',f);
    fputs(pass,f);
    fputc('\n',f);
    printf("Registered Successfully!\n");
    Loginsurface(h,f);
}