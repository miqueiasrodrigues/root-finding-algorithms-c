/*
Author: Miqueias R.
Date: Mar 10, 2021
Metodo_secante
*/
#include <stdio.h>
#include <math.h>

double funcao(double x);

int main()
{
    double array_x[5], toli, tol = 0.00001;
    int i = 1;

    array_x[0] = 0;
    array_x[1] = 4;
    printf("interacao%8s%16s%15s\n","xNS","f(xNS)","toli");
    printf("----------------------------------------------------\n");

    do{
        array_x[2] = array_x[1] - ((funcao(array_x[1])*(array_x[0]-array_x[1]))/(funcao(array_x[0])-funcao(array_x[1])));
        toli = fabs(funcao(array_x[2]));
        printf("%4d %14.8lf %14.8lf %14.8lf\n",i,array_x[2], funcao(array_x[2]),toli);

        array_x[0] = array_x[1];
        array_x[1] = array_x[2];
        i++;
    } while(toli > tol);
     return 0;

}
double funcao(double x){
    double fx;
    fx = 5*(4*acos((2-x)/2)-(2-x)*sqrt(4*x-x*x))-8.5;
    return fx;
}
