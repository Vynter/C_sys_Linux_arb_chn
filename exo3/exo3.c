#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Node{
    int id;
    char nom[100] ;
    char prenom[100] ;
    int note;
    struct Node* nxt;
};

struct Node* Create(int nbr){
    
    struct Node* elm = (struct Node*) malloc(1*sizeof(struct Node));

    elm->id=nbr;
    printf("Veuillez saisir le nom ");
    printf("> ");

    scanf(" %s",elm->nom);
    printf("Veuillez saisir le prénom ");
    printf("> ");

    scanf(" %s",elm->prenom);
    printf("Veuillez saisir la note du module Linux\n");
    scanf("%d",&elm->note);
    
    elm->nxt=NULL;
    return elm;
}

void addE (struct Node* head,int * mat){
    struct Node* elm = (struct Node*) malloc(1*sizeof(struct Node));
    elm=head;
    int i=*mat;
    struct Node* NewN=Create(i);
    i++;
    while(elm->nxt != NULL){
        elm=elm->nxt;
    }
    elm->nxt=NewN;
    *mat=i;
}
void DisplayList(struct Node* head){
    struct Node* elm = (struct Node*) malloc(1*sizeof(struct Node));
    elm=head;
    int nbr=1;
    while(elm !=NULL){
        printf("ID : %d\n",elm->id);
        printf("Nom : %s\n",elm->nom);
        printf("Prénom : %s\n",elm->prenom);
        printf("La note du module Linux: %d\n",elm->note);
        elm=elm->nxt;
        nbr++;
    }
    printf("\n");
}



int searchEtd(struct Node* head, unsigned int id){
    struct Node* elm = (struct Node*) malloc(1*sizeof(struct Node));
    elm=head;
    int pos =1;
    while(elm->nxt != NULL){
        if(elm->id == id){
            
            printf("ID : %d\n",elm->id);
            printf("Nom : %s\n",elm->nom);
            printf("Prénom : %s\n",elm->prenom);
            printf("La note du module Linux: %d\n",elm->note);
            return 0;
        }
        pos++;
        elm=elm->nxt;
    }
    printf("la valeur n'existe pas dans la liste\n");
    return 0;
}

int editEt(struct Node* head, unsigned int id){
    struct Node* elm = (struct Node*) malloc(1*sizeof(struct Node));
    elm=head;
    int pos =1;
    while(elm->nxt != NULL){
        if(elm->id == id){
        char nom[100] ;
        char prenom[100] ;
        int note;
        printf("Veuillez saisir le nom ");
        printf("> ");
        //fgets(elm->nom,101,stdin);
        //scanf(" %[^\n]",elm->nom);
        scanf(" %s",nom);
        printf("Veuillez saisir le prénom ");
        printf("> ");
        //fgets(elm->prenom,101,stdin);
        //scanf("%[^\n]",elm->prenom);
        scanf(" %s",prenom);
        printf("Veuillez saisir la note du module Linux\n");
        scanf("%d",&note);
        strcpy(elm->nom,nom);
        strcpy(elm->prenom,prenom);
        elm->note=note;
            return 0;
        }
        pos++;
        elm=elm->nxt;
    }
    printf("la valeur n'existe pas dans la liste\n");
    return 0;
}

void removeEt(struct Node* head, unsigned int pos){
    struct Node* elm = (struct Node*) malloc(1*sizeof(struct Node));
    struct Node* elm2 = (struct Node*) malloc(1*sizeof(struct Node));
    elm=head;
    int count=1;
    while(count < (pos-1)){
        count++;
        elm=elm->nxt;
    }
    elm2=elm->nxt;
    elm->nxt=elm2->nxt;
    free(elm2);
}

int main(){
    
    int elm,val,choice,loop=1,mat=1,matD;
    printf("La liste est vide , Veuillez saisir les données du premier étudiant avant de continuer\n");
    struct Node* head= Create(mat);
    mat++;
    
    while(loop){
        printf("Veuilez choisir une des options... \n");
        printf("1 : ajouter un nouvel étudiant. \n");
        printf("2 : supprimer un étudiant.  \n");
        printf("3 : Modifier les informations d'un étudiant.  \n");
        printf("4 : Chercher un étudiant en utilisant l'ID.  \n");
        printf("5 : Affichage de la liste d'étudiants. \n ");


        scanf("%d",&choice);
        switch(choice){
            case 1:
                addE(head,&mat);
                printf("%d",mat);
                break;
            case 2:
                printf("Veuillez saisir le matricule de l'étudiant a suprimer\n");
                scanf("%d",&matD);
                removeEt(head,matD);
                break;
            case 3:
                printf("Veuillez saisir le matricule de l'étudiant que vous voulez modifier\n");
                scanf("%d",&matD);
                editEt(head,matD);
                break;
            case 4:
                printf("Veuillez saisir le matricule de l'étudiant que vous chercher\n");
                scanf("%d",&matD);
                searchEtd(head,matD);
                break;
            case 5:
                DisplayList(head);
                break;
            default:
                printf("A bientot!");
                loop=0;
                break;
        }
        
    }

    return 0;
}
