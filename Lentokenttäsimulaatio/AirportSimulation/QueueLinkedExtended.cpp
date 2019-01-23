#include "QueueLinkedExtended.h"
#include <new>

template <class Queue_entry>
bool QueueLinkedExtended<Queue_entry>::full() const
{
    Node_entry item = 0;
    Node<Queue_entry> *new_rear = new (std::nothrow)Node<Queue_entry>(item);
    if (new_rear == nullptr)
        return true;

    delete new_rear;
    return false;
}
template <class Queue_entry>
unsigned int QueueLinkedExtended<Queue_entry>::size() const
{
    unsigned int count = 0;
    const Node<Queue_entry>* position = front;
    if (position == nullptr) return 0;
    while (position->next != nullptr)
    {
        count++;
        position = position->next;
    }
    return count + 1;
}
template <class Queue_entry>
void QueueLinkedExtended<Queue_entry>::clear()
{
    while (!empty())
        serve();
}
template <class Queue_entry>
Error_code QueueLinkedExtended<Queue_entry>::serve_and_retrieve(Queue_entry &item)
{
    if (retrieve(item) == underflow) return underflow;
    serve();
    return success;
}
