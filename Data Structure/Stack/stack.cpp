#include <iostream>

using namespace std;

//generic class
template <class T>
class Stack
{

private:
    T *ptr;
    int top = 0;
    int size = 5;

public:
    Stack()
    {
        ptr = new T[5];
    }

    //deconstructor
    ~Stack()
    {
        free(ptr);
    }

    //for inserting the element into the stack
    void push(T item)
    {
        // create new array if stack overflow happens
        if (top == size)
        {
            T arr[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = new T[size * 2];
            size = size * 2;

            for (int i = 0; i < top; i++)
            {
                ptr[i] = arr[i];
            }
        }
        ptr[top] = item;
        top++;
    }

    // for removing the element at the top of the stack
    T pop()
    {
        if (top == 0)
        {
            throw std::runtime_error("Stack Underflow Exception");
        }
        top--;
        T a = ptr[top];
        return a;
    }

    //shows what element is present at the top of the stack
    T peek()
    {
        if (top == 0)
        {
            throw std::runtime_error("Stack is empty");
        }
        return ptr[top - 1];
    }

    int length()
    {
        return top;
    }

    // shows all the elements in the stack
    void print()
    {
        for (int i = 0; i < top; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    //checks if that element in present in the stack or not
    bool contains(T item)
    {
        for (int i = 0; i < top; i++)
        {
            if (ptr[i] == item)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Stack<int> s;

    cout << "Inserted 4 5 6 7 into the stack" << endl;
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    cout << "The popped element is: " << s.pop() << endl;
    cout << "The element at the top is (peek): " << s.peek() << endl;
    cout << "The number of elements present in the stack: " << s.length() << endl;
    cout << "Printing all the elements in the stack: ";
    s.print();
}