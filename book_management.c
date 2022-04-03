#include <stdio.h>
#include "book_management.h"
#include <stdlib.h>
#include <string.h>
#include "Librarian.h"
#include "Login.h"

int store_books(char *filename,Book *h){
    int flag = 0;
    FILE *file;
    Book *l;
    if((file = fopen(filename,"r")) == NULL){
        file = fopen(filename,"w");
        fclose(file);
    }
    else{
        fclose(file);
    }
    if(h->next != NULL) {
        l = h;
        file = fopen(filename,"w");
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
            fputc('=',file);
            fprintf(file,"%d",l->whole);
            fputc('\n',file);
        }
    }
    else{
        flag = 1;
    }
    return flag;
}

Book *createbook(unsigned int id,char *title,char *authors,unsigned int year,unsigned int copies,int whole){
    Book *book = (Book *)malloc(sizeof(Book));
    book->id = id;
    book->title = title;
    book->authors = authors;
    book->year = year;
    book->copies = copies;
    book->whole = whole;
    return book;
}

void linkbook(unsigned int id,char *title,char *authors,unsigned int year,unsigned int copies,int borrowed, Book *h){
    Book *nbook = createbook(id,title,authors,year,copies,borrowed);
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

int load_books(char *filename,Book *h){
    FILE *file;
    h->title = filename;
    store_books(filename,h);
    char c[1024];
    file = fopen(filename,"r");
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
        m = strtok(NULL,"=");
        unsigned int copies = atoi(m);
        m = strtok(NULL,"\n");
        int whole = atoi(m);
        linkbook(id,title,authors,year,copies,whole,h);
    }
    fclose(file);
    return 0;
}

int add_book(Book *book,User *h1){
    int i,year,copies,id = 0,flag = 0, t = 0;
    char c,*title,*author,title1[100],author1[100],year1[100],copies1[100];
    Book *s;
    s = book;
    while(s->next != NULL){
        s = s->next;
        id = s->id;
    }
    id++;
    printf("\n\n********************\nPlease Enter the Book title:");
    i = 0;
    c = getchar();
    while( c != '\n'){
        title1[i] = c;
        i++;
        c = getchar();
    }
    title = title1;
    title[i] = '\0';
    printf("Please Enter the Book author:");
    i = 0;
    c = getchar();
    while( c != '\n'){
        author1[i] = c;
        i++;
        c = getchar();
    }
    author = author1;
    author[i] = '\0';
    if(checkbook(title,author,book) == 1){
        printf("Book exists!\n--------------------\n");
        t = 1;
        librariansurface(h1,book);
    }else{
        printf("Please enter years:");
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
            printf("Year must be an integer!\n--------------------\n");
            t = 1;
            getchar();
            librariansurface(h1,book);
        }else{
            year1[i] = '\0';
            year = atoi(year1);
            printf("Please enter copies:");
            i = 0;
            c = getchar();
            while( c != '\n'){
                if(c <'0' || c > '9'){
                    flag = 1;
                    break;
                }
                copies1[i] = c;
                i++;
                c = getchar();
            }
            if(flag == 1){
                printf("Copies must be an integer!\n--------------------\n");
                t = 1;
                getchar();
                librariansurface(h1,book);
            }else{
                copies1[i] = '\0';
                copies = atoi(copies1);
                linkbook(id,title,author,year,copies,copies,book);
                librariansurface(h1,book);
            }
        }
    }

    return t;
}

