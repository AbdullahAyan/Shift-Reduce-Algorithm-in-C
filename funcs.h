//
//  funcs.h
//  Shift Reduce
//
//  Created by Abdullah Ayan on 16.12.2021.
//

#ifndef funcs_h
#define funcs_h


void shiftAct(int num,node *stackRoot);
void reduceAct(int num,node *stackRoot,node *queueRoot);
void spacer(void){
    for (int i = 0; i< (30 - counter); i++) {
        printf(" ");
    }
    counter = 0;
}

void shiftReduce(node *queueRoot,node *stackRoot){
    pushStack(&stackRoot, "0");
    while (strcmp(topStack(stackRoot),"0") != 0 || strcmp(nextQueue(queueRoot), "$") != 0) {
        if (strcmp(topStack(stackRoot),"1") == 0 && strcmp(nextQueue(queueRoot), "$") == 0) {
            printStack(stackRoot);
            spacer();
            printQueue(queueRoot);
            spacer();
            printf("Accept\n");
            break;
        }
        int num = atoi(topStack(stackRoot));
        char sym[3];
        strcpy(sym, nextQueue(queueRoot));
        int symint = 0;
        for (int i = 0; i<6; i++) {
            if (strcmp(symbols[i], sym) == 0) {
                symint = i;
            }
        }
        printStack(stackRoot);
        spacer();
        printQueue(queueRoot);
        spacer();



        char act[4];
        if (strcmp("\0", parseTable[num][symint])) {
            strcpy(act, parseTable[num][symint]);
        }else{
            printf("\nInvalid Syntax\n");
            break;
        }
        if (act[0] == 's') {
            shiftAct(atoi(&act[1]),stackRoot);
            queueRoot = queueRoot->next;
        }else if(act[0] == 'r'){
            reduceAct(atoi(&act[1]),stackRoot,queueRoot);
        }
    }
}


void shiftAct(int num,node *stackRoot){
    if (num == 1) {
        printf("Shift 11\n");
        pushStack(&stackRoot, nextQueue(queueRoot));
        pushStack(&stackRoot, "11");
        popQueue(&queueRoot);
    }else{
        printf("Shift %d\n",num);
        char numstr[3];
        sprintf(numstr, "%d", num);
        pushStack(&stackRoot, nextQueue(queueRoot));
        pushStack(&stackRoot, numstr);
        popQueue(&queueRoot);
    }
}

void reduceAct(int num,node *stackRoot,node *queueRoot){
    if (num%2 == 0){
        popStack(stackRoot);
        popStack(stackRoot);
    }else{
        popStack(stackRoot);
        popStack(stackRoot);
        popStack(stackRoot);
        popStack(stackRoot);
        popStack(stackRoot);
        popStack(stackRoot);

    }
        int goToint = atoi(topStack(stackRoot));
        printf("Reduce %d (use GOTO[%d, %c])\n",num,goToint,rules[num-1][0]);
        int goTocharint = 0;
        if (rules[num-1][0] == 'E') {
            goTocharint = 0;
        }
        if (rules[num-1][0] == 'F') {
            goTocharint = 2;
        }
        if (rules[num-1][0] == 'T') {
            goTocharint = 1;
        }
        char x = rules[num-1][0];
        pushStack(&stackRoot,&x);
        pushStack(&stackRoot,goTo[goTocharint][goToint]);
}


#endif /* funcs_h */
