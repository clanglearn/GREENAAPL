#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    int i=0,j=0;

    int arr[3][3] = {
        {7, 1, 4},
        {3, 8, 5},
        {2, 2, 1}
    };
    printf("층 호: ");
    scanf("%d %d", &i,&j);
    getchar();


    printf("%d층 %d호: %d명\n", i,j, arr[i][j]);
    printf("\n");

    int pNum=0,room=0;
    for(int floor=0;floor<3;floor++){

        for(room=0;room<3;room++){
            pNum+=arr[floor][room];

        }
        printf("%d층 %d명\n",floor,pNum);
        pNum=0;
    }

    return 0;
}