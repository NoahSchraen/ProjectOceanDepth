#ifndef COMPETENCES_H
#define COMPETENCES_H

typedef struct {
    int numero;
    char nom[50];
    int cout;
    int cooldown;
    int degats;
    int creatureAffecte;
}Competences;

Competences **competence_dispo();
#endif //COMPETENCES_H