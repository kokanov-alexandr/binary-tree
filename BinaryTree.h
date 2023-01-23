#ifndef BINARY_TREE_H

template <class T>
class Node {
public:
    T key;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;

    Node(T key);
};

template <class T>
class BinaryTree {
public:
    Node<T>* root;

    void Insert(T key);

    Node<T>* Search(T key);

    Node<T>* Minimum(Node<T>* elem);

    Node<T>* Maximum(Node<T>* elem);

    Node<T>* Next(T key);

    Node<T>* Previous(T key);

    void Remove(T key);

    // вывод узлов в отсортированном порядке
    void InorderTraversal(Node<T>* elem);

    // вывод узлов в порядке: вершина, левое поддерево, правое поддерево
    void PreorderTraversal(Node<T>* elem);

    // вывод узлов в порядке: левое поддерево, правое поддерево, вершина
    void PostorderTraversal(Node<T>* elem);
};


#include "BinaryTree.hpp"
#endif