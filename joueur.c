typedef struct {
    int points_de_vie;
    int points_de_vie_max;
    int niveau_oxygene;
    int niveau_oxygene_max;
    int niveau_fatigue; // 0 à 5
    int perles; // monnaie du jeu
} Plongeur;


Plongeur intitPlongeur(Plongeur p) {
    p.points_de_vie = 300;
    p.points_de_vie_max = 300;
    p.niveau_oxygene = 100;
    p.niveau_oxygene_max = 100;
    p.niveau_fatigue = 0;
    p.perles = 0;

    return p;

}

int pertePointsVie(int pointVie, int perdu) {
    int result = pointVie - perdu;

    return result;
}

int gagnerPointsVie(int pointVie, int gagne) {
    int result = pointVie + gagne;

    return result;
}