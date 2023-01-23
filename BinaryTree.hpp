#ifndef BINARY_TREE_HPP
using namespace std;

template <class T>
Node<T>::Node(T key) {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

template <class T>
void BinaryTree<T>::Insert(T key) {
    if (root == nullptr) {
        root = new Node<T>(key);
        return;
    }
    auto elem = root;
    auto elem_parent = elem;
    while (elem != nullptr) {
        elem_parent = elem;
        if (key < elem->key) {
            elem = elem->left;
        }
        else if (key > elem->key) {
            elem = elem->right;
        }
        else return;
    }
    auto new_elem = new Node(key);
    if (key < elem_parent->key) {
        elem_parent->left = new_elem;
    }
    else if (key > elem_parent->key) {
        elem_parent->right = new_elem;
    }
    new_elem->parent = elem_parent;
}

template <class T>
Node<T>* BinaryTree<T>::Search(T key) {
    auto elem = root;
    while (elem != nullptr && elem->key != key) {
        if (key < elem->key) {
            elem = elem->left;
        }
        else if (key > elem->key) {
            elem = elem->right;
        }
    }
    return elem;
}

template <class T>
Node<T>* BinaryTree<T>::Minimum(Node<T>* elem) {
    if (elem == nullptr) {
        return elem;
    }
    while (elem->left != nullptr) {
        elem = elem->left;
    }
    return elem;
}

template <class T>
Node<T>* BinaryTree<T>::Maximum(Node<T>* elem) {
    if (elem == nullptr) {
        return elem;
    }
    while (elem->right != nullptr) {
        elem = elem->right;
    }
    return elem;
}

template <class T>
Node<T>* BinaryTree<T>::Next(T key) {
    auto elem = Search(key);
    if (elem->right != nullptr) {
        return Minimum(elem->right);
    }
    auto p = elem->parent;
    while (p != nullptr && elem == p->right) {
        elem = p;
        p = p->parent;
    }
    return p;
}

template <class T>
Node<T>* BinaryTree<T>::Previous(T key) {
    auto elem = Search(key);
    if (elem->left != nullptr) {
        return Minimum(elem->left);
    }
    auto p = elem->parent;
    while (p != nullptr && elem == p->left) {
        elem = p;
        p = p->parent;
    }
    return p;
}

template <class T>
void BinaryTree<T>::Remove(T key) {
    auto del_elem = Search(key);
    if (del_elem == nullptr) {
        return;
    }
    auto p = del_elem->parent;

    // первый случай: удаляемый элемент - лист
    if (del_elem->left == nullptr && del_elem->right == nullptr) {
        if (p->left == del_elem) {
            p->left = nullptr;
        }
        else {
            p->right = nullptr;
        }
    }

    // второй случай: удаляемый элемент имеет одного потомка
    else if (del_elem->left == nullptr || del_elem->right == nullptr) {
        if (del_elem->left == nullptr) {
            if (p->left == del_elem) {
                p->left = del_elem->right;
            }
            else {
                p->right = del_elem->right;
            }
            del_elem->right->parent = p;
        }
        else {
            if (p->left == del_elem) {
                p->left = del_elem->left;
            }
            else {
                p->right = del_elem->left;
            }
            del_elem->left->parent = p;
        }
    }

    else {
        auto next_elem = Next(key);
        del_elem->key = next_elem->key;
        if (next_elem->parent->left == next_elem) {
            next_elem->parent->left = next_elem->right;
            if (next_elem->right != nullptr) {
                next_elem->right->parent = next_elem->parent;
            }
        }
        else {
            next_elem->parent->right = next_elem->right;
            if (next_elem->right != nullptr) {
                next_elem->right->parent = next_elem->parent;
            }
        }
    }
}

template <class T>
void BinaryTree<T>::InorderTraversal(Node<T>* elem) {
    if (elem != nullptr) {
        InorderTraversal(elem->left);
        cout << elem->key << " ";
        InorderTraversal(elem->right);
    }
}

template <class T>
void BinaryTree<T>::PreorderTraversal(Node<T>* elem) {
    if (elem != nullptr) {
        cout << elem->key << " ";
        PreorderTraversal(elem->left);
        PreorderTraversal(elem->right);
    }
}

template <class T>
void BinaryTree<T>::PostorderTraversal(Node<T>* elem) {
    if (elem != nullptr) {
        PostorderTraversal(elem->left);
        PostorderTraversal(elem->right);
        cout << elem->key << " ";
    }
}
#endif