#include <stdio.h>
#include <stdlib.h>
#include "Register.h"
#include "Login.h"
#include "book_management.h"

void Loaduser(User *user,User *h,FILE *f){
    char c;
    User *p;
    p = (User *)malloc(sizeof(User));
    int k,flag,count=0;
    c = fgetc(f);
    while (c != EOF) {
        k = 0;
        flag = 0;
        while (c != '\n') {
            if (c == '\t') {
                flag = 1;
                p->username[k] = '\0';
                k = 0;
            }
            else if (flag == 0) {
                p->username[k] = c;
                k++;
            }
            else {
                p->password[k] = c;
                k++;
            }
            c = fgetc(f);
        }
        p->password[k] = '\0';
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
    return;
}

int main(){
    int i = 0,j=0;
    char choice[100];
    signed char c;
    FILE *f = NULL;
    User *users,*h1;
    users = (User *)malloc( sizeof(User));
    h1 =  (User *)malloc(sizeof (User));
    f = fopen("user.txt","r+");
    if(f == NULL){
        printf("Data Loading!\n");
        f = fopen("user.txt","w");
        fputs("librarian\tlibrarian\n",f);
        fclose(f);
        f = fopen("user.txt","r+");
    }
    Loaduser(users,h1, f);
    choice[1] = ' ';
    printf("Welcome to online library!\n");
    printf("1.Login\n2.Register\n3.exit\n");
    c = getchar();
    while(c != '\n'){
        choice[j] = c;
        c = getchar();
        j++;
    }
    do{
        if(choice[1] != ' ' || choice[0] != '1' && choice[0] != '2' && choice[0] != '3'){
            printf("Wrong instruction!\nPlease retype your instruction:");
            choice[1] = ' ';
            j = 0;
            c = getchar();
            while(c != '\n'){
                choice[j] = c;
                c = getchar();
                j++;
            }
        }
        else if(choice[0] == '1'){
            i = 1;
            Loginsurface(h1,f);
        }
        else if( choice[0] == '2'){
            i = 1;
            Registersurface(h1,f);
        }
        else if(choice[0] == '3'){
            break;
        }
    }while(i == 0);
    fclose(f);
    return 0;
}
