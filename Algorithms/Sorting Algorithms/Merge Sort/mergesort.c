#include <stdio.h>

int arr_size = 10;
int a[10] = {40, 42, 44, 43, 46, 41, 47, 45, 39, 50};

// makes the changes in original array
void copy(int b[], int lb, int ub)
{
    int k = 0;
    for (int i = lb; i <= ub; i++)
    {
        a[i] = b[k++];
    }
}

void display()
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//combines the subset array in sorted order
void merge(int a[], int lb, int mid, int ub)
{
    int b[ub - lb + 1];
    int i = lb;
    int k = 0;
    int j = mid + 1;


    while (i <= mid && j <= ub)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }


    if (i > mid)
    {   
        //remaining elements in j
        while (j <= ub)
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    else
    {   
        //remaining elements in i
        while (i <= mid)
        {
            b[k] = a[i];
            k++;
            i++;
        }
    }

    copy(b, lb, ub);
    printf("%d-%d---> ", lb, ub);
    display();
}

//breaks the main array into smaller subsets
void mergesort(int a[], int lb, int ub)
{
    if (lb < ub)
    {

        int mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main()
{
    printf("original array: ");
    display();
    printf("\nProcess Start....\n");
    printf("[index range which got sorted in that iteration]-->.....\n");
    mergesort(a, 0, 9);
    printf("Process End....\n\n");
    printf("Sorted array: ");
    display();
}