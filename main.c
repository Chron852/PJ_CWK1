#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Register.h"
#include "Login.h"
#include "book_management.h"

void Loaduser(char *filename,User *h){
    FILE *f;
    User *user;
    h->username = filename;
    f = fopen(filename,"r+");
    if(f == NULL){
        f = fopen(filename,"w");
        fputs("librarian\tlibrarian\n",f);
        fclose(f);
    }
    f = fopen(filename,"r");
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
        count++;
    }
    user->next = NULL;
    fclose(f);
    return;
}

void mainsurface(User *h,Book *b){
    int i = 0,j=0;
    char choice[100];
    signed char c;
    choice[1] = ' ';
    printf("\n\n******************************************\nWelcome to online library!\n");
    printf("Choose an option:\n\n\t1.Login\n\t2.Register\n\t3.exit\n\n******************************************\n");
    printf("Please enter you choice:");
    c = getchar();
    while(c != '\n'){
        choice[j] = c;
        c = getchar();
        j++;
    }
    do{
        if(choice[1] != ' ' || (choice[0] != '1' && choice[0] != '2' && choice[0] != '3')){
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
            Loginsurface(h,b);
        }
        else if( choice[0] == '2'){
            i = 1;
            Registersurface(h,b);
        }
        else if(choice[0] == '3'){
            printf("\nLibrary closed!\n--------------------\n");
            return;
        }
    }while(i == 0);
}

int main(int argc,char *argv[]){
    User *h1;
    Book *h2;
    char *file1 = "books.txt",*file2 = "user.txt";
    if(argc == 2){
        file1 = argv[1];
    }else if(argc == 3){
        file1 = argv[1];
        file2 = argv[2];
    }
    h1 = (User *)malloc(sizeof (User));
    h1->next = NULL;
    h2 = (Book *) malloc(sizeof(Book));
    h2->next = NULL;
    load_books(file1, h2);
    Loaduser(file2,h1);
    printf("Data Loading!\n--------------------\n");
    mainsurface(h1,h2);
    return 0;
}
