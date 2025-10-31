#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include "joueur.h"

#define INV_TAILLE_MAX 8

// Types d’objets
enum {
    OBJ_VIDE = 0,
    OBJ_CAPSULE_O2 = 1,
    OBJ_TROUSSE_SOIN = 2,
    OBJ_STIMULANT = 3,
    OBJ_ANTIDOTE = 4
};

// Un objet = type + quantité
typedef struct {
    int type;
    int quantite;
} Item;

// Inventaire simple
typedef struct {
    Item slots[INV_TAILLE_MAX];
    int equipe_harpon;
    int equipe_combi;
} Inventaire;

void inv_init(Inventaire *inv);
int  inv_ajouter(Inventaire *inv, int type, int quantite);
void inv_afficher(const Inventaire *inv, const Plongeur *p);
void inv_recompense_victoire(Inventaire *inv, Plongeur *p, int difficulte);

#endif
