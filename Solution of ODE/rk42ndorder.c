#include <stdio.h>
float f(float x,float y, float z){
    return z;
}

float g(float x, float y, float z){
    return x*z*z - y*y;
}

int main(){
    float xo,yo,zo,h,xn,y1,z1;
    float k1,l1,k2,l2,k3,l3,k4,l4,k,l;

    printf("Enter the initial condition xo,yo,zo: \n");
    scanf("%f %f %f",&xo,&yo, &zo);

    printf("Enter the value of xn: \n");
    scanf("%f",&xn);

    printf("Enter the step size: ");
    scanf("%f",&h);

    while(xo<xn){
        k1 = h*f(xo,yo,zo);
        l1 = h*g(xo,yo,zo);

        k2 = h*f(xo+h/2,yo+k1/2, zo+l1/2);
        l2 = h*g(xo+h/2,yo+k1/2, zo+l1/2);

        k3 = h*f(xo+h/2,yo+k2/2,zo + l2/2);
        l3 = h*g(xo+h/2,yo+k2/2,zo + l2/2);

        k4 = h*f(xo+h,yo+k3, zo + l3);
        l4 = h*g(xo+h,yo+k3, zo + l3);

        k = (k1+2*k2+2*k3+k4)/6;
        l = (l1 + 2*l2+2*l3+l4)/6;

        y1 = yo+ k;
        z1 = zo + l;
        xo = xo + h;
        yo = y1;
        zo = z1;
    }

    printf("The value of y at x = %f is %.4f",xn,y1);
    return 0;
}

