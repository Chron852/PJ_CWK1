#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "user.h"
#include "Librarian.h"
#include "Register.h"

void loaduserbook(Book *b,char *name){
    char c[1024];
    name = strcat(name,"loans");
    char *f = strcat(name,".txt");
    FILE *file = fopen(f,"r");
    if(file == NULL){
        file = fopen(f,"w");
        fclose(file);
    }
    else{
        while(fgets(c,1024,file) != NULL){
            char *m;
            m = strtok(c,"=");
            unsigned int id = atoi(m);
            m = strtok(NULL,"=");
            char *title;
            title = (char *)malloc(sizeof (m));
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
            linkbook(id,title,authors,year,copies,b);
        }
        fclose(file);
    }

}

void searchbookuser(Book *b,User *h,char *name){
    BookList list1;
    char choice[100],c,*title,*author,title1[100],author1[100],year1[100];
    int i,j = 0,year,k = 0,flag = 0;
    choice[1] = ' ';
    printf("\nChoose an option:\n1.search book by title\n2.search book by author\n3.search book by year\n4.exit\n");
    printf("please enter your choice:");
    c = getchar();
    while(c != '\n'){
        choice[j] = c;
        c = getchar();
        j++;
    }
    do{
        if(choice[1] != ' ' || choice[0] != '1' && choice[0] != '2' && choice[0] != '3' && choice[0] != '4'){
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
            k = 1;
            printf("Please enter title:");
            i = 0;
            c = getchar();
            while( c != '\n'){
                title1[i] = c;
                i++;
                c = getchar();
            }
            title = title1;
            title[i] = '\0';
            list1 = find_book_by_title(title,b);
            Book *s;
            s = list1.list;
            if(s->next != NULL){
                printf("\n\nID\tTitle\tAuthors\tYears\tCopies\n");
                while(s->next != NULL){
                    s = s->next;
                    printf("%d\t%s\t%s\t%d\t%d\n",s->id,s->title,s->authors,s->year,s->copies);
                }
            }else{
                printf("Book do not exist!\n");
            }
        }
        else if( choice[0] == '2'){
            k = 1;
            printf("Please enter authors:");
            i = 0;
            c = getchar();
            while( c != '\n'){
                author1[i] = c;
                i++;
                c = getchar();
            }
            author = author1;
            author[i] = '\0';
            list1 = find_book_by_author(author,b);
            Book *s;
            s = list1.list;
            if(s->next != NULL){
                printf("\n\nID\tTitle\tAuthors\tYears\tCopies\n");
                while(s->next != NULL){
                    s = s->next;
                    printf("%d\t%s\t%s\t%d\t%d\n",s->id,s->title,s->authors,s->year,s->copies);
                }
            }else{
                printf("Book do not exist!\n");
            }
        }
        else if(choice[0] == '3'){
            k = 1;
            printf("Please enter year:");
            i = 0;
            c = getchar();
            while( c != '\n'){
                if(c <'0' || c > '9'){
                    flag = 1;
                    break;
                }
                year1[i] = c;
                i++;
                c = getchar();
            }
            if(flag == 1){
                printf("Year must be an integer!\n");
                getchar();
                searchbook(b,h);
            }
            year1[i] = '\0';
            year = atoi(year1);
            list1 = find_book_by_year(year,b);
            Book *s;
            s = list1.list;
            if(s->next != NULL){
                printf("\n\nID\tTitle\tAuthors\tYears\tCopies\n");
                while(s->next != NULL){
                    s = s->next;
                    printf("%d\t%s\t%s\t%d\t%d\n",s->id,s->title,s->authors,s->year,s->copies);
                }
            }else{
                printf("Book do not exist!\n");
            }
        }
        else if(choice[0] == '4'){
            k = 1;
        }
    }while(k == 0);
    usersurface(name,b,h);
}

void borrowbook(Book *b){
    return;
}

void returnbook(Book *b){
    return;
}

void usersurface(char *name,Book *b,User *h){
    char choice[100],c,name1[100];
    int i=0,j;
    strcpy(name1,name);
    Book *us = (Book *) malloc(sizeof (Book));
    us->next = NULL;
    loaduserbook(us,name);
    name = name1;
    choice[1] = ' ';
    printf("\nWelcome, %s!\n",name);
    printf("Choose you option:\n1.list all books\n2.search for books\n3.borrow books\n4.return books\n5.exit\n");
    printf("Please enter you choice:");
    j = 0;
    c = getchar();
    while(c != '\n'){
        choice[j] = c;
        c = getchar();
        j++;
    }
    do{
        if(choice[1] != ' ' || choice[0] != '1' && choice[0] != '2' && choice[0] != '3' && choice[0] != '4' && choice[0] != '5'){
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
            list_books(b);
            usersurface(name,b,h);
        }
        else if( choice[0] == '2'){
            i = 1;
            searchbookuser(b,h,name);
        }
        else if(choice[0] == '3'){
            i = 1;
            borrowbook(b);
        }
        else if(choice[0] == '4'){
            i = 1;
            returnbook(b);
        }
        else if(choice[0] == '5'){
            i = 1;
            mainsurface(h,b);
        }
    }while(i == 0);
}