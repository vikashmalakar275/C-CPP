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

