#include <stdio.h>
#include <stdlib.h>
#include "inventaire.h"

// Remet tout à vide
void inv_init(Inventaire *inv) {
    if (!inv) return;
    for (int i = 0; i < INV_TAILLE_MAX; i++) {
        inv->slots[i].type = OBJ_VIDE;
        inv->slots[i].quantite = 0;
    }
    inv->equipe_harpon = 0;
    inv->equipe_combi = 0;
}

// Ajoute un objet (stack si même type)
int inv_ajouter(Inventaire *inv, int type, int quantite) {
    if (!inv || quantite <= 0 || type == OBJ_VIDE) return 0;

    for (int i = 0; i < INV_TAILLE_MAX; i++) {
        if (inv->slots[i].type == type) {
            inv->slots[i].quantite += quantite;
            return 1;
        }
    }
    for (int i = 0; i < INV_TAILLE_MAX; i++) {
        if (inv->slots[i].type == OBJ_VIDE) {
            inv->slots[i].type = type;
            inv->slots[i].quantite = quantite;
            return 1;
        }
    }
    return 0; // plein
}

// Nom lisible
static const char *nom_objet(int t) {
    switch (t) {
        case OBJ_CAPSULE_O2:   return "Capsule O2";
        case OBJ_TROUSSE_SOIN: return "Trousse de soin";
        case OBJ_STIMULANT:    return "Stimulant";
        case OBJ_ANTIDOTE:     return "Antidote";
        default:               return "-";
    }
}

// Affiche l’inventaire
void inv_afficher(const Inventaire *inv, const Plongeur *p) {
    (void)p; // pas utilisé ici
    if (!inv) return;
    printf("=== INVENTAIRE ===\n");
    for (int i = 0; i < INV_TAILLE_MAX; i++) {
        if (inv->slots[i].type != OBJ_VIDE) {
            printf(" - Slot %d : %s x%d\n",
                   i + 1, nom_objet(inv->slots[i].type), inv->slots[i].quantite);
        }
    }
    printf("Equipement : harpon=%d | combi=%d\n", inv->equipe_harpon, inv->equipe_combi);
}

// Petite récompense après victoire
void inv_recompense_victoire(Inventaire *inv, Plongeur *p, int difficulte) {
    (void)p; (void)difficulte; // on reste simple pour l’instant

    int r = rand() % 4;
    int type = OBJ_CAPSULE_O2;
    if (r == 1) type = OBJ_TROUSSE_SOIN;
    else if (r == 2) type = OBJ_STIMULANT;
    else if (r == 3) type = OBJ_ANTIDOTE;

    inv_ajouter(inv, type, 1);
}
