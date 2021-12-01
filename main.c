#include <stdio.h>
#include "headers/token.h"
#include <ctype.h>
#include <string.h>

int main(){
    init_token("example.pgi");
    int tokenID = nextToken();
    printf("STARTED\n");
    while(tokenID!=EOI){
        printf("TOKEN ID: %d,\t\t VALUE:%s,\t\t LINE:%d\n",tokenID,tokenValue,tokenLine);
        tokenID = nextToken();
    }
    printf("FINSIHED\n");
    return 0;
}