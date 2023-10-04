#include<stdio.h>
#include<math.h>

#define EPS 0.00005
#define f(x) x*x*x-5*x+1

void SEC();

void main(){
    system("cls");
    printf("\nSolution by SECANT method\n");
    printf("\nEquation is");
    printf("\n\t\t\t x*x*x-5*x+1=0\n\n");
    SEC();
}

void SEC(){
    float f0,f1,f2;
    float x0,x1,x2;
    int itr;
    int i;
    printf("Enter the number of iteration:");
    scanf("%d",&itr);
    for(x1=0.0; ;){
        f1=f(x1);
        if(f1>0){
            break;
        }else{
            x1+=0.1;
        }
    }
    x0=x1-0.1;
    f0=f(x0);
     printf("\n\t\t----------------------------------------------------------------------");
    printf("\n\t\t  ITERATION\t x2\t\t F(x)\n");
    printf("\t\t----------------------------------------------------------------------");
    for(i=0;i<itr;i++){
        x2=x1-((x1-x0)/(f1-f0))*f1;
        f2=f(x2);
    }

}