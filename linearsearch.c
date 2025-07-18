#include<stdio.h>
int main()
{
    int num;
    int i, key, flag=0;
    scanf("%d",&num);
    int arr[num];
    printf("Enter the number of values: ");
    for(int i=0; i<num; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Find the elements you want to search: ");
    scanf("%d",&key);
    for(int i=0; i<num; i++)
    {
        if(arr[i]==key){
            flag=1;
            break;
        }

    }
    if(flag==1) {
        printf("Found\n");
    }
    else {
        printf("Not Found\n");
    }
    return 0;
}