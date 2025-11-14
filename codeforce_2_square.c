#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int arr[x][4];
    for(int i=0;i<x; i++)
    {
        for(int j=0; j<4; j++)
        scanf("%d",&arr[i][j]);
    }
    for(int i=0; i<x; i++)
    {
        if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3])
        printf("YES\n");
        else
            printf("NO\n");
    }
}
