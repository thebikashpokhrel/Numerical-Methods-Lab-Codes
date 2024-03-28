
#include <stdio.h>

float f(float x, float y){
    return 2*x+sin(y);
}

int main(){
    float xo,yo,xn,h,m, mavg, yold, mold, temp;

    printf("Enter the value of xo,yo: \n");
    scanf("%f %f",&xo,&yo);

    printf("Enter the value of xn: \n");
    scanf("%f",&xn);

    printf("Enter the value of step size: ");
    scanf("%f", &h);

    do{
        yold = yo;
        m = f(xo,yo);
        mold = m;
        yo = yo + m * h;
        xo = xo + h;
        do{
            m = f(xo,yo);
            mavg = (m + mold)/2;
            temp = yo;
            yo = yold +  mavg * h;
        }while(fabs(yo - temp) >= 0.0001);
    }while(xo < xn);

    printf("The value is %f at x = %f",yo,xn);
}
