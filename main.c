#include <stdio.h>
#include "headers/token.h"
#include "headers/logger.h"
#include <ctype.h>
#include <string.h>
#include "headers/semantics.h"
#include "headers/executor.h"

int main(){
    init_token("team.pgi");
    char *s;
    logOn = 1;
    
    // printf("Enter the program name : ");
    // scanf("%s",s);

    // init_token(s);
    init_semantics();

    int semantic = 0;
    do{
        printf("HERE\n");
        semantic = getSemantic();
        printf("--%d\n",semantic);
        if(execute(semantic)!=0){
            break;
        }

    }while(semantic!=ENDED && semantic!=SEMANTIC_ERROR);
    
    return 0;
}