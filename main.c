#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "creature.h"
#include "joueur.h"


int main(void) {
    // initialisation du joueur :
    Plongeur p;
    p = intitPlongeur(p);
    int nbAttaques = 0;
    //initialisation de la profondeur
    int profondeur = 0;

    //Génération aléatoire
    srand(time(NULL));
    int nbgen=rand()%4+1;
    int nbgenAttaques2 = rand()%3+1;
    int nbgenAttaques3 = rand()%2+1;

    //Créatures marines existantes pas zones :
    CreatureMarine **creatures = creature_marine();


    printf("----------------------------------------\n");
    //printf("Monstres de la zone 1 :\n");
    for (int i = 0; i < 4; i++) {
        printf("Monstres de la zone : %d \n",i+1);
        for (int j = 0; j < 4; j++) {
            if (creatures[i][j].zone == 1 ) {
                printf("%s ", creatures[i][j].nom);
                printf("(%d / %d )PV ", creatures[i][j].points_de_vie_actuels,creatures[i][j].points_de_vie_max);
                printf("  ");
            }else if (creatures[i][j].zone == 2 ) {
                printf("%s ", creatures[i][j].nom);
                printf("(%d / %d )PV ", creatures[i][j].points_de_vie_actuels,creatures[i][j].points_de_vie_max);
                printf("  ");
            }else if (creatures[i][j].zone == 3 ) {
                printf("%s ", creatures[i][j].nom);
                printf("(%d / %d )PV ", creatures[i][j].points_de_vie_actuels,creatures[i][j].points_de_vie_max);
                printf("  ");
            }


        }
    }
    printf("Point de fatigue %d \n", p.niveau_fatigue);
    printf("Veuillez selectionner votre profondeur :\n");
    scanf("%d", &profondeur);
    printf("Votre profondeur : %d \n",profondeur);


    printf("---------------------------------------------Combat Sous Marin ---------------------------------------------- \n");

    if (profondeur >= 0 && profondeur < 50) {
        printf("Vous attaquez le %s \n", creatures[0][nbgen-1].nom);
        printf("Plongeur                  VS                          %s \n", creatures[0][nbgen-1].nom);
        printf("Vos statistiques en debut de tour : \n");
        printf("Votre vie : %d / %d \n",p.points_de_vie,p.points_de_vie_max);
        printf("Votre niveau d'oxygene : %d / %d \n",p.niveau_oxygene,p.niveau_oxygene_max);
        printf("Votre niveau de fatigue : %d \n",p.niveau_fatigue);
        int degats_base = rand() % (creatures[0][nbgen-1].attaque_maximale - creatures[0][nbgen-1].attaque_minimale + 1)+ creatures[0][nbgen-1].attaque_minimale ;
        int degats = degats_base - creatures[0][nbgen-1].defense;
        if (degats < 1)degats = 1;

        if (p.niveau_fatigue == 0 || p.niveau_fatigue == 1) {
            // attaque du plongueur
            //printf("Peut attaquer seulement 3 fois \n");
            nbAttaques = 3;

            //reposte de la creature marine
            while (nbAttaques != 0 ) {
                if ( strcmp(creatures[0][nbgen-1].effet_special , "aucun") != 0) {
                //printf("La creature a 3 types d'attaques \n");
                nbAttaques--;
                switch (nbgenAttaques3) {
                    case 1:
                        printf("La creature a utilise sont attaque minimale vous perdez : %d points de vie \n",creatures[0][nbgen-1].attaque_minimale);
                        printf("Vous riposter %d \n", degats);
                        p.points_de_vie = p.points_de_vie - creatures[0][nbgen-1].attaque_minimale;
                        printf("-2 en oxygene (action de combat)\n");
                        p.niveau_oxygene = p.niveau_oxygene - 2;
                        break;
                    case 2:
                        printf("La creature a utilise sont attaque maximale vous perdez : %d points de vie \n",creatures[0][nbgen-1].attaque_maximale);
                        printf("Vous riposter %d \n", degats);
                        p.points_de_vie = p.points_de_vie - creatures[0][nbgen-1].attaque_maximale;
                        printf("-2 en oxygene (action de combat)\n");
                        p.niveau_oxygene = p.niveau_oxygene - 2;
                        break;
                    case 3:
                        printf("La creature a utilise sont attaque speciale vous perdez : %d points de vie \n",creatures[0][nbgen-1].attaque_minimale + creatures[0][nbgen-1].attaque_maximale);
                        printf("Vous riposter %d \n", degats);
                        p.points_de_vie = p.points_de_vie - (creatures[0][nbgen-1].attaque_maximale + creatures[0][nbgen-1].attaque_maximale);
                        printf("-5 en oxygene (action de combat)\n");
                        p.niveau_oxygene = p.niveau_oxygene - 5;
                        break;
                    default:
                        printf("Erreur ");
                        break;

                }
            }else if ( strcmp(creatures[0][nbgen-1].effet_special , "aucun") == 0) {
                //printf("La creature a 2 types d'attaques \n");
                nbAttaques--;
                switch (nbgenAttaques2) {
                    case 1:
                        printf("La creature a utilisé sont attaque minimale vous perdez : %d points de vie \n",creatures[0][nbgen-1].attaque_minimale);
                        printf("Vous riposter %d \n", degats);
                        p.points_de_vie = p.points_de_vie - creatures[0][nbgen-1].attaque_minimale;
                        printf("-2 en oxygene (action de combat)\n");
                        p.niveau_oxygene = p.niveau_oxygene - 2;
                        break;
                    case 2:
                        printf("La creature a utilisé sont attaque maximale vous perdez : %d points de vie \n",creatures[0][nbgen-1].attaque_maximale);
                        printf("Vous riposter %d \n", degats);
                        p.points_de_vie = p.points_de_vie - creatures[0][nbgen-1].attaque_maximale;
                        printf("-2 en oxygene (action de combat)\n");
                        p.niveau_oxygene = p.niveau_oxygene - 2;
                        break;
                    default:
                        printf("Erreur ");
                        break;

                }
            }
                printf("---------------------------------------------------------\n");
                printf("Vos statistiques : \n");
                printf("Votre vie : %d / %d \n",p.points_de_vie,p.points_de_vie_max);
                printf("Votre niveau d'oxygene : %d / %d \n",p.niveau_oxygene,p.niveau_oxygene_max);
            }


        }else if (p.niveau_fatigue ==2 || p.niveau_fatigue == 3) {
            nbAttaques = 2;
        }else if (p.niveau_fatigue == 4 || p.niveau_fatigue == 5) {
            nbAttaques = 1;
        }else {
            printf("Erreur  \n");
        }

        printf("Fatigue augmente : +1 \n");
        p.niveau_fatigue = p.niveau_fatigue + 1;
        printf("Vous avez inflige : %d de degats \n", degats*3);

    }


    printf("---------------------------------------------------------\n");
    printf("Vos statistiques en fin de tour : \n");
    printf("Votre vie : %d / %d \n",p.points_de_vie,p.points_de_vie_max);
    printf("Votre niveau d'oxygene : %d / %d \n",p.niveau_oxygene,p.niveau_oxygene_max);
    printf("Votre niveau de fatigue : %d \n",p.niveau_fatigue);

    if (p.points_de_vie <= 0) {
        printf("Vous êtes mort !\n");
    } else if (p.niveau_oxygene <= 0) {
        printf("Vous n'avez plus d'oxygène !\n");
    } else {
        printf("Le tour se termine, vous êtes encore en vie.\n");
    }
    free(creatures);
    return 0;
}