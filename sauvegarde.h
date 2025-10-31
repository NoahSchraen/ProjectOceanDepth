#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include "joueur.h"
#include "inventaire.h"

int sauvegarder(const Plongeur *p, const Inventaire *inv, const char *fichier);
int charger(Plongeur *p, Inventaire *inv, const char *fichier);

#endif // SAUVEGARDE_H
