#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef COMPETENCES
#define COMPETENCES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int numero;
    char nom[50];
    int cout;
    int cooldown;
    int degats;
    int creatureAffecte;
}Competences;


Competences  *competence_dispo() {
    srand(time(NULL)); //Initialisation rand

    Competences *competence_dispo = malloc(sizeof(Competences)*4) ; //allocation dynamique mémoire des compétences

    Competences competences[4] ={
        {1, "Apnée Prolongée", 0, 4, 0, 0 },
        {2, "Décharge de Taser", 18, 0, rand()%30+20, 2 }, //degats aléatoire entre 20-30
        {3, "Attaque Double", 15, 1, 0, 1},
        {4, "Palmage Rapide", 22, 0, 0, 1}
    };

    return competences;
    free(competence_dispo) ;
}

#endif