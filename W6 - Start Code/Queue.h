#include "Node.h"

class Queue {
private:
    Node* front;     // Pointer to the front of the queue
    Node* rear;      // Pointer to the rear of the queue
    int length;      // Keeps track of the queue size
public:
    Queue() {       // Constructor
        // your code here
        front = nullptr;
        rear = nullptr;
        length = 0;
    }
    ~Queue() {      // Destructor to free memory
        while (!isEmpty()) {
            dequeue();   // Deallocate all nodes
        }
    }

    // Enqueue an element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        length++;
    }
    // Dequeue the front element from the queue
    void dequeue() {
        // your code here
        if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
        Node* temp = front;
        front = front->next;
        delete temp;
        length--;
        if (front == nullptr) { 
        rear = nullptr;
    }
    }
    // Peek the front element without removing it
    int peek() {
        // your code here
        if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return front->data;

    }
    // Check if the queue is empty
    bool isEmpty() {
        // your code here
        return length == 0;
    }
    // Get the current length of the queue
    int size() {
        return length;
    }

    // Convert the queue to a string representation
    std::string toString() {
      // your code here
      if (isEmpty()) {
        return "Queue is empty";
    }
    std::string result;
    Node* current = front;
    while (current != nullptr) {
        result += std::to_string(current->data) + " -> ";
        current = current->next;
    }
       result += "NULL";
    return result;
    }

};
