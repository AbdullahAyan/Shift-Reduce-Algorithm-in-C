//
//  srstack.h
//  Shift Reduce
//
//  Created by Abdullah Ayan on 16.12.2021.
//

#ifndef stack_h
#define stack_h

void pushStack(node **root,char element[]){
    if (*root == NULL) {
        *root = (node *)malloc(sizeof(node));
        strcpy((*root)->element, element);
        (*root)->next = NULL;
    }else{
        pushStack(&(*root)->next, element);
    }
}


char* topStack(node *root){
    node *iter = root;
    while (iter->next != NULL) {
        iter = iter->next;
    }
    return iter->element;
}


void popStack(node *root){
    node *iter = root;
    while (iter->next->next != NULL) {
        iter = iter->next;
    }
    iter->next = NULL;
}


void printStack(node *stackRoot){
    node *iter = stackRoot;
    while (iter->next != NULL) {
        counter += strlen(iter->element);
        printf("%s",iter->element);
        iter = iter->next;
    }
    if (iter->next == NULL) {
        counter += strlen(iter->element);
        printf("%s",iter->element);

    }
}

#endif /* stack_h */
