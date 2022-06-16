#ifndef SEMANTICS_H
#define SEMANTICS_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "token.h"
#include "var.h"

#define SEMANTIC_ERROR 0
#define VAR_DECLARATION 1
#define VAR_UPDATION 2
#define CALL_METHOD 3
#define METHOD_DECLARATION 4
#define METHOD_DEFINATION_START 5
#define METHOD_DEFINATION_END 6
#define ENDED 100

struct node{
    struct node *next[10];
    int tokenType;
    int final;
    int semanticType;
};
struct cacheNode{
    struct cacheNode *next;
    int varType;
    union varCacheUnion *varCache;  
};

struct node *Sroot;
struct cacheNode *cache;

void init_semantics(){
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    root->final = 0;

    root->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[0]->tokenType = DATATYPE;
    root->next[0]->final = 0;
    root->next[0]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[0]->next[0]->tokenType = IDENTIFIER;
    root->next[0]->next[0]->final = 0;
    root->next[0]->next[0]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[0]->next[0]->next[0]->tokenType = SEMI;
    root->next[0]->next[0]->next[0]->final = 1;
    root->next[0]->next[0]->next[0]->semanticType = VAR_DECLARATION;

    
    root->next[1] = (struct node*)malloc(sizeof(struct node));
    root->next[1]->tokenType = IDENTIFIER;
    root->next[1]->final = 0;
    root->next[1]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[1]->next[0]->tokenType = EQUAL;
    root->next[1]->next[0]->final = 0;
    
    root->next[1]->next[0]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[1]->next[0]->next[0]->tokenType = NUMBER;
    root->next[1]->next[0]->next[0]->final = 0;
    root->next[1]->next[0]->next[0]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[1]->next[0]->next[0]->next[0]->tokenType = SEMI;
    root->next[1]->next[0]->next[0]->next[0]->final = 1;
    root->next[1]->next[0]->next[0]->next[0]->semanticType = VAR_UPDATION;

    root->next[1]->next[0]->next[1] = (struct node*)malloc(sizeof(struct node));
    root->next[1]->next[0]->next[1]->tokenType = D_QOUTE;
    root->next[1]->next[0]->next[1]->final = 0;
    root->next[1]->next[0]->next[1]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[1]->next[0]->next[1]->next[0]->tokenType = IDENTIFIER;
    root->next[1]->next[0]->next[1]->next[0]->final = 0;
    root->next[1]->next[0]->next[1]->next[0]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[1]->next[0]->next[1]->next[0]->next[0]->tokenType = D_QOUTE;
    root->next[1]->next[0]->next[1]->next[0]->next[0]->final = 0;
    root->next[1]->next[0]->next[1]->next[0]->next[0]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[1]->next[0]->next[1]->next[0]->next[0]->next[0]->tokenType = SEMI;
    root->next[1]->next[0]->next[1]->next[0]->next[0]->next[0]->final = 1;
    root->next[1]->next[0]->next[1]->next[0]->next[0]->next[0]->semanticType = VAR_UPDATION;
    
    root->next[1]->next[1] = (struct node*)malloc(sizeof(struct node));
    root->next[1]->next[1]->tokenType = LP;
    root->next[1]->next[1]->final = 0;
    root->next[1]->next[1]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[1]->next[1]->next[0]->tokenType = RP;
    root->next[1]->next[1]->next[0]->final = 0;
    root->next[1]->next[1]->next[0]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[1]->next[1]->next[0]->next[0]->tokenType = SEMI;
    root->next[1]->next[1]->next[0]->next[0]->final = 1;
    root->next[1]->next[1]->next[0]->next[0]->semanticType = CALL_METHOD;

    root->next[2] = (struct node*)malloc(sizeof(struct node));
    root->next[2]->tokenType = KEYWORD;
    root->next[2]->final = 0;
    root->next[2]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[2]->next[0]->tokenType = DATATYPE;
    root->next[2]->next[0]->final = 0;
    root->next[2]->next[0]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[2]->next[0]->next[0]->tokenType = IDENTIFIER;
    root->next[2]->next[0]->next[0]->final = 0;
    root->next[2]->next[0]->next[0]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[2]->next[0]->next[0]->next[0]->tokenType = LP;
    root->next[2]->next[0]->next[0]->next[0]->final = 0;
    root->next[2]->next[0]->next[1]->next[0]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[2]->next[0]->next[1]->next[0]->next[0]->tokenType = RP;
    root->next[2]->next[0]->next[1]->next[0]->next[0]->final = 0;
    root->next[2]->next[0]->next[1]->next[0]->next[0]->next[0] = (struct node*)malloc(sizeof(struct node));
    root->next[2]->next[0]->next[1]->next[0]->next[0]->next[0]->tokenType = L_FLOWER;
    root->next[2]->next[0]->next[1]->next[0]->next[0]->next[0]->final = 1;
    root->next[2]->next[0]->next[1]->next[0]->next[0]->next[0]->semanticType = METHOD_DEFINATION_START;

    root->next[3] = (struct node*)malloc(sizeof(struct node));
    root->next[3]->tokenType = R_FLOWER;
    root->next[3]->final=1;
    root->next[3]->semanticType = METHOD_DEFINATION_END;

    root->next[4] = (struct node*)malloc(sizeof(struct node));
    root->next[4]->tokenType = EOI;
    root->next[4]->final = 1;
    root->next[4]->semanticType = ENDED;
    Sroot = root;
}


