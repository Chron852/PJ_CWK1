#include <stdio.h>
#include <stdlib.h>
#include "Register.h"
#include "Login.h"
#include "book_management.h"

void Loaduser(User *user,User *h){
    char *c;
    FILE *f;
    printf("Data Loading!\n");
    if((f = fopen("user.txt","r+")) == NULL){
        f = fopen("user.txt","w");
        fputs("librarian\tlibrarian\n",f);
        fclose(f);
    }
    f = fopen("user.txt","r");
    User *p;
    p = (User *)malloc(sizeof(User));
    p->password = malloc(1024);
    p->username = malloc(1024);
    int count=0;
    char *username= malloc(1024);
    char *password= malloc(1024);
    while (fscanf(f,"%s",p->username) != EOF) {
        fscanf(f,"%s",p->password);
        if(count == 0){
            h -> next = p;
            user = p;
        }
        else{
            user -> next = p;
            user = p;
        }
        user->Plibrarynum = count;
        count++;
    }
    user->next = NULL;
    fclose(f);
    return;
}

int main(){
    int i = 0,j=0;
    char choice[100];
    signed char c;
    User *users,*h1;
    users = (User *)malloc( sizeof(User));
    h1 =  (User *)malloc(sizeof (User));
    Loaduser(users,h1);
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
            Loginsurface(h1);
        }
        else if( choice[0] == '2'){
            i = 1;
            Registersurface(h1);
        }
        else if(choice[0] == '3'){
            break;
        }
    }while(i == 0);
    return 0;
}
