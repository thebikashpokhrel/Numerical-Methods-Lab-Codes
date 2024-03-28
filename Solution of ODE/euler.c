#include <stdio.h>

float f(float x, float y){
    return x+y;
}

int main(){
    float xo,yo,xn,h,m;

    printf("Enter the value of xo,yo: \n");
    scanf("%f %f",&xo,&yo);

    printf("Enter the value of xn: \n");
    scanf("%f",&xn);

    printf("Enter the value of step size: ");
    scanf("%f", &h);

    do{
        m = f(xo,yo);
        yo = yo + h*m;
        xo = xo + h;
    }while(xo < xn);

    printf("The value is %.4f at x = %f",yo,xn);
}
