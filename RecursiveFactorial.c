#include <stdio.h>
#include <windows.h>

int factorial(int n);

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n;
    printf("input number: ");
    scanf("%d",&n);

    printf("%d\n",factorial(n));

    return 0;
}

int factorial(int n){
    if (n==0){
        return 1;
    }
    else if(n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}