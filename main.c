//
//  main.c
//  Shift Reduce
//
//  Created by Abdullah Ayan on 14.12.2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shiftreducedatas.h"
#include "queue.h"
#include "stack.h"
#include "funcs.h"


int main(int argc, const char * argv[]) {
    
    char input[100];
    char chr;
    scanf("%c",&chr);
    int ncounter = 0;
    while (chr != '\n') {
        strcpy(&input[ncounter], &chr);
        scanf("%c",&chr);
        ncounter++;
    }
    char Null = '\0';
    strcpy(&input[ncounter], &Null);
    queueRoot = createQueue(queueRoot, input);
    pushQueue(&queueRoot, "$");
    shiftReduce(queueRoot, stackRoot);

    return 0;
}
