#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char *str;
    struct Node *next;
};

struct Stack{
    struct Node *first;
};

int is_empty(struct Stack *s){
    return s->first==NULL;
}


void push(struct Stack *s,struct Node *node){
    node->next=s->first;
    s->first=node;
}

char *pop(struct Stack *s){
    if(is_empty(s)){
        printf("%s\n", "empty Stack");
        return NULL;
    }
    struct Node *popnode;
    char *tmp;
    popnode=s->first;
    tmp=popnode->str;
    s->first=popnode->next;
    free(popnode);
    return tmp;
}


int main(int argc, char const *argv[])
{
    struct Stack s;
    s.first=NULL;
    char *back="-";
    char *a[]={"this","-","is","-","test","program","-","-"};
    int i=0;
    while(i<sizeof(a)/sizeof(char *)){
        if(strcmp(a[i],back)==0){
            printf("%s ", pop(&s));
        }
        else{
            struct Node *n=(struct Node *)malloc(sizeof(struct Node));
            n->str=a[i];
            n->next=NULL;
            push(&s,n);
        }
        i++;
    }
    return 0;
}