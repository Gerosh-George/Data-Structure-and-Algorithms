# Stacks

Stack is a linear Data Structure that follows the principle of First In Last Out (FILO) or Last In First Out (LIFO). 

Stack DS literally means a stack only 😂 like consider a simple example of books or plates that are stacked up. The thing at the top is the first thing that is removed from the stack.

![image](https://user-images.githubusercontent.com/62696039/99896455-c2df0d80-2cb6-11eb-8384-fbc184c755b2.png)

- <b> Time Complexity (Array Implementation) </b>
    - Push: O(1)
    - Pop: O(1)
    - Peek: O(1)
<hr>

### C++ Implementation:

--> <u> [stack.cpp](stack.cpp) </u>

Generic programming is used for the implementation of Stack in cpp. The functions implemented are:
- push()
- pop()
- length()
- contains()
- print()
- peek()

Here we are creating a new dynamic array whenever the size of stack becomes equal to the array size so that stack overflow doesn't happen. 

Output: 

![image](https://user-images.githubusercontent.com/62696039/99898781-258dd480-2cca-11eb-8458-f0e442ae7d36.png)
<hr>

### C Implementation:

--> <u> [stack.c](stack.c) </u>

Here we have used an array of fixed length (10) which will behave as a stack,thus it's important to check the boundary conditions like Stack Overflow and Undeflow in this scenario.

Functions implemented are:
- push()
- pop()
- peek()
- print()

Output:

![image](https://user-images.githubusercontent.com/62696039/99899425-558ba680-2ccf-11eb-8d0d-fb557fd29970.png)

<hr>

### Solving Postfix expression using stacks:

This is one of the application of stacks.

--> <u> [postfix.c](postfix.c) </u>

Output:
![image](https://user-images.githubusercontent.com/62696039/99899608-aa7bec80-2cd0-11eb-81f8-3835c5bc8c06.png)

Here ` 5 10 + 6 * 20 - ` is calculated by the program which is actually the postfix expression of ` (5+10)*6-20=100 `.

[Learn more about postfix, infix and prefix expressions](https://www.tutorialspoint.com/data_structures_algorithms/expression_parsing.htm)

