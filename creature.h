#ifndef CREATURE_H
#define CREATURE_H

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

CreatureMarine **creature_marine();

#endif
