#include <stdio.h>
#include <time.h>

int RecursiveBS(int arr[],int left,int right,int x)
{
    if(left == right)
    {
        if(arr[left] == x)
        {
            return left;
        }
        else
        {
            return -1;
        }
    }
    int mid = (left + right)/2;
    if(arr[mid] == x)
    {
        return mid;
    }
    else if(x < arr[mid])
    {
        return RecursiveBS(arr,left,mid-1,x);
    }
    else
    {
        return RecursiveBS(arr,mid+1,right,x);
    }
}

int IterativeBS(int arr[],int left,int right,int x)
{
    while(left<=right)
    {
        int mid = (left + right -1)/2;
        if(arr[mid] == x)
        {
            return mid;
        }
        if(arr[mid]<x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int result1 = 0;
    int result2 = 0;
    int n,value;
    printf("Enter the size of array =\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the element :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Please enter the number which you want to search = \n");
    scanf("%d",&value);
    clock_t t1;
    t1 = clock();
    result1 = RecursiveBS(arr,0,n,value);
    t1 = clock() - t1;
    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

    clock_t t2;
    t2 = clock();
    result2 = IterativeBS(arr,0,n,value);
    t2 = clock() - t2;
    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds
 
    printf("RecursiveBS took %f seconds to execute \n", time_taken1);
    printf("IterativeBS took %f seconds to execute \n", time_taken2);
    if(result1==0)
    {
        printf("Opps! Element not found");
    }
    else
    {
        printf("Hooray! Element present at position %d",result1);
    }
    return 0;
}