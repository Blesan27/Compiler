#ifndef LOGGER_H
#define LOGGER_H

int logOn = 0;

void printInfo(char *s){
    printf("INFO : %s \n",s);
}

void printError(char *s){
    printf("ERROR : %s \n",s);
}

#endif