/*



*/

#include <stdio.h>
#include <stdlib.h>
#include "Singleton.h"
#include "Resume.h"
#include <iostream>
#include "Cache.h"

#include "Composite.h"
#include "Leaf.h"

void SelectSort(int data[], int n);
void QuickSort(int data[], int low, int high);
void ShellSort(int data[], int n);
void printData(int data[], int n);

int main() {
    
    int data[10] = {32, 16, 9, 21, 10, 13, 47, 45, 67, 34};
    // SelectSort(data, 10);
    // QuickSort(data, 0, 9);
    // ShellSort(data, 10);
    printData(data, sizeof(data));

//Design Patterns-- Singleton
    printf("Design Patterns -- Singleton");
    Singleton* singleton = Singleton::GetInstance();
    singleton->show();

//Design Patterns -- Prototype
    printf("Design Patterns -- Prototype");
    Resume *r1 = new ResumeA("r2");
    Resume *r2 = r1->Clone();
    r2->Set("r2");
    r1->Show();
    r2->Show();


//Design Patterns -- Strategy
    printf("Design Patterns -- Strategy");
    Cache cache(new FIFO_ReplaceAlgorithm());
    cache.Replace();


    printf("Design Patterns -- Composite");

    Component *pRoot = new Composite("000");

    Component *pDepart1 = new Composite("111");
    pDepart1->Add(new Leaf("22221"));
    pDepart1->Add(new Leaf("22222"));
    pRoot->Add(pDepart1);

    pRoot->Add(new Leaf("112"));
    Component *pLeaf = new Leaf("113");
    pRoot->Add(pLeaf);
    
    pRoot->Operation(1);

    delete pRoot;

    std::cout<<"main() Exit"<<std::endl;
    return 0;
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

void printData(int data[], int n)
{
    for ( int i = 0; i < 10; i++)
    {
        printf("%d, ", data[i]);
    }
    printf("\n");
}