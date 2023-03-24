#include <stdio.h>
#include <time.h>

int RecursiveLS(int arr[],int value,int index,int n)
{
    int pos = 0;
    if(index>=n)
    {
        return 0;
    }
    else if(arr[index] == value)
    {
        pos = index + 1;
        return pos;
    }
    else
    {
        return RecursiveLS(arr,value,index+1,n);
    }
}
int IterativeLS(int arr[],int value,int n)
{
    int pos = 0;
    if(n<=0)
    {
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==value)
        {
            pos = i+1;
        }
    }
    return pos;
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
    result1 = RecursiveLS(arr,value,0,n);
    t1 = clock() - t1;
    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

    clock_t t2;
    t2 = clock();
    result2 = IterativeLS(arr,value,n);
    t2 = clock() - t2;
    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds
 
    printf("RecursiveLS took %f seconds to execute \n", time_taken1);
    printf("IterativeLS took %f seconds to execute \n", time_taken2);
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

