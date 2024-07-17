#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    int n;

    printf("input n: ");
    scanf("%d",&n);
    
    char ans= (n>90) ? 'A' : (n>80) ? 'B': 'F';

    printf("%c\n",ans);

    return 0;
}