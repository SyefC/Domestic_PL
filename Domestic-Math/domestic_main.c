//Standard_Main Libralies:
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////////////////////
//Main Libralies
#include "lib/check_digit.h"
///////////////////
int increment_checking = 0;
int placevaluenotation = 0;
int mychar;
//////////////////

#define or ||
#define and &&
#define equalto ==
#define notequalto !=

typedef enum token{
    TOKEN_NULL,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_PRE_UNKNOWN,
    TOKEN_WHITESPACE,
}TOKENER;

int TRUE = 1;

char get_value[100] = {0};
int calculate[100] = {0};

int main(){
    TOKENER token;
    FILE *tf = fopen("tf.txt", "r");
 while(TRUE){
   get_value[increment_checking] = fgetc(tf);
   if(checkdigit(get_value[increment_checking])){
     token = TOKEN_NUMBER;
     printf("NUMBER TOKEN: %c, TOKEN NUMBER: %d\n", get_value[increment_checking], token);
   }
   else if(get_value[increment_checking + 1] == '\0' && increment_checking >= strlen(get_value)){
    token = TOKEN_NULL;
    printf("AFTER TOKEN TO FIND NULL: NULL, TOKEN NUMBER: %d\n", token);
    for(int i = 0; i <= sizeof(get_value); i++){
        get_value[i] = 0;
    }
    printf("\n\n\n\n\n\n\n\n\n\n TEST:%s\n\n", get_value);
   }
   else if(get_value[increment_checking] == '\n'){
    printf("WHITESPACE TOKEN: NEWLINE, TOKEN NUMBER: %d\n", token);
   }
   else if (get_value[increment_checking] == '+'){
    token = TOKEN_PLUS;
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
 return 0;
}