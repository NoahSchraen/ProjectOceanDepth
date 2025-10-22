//
// Created by laura on 22/10/2025.
//

#ifndef JOUEUR_H
#define JOUEUR_H

typedef struct {
    int points_de_vie;
    int points_de_vie_max;
    int niveau_oxygene;
    int niveau_oxygene_max;
    int niveau_fatigue; // 0 à 5
    int perles; // monnaie du jeu
} Plongeur;


Plongeur intitPlongeur(Plongeur p);

int pertePointsVie(int pointVie, int perdu);

int gagnerPointsVie(int pointVie, int gagne);

#endif //UNTITLED1_JOUEUR_H