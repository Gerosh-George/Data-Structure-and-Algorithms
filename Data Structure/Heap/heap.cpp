// implementing min binary heap
// for max heap just invert the comparison of the elements (instead of minimum find maximum)

#include <iostream>

using namespace std;

//using array representation of tree as heaps are compulsorily going to be a complete binary tree
template <class T>
class Heap
{

private:
    int heapcount; // number of current elements in the heap
    int heapsize;  // internal dynamic size of heap
    T *arr_heap;

public:
    Heap()
    {
        this->heapcount = 0;
        this->heapsize = 0;
    }

    Heap(int n)
    {
        this->heapsize = n;
        this->arr_heap = new T[heapsize];
        this->heapcount = 0;
    }

    ~Heap()
    {
        free(this->arr_heap);
    }

    // builds the heap from an array of elements
    template <size_t N>
    void buildHeap(T (&items)[N])
    {
        heapsize = heapcount = (sizeof(items) / sizeof(items[0]));
        if (!arr_heap)
            this->arr_heap = new T[heapsize];

        for (int i = 0; i < heapcount; i++)
        {
            arr_heap[i] = items[i];
        }

        //heapify process;
        //it takes log(n) to build the heap
        for (int i = heapcount / 2 - 1; i >= 0; i--)
            sink(i);
    }

    //inserts an element into the heap
    void push(T value)
    {
        if (heapcount == heapsize)
            heapsize++;

        arr_heap[heapcount] = value;
        heapcount++;
        swim(heapcount - 1);
    }

    // removes the min value from the heap
    void pop()
    {
        if (heapcount == 0)
        {
            throw runtime_error("Heap is empty!");
        }
        swap(0, heapcount - 1);
        cout << "Removed valued: " << arr_heap[heapcount - 1] << endl;
        heapcount--;
        sink(0);
    }

    //displays the heap array and heap count
    void print()
    {

        cout << "Heap Count: " << heapcount << endl;
        cout << "Heap array: ";
        for (int i = 0; i < heapcount; i++)
        {
            cout << arr_heap[i] << " ";
        }
        cout << endl;
    }

    int len()
    {
        return heapcount;
    }

private:
    // helper function that finds index having minimum value between i and j
    int minimum(int i, int j)
    {
        if (arr_heap[i] < arr_heap[j])
            return i;
        return j;
    }

    //helper function to swap two values in heap array
    void swap(int i, int j)
    {
        T temp = arr_heap[i];
        arr_heap[i] = arr_heap[j];
        arr_heap[j] = temp;
    }

    // moves the smaller element value upwards
    void swim(int i)
    {
        while (i != 0)
        {
            int parent = (i - 1) / 2;
            int small = minimum(i, parent);
            if (small == parent)
            {
                break;
            }
            else
            {
                swap(i, parent);
                i = parent;
                swim(i);
            }
        }
    }

    // sink the larger value to the bottom of the tree
    void sink(int i)
    {

        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int small = -1;
            if (right >= heapcount)
            {
                small = left;
            }
            else
            {
                small = minimum(left, right);
            }

            if (arr_heap[i] < arr_heap[small] || i >= heapcount / 2)
            {
                break;
            }
            swap(small, i);
            i = small;
        }
    }

    //checks if the heap invariant property is satisfied or not
    //here it is Min Heap
    bool isMinHeap()
    {
        if (heapcount == 0)
        {
            throw runtime_error("Heap is empty!");
        }

        int i = 0;
        while (i < heapcount / 2)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (right < heapcount)
            {
                if (i != minimum(i, left) || i != minimum(i, right))
                    return false;
            }
            i++;
        }

        return true;
    }
};

int main()
{
    Heap<int> heap;
    int a[7] = {7, 6, 5, 4, 3, 2, 1};

    cout << "Input array: ";
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    heap.buildHeap(a);

    // for (int i = 0; i < 7; i++)
    // {
    //     heap.push(a[i]);
    // }

    heap.print();

    for (int i = 0; i < 7; i++)
    {
        heap.pop();
    }
}