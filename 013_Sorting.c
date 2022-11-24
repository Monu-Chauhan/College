#include<stdio.h>
void bubbleSort(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void SelectionSort(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        int minind=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[minind]>arr[j])
            {
                minind=j;
            }

        }
        int temp = arr[minind];
        arr[minind]=arr[i];
        arr[i]=temp;
    }

}

int main()
{
    int arr[10]={30,11,32,23,94,75,66,7,38,19};
    //bubbleSort(arr,10);
    //SelectionSort(arr,10);
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}