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

FREE LICENSES IN GITHUB OR OTHER DOWNLOADABLE SOURCES
FOR MORE TRUSTWORTHY LICENSES VISIT OFFICIAL WEBSITE OF DOMESTIC PROGRAMMING LANGUAGE: 
*/


//Standard_Main Libralies:
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////////////////////
typedef enum token{ //TOKENER ENUM
    TOKEN_NULL,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_PRE_UNKNOWN,
    TOKEN_PRE_OPERATION,
    TOKEN_OPERATION,
    TOKEN_WHITESPACE,
    TOKEN_CHAR,
    TOKEN_END_OF_STATEMENT_,
}TOKENER;
TOKENER token;

FILE *tf;

int TRUE = 1; //runnner
int exponent = 0;
int GET_READ = 1;
int checker = 0;
int a = 0;
int b = 0;
int ok = 1;
int new = 0;
int store_num = 0;
int calculate_lenght = 0;
int put_numresults = 0;
int results = 0;
int final_results = 0;
int clear_check = 0;
int increment_checking = 0;
int placevaluenotation = 0;
int mychar;
int code = 0;

char get_value[100];
int calculate[100] = {0};
char print_token[] = "printcal";


//Main Libralies
#include "lib/check_digit.h"
#include "lib/check_operation.h"
#include "lib/check_eos.h"
#include "lib/check_ws.h"
#include "lib/debug_and_reset.h"
#include "lib/check_char.h"
///////////////////
//////////////////

#define or ||
#define and &&
#define equalto ==
#define notequalto !=
#define elif else if


void checktokennumber(){
 if(ok == 1){
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
else{
    printf("\033[31munexpected event has occured!\n\033[0m");
}
}


void getnv(){
    exponent = 1;
while(TRUE){
    if(calculate_lenght <= 0 or get_value[calculate_lenght] == '\n'){
        TRUE = 0;
    }
    if(checkdigit(get_value[calculate_lenght])){
        token = TOKEN_NUMBER;
        store_num = get_value[calculate_lenght] - 48;
        printf("NUMBER: %c\n", get_value[calculate_lenght]);
        printf("STORED NUM: %d\n", store_num);
        store_num *= exponent;
        printf("STORED NUM: %d\n", store_num);
        calculate[put_numresults] = store_num;
    }
    //////////////////////
    /////////////////////
    exponent *= 10;
    put_numresults++;
    if(_check_eos(get_value[calculate_lenght])){
        token = TOKEN_END_OF_STATEMENT_;
        exponent = 1;
    }
        if(__checkoperate(get_value[calculate_lenght])){
        token = TOKEN_PLUS;
        exponent = 1;
    }
    if(_check_eos(get_value[calculate_lenght])){
        token = TOKEN_END_OF_STATEMENT_;
        exponent = 1;
    }
    if(!checkdigit(get_value[calculate_lenght])){
        token = TOKEN_PRE_UNKNOWN;
        printf("not a number!\n");
        exponent = 1;
    }
    clear_check++;
    calculate_lenght--;
}
}

int gt_results(){
     new = 0;
     int leng = sizeof(calculate) / sizeof(calculate[0]);
    for(int c = 0; c < leng; c++){
     new += calculate[c];
    }
    return new;
}

int __MAIN(){
    system("cls");
    a = 0;
increment_checking = 0;
    FILE *tf = fopen("tf.txt", "r");
     while(TRUE){
   while((checker = fgetc(tf)) != EOF){ //get all characters.
        get_value[a] = (char)checker;
                a++;
   }
   calculate_lenght = strlen(get_value) - 1;
   if(get_value[increment_checking] == 'p'){
    printf("OORAHHH\n");
    for(int ck = 0; ck < strlen(get_value); ck++){
        if(get_value[ck] == print_token[ck]){
            code++;
        }
        else{
            ck = strlen(get_value) + 1;
        }
    }
   }
    if(code == 8){
        getnv();
    }
    else{
        printf("\033[31mError: no \"printcal([])\" function was called! : '%s'\n                                                 ~~~\n\033[0m", get_value);
        ok = 0;
        TRUE = 0;
    }
   if(get_value[calculate_lenght] != ';'){
    printf("Error: Missing ';' : \033[31m%s ';' <-------- add this at the end!.\n                               ~~\n\033[0m", get_value);
    ok = 0;
    TRUE = 0;
   }
if(ok == 1){
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
    token = TOKEN_WHITESPACE;
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

int main(){
    __MAIN();
    final_results = gt_results();
if(ok == 1){
    printf("results: %d", final_results);
}
   fclose(tf);
 return 0;
}