/*
NOTES:
This compiler is a interpreted programming language. i will make a executable maker later but in this part you can calculate by typing not on a input but in a-
.txt file calculate using your own typing arithmetic this programming language will be updated maybe a month or somehow daily even. this programming language was
made with C programming language and it's compiler use is GCC MinGW 32-BITS (works also in 64-BITS), This will be open-sourced in GitHub, Itch.io, Sourceforge, and maybe more platformed
this programming language is called: Domestic-Math or you can just call DOMESTIC this refer to a species of a Duck called Domestic Duck.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Description:
Compiler: GCC MinGW 32-Bits.
Language: Domestic MATH.
Language Maker: C.
OS works on: Windows 11 or lower (LINUX COMING SOON!).
*/


//Standard_Main Libralies:
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////////////////////
//Main Libralies
#include "lib/check_digit.h"
#include "lib/check_operation.h"
#include "lib/check_eos.h"
///////////////////
int increment_checking = 0;
int placevaluenotation = 0;
int mychar;
//////////////////

#define or ||
#define and &&
#define equalto ==
#define notequalto !=
#define elif else if

typedef enum token{ //TOKENER ENUM
    TOKEN_NULL,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_PRE_UNKNOWN,
    TOKEN_PRE_OPERATION,
    TOKEN_OPERATION,
    TOKEN_WHITESPACE,
    TOKEN_END_OF_STATEMENT_,
}TOKENER;
TOKENER token;

int TRUE = 1; //runnner
int exponent = 0;
int GET_READ = 1;
int checker = 0;
int a = 0;
int b = 0;

char get_value[100] = {0};
int calculate[100] = {0};

FILE *tf;


void checktokennumber(){
    if(token == 0){
     printf("Token NULL: %d\n", token);
    }
    if(token == 1){
     printf("Token NUMBER: %d\n", token);
    }
        if(token == 2){
     printf("Token PLUS: %d\n", token);
    }
        if(token == 3){
     printf("Token PRE_UNKNOWN: %d\n", token);
    }
        if(token == 4){
     printf("Token PRE_OPERATION: %d\n", token);
    }
        if(token == 5){
     printf("Token OPERATION: %d\n", token);
    }
        if(token == 6){
     printf("Token WHITESPACE: %d\n", token);
    }
    if(token == 7){
        printf("Token END_OF_STATEMENT: %d\n", token);
    }
}


void getnv(char ch){
    if(checkdigit(ch)){
        token = TOKEN_NUMBER;
        
    }
    else if(__checkoperate(ch)){
        
    }
}

int __MAIN(){
    a = 0;
increment_checking = 0;
    FILE *tf = fopen("tf.txt", "r");
     while(TRUE){
   while((checker = fgetc(tf)) != EOF){ //get all characters.
        get_value[a] = (char)checker;
        a++;
   }
   if(checkdigit(get_value[increment_checking])){
     token = TOKEN_NUMBER;
   }
   else if(get_value[increment_checking + 1] == '\0' && increment_checking >= strlen(get_value)){
    token = TOKEN_NULL;
    for(int i = 0; i <= sizeof(get_value); i++){
        get_value[i] = 0;
    }
   }
   else if(get_value[increment_checking] == '\n'){
    token = TOKEN_WHITESPACE;
   }
   else if(__checkoperate(get_value[increment_checking])){
    token = TOKEN_OPERATION;
   }
   else if(_check_eos(get_value[increment_checking])){
    token = TOKEN_END_OF_STATEMENT_;
   }
if(increment_checking >= strlen(get_value)){
    printf("OUT\n");
   break;
}
else{
    increment_checking++;
}
checktokennumber();
 }
 rewind(tf);
 return 0;
}

int __Debug__TOKEN(){
    a = 0;
    increment_checking = 0;
    FILE *tf = fopen("tf.txt", "r");
     while(TRUE){
   while((checker = fgetc(tf)) != EOF){
         get_value[a] = (char)checker;
         a++;
   }
   if(checkdigit(get_value[increment_checking])){
     token = TOKEN_NUMBER;
     printf("NUMBER TOKEN: \e[42m%c\e[0m, TOKEN NUMBER: \033[36m%d\n\033[0m", get_value[increment_checking], token);
   }
   else if(get_value[increment_checking + 1] == '\0' && increment_checking >= strlen(get_value)){
    token = TOKEN_NULL;
    printf("AFTER TOKEN TO FIND NULL: NULL, TOKEN NUMBER: %d\n", token);
    for(int i = 0; i <= sizeof(get_value); i++){
        get_value[i] = 0;
    }
   }
   else if(get_value[increment_checking] == '\n'){
    printf("WHITESPACE TOKEN: NEWLINE, TOKEN NUMBER: \033[35m%d\n\033[0m", token);
   }
   else if(__checkoperate(get_value[increment_checking])){
    token = TOKEN_OPERATION;
   printf("OPERATION TOKEN: %c, TOKEN NUMBER: %d\n", get_value[increment_checking], token);
   }
if(increment_checking >= strlen(get_value)){
    printf("OUT\n");
   break;
}
else{
    increment_checking++;
}
 }
 rewind(tf);
 return 0;
}

void hi(){printf("hi\n\n\n\n");}

int main(){
   __MAIN();
   __Debug__TOKEN();
   fclose(tf);
 return 0;
}