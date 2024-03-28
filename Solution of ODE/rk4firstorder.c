#include <stdio.h>

float f(float x,float y){
    return exp(x) - 2*y;
}

int main(){
    float xo,yo,h,xn,y1;
    float k1,k2,k3,k4,k;

    printf("Enter the initial condition xo,yo: \n");
    scanf("%f %f",&xo,&yo);

    printf("Enter the value of xn: \n");
    scanf("%f",&xn);

    printf("Enter the step size: ");
    scanf("%f",&h);

    do{
        k1 = h*f(xo,yo);
        k2 = h*f(xo+h/2,yo+k1/2);
        k3 = h*f(xo+h/2,yo+k2/2);
        k4 = h*f(xo+h,yo+k3);
        k = (k1+2*k2+2*k3+k4)/6;
        y1 = yo+ k;
        xo = xo + h;
        yo = y1;
    }while(xo<xn);

    printf("The value of y at x = %f is %.4f",xn,y1);
    return 0;
}

