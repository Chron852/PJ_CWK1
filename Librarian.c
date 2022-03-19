#include<stdio.h>
#include<stdlib.h>
#include "book_management.h"
#include "Register.h"

int add_book(Book *book){
    return 0;
}

int remove_book(Book *book){
    return 0;
}

void librariansurface(User *h1,Book *b){
    char choice[100];
    Book *abook = (Book *)malloc(sizeof(Book));
    Book *dbook = (Book *)malloc(sizeof(Book));
    signed char c;
    choice[1] = ' ';
    int i = 0,j = 0;
    printf("\nWelcome to the librarian interface!\n");
    printf("1.list all books\n2.add books\n3.delete books\n4.exit\n");
    printf("Please enter you choice:");
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
            i = 1;
            Book *h;
            h = b;
            printf("\n\nID\tTitle\tAuthors\tYears\tCopies\n");
            while(h->next != NULL){
                h = h->next;
                printf("%d\t%s\t%s\t%d\t%d\n",h->id,h->title,h->authors,h->year,h->copies);
            }
            librariansurface(h1,b);
        }
        else if( choice[0] == '2'){
            i = 1;
            add_book(abook);
        }
        else if(choice[0] == '3'){
            i = 1;
            remove_book(dbook);
        }
        else if(choice[0] == '4'){
            mainsurface(h1,b);
            break;
        }
    }while(i == 0);
}