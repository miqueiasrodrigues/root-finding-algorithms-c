/*
Author: Miqueias R.
Date: Mar 9, 2021
Metodo_newton
*/
#include <stdio.h>
#include <math.h>

double funcao(double x);
double funcao_der(double x);

int main()
{
    double array_x[5], toli, tol = 0.00001;
    int i = 1;

    array_x[0] = 2;
    printf("interacao%10s%17s%14s\n","xNS","f(xNS)","toli");
    printf("-----------------------------------------------------\n");

    do{
        array_x[1] = array_x[0] - (funcao(array_x[0])/funcao_der(array_x[0]));

        toli = fabs((array_x[1] - array_x[0])/array_x[0]);
        printf("%4d %16.8lf %14.8lf %14.8lf \n",i,array_x[1], funcao(array_x[1]),toli);
        array_x[0] = array_x[1];
        i++;
    } while(toli > tol);
     return 0;
}

double funcao(double x){
    double fx;
    fx = 5*(4*acos((2-x)/2)-(2-x)*sqrt(4*x-x*x))-8.5;
    return fx;
}
double funcao_der(double x){
    double fx;
    fx = -(10*(x-4)*x)/sqrt(-(x-4)*x);
    return fx;
}
