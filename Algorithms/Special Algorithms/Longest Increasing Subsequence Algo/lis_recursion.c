#include <stdio.h>

int mem[14];

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int lis_ending_here(int arr[], int index)
{   
    if(mem[index]!=0) return mem[index];

    if (index == 0)
        return 1;

    int ans = 1;
    for (int i = index - 1; i >= 0; i--)
    {
        if (arr[i] < arr[index])
            ans = max(ans, 1 + lis_ending_here(arr, i));
    }

    mem[index]=ans;
    return ans;
}

int longest_increasing_subsequence(int arr[], int n)
{
    int max_ans = 1;

    for (int i = 0; i <n; i++)
    {
        max_ans = max(max_ans, lis_ending_here(arr, i));
    }

    return max_ans;
}

int main()
{
    int input[14] = {0, 5, 2, 1, 4, 7, 6, 5, 14, 16, 3, 7, 8, 9};

    printf("%d", longest_increasing_subsequence(input, 14));
}