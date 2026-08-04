#include<stdio.h>
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

    while(s < e){
            if(a[(s+e)/2] != k){
                if(a[(s+e)/2] < k){
                    s = ((s+e)/2);
                }
                else{
                    e = ((s+e)/2);
                }
            }
            else{
                printf("%d", (s+e)/2);
                break;
            }
        }
}