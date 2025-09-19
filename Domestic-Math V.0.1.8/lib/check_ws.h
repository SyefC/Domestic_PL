
#define OR ||

//WHITESPACE CHEKCER \n, \t AND \0

int checkwhitespace(char CH){
     if(CH == '\0' OR CH == '\n' OR CH == '\t' OR CH == EOF){
        return 1;
     }
     else{
        return 0;
     }
}