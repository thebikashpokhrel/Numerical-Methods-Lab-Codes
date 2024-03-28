#include <stdio.h>

int main(){
    int n,d;
    double A[100][100], x[20], y[20], z[20];
    printf("Enter the number of data: ");
    scanf("%d",&n);
    printf("Enter the degree of polynomial curve: ");
    scanf("%d", &d);

    //Get values pairs (x,y) from users
    for(int i = 0;i<n;i++){
        printf("Enter the value of x[%d]: ", i+1);
        scanf("%lf", &x[i]);
        printf("Enter the value of y[%d]: ", i+1);
        scanf("%lf", &y[i]);
    }

    //check whether number of data is less than the degree of curve
    if( n < d){
        return 0;
    }

    //Form the sum matrices
    for(int i = 0;i<=d;i++){
        for(int j = 0; j<=d; j++){
            A[i][j] = 0;
            for(int k = 0;k < n ; k++){
                A[i][j] += pow(x[k], i+j);
            }
        }
    }
    //Complete the augmented matrix
    for(int i = 0; i<=d;i++){
        A[i][d+1] = 0;
        for(int k = 0;k<n;k++){
            A[i][d+1] += pow(x[k],i) * y[k];
        }
    }

    //Print the augmented matrix
    printf("The augmented matrix is : \n");
    for(int i=0;i<n;i++){
        for(int j = 0; j<=n;j++){
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }

    //Applying Gauss Jordan
    float t;
    for(int j = 0; j<=d;j++){
        if(fabs(A[j][j]) <= 0.0005){
            printf("Pivot row is zero\n");
            return;
        }
        for(int i = 0;i<=d;i++){
            if(i != j){
                t = A[i][j]/A[j][j];
            }
            for(int k = 0; k<=d+1;k++){
                A[i][k] = A[i][k] -t * A[j][k];
            }
        }
    }

    printf("\n The cofficients are :\n");
    for(int i = 0;i<=d;i++){
        z[i] = A[i][d+1]/A[i][i];
        printf("%lf \n",z[i]);
    }
    return 0;
}
