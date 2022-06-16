#ifndef VAR_H
#define VAR_H

#include<string.h>
#include<stdlib.h>

#include "logger.h"

#define ERROR -1
#define SUCCESS 0
#define INT 1
#define CHAR 2
#define STRING 3


char* numName[10];
int num[10];
int ni=0;

char* charsName[10];
char chars[10];
int ci=0;

char* stringName[10];
char* string[10];
int si=0;

union varCacheUnion{
    int numValue;
    char charValue;
    char* stringValue;
} varCache;

int getVar(char* var){
    for(int i=0;i<ni; i++){
        if(strcmp(var,numName[i])==0){
            varCache.numValue = num[i];
            return INT;
        }
    }
    for(int i=0;i<ci; i++){
        if(strcmp(var,charsName[i])==0){
            varCache.charValue = chars[i];
            return CHAR;
        }
    }
    for(int i=0;i<si; i++){
        if(strcmp(var,stringName[i])==0){
            varCache.stringValue = string[i];
            return STRING;
        }
    }

    if(logOn)printError("Variable not found");
    return ERROR;
}

int initVar(char* var,int type){
    if(getVar(var)!=-1){
        if(logOn)printError("Variable declared already");
        return ERROR;
    }

    switch (type){
        case INT:
            numName[ni] = (char *)malloc(strlen(var));
            strcpy(numName[ni],var);
            ni++;
            break;
        case CHAR:
            charsName[ci] = (char *)malloc(strlen(var));
            strcpy(charsName[ci],var);
            ci++;
            break;
        case STRING:
            stringName[si] = (char *)malloc(strlen(var));
            strcpy(stringName[si],var);
            si++;
            break;
        default:
            if(logOn)printError("Invalid Datatype-");
            return ERROR;
            break;
    }
    return SUCCESS;

}

int updateVar(char *var, int type){
    if(getVar(var)!=-1){
        if(logOn)printError("Variable Not Initialized");
        return ERROR;
    }

    switch (type){
        case INT:
            for(int i=0;i<ni; i++){
                if(strcmp(var,numName[i])==0){
                    num[i] = varCache.numValue;
                    return INT;
                }
            }
            break;
        case STRING:
            for(int i=0;i<si; i++){
                if(strcmp(var,stringName[i])==0){
                    string[i] = (char *)malloc(strlen(varCache.stringValue));
                    strcpy(string[i],varCache.stringValue);
                    return STRING;
                }
            }
            break;
        case CHAR:
            for(int i=0;i<ci; i++){
                if(strcmp(var,charsName[i])==0){
                    chars[i] = varCache.charValue;
                    return CHAR;
                }
            }
            break;
        default:
            if(logOn)printError("Invalid Datatype-");
            return ERROR;
            break;
    }
    return SUCCESS;
}

#endif