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

void bubble_sort()
{
    int i,j,t;
    int n=sizeof(a)/sizeof(a[0]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                cout<<j<<"-"<<j+1<<"--->";
                display();
            }
        }
    }
}

int main()
{
    cout<<"Original Array is:"<<endl;
    display();
    cout<<endl;
    cout<<"Sorting starts."<<endl;
    bubble_sort();
    cout<<"Sorting ends."<<endl;
    cout<<endl;
    cout<<"Sorted Array is:"<<endl;
    display();
    return 0;
}
