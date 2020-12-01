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

void insert_sort()
{
    int i,j,key;
    int n=sizeof(a)/sizeof(a[0]);
    for(i=0;i<n;i++)
    {
       key = a[i];  
        j = i - 1;  
        cout<<endl<<"Iteration no: "<<i+1<<endl;
        while (j >= 0 && a[j] > key) 
        {  
            a[j + 1] = a[j];  
            cout<<"Value in "<<j<<" is shifted to "<<j+1<<endl;
            display();
            j = j - 1;  
        }  
        cout<<"Value in "<<j+1<<" is made "<<key<<endl;
        a[j + 1] = key;  
    }
}

int main()
{
    cout<<"Original Array is:"<<endl;
    display();
    cout<<endl;
    cout<<"Sorting starts."<<endl;
    insert_sort();
    cout<<"Sorting ends."<<endl;
    cout<<endl;
    cout<<"Sorted Array is:"<<endl;
    display();
    return 0;
}