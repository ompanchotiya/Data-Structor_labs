#include<stdio.h>
int binarySearch(int a[],int s, int e, int k){
    int mid  =(s+e)/2;
        if(a[mid] == k){
           return mid;
        }
        else if(a[mid] < k){
            return binarySearch(a,mid,e,k);
        }
        else{
            return binarySearch(a,s,mid,k);
        }
    }
void main(){
    int n, k;
    int s = 0;
    printf("Enter a size of array: ");
    scanf("%d",&n);

    int a[n];
    int e = n;
    for(int i=0; i<n; i++){
        printf("Enter a Element %d: ",i);
        scanf("%d",&a[i]);
    }

    printf("Enter a number you want to search: ");
    scanf("%d", &k);

    int ans = binarySearch(a, s, e, k);

    printf("%d", ans);
}