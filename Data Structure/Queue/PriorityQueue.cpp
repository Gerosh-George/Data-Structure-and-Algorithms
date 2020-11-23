// Min binary Heap implementation is used
// only integers are allowed
// to make it Generic Template class can be used.

#include <iostream>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <cmath>

using namespace std;

class PriorityQueue
{
private:
    int heapcount;    // the number of elements currently inside the heap
    int heapcapacity; //the internal capacity of heap
    list<int> heap;   // dynamic list to track the elemenst in the heap

    //This map keeps track of the possible index of a particular node element found in the heap.
    //This mapping lets us have O(log(n)) removals and O(1) element containment check.
    //At the cost of some small overhead and additional space.
    map<int, set<int>> map1;

public:
    //construct empty priority queue.
    PriorityQueue()
    {
        this->heapcapacity = 0;
        this->heapcount = 0;
    }

    //construct PQ with initial capacity.
    PriorityQueue(int size)
    {
        this->heapcapacity = size;
        this->heapcount = 0;
    }

    bool isEmpty()
    {
        return heapcount == 0;
    }

    int len()
    {
        return heapcount;
    }

    //constructs a PQ with defined array passed to the function
    template <size_t N>
    void buildPQ(int (&items)[N])
    {

        heapcapacity = heapcount = (sizeof(items) / sizeof(items[0]));

        for (int i = 0; i < heapcount; i++)
        {

            mapAdd(items[i], i);
            heap.push_back(items[i]);
        }

        //heapify process, O(n)
        for (int i = max(0, (heapcount / 2) - 1); i >= 0; i--)
            sink(i);
    }

    //shows the element which can be removed next
    int peek()
    {
        if (isEmpty())
            return -1;
        list<int>::iterator itr = heap.begin();
        return *itr;
    }

