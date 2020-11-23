#include <stdio.h>

int arr_size = 11;
int a[11] = {14, 5, 8, 3, 1, 10, 12, 7, 4, 9, 11};

void display()
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[], int lb, int ub)
{
    int pivot = lb;
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (a[start] <= a[pivot])
        {
            start++;
        }
        while (a[end] > a[pivot])
        {
            end--;
        }
        if (start < end)
            swap(a, start, end);
    }

    swap(a, end, pivot);

    printf("%d---> ", end);
    display();
    return end;
}

void quicksort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int partition_index = partition(a, lb, ub);
        quicksort(a, lb, partition_index - 1);
        quicksort(a, partition_index + 1, ub);
    }
}

int main()
{
    printf("Original array: ");
    display();
    printf("\nProcess Start....");
    quicksort(a, 0, 10);
    printf("Process End....\n\n");
    display();
}