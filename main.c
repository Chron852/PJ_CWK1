#include <stdio.h>
#include <stdlib.h>
#include "Register.h"
#include "Login.h"
#include "book_management.h"


int main(){
    int i = 0,j=0;
    char choice[100];
    signed char c;
    FILE *f;
    User *users,*h1;
    users = (User *)malloc( sizeof(User));
    h1 =  (User *)malloc(sizeof (User));
    if((f=fopen("user.txt","r")) == NULL){
        printf("Data Loading!\n");
        f = fopen("user.txt","w");
        fputs("librarian\tlibrarian\n",f);
        users->username = "librarian";
        users->password = "librarian";
        users->Plibrarynum = 0;
        users->next = NULL;
        h1->next = users;
    }
    else {
        Loaduser(users, h1, f);
    }
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
            return 0;
        }
    }while(i==0);
    fclose(f);
    return 0;
}
