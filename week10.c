/*
HW NUMBER: 3
FILE NAME : SolutionToCH10Problems.c
YYYYMMDD : 20241102
AUTHOR : 컴퓨터공학과 1학년 C311188 박주민
PURPOSE : (과제문서에서 COPY/PASTE)

1. 10장의 모든 Exercise 문제들을 스스로 학습하시오. (제출하지 않음)
(각 문제에 대한 정답은 (a) 출판사에서 제공된(다운받은) 정답, (b) Googling 하여 찾아진 정답
등을 사용하여 확인)
2. 10장의 Programming 문제: 01,02,03,04,05,06,07 에 대한 솔루션 코드를 다음과 같은 방식으로 소스파일을 작성한 후, 프로그램 실행결과와 함께 제출:
1) 모든 문제에 대한 C 솔루션 코드를 main()함수 안에 문제 순서대로 주석을 붙여서 작성
2) 각 문제에 대한 입력 값과 출력 결과는 문제에서 제시한 것들을 사용/확인
3) 소스파일 이름은 반드시 아래에서 제시한 파일명을 사용
4) 소스파일은 VisualStudio 2022를 사용하여 작성 (원하다면 다른 IDE 도구를 사용할 수 있음)
5) 소스파일의 실행결과는 과제 제출시 유의사항(C) 문서에 기술된 방식대로 실행화면을 캡쳐하여
   소스파일과 함께, 아래와 같이, 제출

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define SIZE 10 // #define SIZE 10 으로 상수 선언
int AreArraysEqual(int arr1[], int arr2[]);  // AreArraysEqual 프로토타입 
void DoSelectionSort(int arr[]);   // DoSelectionSort 프로토타입
int DoSequentialSearch(int arr[]);  //DoSequentialSearch 프로토타입
void CopyArray(int arr1[], int arr2[]); //CopyArray 프로토타입

int AreArraysEqual(int arr1[], int arr2[]){ // 배열이 동일한지 판단하는 함수 선언
    for(int i=0;i<SIZE;i++){ // i가 0번째부터 SIZE-1번째까지 배열의 전구간을 훑어본다
        if(arr1[i] != arr2[i]){
            return 0;   // 두 배열은 다를때 0 반환
            break; // 하나의 요소만 다르더라도 배열 전체가 같지 않기 때문에 break;를 통해 반복문을 탈출한다
        }
        else{
            continue; // 일단 요소끼리는 같다(잠재적 정답) 다시 반복한다
        }
        return 1; // 두 배열은 같다 (완벽한 정답) 1 반환
    }
}

void DoSelectionSort(int arr[]){ // 선택정렬 함수 선언
    for(int i=0;i<SIZE-1;i++){ // i가 0번째부터 SIZE-1번째까지 배열의 전구간을 훑어본다 (이중 for문을 사용해서 선택정렬을 구현한다)
        int least=i; // 최솟값을 넣을 int 변수 선언
        int temp; // 임시로 값을 넣을 int형 변수 선언
        for(int j=i+1;j<SIZE;j++){ // // j가 (i+1)번째부터 SIZE-1번째까지 배열의 전구간을 훑어본다
            if(arr[j]>arr[least]){ // arr[j]가 arr[least]보다 크다면
                continue;   // least 값을 유지한다
            }
            else{
                least=j; // a[least]보다 작은 수가 나타나면 least에 j를 할당한다
            }
        }
        temp=arr[i]; // temp를 이용해서 arr[i]와 arr[least]의 값을 바꾼다
        arr[i]=arr[least]; // arr[least]의 값을 arr[i]에 넣는다
        arr[least]=temp; // temp의 값을 arr[least]에 넣는다

    }
    printf("SORTED num1 = "); // 출력문
    for(int i=0;i<SIZE;i++) // i가 0번째부터 SIZE-1번째까지 배열의 전구간을 훑어본다
    printf("%d ",arr[i]);   // 반복문을 통해 정렬된 배열 출력
    
}

int DoSequentialSearch(int arr[]){
    int max = 0; // max를 0으로 설정
    for(int i=0;i<SIZE;i++){ // i가 0번째부터 SIZE-1번째까지 배열의 전구간을 훑어본다
        if (arr[max]<arr[i]){ // arr[max]<arr[i] 이라면 max에 i를 넣는다
            max = i;
        }
    }
    return arr[max]; // 결론적으로 배열에서 가장 큰 값을 반환한다
}

void CopyArray(int arr1[], int arr2[]){ // 배열1 배열2를 인자로 받는다
    printf("nums2 BEFORE COPY = ");  // 배열2가 아직 변경되지 않았다는 것을 알려주기 위해 쓰는 출력문
    for(int i=0;i<SIZE;i++){ // i가 0번째부터 SIZE-1번째까지 배열의 전구간을 훑어본다
        printf("%d ",arr2[i]); // 배열2가 변경되기 전 상태를 출력한다
    }

    printf("\n"); // 가독성을 위해 줄 바꿈

    for(int j=0;j<SIZE;j++){ // j가 0번째부터 SIZE-1번째까지 배열의 전구간을 훑어본다
        arr2[j]=arr1[j]; // 배열2의 각각의 자리에 배열1의 값을 할당한다
    }
    printf("nums2 AFTER COPY = "); // 배열2가 변경되었다는 것을 알려주기 위해 쓰는 출력문
    for(int i=0;i<SIZE;i++){ // i가 0번째부터 SIZE-1번째까지 배열의 전구간을 훑어본다
        printf("%d ",arr2[i]); // 배열2가 변경된 상태를 출력한다
    }
}

int main(void) { //(7)
    SetConsoleOutputCP(CP_UTF8);

    //(1) 
    int nums1[SIZE], nums2[SIZE]; 
    srand((unsigned)time(NULL)); //time()으로 rand 함수 seed 바꾸기

    for(int i=0;i<SIZE;i++)
        nums1[i]=(rand()%101); // 0부터 100사이의 정수 난수 생성
    
    for(int j=0;j<SIZE;j++)
        nums2[j]=(rand()%101); // 0부터 100사이의 정수 난수 생성
    
    //(2)
    printf("nums1 = ");
    for(int i=0;i<10;i++) 
        printf("%d ",nums1[i]); // 배열 nums1의 요소들 출력

    printf("nums2 = ");
    for(int j=0;j<10;j++)
        printf("%d ",nums2[j]); // 배열 nums2의 요소들 출력
        printf("\n"); // 가독성을 위해 줄 바꿈
    
     //(3)
    if(AreArraysEqual(nums1,nums2)==0){
        printf("THE nums1 IS DIFFERENT WITH nums2."); // 배열이 같을 때 출력문
    }
    else{
        printf("THE nums1 IS SAME WITH nums2."); // 배열이 다를 때 출력문
    }
    printf("\n"); // 가독성을 위해 줄 바꿈
    printf("\n"); // 가독성을 위해 줄 바꿈

    //(4)
    DoSelectionSort(nums1);
    printf("\n"); // 가독성을 위해 줄 바꿈
    printf("\n"); // 가독성을 위해 줄 바꿈

    //(5)
    printf("THE LARGEST OF num1 is %d",DoSequentialSearch(nums1));
    printf("\n"); // 가독성을 위해 줄 바꿈
    printf("\n"); // 가독성을 위해 줄 바꿈

    //(6)
    CopyArray(nums1, nums2);
    printf("\n"); // 가독성을 위해 줄 바꿈

    return 0;
}