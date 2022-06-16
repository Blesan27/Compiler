#ifndef TOKEN_H
#define TOKEN_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define EOI         0           // End Of File
#define SEMI        1           // ;
#define PLUS        2           // +
#define MINUS       3           // -
#define TIMES       4           // *
#define LP          5           // (
#define RP          6           // )
#define IDENTIFIER  7           // variable name
#define LESS        8           // <
#define GREATOR     9           // >
#define COLON       10          // :
#define QOUTE       11          // "
#define D_QOUTE     12          // '
#define L_FLOWER    13          // {
#define R_FLOWER    14          // }
#define DOT         15          // .
#define EQUAL       16          // = 
#define COMMA       17          // , 
#define HASH        18          // # 
#define F_SLASH     19          // /
#define B_SLASH     20          // "\" 
#define EQUALITY    21          // == 
#define L_EQUAL     22          // <= 
#define G_EQUAL     23          // >=  

#define NUMBER      24          // number
#define KEYWORD     25          // keyword
#define DATATYPE    26          // datatype

///////////////////////////////////////////////////////////////

FILE *fPtr = NULL;
char *tokenValue; 
int tokenLength;
int tokenLine = 1;
int def = 0;
char c;

char *keywords[] = {"work", "return","function"};
int TOTAL_KEYWORDS = 3;

char *datatypes[] = {"int", "char","string"};
int TOTAL_DATATYPES = 3;


////////////////////////////////////////////////////////////////

int isDelimeter(char c);
int isNumber_Keyword_Identifier();
void init_token(char* filePath){
    printf("OPENING FILE \n");
    fPtr = fopen(filePath, "r");
    printf("TOKEN INITIALIZED %d\n",fPtr);
}

int nextToken(){
    free(tokenValue);
    tokenLength = 0;
    while(1){
        if(!def)c = fgetc(fPtr);
        def = 0;
        if(isDelimeter(c)){
            if(c=='\n')tokenLine++;
            continue;
        }
        switch(c){
            case '+':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"+");
                return PLUS;
                break;
            case '-':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"-");
                return MINUS;
                break;
            case '*':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"*");
                return TIMES;
                break;
            case '/':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"/");
                return B_SLASH;
                break;
            case '\\':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"\\");
                return F_SLASH;
                break;
            case '.':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,".");
                return DOT;
                break;
            case '(':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"(");
                return LP;
                break;
            case ')':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,")");
                return RP;
                break;
            case '{':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"{");
                return L_FLOWER;
                break;
            case '}':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"}");
                return R_FLOWER;
                break;
            case '=':
                if((c=fgetc(fPtr)) == '='){
                    tokenLength = 2;
                    tokenValue = (char *)malloc(3*sizeof(char));
                    strcpy(tokenValue,"==");
                    return EQUALITY;
                }else def = 1;
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"=");
                return EQUAL;
                break;
            case '<':
                if((c=fgetc(fPtr)) == '='){
                    tokenLength = 2;
                    tokenValue = (char *)malloc(3*sizeof(char));
                    strcpy(tokenValue,"<=");
                    return L_EQUAL;
                }else def = 1;
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"<");
                return LESS;
                break;
            case '>':
                if((c=fgetc(fPtr)) == '='){
                    tokenLength = 2;
                    tokenValue = (char *)malloc(3*sizeof(char));
                    strcpy(tokenValue,">=");
                    return G_EQUAL;
                }else def = 1;
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,">");
                return GREATOR;
                break;
            case '\'':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"'");
                return QOUTE;
                break;
            case '"':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"\"");
                return D_QOUTE;
                break;
            case ':':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,":");
                return COLON;
                break;
            case ';':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,";");
                return SEMI;
                break;
            case ',':
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,",");
                return COMMA;
                break;
            case '#':
                tokenLine++;
                while((c=fgetc(fPtr))!='\n' && c!=EOF);
                return nextToken();
                break;
            case EOF:
                tokenLength = 1;
                tokenValue = (char *)malloc(2*sizeof(char));
                strcpy(tokenValue,"NONE");
                return EOI;
                break;
            default:
                if(isalnum(c) || c=='_'){
                    def = 1;
                    char variable[32];
                    int vl = 0;
                    variable[vl] = c;
                    vl++;
                    tokenLength = 1;
                    while(isalnum(c=fgetc(fPtr)) || c=='_'){
                        if(vl>31){
                            fprintf(stderr," variable lenght SO LONG...\n");
                            return EOI;
                        }
                        variable[vl] = c;
                        vl++;
                        tokenLength++;
                    }
                    variable[vl] = '\0';
                    tokenValue = (char *)malloc(tokenLength*sizeof(char));
                    strcpy(tokenValue,variable);
                    return isNumber_Keyword_Identifier();
                }else{
                    fprintf(stderr,"Error while parsing %c at line no:%d\n",c,tokenLine);
                    return EOI;
                }
                break;
        }
    }
    return 0;
}

int isNumber_Keyword_Identifier(){
    int isNumber = 1;
    int i=0;
    for(i=0; i<tokenLength; i++){
        char c = *(tokenValue+i);
        if( c < '0' || c > '9' ){
            isNumber = 0;
            break;
        }
    }
    if(isNumber)return NUMBER;

    for(i=0; i<TOTAL_KEYWORDS ; i++){
        if(strcmp(tokenValue,keywords[i]) == 0){
            return KEYWORD;
        }
    }

    for(i=0; i<TOTAL_DATATYPES ; i++){
        if(strcmp(tokenValue,datatypes[i]) == 0){
            return DATATYPE;
        }
    }

    return IDENTIFIER;

}

int isDelimeter(char c){
    return (c== ' ' || c=='\t' || c=='\n');
}

#endif