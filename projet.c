#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#include <termios.h>


#include "variable.h"

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
        printf("L'allocation de mémoire a échoué.\n");
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

int main(){
    
    // printf("%f\n",rayon(M_PI/6.0));
    // printf("%d", test_carre(pos_j));
    system("clear");
    /*for(float i=0;i<M_PI*6;i = i +0.1){
        regard_j = i;
        usleep(50000);
        // printf("%d",getchar());
        image();
    }*/
printf("Choisissez la difficulté du labirynthe: \n 1: Facile \n 2: Difficile \n ");
    char input;
    int difficulte;

    scanf("%c", &input);
    if (input == '1') {
        difficulte = 1;
    }
    else if (input == '2') {
        difficulte = 2;
    } else {
        printf("Tu n'es pas très inteligent il faut mettre un nombre entre 1 et 2.\n");
        exit(2);
    }

    printf("Choisissez vos parametres graphiques (1, 2, 3 ou 4): \n 1: Bas  \n 2: Moyen \n 3: Eleve \n 4: Cyberpunk \n ATTENTION IL FAUT D ABORD DEZOOM AU MAXIMUM AVANT D APPUYER SUR ENTREE \n");
    printf("%c",input);
    char input2;
    scanf(" %c", &input2);

    if (input2 == '1') {
        def_var(2, difficulte);
    }
    else if (input2 == '2') {
        def_var(4, difficulte);
    }
    else if (input2 == '3') {
        def_var(6, difficulte);
    }
    else if (input2 == '4') {
        def_var(8, difficulte);
    }
    else{
        printf("Tu n'es pas très inteligent il faut mettre un nombre entre 1 et 4.\n");
        exit(2);
    }
    
    printf("salut");
    

    image();
    while (test_carre_sortie(pos_j)==false){
        char input;
        scanf("%c", &input);
        if (input == 'q'){
            float fin = regard_j + M_PI/2 + 0.0001;
            for(float i=regard_j + M_PI/16 ;i<fin;i = i + M_PI/16){ // pour que le mouvement soit progressif
                regard_j = i ;
                // usleep(10000);
                // printf("%f , %f\n",i,fin);
                image();
            }
        }
        if (input == 'd'){
            float fin = regard_j - M_PI/2 - 0.0001;
            for(float i=regard_j - M_PI/16 ;i>fin;i = i - M_PI/16){ // pour que le mouvement soit progressif
                regard_j = i ;
                // usleep(10000);
                // printf("%f , %f\n",i,fin);
                image();
            }
        }
        if (input == 'z'){
            float pas_x = cosf(regard_j)*(taille_carre/5);
            float pas_y = sinf(regard_j)*(taille_carre/5);
            float future_position_j[2] = {(pos_j[0] + pas_x*5),  (pos_j[1] - pas_y*5)};  // verifie qu'il n'y a pas de murs
            if (test_carre(future_position_j) == true || test_carre_sortie(future_position_j)) {
                for (int i = 0; i<100; i = i+20){ // 5 itérations pour que le mouvement soit progressif
                pos_j[0] = pos_j[0] +pas_x;
                pos_j[1] = pos_j[1] -pas_y;
                image();
            }
        }
        }
        if (input == 's'){
            float pas_x = cosf(regard_j)*(taille_carre/5);
            float pas_y = sinf(regard_j)*(taille_carre/5);
            float future_position_j[2] = {(pos_j[0] - pas_x*5),  (pos_j[1] + pas_y*5)}; // verifie qu'il n'y a pas de murs
            if (test_carre(future_position_j) == true || test_carre_sortie(future_position_j)) {
            for (int i = 0; i<100; i = i+20) { // 5 itérations pour que le mouvement soit progressif
                pos_j[0] = pos_j[0] -pas_x;
                pos_j[1] = pos_j[1] +pas_y;
                image();
            }
        }
        }
        input = '0';
    }
    system("clear");
    printf("\033[38;2;255;255;0m"
"-----------  --------  ------------ ----    ----      --------      --------   ----    ---- ------------       ------------ ----    ----         ------     ------------     ------------ -----------    --------   ----    ---- ---    ---  ------------       ----            ------         ------------   --------   -----------  ------------ --------  ------------ \n"
"***********  ********  ************ *****   ****      ********     **********  ****    **** ************       ************ ****    ****        ********    ************     ************ ***********   **********  ****    **** ***    ***  ************       ****           ********        ************  **********  ***********  ************ ********  ************ \n"
"----       -   ----    ----         ------  ----        ---       ----    ---- ----    ---- ----               ------------ ----    ----       ----------   ----             ------------ ----    ---  ----    ---- ----    ---- ---    ---  ----               ----          ----------       ----         ----    ---- ----    ---  ------------   ----    ----         \n"
"***********    ****    ************ ************        ***       ***      *** ****    **** ************           ****     ****    ****      ****    ****  ************         ****     *********    ***      *** ****    **** ***    ***  ************       ****         ****    ****      ************ ***      *** *********        ****       ****    ************ \n"
"-----------    ----    ------------ ------------        ---       ---      --- ----    ---- ------------           ----     ----    ----      ------------  ------------         ----     ---------    ---      --- ----    ---- ---    ---  ------------       ----         ------------      ------------ ---      --- ---------        ----       ----    ------------ \n"
"****       *   ****    ****         ****  ******        ***   **  ****    **** ************ ****                   ****     ************      ************         *****         ****     ****  ****   ****    **** ************  ********   ****               ************ ************             ***** ****    **** ****  ****       ****       ****    ****         \n"
"-----------  --------  ------------ ----   -----        --------   ----------  ------------ ------------           ----     ------------      ----    ----  ------------         ----     ----   ----   ----------  ------------   ------    ------------       ------------ ----    ----      ------------  ----------  ----   ----      ----     --------  ------------ \n"
"***********  ********  ************ ****    ****        ********    ********   ************ *************          ****     ************      ****    ****  ************         ****     ****    ****   ********   ************    ****     ************       ************ ****    ****      ************   ********   ****    ****     ****     ********  ************ \n"
"\n");
    free(map);
}   