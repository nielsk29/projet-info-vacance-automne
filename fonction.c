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
bool test_carre_sortie(float* pos){//fonction qui prend en paramètre des coordonées et qui permet de savoir si il y a un mur a cet endroit
    int carre_x = pos[0]/taille_carre; // position du carré
    int carre_y = pos[1]/taille_carre;
    return map[carre_y][carre_x] == 'S'; // return true si les coordonées sont dans du vide 
}
float* rayon(float direction){ // fonction envoie un rayon dans une direction (radiant) qui commence du joueur jusqu'a qu'il touche un mur 
    static float pos[2] ; //position du rayon
    pos[0] = pos_j[0];
    pos[1] = pos_j[1];
    while (test_carre(pos)){//tant que la position du rayon est dans le vide
        // on augmente la pos x du cosinus de direction et le y du sinus ce qui permet d'augmenter la longueur du rayon de 1
        // c'est comme si on créer un cercle trigo autour de la pos du rayon puis on change les coordonées a celle de direction dans le cercle
        pos[0] = pos[0]+cosf(direction)/4;
        pos[1] = pos[1]-sinf(direction)/4;
        // printf("%f , %f\n",pos[0],pos[1]);
    }
    // printf("%f,%f\n",pos[0], pos[1]);
    return pos;
}
void image() // fonction qui créer une image en utilisant la fonction rayon avec beaucoup de rayon dans le l'angle de vision du joueur
{
    float dif_dir = angle_regard / (float) nb_rayon; //angle de différence entre les rayons
    
    int* long_barre = malloc(sizeof(int)*nb_rayon);
     //chaque rayon correspond a une colone de l'affichage et donc cet variable est la longueur du mur dans la colonne de chaque rayon
    if (long_barre == NULL) {
        printf( "L'allocation de mémoire a échoué.\n");
        exit(EXIT_FAILURE);
    }

    int* couleur = malloc(sizeof(int)*nb_rayon); // on memorise chaque couleurs des barres de rayons pour ne pas avoir à les calculer
    if (couleur == NULL) {
        printf( "L'allocation de mémoire a échoué.\n");
        exit(EXIT_FAILURE);
    }
    bool* sortie = malloc(sizeof(bool)*nb_rayon); // on memorise chaque couleurs des barres de rayons pour ne pas avoir à les calculer
    if (couleur == NULL) {
        printf(, "L'allocation de mémoire a échoué.\n");
        exit(EXIT_FAILURE);
    }
    float i = regard_j+angle_regard/2; //direction du premier rayon
    for(int t=0;t<nb_rayon;t=t+1){//boucle pour chaque rayon
        float pos[2] = {rayon(i)[0],rayon(i)[1]};
        float longueur_rayon = sqrtf(powf((roundf(pos[0])-pos_j[0]),2.0) + powf((roundf(pos[1])-pos_j[1]),2.0));
        long_barre[t] = (int) roundf((24*taille_ecran)/(longueur_rayon*cosf(regard_j-i))); //taille de la barre du rayon calluer avec la fonction rayon
        sortie[t] = test_carre_sortie(pos);
        couleur[t] = (long_barre[t]*200/taille_ecran+55);
        // printf("%d : %f ; %d\n",t,i,long_barre[t]);
        i = i-dif_dir; // calcul du prochain rayon
    }
    // char* affichage=(char*)malloc(sizeof(char)*(taille_ecran*nb_rayon*3*13+1)) ; //allocation de la mémoire du string qui va avoir l'image
    // affichage[0] = 0; //intialise la fin du string
    printf("\033[0;0H");
    for (int i = 0; i<taille_ecran; i++){
        for (int l=0; l<nb_rayon; l++){
                if (abs(i-taille_ecran/2)<long_barre[l]){
                    // strncat(affichage,"\033[31m#\033[00m",12);
                    if (sortie[l]==true){
                        printf("\033[38;2;%d;%d;0m*",couleur[l],couleur[l]);
                    }else{
                        printf("\033[38;2;%d;0;0m*",couleur[l]);
                    }
                }
                else if (i>taille_ecran/2){
                    // strncat(affichage,"\033[37m%\033[00m",13);
                    printf("\033[37m*");
                }else{
                    // strncat(affichage,"\033[34m*\033[00m",12);
                    printf("\033[34m*");
                }
        }
        // strncat(affichage,"\n",2);
        printf("\n\e[0");
    }
    // printf("%s\n",affichage);
    // free(affichage);
}
