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

    Competences competences[4] = {
        {1, "Apnee Prolongee", 0, 4, 0, 0},
        {2, "Decharge de Taser", 18, 0, rand()%30 + 20, 2},
        {3, "Attaque Double", 15, 1, 0, 1},
        {4, "Palmage Rapide", 22, 0, 0, 1}
    };

    Competences *competences_dispo = malloc(sizeof(Competences) * 4);

    for (int i = 0; i < 4; i++) {
        competences_dispo[i] = competences[i];
    }

    return competences_dispo;
}

#endif