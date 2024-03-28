#include <stdio.h>

float f(float x){
    return x*sin(x) + cos(x);
}

float df(float x){
    return x*cos(x);
}

int main(){
    float xo,x1,temp,fxo,dfxo,E;

    printf("Enter the initial guess xo: ");
    scanf("%f",&xo);

    printf("Enter the tolerable error: ");
    scanf("%f",&E);
    do{
        fxo = f(xo);
        dfxo = df(xo);
        if(fabs(dfxo) < 0.00001){
            printf("Slope too small");
            return ;
        }
        x1 = xo - fxo/dfxo;
        temp = xo;
        xo = x1;
    }while(fabs(x1 - temp) >= E);

    printf("One of the required solution is %.5f",x1);
}
