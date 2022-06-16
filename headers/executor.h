#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "semantics.h"
#include "var.h"

int execute(int semantic){
    int type = INT;
    switch (semantic)
    {
    case VAR_DECLARATION:
    printf("EXECUTION VAR_DECLARATION");
        type = cache->varCache->numValue;
        cache = cache->next;
        initVar(cache->varCache->stringValue,type);
        break;
    
    default:
        break;
    }
}



#endif