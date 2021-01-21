#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
    int val;
    struct Node* nxt;
};

struct Node* Create(){
    
    struct Node* elm = (struct Node*) malloc(1*sizeof(struct Node));
    int randN=0;
    randN=rand()%10;
    
    elm->val=randN;
    elm->nxt=NULL;
    return elm;
}

void add(struct Node* head){
    struct Node* elm = (struct Node*) malloc(1*sizeof(struct Node));
    elm=head;
    struct Node* NewN=Create();
    while(elm->nxt != NULL){
        elm=elm->nxt;
    }
    elm->nxt=NewN;
}
void DisplayList(struct Node* head){
    struct Node* elm = (struct Node*) malloc(1*sizeof(struct Node));
    elm=head;
    int nbr=1;
    while(elm !=NULL){
        printf("La valeur N %d est %d\n",nbr,elm->val);
        elm=elm->nxt;
        nbr++;
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int randN=0,count=1;
    randN=rand()%10;
    struct Node* head= Create();
    for(int i=1;i<randN;i++){
        add(head);
        count++;
    }
    DisplayList(head);
    printf("la longueur de la chaine est : %d\n",count);
    return 0;
}
