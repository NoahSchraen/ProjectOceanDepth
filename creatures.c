#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef CREATURES
#define CREATURES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id; // identifiant unique pour cibler
    char nom[30];
    int points_de_vie_max;
    int points_de_vie_actuels;
    int attaque_minimale;
    int attaque_maximale;
    int defense;
    int vitesse;
    char effet_special[20]; // "paralysie", "poison", "aucun"
    int est_vivant;
    int zone;
} CreatureMarine;

CreatureMarine **creature_marine() {
    //Créatures marines existantes par zones :
    CreatureMarine zone1[4] = {
        {1, "Poisson Clown", 30, 30, 2, 5, 1, 8, "aucun", 1, 1},
        {2, "Tortue Marine", 50, 50, 4, 8, 5, 4, "aucun", 1, 1},
        {3, "Meduse", 25, 25, 3, 6, 2, 6, "paralysie", 1, 1}

    };

    CreatureMarine zone2[4] = {
        {4, "Requin Gris", 100, 100, 8, 15, 6, 7, "aucun", 1, 2},
        {5, "Raie Electrique", 80, 80, 7, 12, 5, 5, "paralysie", 1, 2},
        {6, "Anguille Géante", 90, 90, 6, 14, 4, 6, "poison", 1, 2}
    };

    CreatureMarine zone3[4] = {
        {7, "Requin Marteau Abyssal", 160, 160, 15, 25, 10, 6, "aucun", 1, 3},
        {8, "Calmar Géant", 180, 180, 12, 28, 8, 7, "paralysie", 1, 3},
        {9, "Dragon des Abysses", 220, 220, 18, 35, 12, 9, "poison", 1, 3}
    };

    //Génération aléatoire du nombre de créatures marines
    srand(time(NULL));
    int nbgen=rand()%4+1;
    printf("%d \n",nbgen);

    //Allocation dynamiques des créatures marines
    CreatureMarine **creatures_marines = malloc(sizeof(CreatureMarine)*4);
    for (int i = 0; i < 4; i++) {
        creatures_marines[i] = malloc(sizeof(CreatureMarine)*4);

        for (int j = 0; j < nbgen; j++) {
            if (i == 0) {
                creatures_marines[i][j] = zone1[j];
            }else if (i == 1) {
                creatures_marines[i][j] = zone2[j];
            }else if (i == 2) {
                creatures_marines[i][j] = zone3[j];
            }
        }
    }
    return creatures_marines;
    free(creatures_marines);

};

#endif