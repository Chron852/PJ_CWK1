#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Register.h"
#include "Login.h"
#include "book_management.h"

void Loaduser(User *h){
    FILE *f;
    User *user;
    f = fopen("user.txt","r+");
    if(f == NULL){
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

void mainsurface(User *h,Book *b){
    int i = 0,j=0;
    char choice[100];
    signed char c;
    User *user;
    choice[1] = ' ';
    printf("\n\n\nWelcome to online library!\n");
    printf("1.Login\n2.Register\n3.exit\n");
    printf("Please enter you choice:");
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
            Loginsurface(h,b);
        }
        else if( choice[0] == '2'){
            i = 1;
            Registersurface(h,b);
        }
        else if(choice[0] == '3'){
            break;
        }
    }while(i == 0);
}


int store_books(FILE *file,Book *h){
    int flag = 0;
    Book *l;
    file = fopen("books.txt","r+");
    if(file == NULL){
        file = fopen("books.txt","w");
        fclose(file);
    }
    if(h->next != NULL) {
        l = h;
        while (l->next != NULL) {
            l = l->next;
            fputc(l->id, file);
            fputs("\t", file);
            fputs(l->title, file);
            fputs("\t", file);
            fputs(l->authors, file);
            fputs("\t", file);
            fputc(l->year, file);
            fputs("\t", file);
            fputc(l->copies, file);
            fputs("\n", file);
        }
        fclose(file);
    }
    else{
        flag = 1;
    }
    return flag;
}

Book *createbook(unsigned int id,char *title,char *authors,unsigned int year,unsigned int copies){
    Book *book = (Book *)malloc(sizeof(Book));
    book->id = id;
    book->title = title;
    book->authors = authors;
    book->year = year;
    book->copies = copies;
    return book;
}

void linkbook(unsigned int id,char *title,char *authors,unsigned int year,unsigned int copies,Book *h){
    Book *nbook = createbook(id,title,authors,year,copies);
    nbook->next = NULL;
    if(h->next == NULL){
        h->next = nbook;
    }
    else{
        Book *s;
        s = h->next;
        while(s->next != NULL){
            s = s->next;
        }
        s->next = nbook;
    }
}

int load_books(FILE *file,Book *h){
    store_books(file,h);
    char c[1024];
    file = fopen("books.txt","r");
    while(fgets(c,1024,file) != NULL){
        char *m;
        m = strtok(c,"=");
        unsigned int id = atoi(m);
        m = strtok(NULL,"=");
        char *title;
        title = (char *)malloc(sizeof (title));
        strcpy(title,m);
        title[strlen(title)] = '\0';
        m = strtok(NULL,"=");
        char *authors;
        authors = (char *)malloc(sizeof (m));
        strcpy(authors, m);
        authors[strlen(authors)] = '\0';
        m = strtok(NULL,"=");
        unsigned int year = atoi(m);
        m = strtok(NULL,"\n");
        unsigned int copies = atoi(m);
        linkbook(id,title,authors,year,copies,h);
    }
    fclose(file);
    return 0;
}


int main(){
    User *users,*h1;
    Book *h2;
    FILE *file = NULL;
    users = (User *)malloc( sizeof(User));
    h1 = (User *)malloc(sizeof (User));
    h1->next = NULL;
    h2 = (Book *) malloc(sizeof(Book));
    h2->next = NULL;
    load_books(file, h2);
    Loaduser(h1);
    printf("Data Loading!\n");
    mainsurface(h1,h2);
    return 0;
}
