#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Register.h"
#include "book_management.h"

void Loaduser(User *user,User *h,FILE *f){
    char c = ' ';
    User *p;
    p = (User *)malloc(sizeof (User));
    int i,flag,count=0;
    while (c != EOF) {
        i = 0;
        flag = 0;
        c = fgetc(f);
        while (c != '\n') {
            if (c == '\t') {
                flag = 1;
                p->username[i] = '\0';
                i = 0;
            }
            else if (flag == 0) {
                p->username[i] = c;
                i++;
            }
            else {
                p->password[i] = c;
                i++;
            }
            c = fgetc(f);
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
    printf("%s\n%s",user->username,user->password);
    return;
}

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
    name[strlen(name)] = '\0';
    printf("%s\n",name);
    while(checkname(name,h) == 1){
        printf("username exists!\nPlease retype!\n");
        i = 0;
        do{
            c = getchar();
            name1[i] = c;
            i++;
        }while( c != '\n');
        name = name1;
        name[strlen(name)] = '\0';
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
    pass[strlen(pass)] = '\0';
    fputs(name,f);
    fputs("\t",f);
    fputs(pass,f);
    fputs("\n",f);
    return;
}