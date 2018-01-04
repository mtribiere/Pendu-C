#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Fonction pour creer le masque
void creerMasque(int taille,int *masque[]){
    for(int i = 0;i<taille;i++){
        masque[i] = 0;
    }
}

// Fonction pour mettre le masque a jour
bool verifierLettre(char lettre,char mot[],int *masque[]){
    bool lettreTrouvee = false;
    for(int i = 0;i<strlen(mot);i++){
        if(lettre==mot[i]){
            masque[i] = 1;
            lettreTrouvee = true;
        }
    }
    return lettreTrouvee;
}

// Fonction pour afficher le mot avec le masque
void affichage(char mot[], int masque[], int vies){
    printf("\n\nVies restantes : %d\n     ",vies);
    for(int i=0;i<strlen(mot);i++){
        if(masque[i] == 0){
            printf("*");
        }else{
            printf("%c",mot[i]);
        }
    }
    printf("\n");

}

// Fonction pour entrer une lettre
char entrerLettre(){
    char lettre = getchar();
    while(getchar() != '\n');

    return tolower(lettre);
}

// Fonction pour savoir si le mot a été trouver
bool motTrouver(int taille,int masque[]){
    int total = 0;
    for(int i = 0;i<taille;i++) total += masque[i];
    
    return (total == taille);
}


int main()
{
    // Déclaration des variables
    char motATrouver[] = "cidre";

    int masque[strlen(motATrouver)];
    creerMasque(strlen(motATrouver),masque);

    int vies = 8;

    char lettre;

    // Afficher le message de bienvenue
    printf("**************************************\n");
    printf("*  Bienvenue dans le jeu du pendu !  *\n");
    printf("**************************************\n");

    //Boucle Principale
    while(vies>0 && !motTrouver(strlen(motATrouver),masque)){
        // Afficher le mot avec le masque
        affichage(motATrouver,masque,vies);

        // Demander la lettre
        printf("Entrez une lettre : ");
        lettre = entrerLettre();

        // Verification de la lettre
        if(!verifierLettre(lettre,motATrouver,masque)){
            vies--;
        }
    }

    // Afficher le message de fin
    if(vies > 0){
        printf("\n\nBravo ! Le mot était bien %s",motATrouver);
    }else{
        printf("\n\nDésolé, vous n'avez pas trouver le mot... C'était %s",motATrouver);
    }

    return 0;
}


