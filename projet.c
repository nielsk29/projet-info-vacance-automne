#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#include <termios.h>

#include "fonction.h"
#include "variable.h"


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
        int difficulte = 1;
    }
    else if (input == '2') {
        int difficulte = 2;
    } else {
        printf("Tu n'es pas très inteligent il faut mettre un nombre entre 1 et 2.\n");
        exit(2);
    }

    system("clear");
    printf("Choisissez vos parametres graphiques (1, 2, 3 ou 4): \n 1: Bas  \n 2: Moyen \n 3: Eleve \n 4: Cyberpunk \n ATTENTION IL FAUT D ABORD DEZOOM AU MAXIMUM AVANT D APPUYER SUR ENTREE \n");
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
    while (true){   
        char input;
        scanf("%c", &input);
        if (input == 'q'){
            float fin = regard_j + M_PI/2 + 0.0001;
            for(float i=regard_j + M_PI/16 ;i<fin;i = i + M_PI/16){ // pour que le mouvement soit progressif
                regard_j = i ;
                usleep(10000);
                // printf("%f , %f\n",i,fin);
                image();
            }
        }
        if (input == 'd'){
            float fin = regard_j - M_PI/2 - 0.0001;
            for(float i=regard_j - M_PI/16 ;i>fin;i = i - M_PI/16){ // pour que le mouvement soit progressif
                regard_j = i ;
                usleep(10000);
                // printf("%f , %f\n",i,fin);
                image();
            }       
        }
        if (input == 'z'){
            float pas_x = cosf(regard_j)*(taille_carre/5);
            float pas_y = sinf(regard_j)*(taille_carre/5);
            float future_position_j[2] = {(pos_j[0] + pas_x*5),  (pos_j[1] - pas_y*5)};  // verifie qu'il n'y a pas de murs
            if (test_carre(future_position_j) == true) {
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
            if (test_carre(future_position_j) == true) {
            for (int i = 0; i<100; i = i+20) { // 5 itérations pour que le mouvement soit progressif
                pos_j[0] = pos_j[0] -pas_x;
                pos_j[1] = pos_j[1] +pas_y;
                image();
            }
            }
        }
        input = '0';
    }
}   