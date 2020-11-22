#include <iostream>

using namespace std;

//generic class for queue
template <class T>
class Queue
{
private:
    T *ptr;
    int front;
    int rear;
    int size;
    int count;

public:
    Queue()
    {
        this->ptr = new T[5];
        this->size = 5;
        this->count = 0;
        this->front = -1;
        this->rear = -1;
    }

    //deconstructor
    ~Queue()
    {
        free(ptr);
    }

    //inserting element into queue
    void enqueue(T item)
    {

        if (count == size)
        {
            T arr[size];
            for (int i = 0; i < count; i++)
            {
                arr[i] = ptr[i];
            }

            delete[] ptr;
            ptr = new T[size * 2];
            size = size * 2;

            for (int i = 0; i < count; i++)
            {
                ptr[i] = arr[i];
            }
        }

        if (front == rear and front == -1)
        {
            front = 0;
            rear = 0;
        }

        ptr[rear++] = item;
        count++;
    }

    //to delete the element at the front of queue
    T dequeue()
    {
        T a;
        if (front == rear)
        {
            throw std::runtime_error("Queue is empty");
        }
        else
        {

            a = ptr[front++];

            if (front == rear)
            {
                front = -1;
                rear = -1;
            }

            count--;
        }

        return a;
    }

    //size of queue
    int len()
    {
        return count;
    }

    void print()
    {

        for (int i = front; i < rear; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    // shows the element that is at the front of the queue
    T peek()
    {
        if (front == rear)
        {
            throw std::runtime_error("Queue is empty");
        }

        return ptr[front];
    }
};

int main()
{
    Queue<int> q;

    cout << "Inserting 1-10 into the queue" << endl;

    for (int i = 1; i <= 10; i++)
    {
        q.enqueue(i);
    }

    cout << "The element to be removed (peek): " << q.peek() << endl;
    q.print();
    cout << "The element removed from the queue:  " << q.dequeue() << endl;
    cout << "Remainig elements in the queue: ";
    q.print();
}
