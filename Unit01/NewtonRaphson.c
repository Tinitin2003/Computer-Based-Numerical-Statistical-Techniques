#include<stdio.h>
#include<math.h>
#define EPS 0.00005
#define f(x) 3*x-cos(x)-1
#define df(x) 3+sin(x)
void NEW_RAP();
void main()
{
    system("cls");
    printf("\nSolution by NEWTON RAPHSON method\n");
    printf("\nEquation is");
    printf("\n\t\t\t 3*x-cos(x)-1=0\n\n");
    NEW_RAP();
}
void NEW_RAP(){
    float x1,x0,f0,f1,df0;
    int i=1,itr;
    for(x1=0;;x1+=0.1){
        f1=f(x1);
        if(f1>0){
            break;
        }
    }
    x0=x1-0.01;
    f0=f(x0);
    printf("Enter the number of iterations:");
    scanf("%d",&itr);
    if(fabs(f0)>f1){
        printf("\n\t\tThe root is near to %.4f\n",x1);
    }
    if(f1>fabs(f(x0))){
        printf("\n\t\tThe root is near to %.4f\n",x0);
    }
    x0=(x0+x1)/2;
    for( ;i<=itr;i++){
        f0=f(x0);
        df0=df(x0);
        x1=x0-(f0/df0);
        printf("\n\t\tThe %d approximation to the root is : %f",i,x1);
        if(fabs(x1-x0)<EPS){
            break;
        }
        x0=x1;
    }
    if(fabs(x1-x0)>EPS){
        printf("\n\n\t NOTE : - ");
        printf("The number of iterations are not sufficient.");
    }
    printf("\n\n\n\n\t\t\t----------------------------------------------------------------------");
    printf("\n\t\t\t  The root is %.4f",x1);
    printf("\n\t\t\t----------------------------------------------------------------------");
}