int getSemantic(){
    struct node * temp = Sroot;
    cache = (struct cacheNode*)malloc(sizeof(struct cacheNode));
    struct cacheNode* cacheList = cache;
    int d = 0;
    outer:
    while(!temp->final){
        int token = nextToken();
        union varCacheUnion *tempCache = (union varCacheUnion*)malloc(sizeof(union varCacheUnion));
        printf("TOKEN RECEIVED - %d\n",token);
        if(token==NUMBER || token==IDENTIFIER || token==DATATYPE){
            if(token==NUMBER){
                cacheList->varType = INT;
                tempCache->numValue = atoi(tokenValue);
                cacheList->varCache = tempCache;
            }else if(token == IDENTIFIER){
                printf("identifier %d\n",(cacheList==NULL));
                cacheList->varType = STRING;
                printf("1 %s\n",tokenValue);
                tempCache->stringValue = tokenValue;
                printf("2 %d\n",tempCache);
                cacheList->varCache = tempCache;
                printf("NO error\n");
            }else{
                printf("DATATYPE\n");
                if(strcmp(tokenValue,"int")==0){
                    cacheList->varType = INT;
                    tempCache->numValue = INT;
                    cacheList->varCache = tempCache;
                }
                else if(strcmp(tokenValue,"string")==0){
                    cacheList->varType = INT;
                    tempCache->numValue = STRING;
                    cacheList->varCache = tempCache;
                }else{
                    cacheList->varType = INT;
                    tempCache->numValue = CHAR;
                    cacheList->varCache = tempCache;
                }
            }
            printf("cacheList %d\n",cacheList==NULL);
            printf("cacheListnext %d\n",cacheList->next==NULL);
            cacheList->next = (struct cacheNode*)malloc(sizeof(struct cacheNode));
            printf("cacheListnext %d\n",cacheList->next==NULL);
            cacheList = cacheList->next;
            printf("cacheList %d\n",cacheList==NULL);
            
        }
        inner:
        d++;
        printf("STARING LOOP\n");
        for(int i=0;i<10;i++){
            if(temp->next[i]->tokenType == token){
                temp = temp->next[i];
                i=10;
            }
        }
    }
    if(temp->final){
        printf("RETURNING %d\n",temp->semanticType);
        return temp->semanticType;
    }else{
        printf("ERROR\n");
        return SEMANTIC_ERROR;
    }
}
#endif