//
// Created by rosyclouds on 16-7-23.
//


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define INITIAL_ARRAY_SIZE 2

char **arr;
int arrlen;
int N=0;

void stackInitializer(){
    arr=(char **)malloc(sizeof(INITIAL_ARRAY_SIZE* sizeof(char *)));
    arrlen=INITIAL_ARRAY_SIZE;
}


void resize(int size){
    arr=(char **)realloc(arr,sizeof(char *)*size);
    arrlen=size;
}

void push(char *str){
    if (N==arrlen){
        resize(arrlen*2);
    }
    arr[N++]=str;
}

char *pop(){
    if(N==0){
        return NULL;
    }
    char *tmp=arr[--N];
    arr[N]=NULL;
    if(N>0 && N==arrlen/4){
        resize(arrlen/2);
    }
    return tmp;
}

int is_empty(){
    return N==0;
}

int main(int argc, char const *argv[])
{
    stackInitializer();
    char *back="-";
    char *a[]={"this","-","is","-","test","program","a","-","-","-"};
    int i=0;
    while(i<sizeof(a)/sizeof(char *)){
        if(strcmp(a[i],back)==0){
            printf("%s ", pop());
        }
        else{
            push(a[i]);
        }
        i++;
    }
    return 0;
}