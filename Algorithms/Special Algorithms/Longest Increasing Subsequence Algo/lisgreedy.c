#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int upper_bound(int arr[], int item, int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int longest_increasing_subsequence(int arr[], int n)
{
    int pile_top[n], pile_length[n];
    for (int i = 0; i < n; i++)
    {
        pile_top[i] = 1000;
        pile_length[i] = 0;
    }

    for (int i =0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pile_top[j] > arr[i])
            {
                pile_top[j] = arr[i];
                pile_length[j] += 1;
                break;
            }
        }

        //int j = upper_bound(pile_top, arr[i], n);
        //pile_top[j] = arr[i];
        //pile_length[j] += 1;

        display(pile_top, n);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (pile_top[i] == 1000)
            break;
        ans++;
    }
    display(pile_length, n);
    return ans;
}

int main()
{
    int input[14] = {0, 5, 2, 1, 4, 7, 6, 5, 14, 16, 3, 7, 8, 9};

    printf("%d", longest_increasing_subsequence(input, 14));
}