    //displays all the elements present in Priority Queue (array representation form)
    void print()
    {
        list<int>::iterator it;
        for (it = heap.begin(); it != heap.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        /*
        cout<<boolalpha<<isMinHeap(0)<<endl;
        printMap();
        */
    }

    //insertion of element
    void add(int item)
    {
        if (item == NAN)
            throw std::runtime_error("not a number");

        if (heapcount < heapcapacity)
        {
            heap.push_back(item);
        }
        else
        {
            heap.push_back(item);
            heapcapacity++;
        }

        mapAdd(item, heapcount);

        swim(heapcount);
        heapcount++;
    }

    // checks if the element is present or not
    bool contains(int item)
    {
        map<int, set<int>>::iterator itr;
        itr = map1.find(item);

        if (itr == map1.end())
            return false;

        return true;
    }

    // Removes the root of the heap, O(log(n))
    int poll()
    {
        return removeAt(0);
    }

    // Removes a particular element in the heap, O(log(n))
    bool remove(int item)
    {

        if (contains(item))
        {
            int index = mapGet(item);
            removeAt(index);
            return true;
        }

        return false;
    }

private:
    // Recursively checks if this heap is a min heap
    // This method is just for testing purposes to make
    // sure the heap invariant is still being maintained
    // Called this method with k=0 to start at the root
    bool isMinHeap(int k)
    {

        // If we are outside the bounds of the heap return true
        if (k >= heapcount)
            return true;

        int left = 2 * k + 1;
        int right = 2 * k + 2;

        // Make sure that the current node k is less than
        // both of its children left, and right if they exist
        // return false otherwise to indicate an invalid heap
        if (left < heapcount and !less(k, left))
            return false;
        if (right < heapcount and !less(k, right))
            return false;

        // Recurse on both children to make sure they're also valid heaps
        return isMinHeap(left) and isMinHeap(right);
    }

    bool less(int i, int j)
    {

        list<int>::iterator node = heap.begin();
        auto node1 = next(node, i);
        auto node2 = next(node, j);

        if (*node1 <= *node2)
            return true;

        return false;
    }

    //new value inserted in map
    void mapAdd(int value, int index)
    {

        set<int> set1 = map1[value];
        set1.insert(index);
        map1[value] = set1;
    }

    // Perform bottom up node swim, O(log(n))
    void swim(int k)
    {

        int parent = (k - 1) / 2;

        // Keep swimming while we have not reached the
        // root and while we're less than our parent.
        while (k > 0 and less(k, parent))
        {

            swap(parent, k);
            k = parent;

            parent = (k - 1) / 2;
        }
    }

    // Top down node sink, O(log(n))
    void sink(int k)
    {

        while (true)
        {

            int left = 2 * k + 1;
            int right = 2 * k + 2;
            int smallest = left; //assumption

            // Find which is smaller left or right
            // If right is smaller set smallest to be right
            if (right < heapcount and less(right, left))
                smallest = right;

            // Stop if we're outside the bounds of the tree
            // or stop early if we cannot sink k anymore
            if (left >= heapcount or less(k, smallest))
                break;

            // Move down the tree following the smallest node
            swap(smallest, k);
            k = smallest;
        }
    }

    void swap(int i, int j)
    {
        list<int>::iterator node = heap.begin();
        auto nodei = next(node, i);
        int element_i = *nodei;

        auto nodej = next(node, j);
        int element_j = *nodej;

        *nodei = element_j;
        *nodej = element_i;

        mapSwap(element_i, element_j, i, j);
    }

    void mapSwap(int val1, int val2, int val1Index, int val2Index)
    {

        set<int> set1 = map1[val1];
        set<int> set2 = map1[val2];

        set1.erase(val1Index);
        set2.erase(val2Index);

        set1.insert(val2Index);
        set2.insert(val1Index);

        map1[val1] = set1;
        map1[val2] = set2;
    }

    //Removes a node at particular index, O(log(n))
    int removeAt(int i)
    {
        if (isEmpty())
            return int(NAN);

        heapcount--;

        list<int>::iterator itr = heap.begin();
        auto node = next(itr, i);
        int item_to_remove = *node;

        swap(i, heapcount);

        // Obliterate the value
        heap.pop_back();
        mapRemove(item_to_remove, heapcount);

        // Removed last element
        if (i == heapcount)
            return item_to_remove;

        int item = *node;

        sink(i);

        if (*node == item)
            swim(i);

        return item_to_remove;
    }

    int mapGet(int value)
    {
        set<int> set1 = map1[value];
        set<int>::iterator itr;
        itr = set1.end();
        itr--;
        return *itr;
    }

    void mapRemove(int value, int index)
    {
        set<int> set1 = map1[value];
        set1.erase(index);
        map1[value] = set1;
        if (set1.empty())
            map1.erase(value);
    }

    // shows the map table of values to thier indices
    void printMap()
    {
        map<int, set<int>>::iterator itr;

        for (itr = map1.begin(); itr != map1.end(); ++itr)
        {
            cout << itr->first << " : ";
            set<int> varset = itr->second;
            set<int>::iterator it;
            for (it = varset.begin(); it != varset.end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // * Min heap gives priority to smallest number hence the PQ will pop the smallest number present in it *//

    // int a[] = {1, 5, 1, 8, 6, 2, 2, 13, 12, 11, 7, 2, 15, 3, 10};

    PriorityQueue pq;
    
    //pq.buildPQ(a);  // directly insert the array 'a' into the function and create the PQ

    //or else individually also we can add
    cout << "Adding '9' into PQ" << endl;
    pq.add(9);

    cout << "Adding '4' into PQ" << endl;
    pq.add(4);

    cout << "Adding '15' into PQ" << endl;
    pq.add(15);

    cout << "Adding '7' into PQ" << endl;
    pq.add(7);

    cout << endl
         << "Values in PQ are: ";
    pq.print();

    cout << endl
         << "Number of elements in PQ: " << pq.len() << endl;

    cout << endl
         << "Value that can be popped next (peek):" << pq.peek() << endl;

    cout << "Value popped: " << pq.poll() << endl;

    cout << endl
         << "Adding '10' into PQ" << endl;
    pq.add(10);

    cout << "Adding '5' into PQ" << endl;
    pq.add(5);

    cout << endl
         << "is 10 present in PQ: " << boolalpha << pq.contains(10) << endl;
    cout << "is 3 present in PQ: " << boolalpha << pq.contains(3) << endl;
    cout << "Number of elements in PQ now: " << pq.len() << endl;

    cout << endl
         << "Popping all values: ";
    int l = pq.len();
    for (int i = 0; i < l; i++)
    {
        cout << pq.poll() << " ";
    }
}

//1 5 3 9 8 5 4 2 6 7
//1 5 1 8 6 2 2 13 12 11 7 2 15 3 10