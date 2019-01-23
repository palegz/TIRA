#pragma once

template <class Node_entry>
struct Node {
    //  data members
    Node_entry entry;
    Node<Node_entry> *next;

    //  constructors
    Node() { next = nullptr; };
    Node(Node_entry item, Node<Node_entry> *link = nullptr) { entry = item; next = link; };
};


