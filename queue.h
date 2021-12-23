//
//  queue.h
//  Shift Reduce
//
//  Created by Abdullah Ayan on 16.12.2021.
//

#ifndef queue_h
#define queue_h

struct node {
    char element[3];
    struct node *next;
};typedef struct node node;

node *queueRoot = NULL, *stackRoot = NULL;
int counter = 0;

void pushQueue(node **root,char element[]){
    if (*root == NULL) {
        *root = (node *)malloc(sizeof(node));
        strcpy((*root)->element, element);
        (*root)->next = NULL;
    }else{
        pushQueue(&(*root)->next, element);
    }
}

node * createQueue(node *root,char input[]){
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            continue;
        }
        unsigned long elmtlen = 0;
        for (int j = 0; j<7; j++) {
            if (input[i] == symbols[j][0]) {
                elmtlen = strlen(symbols[j]);
                pushQueue(&root, symbols[j]);
            }
        }
        i += elmtlen-1;
    }
    return root;
}

char * nextQueue(node *root){
    return root->element;
}

void popQueue(node **root){
    *root = (*root)->next;
}

void printQueue(node *queueRoot){
    node *iter = queueRoot;
    while (iter->next != NULL) {
        printf("%s",iter->element);
        counter += strlen(iter->element);

        iter = iter->next;
    }
    if (iter->next == NULL) {
        counter += strlen(iter->element);
        printf("%s",iter->element);

    }
}




#endif /* queue_h */
