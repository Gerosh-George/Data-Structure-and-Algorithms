#include <iostream>

using namespace std;

template <class T>
class Sort
{

private:
    T *arr;
    int count;    // current no. of elements in heap
    int arr_size; // dynamic size of heap array
    bool smin;    // flag to check if min heap is to be made
    bool smax;    // flag to check if max heap is to be made

public:
    Sort()
    {
        this->count = 0;
        this->arr_size = 0;
        this->smax = false;
        this->smin = false;
    }

    //deconstructor
    ~Sort()
    {
        free(this->arr);
    }

    template <size_t N>
    void minHeapSort(T (&item)[N])
    {
        this->smin = true;
        this->smax = false;
        count = arr_size = N;
        makeHeap(item);

        for (int i = 0; i < arr_size; i++)
        {
            pop();
        }
    }

    template <size_t N>
    void maxHeapSort(T (&item)[N])
    {
        this->smax = true;
        this->smin = false;
        count = arr_size = N;
        makeHeap(item);

        for (int i = 0; i < arr_size; i++)
        {
            pop();
        }
    }

    void print()
    {
        for (int i = 0; i < arr_size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    // returns true if arr[i]<=arr[j]
    bool less(int i, int j)
    {
        if (arr[i] <= arr[j])
            return true;
        return false;
    }

    // returns true if arr[i]>=arr[j]
    bool more(int i, int j)
    {
        if (arr[i] >= arr[j])
            return true;
        return false;
    }

    //swaps the value at arr[i] and arr[j]
    void swap(int i, int j)
    {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    //moves the element value down the tree to make it obey the heap invariant property
    void sink(int i)
    {

        while (true)
        {

            int right = 2 * i + 2;
            int left = 2 * i + 1;

            //for min heap
            if (smin)
            {
                int smaller = left; //assuming left is small for now

                if (right < count and less(right, smaller))
                {
                    smaller = right;
                }

                if (left >= count or less(i, left))
                {

                    break;
                }

                swap(i, smaller);
                i = smaller;
            }

            //for max heap
            if (smax)
            {
                int larger = left; //assuming left is larger for now

                if (right < count and more(right, larger))
                {
                    larger = right;
                }

                if (left >= count or more(i, left))
                {
                    break;
                }

                swap(i, larger);
                i = larger;
            }
        }
    }

    //removes the root value from the heap
    void pop()
    {
        swap(0, count - 1);
        count--;
        sink(0);
    }

    //builds the heap array using heapify process which takes O(n)
    void makeHeap(int items[])
    {
        this->arr = new T[count];

        for (int i = 0; i < count; i++)
        {
            arr[i] = items[i];
        }

        for (int i = count / 2 - 1; i >= 0; i--)
            sink(i);
    }
};

int main()
{
    Sort<int> s;
    int a[5] = {5, 1, 3, 2, 4};

    cout << "Original array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    s.maxHeapSort(a);
    cout << "Ascending order(max heap): ";
    s.print();

    s.minHeapSort(a);
    cout << "Descending order(min heap): ";
    s.print();
}