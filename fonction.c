#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "fonction.h"
#include "variable.h"

// on utilise des floats pour faciliter les calculs et pour pouvoir etre entre deux positions
bool test_carre(float* pos){//fonction qui prend en paramètre des coordonées et qui permet de savoir si il y a un mur a cet endroit
    int carre_x = pos[0]/taille_carre; // position du carré
    int carre_y = pos[1]/taille_carre;
    return map[carre_y][carre_x] == '0'; // return true si les coordonées sont dans du vide 
}

float rayon(float direction){ // fonction envoie un rayon dans une direction (radiant) qui commence du joueur jusqu'a qu'il touche un mur 
    float pos[2] ; //position du rayon
    pos[0] = pos_j[0];
    pos[1] = pos_j[1];
    while (test_carre(pos)){//tant que la position du rayon est dans le vide
        // on augmente la pos x du cosinus de direction et le y du sinus ce qui permet d'augmenter la longueur du rayon de 1
        // c'est comme si on créer un cercle trigo autour de la pos du rayon puis on change les coordonées a celle de direction dans le cercle
        pos[0] = pos[0]+cosf(direction);
        pos[1] = pos[1]-sinf(direction);
        // printf("%f , %f\n",pos[0],pos[1]);
    }
    // printf("%f,%f\n",pos[0], pos[1]);
    return (sqrtf(powf((ceilf(pos[0])-pos_j[0]),2.0) + powf((ceilf(pos[1])-pos_j[1]),2.0))); // on renvoie la longueur du rayon donc la dif entr la pos final du rayon et celle du joueur qu'on calcul avec pythagore
}

void image() // fonction qui créer une image en utilisant la fonction rayon avec beaucoup de rayon dans le l'angle de vision du joueur
{
    float dif_dir = angle_regard / (float) nb_rayon; //angle de différence entre les rayons
    
    int* long_barre = malloc(sizeof(int)*nb_rayon);
     //chaque rayon correspond a une colone de l'affichage et donc cet variable est la longueur du mur dans la colonne de chaque rayon
     if (long_barre == NULL) {
        printf(stderr, "L'allocation de mémoire a échoué.\n");
        exit(EXIT_FAILURE);
    }

    int* couleur = malloc(sizeof(int)*nb_rayon); // on memorise chaque couleurs des barres de rayons pour ne pas avoir à les calculer
    if (couleur == NULL) {
        printf(stderr, "L'allocation de mémoire a échoué.\n");
        exit(EXIT_FAILURE);
    }

    float i = regard_j+angle_regard/2; //direction du premier rayon
    for(int t=0;t<nb_rayon;t=t+1){//boucle pour chaque rayon
        long_barre[t] = (int) roundf((35*taille_ecran)/(rayon(i)*cosf(regard_j-i))); //taille de la barre du rayon par colonne calculer avec la fonction rayon
        couleur[t] = (long_barre[t]*200/taille_ecran+55);
        // printf("%d : %f ; %d\n",t,i,long_barre[t]);
        i = i-dif_dir; // calcul du prochain rayon
    }
    printf("\033[0;0H"); // remettre le curseur en haut
    // partie qui affiche
    for (int i = 0; i<taille_ecran; i++){ // pour chaque colonne
        for (int l=0; l<nb_rayon; l++){ // pour chaque ligne
                if (abs(i-taille_ecran/2)<long_barre[l]){ // si curseur en haut
                    printf("\033[48;2;%d;0;0m  ",couleur[l]);
                }
                else if (i>taille_ecran/2){
                    printf("\033[47m  "); // affiche ciel
                }else{
                    printf("\033[44m  "); // affiche sol
                }
        }
        printf("\n\e[0");
    }
    free(long_barre);
    free(couleur);
}
