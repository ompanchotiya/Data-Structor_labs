#include <stdio.h>
void main()
{
    int n, k;
    int sum = 0, count = 0, max = 0;

    printf("Enter a size of array: ");
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter a number: ");
    scanf("%d", &k);
    int len = 0;
    int max_len = 0;
    for (int j = 0; j < n; j++)
    {
         sum = 0;
        for (int i = j; i < n; i++)
        {
           
            sum = sum + a[i];
            if (sum <= k)
            {
                len = (i - j + 1);
                
                if (len > max_len)
                {
                    max_len = len;
                }
            }
            else
            {
            
                break;
            }
        }
    }
    printf("%d", max_len);
}