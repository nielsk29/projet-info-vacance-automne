#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "variable.h"

int l_map[2]; //taille x et y en carré de la carte
const int taille_carre = 100; //taille de chaque carré
int taille_map[2]; //taille x et y de la carte
char** map;
int nb_rayon; //nombre de rayon qu'envoie le proagramme à chaque image définit aussi la largeur de l'affichage
int taille_ecran; // la longueur de l'affichage
int nb_rayon; //nombre de rayon qu'envoie le proagramme à chaque image définit aussi la largeur de l'affichage
int taille_ecran; // la longueur de l'affichage

float pos_j[2]; //position x et x du joueur
float regard_j = 3*M_PI/2; //direction du regard du joueur avec un radiant comme si on faisait un cercle trigo autour du joueur
const float angle_regard = 2*M_PI/4; //angle total du regard

int def_var(int t, int diff)
{
    printf("test");
    nb_rayon = 100*t; 
    taille_ecran = 30*t; 
    
    if (diff == 1) {
        pos_j[0] = 150;
        pos_j[1] = 150;
        l_map[0] = 8;
        l_map[1] = 8;
        taille_map[0] = l_map[0]*taille_carre;
        taille_map[1] = l_map[1]*taille_carre;
        map =(char**)malloc(sizeof(char*)*l_map[1]);
        map[0] = "########";
        map[1] = "#0######";// carte '#' -> mur ; '0' -> vide
        map[2] = "#000000#";
        map[3] = "##0##0##";// cela est juste un string on le met comme ça pour plus de lisibilité de la carte
        map[4] = "#000##0#";
        map[5] = "#0#0000#";
        map[6] = "#00#0#0#";
        map[7]=  "######S#";
    } else {
        pos_j[0] = 1550;
        pos_j[1] = 150;
        l_map[0] = 27;
        l_map[1] = 28;
        taille_map[0] = l_map[0]*taille_carre;
        taille_map[1] = l_map[1]*taille_carre;
        map =(char**)malloc(sizeof(char*)*l_map[1]);
        map[0] = "###########################";
        map[1] = "###############0###########";// carte '#' -> mur ; '0' -> vide
        map[2] = "#0000000000000#000000000#0#";
        map[3] = "#0#######0###0#########0#0#";// cela est juste un string on le met comme ça pour plus de lisibilité de la carte
        map[4] = "#0#000000000#000000000#0#0#";
        map[5] = "#0#0#######0#0#######0#0#0#";
        map[6] = "#0#0#0000000#0#00000#0#0#0#";
        map[7] = "#0#0#0#####0#0#0###0#0#0#0#";
        map[8] = "#0#0#0#000#0#0#000#0#0#0#0#";
        map[9]=  "#0#0#0#0###0#####0#0#00000#";
        map[10]=  "#0#000#0#0000000#0#0###0#0#";
        map[11]= "#0#####0#0#####0#0#000#0#0#";
        map[12]= "#0#00000#0#000#0#0###0#0#0#";
        map[13]= "#0#000#0#0#000#00000#0#0###";
        map[14]= "#####0#0#0#000#0#####0#000#";
        map[15]= "#0#000#0#0##00#0#00000#0#0#";
        map[16]= "#0#000#000000000#0#####0#0#";
        map[17]= "#0###0###########0#00000#0#";
        map[18]= "#0#0#000000#000000#0###0#0#";
        map[19]= "#0#0#0####0#0######0#0#0#0#";
        map[20]= "#0#0#000000#0#000000#0#0#0#";
        map[21]= "#0#0########0#0######0#0###";
        map[22]= "#000000000000#0#000000#0#0#";
        map[23]= "#0############0#0######0#0#";
        map[24]= "#0000000000#000#00000000#0#";
        map[25]= "##########0#0#0##########0#";
        map[26]= "S0000000000#0#000000000000#";
        map[27]= "###########################";

    }
    
    if (map == NULL) {
        printf("L'allocation de mémoire a échoué.\n");
        exit(EXIT_FAILURE);
    }
}
