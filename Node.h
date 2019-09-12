//
// Created by usuario on 9/12/2019.
//

#ifndef POLYNOMIAL_NODE_H
#define POLYNOMIAL_NODE_H

template <typename N>
class Node {
private:
    N value;
    Node* next;

public:
    Node(N value) : value(value) {
        next = nullptr;
    }

    N getValue() const {
        return value;
    }

    void setNext(Node *next) {
        Node::next = next;
    }

    Node* getNext() const {
        return next;
    }

    virtual ~Node() {
        delete next;
    }
};


#endif //POLYNOMIAL_NODE_H
