#include<stdio.h>
#include<stdlib.h>

struct node {
    // struct node* prev[5];
    struct node* next[6]; 
    int nextTop;
    // int prevTop;
    int nextFlow;
};

struct log {
    struct node* root[6];
    // int top;
} ;

// void addToPrev (struct node* b,int a) {
//     b->prev[b->prevTop] = a;
//     b->prevTop++;
// }

void addToNext (struct node* b,struct node* a, int flow) {
    b->next[b->nextTop] = a;
    b->next[b->nextTop] -> nextFlow = flow;
    b->nextTop++;
}

struct node* makeNewNode (int nextFlow, struct node* thisNode){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> nextFlow = nextFlow;
    addToNext(thisNode, nextFlow);
    return newNode;
}

void main(){
    struct log* logs[6];
    int a[6][6] = {
        {0, 4, 2, 0, 0, 0},
        {0, 0, 0, 3, 0, 0},
        {0, 3, 0, 0, 5, 0},
        {0, 0, 6, 0, 0, 4},
        {0, 0, 0, 2, 0, 7},
        {0, 0, 0, 0, 0, 0}
    };
    int iteration = 0;
    int i = 0, j = 0;
    for(i = 0; i < 6 ; i++){
        logs[iteration] -> root[i] -> nextFlow = 0; 
    }
    for(i = 0; i < 6 ; i++){
        for(j = 0; j < 6 ; j++){
            if(a[i][j] != 0){
                addToNext(logs[iteration] -> root[i], logs[iteration] -> root[j], a[i][j]);
            }
        }
    }
    
}