#include<stdio.h>
#include<string.h>
#include "Login.h"
#include "Register.h"
#include "book_management.h"
#include "Librarian.h"
#include "user.h"
int check(char *a,char *b){
    int i=0,flag = 0;
    while(a[i] != '\0' && b[i] != '\0'){
        if (a[i] == b[i]) {
            i++;
        } else {
            break;
        }
    }
    if (a[i] == '\0' && b[i] == '\0') {
        flag = 1;
    }
    return flag;
}
int checkTpass(char *pass,User *h,char *name){
    int flag = 0;
    User *p;
    p = h->next;
    while(check(p->username,name) == 0){
        p = p->next;
    }
    if(pass[0] == 'e' && strlen(pass) == 1){
        flag = 2;
    }
    else if(check(pass,p->password) == 1){
        flag = 1;
    }
    return flag;
}

void Loginsurface(User *h,Book *b){
    char c,name1[100],pass1[100],*name,*pass;
    int i;
    printf("\nPlease enter your username:");
    i = 0;
    c = getchar();
    while( c != '\n'){
        name1[i] = c;
        i++;
        c = getchar();
    }
    name = name1;
    name[i] = '\0';
    while(checkname(name,h) != 1){
        if(checkname(name,h) == 0 || checkname(name,h) == 2){
            printf("username don't exist\n");
            printf("Please retype(or type e to back to the upper surface):");
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
        else if(checkname(name,h) == 3){
            mainsurface(h,b);
        }
    }
    printf("Please enter your passcode:");
    i = 0;
    c = getchar();
    while( c != '\n'){
        pass1[i] = c;
        i++;
        c = getchar();
    }
    pass = pass1;
    pass[i] = '\0';
    while(checkTpass(pass,h,name) != 1){
        if(checkTpass(pass,h,name) == 0){
            printf("passcode is wrong!\n");
            printf("Please retype(or type e to back to the upper surface):");
            i = 0;
            c = getchar();
            while( c != '\n'){
                pass1[i] = c;
                i++;
                c = getchar();
            }
            pass = pass1;
            pass[i] = '\0';
        }
        else if(checkTpass(pass,h,name) == 2){
            mainsurface(h,b);
        }
    }
    if(check("librarian",name) == 1){
        librariansurface(h,b);
    }
    else{
        usersurface(name,b,h);
    }
}