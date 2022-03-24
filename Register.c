#include<stdio.h>
#include<string.h>
#include "Register.h"
#include "book_management.h"
#include "Login.h"

int checkpass(char *pass){
    int i,flag = 0;
    i = strlen(pass);
    if(i > 20){
        flag = 1;
    }
    else if(pass[0] == 'e'){
        flag = 2;
    }
    else if(i < 3){
        flag = 3;
    }
    return flag;
}

int checkname(char *name,User *h){
    User *k;
    int j,flag = 0;
    k = h;
    if(strlen(name)<3 || strlen(name)>20){
        if(strlen(name) == 1 && name[0] == 'e'){
            flag = 3;
        }
        else{
            flag = 2;
        }
    }
    else {
        while (k->next != NULL) {
            k = k->next;
            j = 0;
            while (name[j] != '\0' && k->username[j] != '\0') {
                if (name[j] == k->username[j]) {
                    j++;
                } else {
                    break;
                }
            }
            if (name[j] == '\0' && k->username[j] == '\0') {
                flag = 1;
                return flag;
            }
        }
    }
    return flag;
}

void Registersurface(User *h,Book *b){
    char *name,*pass,c,name1[100],pass1[100];
    FILE *f;
    int i = 0;
    printf("Please enter your username(3-20 letters):");
    c = getchar();
    while( c != '\n'){
        name1[i] = c;
        i++;
        c = getchar();
    }
    name = name1;
    name[i] = '\0';
    while(checkname(name,h)!=0){
        if(checkname(name,h) == 1){
            printf("username exists!\nPlease retype(or type e to back to upper surface):");
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
        else if(checkname(name,h) == 2){
            printf("The username you typed is too long or too short!\nPlease retype(or type e to back to upper surface):");
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
    printf("Please enter your passcode(3-20 letters):");
    c = getchar();
    i = 0;
    while( c != '\n'){
        pass1[i] = c;
        i++;
        c = getchar();
    }
    pass = pass1;
    pass[i] = '\0';
    while(checkpass(pass1) != 0){
        if(checkpass(pass1) == 1){
            printf("Longer than 20 letters\n");
            printf("Please retype(or type e to back to upper surface):");
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
        else if(checkpass(pass1) == 2){
            mainsurface(h,b);
        }
        else if(checkpass(pass1) == 3){
            printf("Shorter than 3 letters\n");
            printf("Please retype(or type e to back to upper surface):");
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
    }
    f = fopen("user.txt","a");
    fputs(name,f);
    fputc('\t',f);
    fputs(pass,f);
    fputc('\n',f);
    printf("Registered Successfully!\n");
    fclose(f);
    Loaduser(h->username,h);
    Loginsurface(h,b);
}