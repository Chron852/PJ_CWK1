#include<stdio.h>
#include "Login.h"
#include "book_management.h"
#include "Register.h"

void list_books(Book *b){
    Book *h;
    h = b;
    if(b->next != NULL){
        printf("\n\nID\tTitle\tAuthors\tYears\tCopies\n");
        while(h->next != NULL){
            h = h->next;
            printf("%d\t%s\t%s\t%d\t%d\n",h->id,h->title,h->authors,h->year,h->copies);
        }
    } else{
        printf("There is no book!\n");
    }
    printf("\n");
}

int checkbook(char *title,char *author,Book *b){
    int flag = 0;
    Book *s;
    s = b;
    while(s->next != NULL){
        s = s->next;
        if(check(title,s->title) == 1){
            if(check(author,s->authors) == 1){
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

void librariansurface(User *h1,Book *b){
    char choice[100];
    signed char c;
    choice[1] = ' ';
    int i = 0,j = 0;
    printf("\n******************************************\nWelcome to the librarian interface!\n");
    printf("Choose an option:\n\n\t1.list all books\n\t2.add books\n\t3.delete books\n\t4.search books\n\t5.exit\n\n******************************************\n");
    printf("Please enter you choice:");
    c = getchar();
    while(c != '\n'){
        choice[j] = c;
        c = getchar();
        j++;
    }
    do{
        if(choice[1] != ' ' || (choice[0] != '1' && choice[0] != '2' && choice[0] != '3' && choice[0] != '4' && choice[0] != '5')){
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
            librariansurface(h1,b);
        }
        else if( choice[0] == '2'){
            i = 1;
            add_book(b,h1);
        }
        else if(choice[0] == '3'){
            i = 1;
            remove_book(b,h1);
        }
        else if(choice[0] == '4'){
            searchbook(b,h1);
            printf("\n\n********************\nWelcome to the librarian interface!\n");
            printf("Choose an option:\n1.list all books\n2.add books\n3.delete books\n4.search books\n5.exit\n********************\n");
            printf("Please enter you choice:");
            c = getchar();
            choice[1] = ' ';
            j = 0;
            while(c != '\n'){
                choice[j] = c;
                c = getchar();
                j++;
            }
        }
        else if(choice[0] == '5'){
            store_books(b->title,b);
            mainsurface(h1,b);
            break;
        }
    }while(i == 0);
}
