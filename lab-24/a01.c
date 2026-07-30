#include<stdio.h>
void main(){
    int n, k;

    printf("Enter a size of array: ");
    scanf("%d",&n);

    int a[n];

    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

    printf("Enter a number you want to search: ");
    scanf("%d", &k);

    for(int i=0; i<n; i++){
        if(a[i] == k){
            printf("index of your number: %d",i);
            break;
        }
    }
}