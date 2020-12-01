#include <iostream>
using namespace std;

int arr_size = 10;
int a[10] = {40, 42, 44, 43, 46, 41, 47, 45, 39, 50};

void display()
{
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void selection_sort()
{
    int i,j,min;
    int n=sizeof(a)/sizeof(a[0]);
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        int t= a[i];
        a[i]= a[min];
        a[min]= t;
        cout<<i<<"-"<<min<<"--->";
        display();
    }
}

int main()
{
    cout<<"Original Array is:"<<endl;
    display();
    cout<<endl;
    cout<<"Sorting starts."<<endl;
    selection_sort();
    cout<<"Sorting ends."<<endl;
    cout<<endl;
    cout<<"Sorted Array is:"<<endl;
    display();
    return 0;
}