//
// Created by rosyclouds on 16-7-27.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node {
    char *data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

int is_empty() {
    return head == NULL;
}

int size() {
    int s = 0;
    struct node *temp = head;
    while (temp != NULL) {
        s += 1;
        temp = temp->next;
    }
    return s;
}

void enqueue(char *data) {
    struct node *oldtail = tail;
    tail = (struct node *) malloc(sizeof(struct node));
    tail->data = data;
    tail->next = NULL;
    if (is_empty()) {
        head = tail;
    } else {
        oldtail->next = tail;
    }
}

char *dequeue() {
    if (head == NULL) {
        return NULL;
    }
    char *data = head->data;
    head = head->next;
    if (is_empty()) {
        tail = NULL;
    }
    return data;
}


int main(int argc, char *argv[]) {
    char *input[] = {"this", "is", "-", "-", "a", "-", "-", "test", "program", "-", "-"};
    char *sep = "-";
    for (int i = 0; i < sizeof(input) / sizeof(char *); ++i) {
        if (strcmp(input[i], sep) == 0) {
            printf("%s ", dequeue());
        } else {
            enqueue(input[i]);
        }
    }
    exit(EXIT_SUCCESS);
}