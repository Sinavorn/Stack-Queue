#include "Node.h"
#include <string.h>

class Stack {
private:
    Node* top;     // Pointer to the top of the stack
    int length;      // Keeps track of the stack size

public:
    Stack() {       // Constructor
        // your code here
        top = nullptr;
        length = 0;
    }

    ~Stack() {      // Destructor to free memory
        while (!isEmpty()) {
            pop();   // Deallocate all nodes
        }
    }

    // Push an element onto the stack
    void push(int value) {
       // your code here
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        length++;
    }

    // Pop the top element from the stack
    void pop() {
        // your code here
        if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
     }
       Node* temp = top;
       top = top->next;
       delete temp;
       length--;
    }

    // Peek the top element without removing it
    int peek() {
        // your code here
        if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
       // your code here
        return length == 0;
    }

    // Get the current length of the stack
    int size() {
        return length;
    }
    // Convert the stack to a string representation
    std::string toString() {
       // your code here
       if (isEmpty()) {
        return "Stack is empty";
    }
      std::string result;
      Node* current = top;
      while (current != nullptr) {
        result += std::to_string(current->data) + " -> ";
        current = current->next;
    }
      result += "NULL";
    return result;
        
    }
};
