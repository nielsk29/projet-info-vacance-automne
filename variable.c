#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "variable.h"

const int l_map[2] = {27,27}; //taille x et y en carré de la carte
const int taille_carre = 100; //taille de chaque carré
const int taille_map[2] = {l_map[0]*taille_carre,l_map[1]*taille_carre}; //taille x et y de la carte
char** map;
int nb_rayon; //nombre de rayon qu'envoie le proagramme à chaque image définit aussi la largeur de l'affichage
int taille_ecran; // la longueur de l'affichage

float pos_j[2] = {1550,50}; //position x et x du joueur
float regard_j = 3*M_PI/2; //direction du regard du joueur avec un radiant comme si on faisait un cercle trigo autour du joueur
const float angle_regard = 2*M_PI/4; //angle total du regard

int def_var(int t, int diff)
{
    nb_rayon = 50*t; 
    taille_ecran = 30*t; 

    if (diff == 1) {
        printf("bug");
    } else {
    map =(char**)malloc(sizeof(char*)*l_map[1]);
    map[0] = "###############0###########";// carte '#' -> mur ; '0' -> vide
    map[1] = "#0000000000000#000000000#0#";
    map[2] = "#0#######0###0#########0#0#";// cela est juste un string on le met comme ça pour plus de lisibilité de la carte
    map[3] = "#0#000000000#000000000#0#0#";
    map[4] = "#0#0#######0#0#######0#0#0#";
    map[5] = "#0#0#0000000#0#00000#0#0#0#";
    map[6] = "#0#0#0#####0#0#0###0#0#0#0#";
    map[7] = "#0#0#0#000#0#0#000#0#0#0#0#";
    map[8]=  "#0#0#0#0###0#####0#0#00000#";
    map[9]=  "#0#000#0#0000000#0#0###0#0#";
    map[10]= "#0#####0#0#####0#0#000#0#0#";
    map[11]= "#0#00000#0#000#0#0###0#0#0#";
    map[12]= "#0#000#0#0#000#00000#0#0###";
    map[13]= "#####0#0#0#000#0#####0#000#";
    map[14]= "#0#000#0#0##00#0#00000#0#0#";
    map[15]= "#0#000#000000000#0#####0#0#";
    map[16]= "#0###0###########0#00000#0#";
    map[17]= "#0#0#000000#000000#0###0#0#";
    map[18]= "#0#0#0####0#0######0#0#0#0#";
    map[19]= "#0#0#000000#0#000000#0#0#0#";
    map[20]= "#0#0########0#0######0#0###";
    map[21]= "#000000000000#0#000000#0#0#";
    map[22]= "#0############0#0######0#0#";
    map[23]= "#0000000000#000#00000000#0#";
    map[24]= "##########0#0#0##########0#";
    map[25]= "00000000000#0#000000000000#";
    map[26]= "###########################";
    }

    
    if (map == NULL) {
        printf("L'allocation de mémoire a échoué.\n");
        exit(EXIT_FAILURE);
    }
}
