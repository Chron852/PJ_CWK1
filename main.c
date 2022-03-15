#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Register.h"
#include "Login.h"
#include "book_management.h"

void Loaduser(User *h){
    FILE *f;
    User *user;
    if((f = fopen("user.txt","r+")) == NULL){
        f = fopen("user.txt","w");
        fputs("librarian\tlibrarian\n",f);
        fclose(f);
    }
    f = fopen("user.txt","r");
    User *p,*s;
    s = (User *)malloc(sizeof(User));
    s->password = malloc(20 *sizeof(char));
    s->username = malloc(20 *sizeof(char));
    int count=0;
    user = h;
    while (fscanf(f,"%s",s->username) != EOF) {
        fscanf(f,"%s",s->password);
        s->password[strlen(s->password)] = '\0';
        s->username[strlen(s->username)] = '\0';
        p = (User *)malloc(sizeof(User));
        p->password = malloc(20 *sizeof(char));
        p->username = malloc(20 *sizeof(char));
        strcpy(p->username,s->username);
        strcpy(p->password,s->password);
        user->next = p;
        user = p;
        user->Plibrarynum = count;
        count++;
    }
    user->next = NULL;
    fclose(f);
    return;
}

void mainsurface(User *user,User *h){
    int i = 0,j=0;
    char choice[100];
    signed char c;
    choice[1] = ' ';
    printf("\n\n\nWelcome to online library!\n");
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
            Loginsurface(h,user);
        }
        else if( choice[0] == '2'){
            i = 1;
            Registersurface(h,user);
        }
        else if(choice[0] == '3'){
            break;
        }
    }while(i == 0);
}

int main(){
    User *users,*h1;
    Book *h2;
    users = (User *)malloc( sizeof(User));
    h1 =  (User *)malloc(sizeof (User));
    printf("Data Loading!\n");
    Loaduser(h1);
    mainsurface(users,h1);
    return 0;
}
