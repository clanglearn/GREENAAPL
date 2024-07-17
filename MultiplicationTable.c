#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    
    //1~3단
    int num=1;
    
    while(1){

        int i=1;

        while (i<10){
        printf("%d * %d = %d\n",num,i,num*i);
        i++;
        }
        num++;
        printf("\n");

        if (num>3){
            break;
        }
    }
    
    //4~6단
        int a=4,b=1;

    do{
        printf("%d * %d = %d\n",a,b,a*b);
        b++;
        if (b==10){
            a++;
            b=1;
            printf("\n");
        }
    } 
        while (a<7 && b<10);

    //7~9단        

    for(int n=7;n<10; n++){
        for(int m=1;m<10;m++){
            printf("%d * %d = %d\n",n,m,n*m);
        }
        printf("\n");
    }

    return 0;
}