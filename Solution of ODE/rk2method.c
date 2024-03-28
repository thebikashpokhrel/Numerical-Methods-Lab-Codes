#include <stdio.h>

float f(float x,float y){
    return 2.0*y/x;
}

int main(){
    float xo,yo,h,xn,y1;
    float k1,k2,k;

    printf("Enter the initial condition xo,yo: \n");
    scanf("%f %f",&xo,&yo);

    printf("Enter the value of xn: \n");
    scanf("%f",&xn);

    printf("Enter the step size: ");
    scanf("%f",&h);

    do{
        k1 = h*f(xo,yo);
        k2 = h*f(xo+h,yo+k1);
        k = (k1+k2)/2;
        y1 = yo+ k;
        xo = xo + h;
        yo = y1;
    }while(xo<xn);

    printf("The value of y at x = %f is %.4f",xn,y1);
    return 0;
}
