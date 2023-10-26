#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#include <termios.h>

#include "fonction.h"
#include "variable.h"

int main(){
    // def_var();
    // printf("%f\n",rayon(M_PI/6.0));
    // printf("%d", test_carre(pos_j));
    system("clear");
    for(float i=0;i<M_PI*6;i = i +0.1){
        regard_j = i;
        usleep(50000);
        // printf("%d",getchar());
        image();
    }
    printf("\n");
}