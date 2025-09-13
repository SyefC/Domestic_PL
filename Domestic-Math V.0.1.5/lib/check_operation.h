#define or ||
#define OR ||

//BASIC ARITHMETIC OPERATION
//ADVANCED OPERATION COMING SOON!

int __checkoperate(char GET){
    if(GET=='+' OR GET=='-' OR GET=='*' OR GET=='/'){
      return 1;
    }
    else{
        return 0;
    }
}