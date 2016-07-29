//
// Created by rosyclouds on 16-7-28.
//

#define INITQUEUESIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
    char **base;
    int head;
    int tail;
    int size;
}SqQueue;


void initQueue(SqQueue *s){
    s->base=(char **)malloc(sizeof(char *)*INITQUEUESIZE);
    s->head=0;
    s->tail=0;
    s->size=INITQUEUESIZE;
}

int is_empty(SqQueue s){
    return s.head==s.tail;
}

int is_full(SqQueue s){
    return (s.tail+1)%s.size==s.head;
}

int length(SqQueue s){
    return (s.tail-s.head+s.size)%s.size;
}

void resize(SqQueue *s,int newsize){
    char **newbase=(char **)malloc(sizeof(char *)*newsize);
    int j=0;
    int k=s->head;
    for (int i = 0; i < length(*s) ; ++i) {
        newbase[j++]=s->base[k%s->size];
        k++;
    }
    s->head=0;
    s->tail=j;
    s->size=newsize;
    free(s->base);
    s->base=newbase;
}


void enqueue(SqQueue *s,char *data){
    if (is_full(*s)){
        resize(s,s->size*2);
    }
    s->base[s->tail]=data;
    s->tail=(s->tail+1)%s->size;
   // printf("\nhead=%d,tail=%d,size=%d",s->head,s->tail,s->size);
}

char *dequeue(SqQueue *s){
    if (is_empty(*s)){
    //    printf("\nhead=%d,tail=%d,size=%d",s->head,s->tail,s->size);
        return NULL;
    }else{
        char *temp=s->base[s->head];
        s->head=(s->head+1)%s->size;
        if (length(*s)>0 &&length(*s)==s->size/8){
            resize(s,s->size/2);
        }
    //    printf("\nhead=%d,tail=%d,size=%d",s->head,s->tail,s->size);
        return temp;
    }

}

int main(int argc,char *argv[]){
    SqQueue s;
    initQueue(&s);
    char *inputs[]={"this","is","a","-","-","automatic","test","program","-","-","-","-"};
    char *sep="-";
    for (int i = 0; i < sizeof(inputs)/ sizeof(char *); ++i) {
        if(strcmp(inputs[i],sep)==0){
            printf("%s ",dequeue(&s));
        }else{
            enqueue(&s,inputs[i]);
        }
    }
    if(is_empty(s)) {
        printf("\n%s", "Queue is empty");
    }
    exit(EXIT_SUCCESS);
}