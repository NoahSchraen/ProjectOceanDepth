#include <stdio.h>
#include <string.h>
#include "sauvegarde.h"

#define SAVE_MAGIC "OCEANDEPTHS_SAVE_V1"

// Sauvegarde texte (inventaire + equip)
int sauvegarder(const Plongeur *p, const Inventaire *inv, const char *fichier) {
    (void)p; // pas utilisé ici
    if (!inv || !fichier) return 0;

    FILE *f = fopen(fichier, "w");
    if (!f) return 0;

    fprintf(f, "%s\n", SAVE_MAGIC);
    fprintf(f, "INVENTAIRE:%d", INV_TAILLE_MAX);
    for (int i = 0; i < INV_TAILLE_MAX; i++) {
        fprintf(f, ":%d,%d", inv->slots[i].type, inv->slots[i].quantite);
    }
    fprintf(f, "\n");
    fprintf(f, "EQUIPE:%d:%d\n", inv->equipe_harpon, inv->equipe_combi);

    fclose(f);
    return 1;
}

// Chargement texte
int charger(Plongeur *p, Inventaire *inv, const char *fichier) {
    (void)p; // pas utilisé ici
    if (!inv || !fichier) return 0;

    FILE *f = fopen(fichier, "r");
    if (!f) return 0;

    char ligne[256];
    if (!fgets(ligne, sizeof(ligne), f)) { fclose(f); return 0; }
    ligne[strcspn(ligne, "\r\n")] = 0;
    if (strcmp(ligne, SAVE_MAGIC) != 0) { fclose(f); return 0; }

    inv_init(inv);

    if (!fgets(ligne, sizeof(ligne), f)) { fclose(f); return 0; }
    int n = 0;
    if (sscanf(ligne, "INVENTAIRE:%d", &n) != 1) { fclose(f); return 0; }

    const char *ptr = strchr(ligne, ':');
    if (!ptr) { fclose(f); return 0; }
    ptr = strchr(ptr + 1, ':');

    for (int i = 0; i < INV_TAILLE_MAX && ptr; i++) {
        int t = 0, q = 0;
        if (sscanf(ptr + 1, "%d,%d", &t, &q) == 2) {
            inv->slots[i].type = t;
            inv->slots[i].quantite = q;
        }
        ptr = strchr(ptr + 1, ':');
    }

    if (!fgets(ligne, sizeof(ligne), f)) { fclose(f); return 0; }
    int eh = 0, ec = 0;
    if (sscanf(ligne, "EQUIPE:%d:%d", &eh, &ec) != 2) { fclose(f); return 0; }
    inv->equipe_harpon = eh;
    inv->equipe_combi = ec;

    fclose(f);
    return 1;
}