int remove_book(Book *book,User *h1){
    char choice[100],c;
    int flag = 0;
    choice[1] = ' ';
    int i = 0,j,k = 0,m=0,t = 0;
    Book *s,*last;
    s = book;
    while(s->next != NULL){
        s = s->next;
        m++;
    }
    list_books(book);
    if(book->next != NULL){
        printf("\n\n********************\n\nPlease choose the book id(type \"exit\" to back):");
        j = 0;
        c = getchar();
        while(c != '\n'){
            choice[j] = c;
            k = k*10 + c - '0';
            if(c-'0' < 0 || c-'0' > 9){
                flag = 1;
            }
            c = getchar();
            j++;
        }
        do{
            if(k > m || k < 0 || flag == 1){
                if(check(choice,"exit") == 1) break;
                printf("Wrong instruction!\nPlease retype your instruction(or type \"exit\" to leave):");
                choice[1] = ' ';
                flag = 0;
                j = 0;
                k = 0;
                c = getchar();
                while(c != '\n'){
                    choice[j] = c;
                    k = k*10 + c - '0';
                    if(c-'0' < 0 || c-'0' > 9){
                        flag = 1;
                    }
                    c = getchar();
                    j++;
                }
            }
            else{
                i = 1;
                s = book->next;
                last = book;
                while(s->id != k){
                    last = s;
                    s = s->next;
                }
                if(s->copies != s->whole){
                    printf("Book have been borrowed!\nYou cannot remove!\n--------------------\n");
                }else{
                    last->next = s->next;
                    s = last->next;
                    if(s != NULL){
                        if(book->next == s){
                            s->id =  1;
                        }else{
                            s->id = last->id + 1;
                        }
                        while(s->next != NULL){
                            last = s;
                            s = s->next;
                            s->id = last->id + 1;
                        }
                    }
                    printf("Removed successfully!\n--------------------\n");
                }
            }
        }while(i == 0);
    }
    librariansurface(h1,book);

    return t;
}

BookList find_book_by_title (const char *title, Book *b){
    Book *s;
    s = b;
    BookList listtitle;
    listtitle.list = (Book *) malloc(sizeof (Book));
    listtitle.list->next = NULL;
    char *title1 = (char *)malloc(100*sizeof (char));
    strcpy(title1,title);
    while(s->next != NULL){
        s = s->next;
        if(check(s->title,title1) == 1){
            linkbook(s->id,s->title,s->authors,s->year,s->copies,s->whole, listtitle.list);
        }
    }
    return listtitle;
}

BookList find_book_by_author (const char *author,Book *b){
    Book *s;
    s = b;
    BookList listauthor;
    listauthor.list = (Book *)malloc(sizeof (Book));
    listauthor.list->next = NULL;
    char *author1 = (char *)malloc(100*sizeof (char));
    strcpy(author1,author);
    while(s->next != NULL){
        s = s->next;
        if(check(s->authors,author1) == 1){
            linkbook(s->id,s->title,s->authors,s->year,s->copies,s->whole, listauthor.list);
        }
    }
    return listauthor;
}

BookList find_book_by_year (unsigned int year,Book *b){
    Book *s;
    s = b;
    BookList listyear;
    listyear.list = (Book *) malloc(sizeof (Book));
    listyear.list->next = NULL;
    while(s->next != NULL){
        s = s->next;
        if(year == s->year){
            linkbook(s->id,s->title,s->authors,s->year,s->copies,s->whole, listyear.list);
        }
    }
    return listyear;
}

void searchbook(Book *b,User *h){
    BookList list1;
    char choice[100],c,*title,*author,title1[100],author1[100],year1[100];
    int i,j = 0,year,k = 0,flag = 0;
    choice[1] = ' ';
    printf("\n\n********************\n\n\t1.search book by title\n\t2.search book by author\n\t3.search book by year\n\t4.exit\n\n");
    printf("please enter your choice:");
    c = getchar();
    while(c != '\n'){
        choice[j] = c;
        c = getchar();
        j++;
    }
    do{
        if(choice[1] != ' ' || (choice[0] != '1' && choice[0] != '2' && choice[0] != '3' && choice[0] != '4')){
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
                printf("Book do not exist!\n--------------------\n");
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
                printf("Book do not exist!\n--------------------\n");
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
                printf("Year must be an integer!\n--------------------\n");
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
                printf("Book do not exist!\n--------------------\n");
            }
        }
        else if(choice[0] == '4'){
            k = 1;
        }
    }while(k == 0);
}
//
// Created by Chaos on 2022/3/20.
//
