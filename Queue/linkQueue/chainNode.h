// file chainNode.h
#ifndef CHAIN_NODE_H
#define CHAIN_NODE_H

template <class T>
struct ChainNode {
    T element;
    ChainNode<T>* next;

    ChainNode() : next(nullptr) {}
    ChainNode(const T& element) : element(element), next(nullptr) {}
    ChainNode(const T& element, ChainNode<T>* next) : element(element), next(next) {}
};

#endif
