#include "QueueLinked.cpp"

#ifdef COMPILE_MYCLASSESLIB
#define MYCLASSESLIB_EXPORT __declspec(dllexport)
#else
#define MYCLASSESLIB_EXPORT //__declspec(dllimport)
#endif

template <class Queue_entry>
class MYCLASSESLIB_EXPORT QueueLinkedExtended :
    public QueueLinked<Queue_entry>
{
public:
    // POST: Return true if the ExtendedLinkedQueue is full, return false
    // otherwise.
    bool full() const;
    // POST: Return the number of entries in the ExtendedLinkedQueue
    unsigned int size() const;
    // POST: All entries in the ExtendedLinkedQueue have been removed, it is
    // now empty.
    void clear();
    // Return underflow if the ExtendedLinkedQueue is empty. Otherwise remove
    // and copy the item at the front of the Extended_queue to item and
    // return success.
    Error_code serve_and_retrieve(Queue_entry &);

};

#pragma once
