#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "user.h"
#include "Librarian.h"
#include "Register.h"

void list_user_books(Book *b){
    Book *h;
    h = b;
    if(b->next != NULL){
        printf("\n\nID\tTitle\tAuthors\tYears\n");
        while(h->next != NULL){
            h = h->next;
            printf("%d\t%s\t%s\t%d\n",h->id,h->title,h->authors,h->year);
        }
    } else{
        printf("There is no book!\n");
    }
    printf("\n");
}

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
}

void borrowbook(Book *b,Book *u){
    char choice[100],c;
    int j,k = 0,i = 0,m = 0,n = 0;
    choice[1] = ' ';
    Book *s = b;
    while(s->next != NULL){
        s = s->next;
        m++;
    }
    s = u;
    while(s->next != NULL){
        s = s->next;
        n++;
    }
    if(b->next != NULL){
        list_books(b);
        printf("Please enter the Book ID you want to borrowed:");
        j = 0;
        c = getchar();
        while(c != '\n'){
            choice[j] = c;
            k = k*10 + c - '0';
            c = getchar();
            j++;
        }
        do{
            if(choice[1] != ' ' || k > m || k < 0){
                printf("Wrong instruction!\nPlease retype your instruction:");
                choice[1] = ' ';
                j = 0;
                k = 0;
                c = getchar();
                while(c != '\n'){
                    choice[j] = c;
                    k = k*10 + c - '0';
                    c = getchar();
                    j++;
                }
            }
            else{
                i = 1;
                s = b->next;
                while(s->id != k){
                    s = s->next;
                }
                if(s->copies > 0 && checkborrow(u,s->title,s->authors) == 0){
                    linkbook(n+1,s->title,s->authors,s->year,s->copies,u);
                    s->copies -= 1;
                    printf("Borrowed successfully!\n");
                }
                else if(checkborrow(u,s->title,s->authors) == 1){
                    printf("You have borrowed this book!\n");
                }
                else{
                    printf("Borrowed failed!\n");
                }
            }
        }while(i == 0);
    } else{
        printf("Library is empty!\nPlease call librarian to add books!\n");
    }
}

void returnbook(Book *b,Book *u){
    list_user_books(u);
    char choice[100],c;
    choice[1] = ' ';
    int i = 0,j,k = 0,m = 0;
    Book *s,*last;
    s = u;
    while(s->next != NULL){
        s = s->next;
        m++;
    }
    printf("Please choose the book id:");
    j = 0;
    c = getchar();
    while(c != '\n'){
        choice[j] = c;
        k = k*10 + c - '0';
        c = getchar();
        j++;
    }
    do{
        if(choice[1] != ' ' || k > m || k < 0){
            printf("Wrong instruction!\nPlease retype your instruction:");
            choice[1] = ' ';
            j = 0;
            k = 0;
            c = getchar();
            while(c != '\n'){
                choice[j] = c;
                k = k*10 + c - '0';
                c = getchar();
                j++;
            }
        }
        else{
            i = 1;
            last = u;
            s = u->next;
            while(s->id != k){
                last = s;
                s = s->next;
            }
            Book *re = b->next;
            while(strcmp(re->title,s->title) != 0 || strcmp(re->authors,s->authors) != 0){
                re = re->next;
            }
            re->copies += 1;
            last->next = s->next;
            free((void *)s);
            if(last->next != NULL){
                s = last->next;
                if(s == u->next){
                    s->id = 1;
                } else{
                    s->id = last->id + 1;
                }
                while(s->next != NULL){
                    last = s;
                    s = s->next;
                    s->id = last->id + 1;
                }
            }
            printf("Returned successfully!\n");
        }
    }while(i == 0);
    return;
}

int checkborrow(Book *u,char *title,char *author){
    Book *s = u;
    int flag = 0;
    while(s->next != NULL){
        s = s->next;
        if(strcmp(title,s->title) == 0 && strcmp(author,s->authors) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

void storebook(char *name,Book *u){
    name = strcat(name,"loans");
    char *f = strcat(name,".txt");
    FILE *file = fopen(f,"w");
    Book *l = u;
    while (l->next != NULL) {
        l = l->next;
        fprintf(file,"%d",l->id);
        fputc('=',file);
        fputs(l->title, file);
        fputc('=',file);
        fputs(l->authors, file);
        fputc('=',file);
        fprintf(file,"%d",l->year);
        fputc('=',file);
        fprintf(file,"%d",l->copies);
        fputc('\n',file);
    }
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
            list_books(b);
            printf("Choose you option:\n1.list all books\n2.search for books\n3.borrow books\n4.return books\n5.exit\n");
            printf("Please enter you choice:");
            j = 0;
            c = getchar();
            while(c != '\n'){
                choice[j] = c;
                c = getchar();
                j++;
            }
        }
        else if( choice[0] == '2'){
            searchbookuser(b,h,name);
            printf("Choose you option:\n1.list all books\n2.search for books\n3.borrow books\n4.return books\n5.exit\n");
            printf("Please enter you choice:");
            j = 0;
            c = getchar();
            while(c != '\n'){
                choice[j] = c;
                c = getchar();
                j++;
            }
        }
        else if(choice[0] == '3'){
            borrowbook(b,us);
            printf("Choose you option:\n1.list all books\n2.search for books\n3.borrow books\n4.return books\n5.exit\n");
            printf("Please enter you choice:");
            j = 0;
            c = getchar();
            while(c != '\n'){
                choice[j] = c;
                c = getchar();
                j++;
            }
        }
        else if(choice[0] == '4'){
            returnbook(b,us);
            printf("Choose you option:\n1.list all books\n2.search for books\n3.borrow books\n4.return books\n5.exit\n");
            printf("Please enter you choice:");
            j = 0;
            c = getchar();
            while(c != '\n'){
                choice[j] = c;
                c = getchar();
                j++;
            }
        }
        else if(choice[0] == '5'){
            i = 1;
            FILE *f;
            storebook(name,us);
            store_books(f,b);
            mainsurface(h,b);
        }
    }while(i == 0);
}