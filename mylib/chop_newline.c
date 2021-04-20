#include "mylib.h"

char* chop_newline(char *str, int len){
    int n = strlen(str);
    

    //末尾が改行なら削る
    if(n < len && str[n - 1] == '\n'){
        str[n - 1] = '\0';
    }


    return str;
}