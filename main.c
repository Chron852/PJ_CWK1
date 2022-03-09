//
// Created by Chaos on 2022/3/8.
//
#include <stdio.h>
#include "Register.h"
#include "Login.h"
int main(){
    int i = 0,j=0;
    char choice[100],c;
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
        if(choice[1] != ' '){
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
            Loginsurface();
        }
        else if( choice[0] == '2'){
            i = 1;
            Registersurface();
        }
        else if(choice[0] == '3'){
            return 0;
        }
        else{
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
    }while(i==0);

    return 0;
}
