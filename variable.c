#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "variable.h"
const int l_map[2] = {6,6};
const int taille_carre = 100;
const int taille_map[2] = {l_map[0]*taille_carre,l_map[1]*taille_carre};
const char* map = "######"
                  "#0000#"
                  "#0#00#"
                  "#0000#"
                  "#0000#"
                  "######";
float pos_j[2] = {350,350};
float regard_j = M_PI;
const float angle_regard = M_PI/3;
const int t = 3;
const int nb_rayon = 100*t;
const int taille_ecran = 40*t; 
int def_var()
{

}
