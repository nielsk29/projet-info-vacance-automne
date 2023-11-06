#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#include <termios.h>

#include "fonction.h"
#include "variable.h"

int main(){
    def_var();
    // printf("%f\n",rayon(M_PI/6.0));
    // printf("%d", test_carre(pos_j));
    system("clear");
    /*for(float i=0;i<M_PI*6;i = i +0.1){
        regard_j = i;
        usleep(50000);
        // printf("%d",getchar());
        image();
    }*/
    image();
    while (true){
        char ex;
        scanf("%c", &ex);
        if (ex == 'q'){
            float fin = regard_j + M_PI/2 + 0.0001;
            for(float i=regard_j + M_PI/16 ;i<fin;i = i + M_PI/16){
                regard_j = i ;
                usleep(10000);
                // printf("%f , %f\n",i,fin);
                image();
            }
        }
        if (ex == 'd'){
            float fin = regard_j - M_PI/2 - 0.0001;
            for(float i=regard_j - M_PI/16 ;i>fin;i = i - M_PI/16){
                regard_j = i ;
                usleep(10000);
                // printf("%f , %f\n",i,fin);
                image();
            }
        }
        if (ex == 'z'){
            for (int i = 0; i<100; i = i+20){
                pos_j[0] = pos_j[0] +cosf(regard_j)*20;
                pos_j[1] = pos_j[1] -sinf(regard_j)*20;
                image();
            }
        }
        if (ex == 's'){
            for (int i = 0; i<100; i = i+20){
                pos_j[0] = pos_j[0] -cosf(regard_j)*20;
                pos_j[1] = pos_j[1] +sinf(regard_j)*20;
                image();
            }
        }
        ex = '0';
    }
}   