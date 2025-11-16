#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "creature.h"
#include "joueur.h"
#include "competences.h"


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

    //Créatures marines existantes par zones :
    CreatureMarine **creatures = creature_marine();

    Competences *competences = competence_dispo();


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
        printf("%s vous attaque ! Que voulez vous faire ? \n", creatures[0][nbgen-1].nom);

        while (creatures[0][nbgen-1].points_de_vie_actuels >0 || p.points_de_vie > 0  ) {

            if (p.niveau_fatigue == 0 || p.niveau_fatigue == 1) {
                nbAttaques = 3; //nombre d'action par tour du joueur
            }
            else if (p.niveau_fatigue == 2 || p.niveau_fatigue == 3) {
                nbAttaques = 2;
            }
            else if (p.niveau_fatigue == 4 || p.niveau_fatigue == 5) {
                nbAttaques = 1;
            }

                int degats_base = rand() % (creatures[0][nbgen-1].attaque_maximale - creatures[0][nbgen-1].attaque_minimale + 1)+ creatures[0][nbgen-1].attaque_minimale ; //degats de la creature
                int degats = degats_base - creatures[0][nbgen-1].defense; //degats du plongeur
                if (degats < 1)degats = 1;


                for (int i = nbAttaques; i != 0; i-- ) {

                    printf("Vos statistiques : \n");
                    printf("Votre vie : %d / %d \n",p.points_de_vie,p.points_de_vie_max);
                    printf("Votre niveau d'oxygene : %d / %d \n",p.niveau_oxygene,p.niveau_oxygene_max);
                    printf("Votre niveau de fatigue : %d \n",p.niveau_fatigue);
                    printf("Vie de la creature : %d / %d \n", creatures[0][nbgen-1].points_de_vie_actuels, creatures[0][nbgen-1].points_de_vie_max);
                    printf("C'est votre tour, que voulez-vous faire ? \n");
                    printf("1: Competences       2: Attaque normale \n") ;
                    int choix ;
                    scanf("%d", &choix); //recupere le choix du joueur

                    if (choix == 1) {
                        printf("Choisissez une competence: \n");
                        for (int i = 0; i < 4; i++) {
                            printf("%d: %s \n ", i+1,  competences[i].nom) ;//affiche le nom des compétences
                        }

                        //Differents effets des competences
                        int compChoisie = 0;

                        scanf("%d", &compChoisie) ;
                        if (compChoisie == 1) { //Regeneration d'oxygene (Apnée Prolongée)
                            p.niveau_oxygene = p.niveau_oxygene + 20;
                            printf("Oxygene regenere ! \n Niveau Oxygene : %d \n", p.niveau_oxygene);
                        }
                        else if (compChoisie == 2) { //Décharge de Taser
                            printf("Le taser vous inflige aussis des degats ! \n") ;
                            int degatsTaser = rand()%11+20;
                            p.niveau_oxygene  = p.niveau_oxygene - 18 ;
                            p.points_de_vie = p.points_de_vie - degatsTaser ; // degats entre 20-30 sur toutes les créatures donc plongeur compris
                            creatures[0][nbgen-1].points_de_vie_actuels = creatures[0][nbgen-1].points_de_vie_actuels - degatsTaser ;
                        }
                        else if (compChoisie == 3) {//Attaque Double
                            int degatsAttqDouble = rand()%6+10 ;
                            p.niveau_oxygene = p.niveau_oxygene - 15 ;
                            creatures[0][nbgen-1].points_de_vie_actuels = creatures[0][nbgen-1].points_de_vie_actuels -degatsAttqDouble ;
                        }
                        else if (compChoisie == 4) {//Palmage Rapide, Baisse vitesse creature et donne une action supplementaire
                            p.niveau_oxygene = p.niveau_oxygene - 22 ;
                            creatures[0][nbgen-1].vitesse = creatures[0][nbgen-1].vitesse-2;
                            i =+1 ;
                        }
                        if (p.points_de_vie <= 0) {
                            printf("Vous êtes mort !\n");
                        } else if (p.niveau_oxygene <= 0) {
                            printf("Vous n'avez plus d'oxygène !\n");
                        } else if (creatures[0][nbgen-1].points_de_vie_actuels <=0) {
                            printf("Le combat se termine,  %s est mort, vous etes encore en vie.\n", creatures[0][nbgen-1].nom);
                            break;
                        }
                    }
                    else {
                        creatures[0][nbgen-1].points_de_vie_actuels = creatures[0][nbgen-1].points_de_vie_actuels - degats ;

                        if (p.points_de_vie <= 0) {
                            printf("Vous êtes mort !\n");
                        } else if (p.niveau_oxygene <= 0) {
                            printf("Vous n'avez plus d'oxygène !\n");
                        } else if (creatures[0][nbgen-1].points_de_vie_actuels <=0) {
                            printf("Le combat se termine,  %s est mort, vous etes encore en vie.\n", creatures[0][nbgen-1].nom);
                            break;
                        }
                    }
                }

                //tour de la creature
            if (creatures[0][nbgen-1].points_de_vie_actuels > 0) {
                if ( strcmp(creatures[0][nbgen-1].effet_special , "aucun") != 0) { // si la creature a une attaque speciale
                    switch (nbgenAttaques3) {
                        case 1:
                            printf("La creature a utilise sont attaque minimale vous perdez : %d points de vie \n",creatures[0][nbgen-1].attaque_minimale);
                            p.points_de_vie = p.points_de_vie - creatures[0][nbgen-1].attaque_minimale;
                            printf("-2 en oxygene (action de combat)\n");
                            p.niveau_oxygene = p.niveau_oxygene - 2;

                        case 2:
                            printf("La creature a utilise sont attaque maximale vous perdez : %d points de vie \n",creatures[0][nbgen-1].attaque_maximale);
                            p.points_de_vie = p.points_de_vie - creatures[0][nbgen-1].attaque_maximale;
                            printf("-2 en oxygene (action de combat)\n");
                            p.niveau_oxygene = p.niveau_oxygene - 2;

                        case 3:
                            printf("La creature a utilise sont attaque speciale vous perdez : %d points de vie \n",creatures[0][nbgen-1].attaque_minimale + creatures[0][nbgen-1].attaque_maximale);
                            p.points_de_vie = p.points_de_vie - (creatures[0][nbgen-1].attaque_maximale + creatures[0][nbgen-1].attaque_maximale);
                            printf("-5 en oxygene (action de combat)\n");
                            p.niveau_oxygene = p.niveau_oxygene - 5;

                        default:
                            printf("Erreur ");
                            break;

                    }
                }else if ( strcmp(creatures[0][nbgen-1].effet_special , "aucun") == 0) {
                    // si la creature n'a pas d'attaque speciale
                    switch (nbgenAttaques2) {
                        case 1:
                            printf("La creature a utilise sont attaque minimale vous perdez : %d points de vie \n",creatures[0][nbgen-1].attaque_minimale);
                            p.points_de_vie = p.points_de_vie - creatures[0][nbgen-1].attaque_minimale;
                            printf("-2 en oxygene (action de combat)\n");
                            p.niveau_oxygene = p.niveau_oxygene - 2;

                        case 2:
                            printf("La creature a utilise sont attaque maximale vous perdez : %d points de vie \n",creatures[0][nbgen-1].attaque_maximale);
                            p.points_de_vie = p.points_de_vie - creatures[0][nbgen-1].attaque_maximale;
                            printf("-2 en oxygene (action de combat)\n");
                            p.niveau_oxygene = p.niveau_oxygene - 2;

                        default:
                            printf("Erreur ");
                            break;

                    }
                }
            }

                printf("---------------------------------------------------------\n");
                printf("Vos statistiques en fin de combat : \n");
                printf("Votre vie : %d / %d \n",p.points_de_vie,p.points_de_vie_max);
                printf("Votre niveau d'oxygene : %d / %d \n",p.niveau_oxygene,p.niveau_oxygene_max);
                printf("Votre niveau de fatigue : %d \n",p.niveau_fatigue);

                free(creatures);
                return 0;
            }
        }
    }
