#include <stdio.h>

int main(){
    int n,i,j,k;
    float A[20][20],x[20];
    float t;

    //Read n from user
    printf("Enter the number of variables: ");
    scanf("%d",&n);

    //Get the matrix from user
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            printf("Enter element A[%d][%d]: ",i,j);
            scanf("%f",&A[i][j]);
        }
    }

    //Apply Gauss Elimination
    for(j=0;j<n;j++){
        if(fabs(A[j][j]) <= 0.0005){
            printf("Diagonal element too small");
            return;
        }else{
            for(i=0;i<n;i++){
                if(i > j){
                    t = A[i][j]/A[j][j];
                    for(k=0;k<=n;k++){
                        A[i][k] = A[i][k] - t * A[j][k];
                    }
                }
            }
        }
    }

    //Back Substitution
    float sum;
    for(i=n-1;i>=0;i--){
        sum = 0;
        for(j=i+1;j<n;j++){
            sum += A[i][j] * x[j];
        }
        x[i] = (A[i][n] - sum)/A[i][i];
    }

    //Print the solution
    for(i=0;i<n;i++){
        printf("x%d = %.3f\n",i+1,x[i]);
    }
}
