#pragma once

#include "NODE.H"
#include "Utility.h"

#ifdef COMPILE_MYCLASSESLIB
#define MYCLASSESLIB_EXPORT __declspec(dllexport)
#else
#define MYCLASSESLIB_EXPORT //__declspec(dllimport)
#endif

template <class Queue_entry>
class MYCLASSESLIB_EXPORT QueueLinked
{
public:
    QueueLinked();
    QueueLinked(const QueueLinked<Queue_entry> &);
    QueueLinked<Queue_entry>& operator=(const QueueLinked<Queue_entry> &);
    ~QueueLinked();

    // Returns true if the QueueLinked is empty
    // Otherwise returns false
    bool empty() const;
    // Node_entry is added to the top of the QueueLinked
    // Returns overflow if dynamic memory is exhausted
    Error_code append(const Queue_entry &);
    // The end of the QueueLinked is removed
    // Returns underflow if QueueLinked is empty
    // Otherwise returns success
    Error_code serve();
    Error_code retrieve(Queue_entry &);
protected:
    Node<Queue_entry> *front, *rear;
};

