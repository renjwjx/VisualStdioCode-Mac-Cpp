/*



*/

#include <stdio.h>
#include <stdlib.h>

void SelectSort(int data[], int n);
void QuickSort(int data[], int low, int high);
void ShellSort(int data[], int n);

int main() {

    int i = 1233;
    
    int data[10] = {32, 16, 9, 21, 10, 13, 47, 45, 67, 34};
    // SelectSort(data, 10);
    // QuickSort(data, 0, 9);
    ShellSort(data, 10);
    for ( int i = 0; i < 10; i++)
    {
        printf("%d, ", data[i]);
    }


}

void SelectSort(int data[], int n)
{
    int i, j, k, temp;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for(j = i + 1; j < n; j++)
         {
            if(data[j] < data[k])
            {
                k = j;
            }
         }
        if (k != i)
        {
            temp = data[i];
            data[i] = data[k];
            data[k] = temp;
        }
    }

}

void QuickSort(int data[], int low, int high)
{
    printf(" %d -- %d \n", low, high);
    int i, pivotkey, j;
    if (low < high)
    {
        pivotkey = data[low];
        i = low;
        j = high;
        while(i < j)
        {
            while(i < j && data[j] >= pivotkey)
            {
                j--;
            }   
            if(i < j)
            {
                data[i++] = data[j];
            }
            while(i < j && data[i] <= pivotkey)
            {
                i++;
            }
            if(i < j)
            {
                data[j--] = data[i];
            }
            data[i] = pivotkey;
            QuickSort(data, low, i - 1);
            QuickSort(data, i + 1, high);
        }
    }
}

void ShellSort(int data[], int n)
{
    int *delta, k, i, t, dk, j;
    k = n;
    delta = (int *)malloc(sizeof(int)*(n/2));
    i = 0;
    do{
        k = k/2;
        delta[i++] = k;
    }while(k > 1);
    i = 0;
    while((dk = delta[i]) > 0) {
        for (k = delta[i]; k < n; ++k)
        {
            if(data[k] < data[k - dk])
            {
                t = data[k];
                for(j = k-dk; j>= 0 && t < data[j]; j -=dk)
                { 
                    data[j+dk] = data[j];
                }
                data[j+dk] = t;
            }
        }
        ++i;
    }
}