
#include <iostream>

void sortinsert(int arr[], int size)
{
    int temp, pos;
    for (size_t i = 1; i < size; i++)
    {
        temp = arr[i];
        pos = i - 1;
        while (pos>=0 && arr[pos] > temp)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

void quicksort(int arr[], int first, int last)
{
    int i = first;
    int j = last;
    int temp;
    int x = arr[(first + last) / 2];

    do
    {
        while (arr[i]<x)
        {
            i++;
        }
        while (arr[j]>x)
        {
            j--;
        }
        if (i<=j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;  
            i++;
            j--;

        }
    } while (i<=j);
    if (i<last)
    {
        quicksort(arr, i, last);
    }
    if (first < j)
    {
        quicksort(arr, first, j);
    }
}

void fillarr(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 15;
    }
}

void printarr(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    /////exercise 1
    const int size = 9;
    int arr1[size];

    fillarr(arr1, size);

    if (size <= 10)
    {
        sortinsert(arr1, size);
        printarr(arr1, size);

    }
    else
    {
        quicksort(arr1, 0, size-1);
        printarr(arr1, size);
    }

    //////////

    //////exercise 2

    const int max = 10;
    const int b = 10;
    int arr[max];

    fillarr(arr, max);

    printarr(arr, max);

    int buckets[b][max + 1];

    for (size_t i = 0; i < b; i++)
    {
        buckets[i][max] = 0;
    }

    for (int digit = 1; digit < 1000000000; digit *= 10)
    {
        for (size_t i = 0; i < max; i++)
        {
            if (arr[i] % 2 == 0)
            {
                int d = (arr[i] / digit) % b;
                int counter = buckets[d][max];
                buckets[d][counter] = arr[i];
                counter++;
                buckets[d][max] = counter;
                arr[i] = -1;
            }
        }
        int idx = 0;
        for (size_t i = 0; i < b; i++)
        {
            for (size_t j = 0; j < buckets[i][max]; j++)
            {
                while (arr[idx] != -1)
                {
                    idx++;
                }
                arr[idx] = buckets[i][j];
            }
            buckets[i][max] = 0;

        }
    }


    printarr(arr, max);

    ///////

    system("pause");
    return 0;
}

