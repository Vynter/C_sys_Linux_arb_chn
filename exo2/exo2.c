#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
    int val;
    struct Node* nxt;
};

struct Node* Create(int nbr){
    
    struct Node* elm = (struct Node*) malloc(1*sizeof(struct Node));

    elm->val=nbr;
    elm->nxt=NULL;
    return elm;
}

void add(struct Node* head,int i){
    struct Node* elm = (struct Node*) malloc(1*sizeof(struct Node));
    elm=head;
    struct Node* NewN=Create(i);
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

int searchElm(struct Node* head, unsigned int val){
    struct Node* elm = (struct Node*) malloc(1*sizeof(struct Node));
    elm=head;
    int pos =1;
    while(elm->nxt != NULL){
        if(elm->val == val){
            printf("la valeur se situe a la position %d\n",pos);
            return 0;
        }
        pos++;
        elm=elm->nxt;
    }
    printf("la valeur n'existe pas dans la liste\n");
    return 0;
}

int main(){
    
    int elm,val;

    
    printf("Veuillez saisir le nombre d'element \n");
    scanf("%d",&elm);
    
    struct Node* head= Create(1);
    for(int i=1;i<elm;i++){
        add(head,i+1);
        
    }
    DisplayList(head);

    
    printf("Veuillez saisir une valeur sur la quel la recherche sera appliqué \n");
    scanf("%d",&val);
    searchElm(head,val);
    return 0;
}
