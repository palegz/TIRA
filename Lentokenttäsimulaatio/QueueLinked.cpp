#include "QueueLinked.h"

template <class Queue_entry>
QueueLinked<Queue_entry>::QueueLinked() : front(nullptr), rear(nullptr)
{
}
template <class Queue_entry>
QueueLinked<Queue_entry>::QueueLinked(const QueueLinked<Queue_entry> &org)
{
    Node<Queue_entry> *new_copy, *original_node = org.front;
    if (original_node == nullptr)
    {
        front = nullptr;
        rear = nullptr;
    }
    else {                         //  Duplicate the linked nodes.
        front = new_copy = new Node<Queue_entry>(original_node->entry);
        while (original_node->next != nullptr) {
            original_node = original_node->next;
            new_copy->next = new Node<Queue_entry>(original_node->entry);
            new_copy = new_copy->next;
        }
        rear = new Node<Queue_entry>(original_node->entry);
    }
}
template <class Queue_entry>
QueueLinked<Queue_entry>& QueueLinked<Queue_entry>::operator=(const QueueLinked<Queue_entry> &source)
{
    Node<Queue_entry> *new_top, *new_copy, *original_node = source.front;
    if (original_node == nullptr) new_top = nullptr;
    else
    {
        new_copy = new_top = new Node<Queue_entry>(original_node->entry);
        while (original_node->next != nullptr)
        {
            original_node = original_node->next;
            new_copy->next = new Node<Queue_entry>(original_node->entry);
            new_copy = new_copy->next;
        }
        rear = new Node<Queue_entry>(original_node->entry);
    }
    while (!empty())
        serve();
    front = new_top;

    return *this;
}
template <class Queue_entry>
QueueLinked<Queue_entry>::~QueueLinked()
{
    while (!empty())
        serve();
}
template <class Queue_entry>
bool QueueLinked<Queue_entry>::empty() const
{
    if (front == nullptr)
        return true;
    return false;
}
template <class Queue_entry>
Error_code QueueLinked<Queue_entry>::append(const Queue_entry &item)
{
    Node<Queue_entry> *new_rear = new Node<Queue_entry>(item, nullptr);
    if (new_rear == nullptr) return overflow;
    if (rear == nullptr) front = rear = new_rear;
    else
    {
        rear->next = new_rear;
        rear = new_rear;
    }
    return success;
}
template <class Queue_entry>
Error_code QueueLinked<Queue_entry>::serve()
{
    if (front == nullptr) return underflow;
    Node<Queue_entry> *old_front = front;
    front = old_front->next;
    if (front == nullptr) rear = nullptr;
    delete old_front;
    return success;
}
template <class Queue_entry>
Error_code QueueLinked<Queue_entry>::retrieve(Queue_entry &item)
{
    if (front == nullptr) return underflow;
    item = front->entry;
    return success;
}
