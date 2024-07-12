#include "Queue.h"

/**
 * Implement Queue constructor
 */
Queue::Queue() {
    /* YOUR CODE HERE */
    head = NULL;
    tail = NULL;
    numElements = 0;
}

/**
 * Implement the Queue destructor
 */
Queue::~Queue() {
    /* YOUR CODE HERE */
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int Queue::size() {
    /* YOUR CODE HERE */
    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void Queue::clear() {
    /* YOUR CODE HERE */
    Node* n = head;
    while (n != NULL)
    {
        Node* n2 = n->next;
        delete n;
        n = n2;
    }
    head = NULL;
    tail = NULL;
    numElements = 0;
}

/**
 * Implement push() correctly
 */
void Queue::push(string s) {
    /* YOUR CODE HERE */
    Node* n = new Node(s);
    if (tail == NULL)
    {
        head = tail = n;
    }
    else
    {
        tail->next = n;
        tail = n;
    }
    numElements= numElements+1;
}

/**
 * Implement pop() correctly without memory leaks
 */
string Queue::pop() {
    /* YOUR CODE HERE */
    if (head == NULL)
    {
        return "";
    }
    Node* n = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    numElements--;
    string data = n->data;
    delete n;
    return data;
}
