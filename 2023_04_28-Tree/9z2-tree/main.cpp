#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T inf = T();
    Node *left = nullptr, *right = nullptr;
    Node(T el);
};

template <typename T>
Node<T>::Node(T el) {
    inf = el;
}

template <typename T>
struct Tree {
    Node<T> *root = nullptr;

    void Addint(T el);
    void Add(T el);
    void Add(T el, Node<T> *&root);
    void LKP();
    void LKP(Node<T> *root);
    void Clear();
    void Clear(Node<T> *root);
    bool Find(T el);
    bool Find(T el, Node<T> *root);
    Node<T> * Get(T el);
    Node<T> * Get(T el, Node<T> *root);
    void Delete(T el);
    void Delete(T el, Node<T> *&root);

    Tree();
    ~Tree();

};

template <typename T>
Tree<T>::Tree() {
    cout << "Hello" << '\n';
}

template <typename T>
Tree<T>::~Tree() {
    Clear();
    cout << "Bye" << '\n';
}

template <typename T>
void Tree<T>::Addint(T el){
    if (!root)
        root = new Node<T>(el);
    else {
        Node<T> *tmp = root;
        bool fl = true;
        while (fl)
            if (el < tmp -> inf && tmp -> left)
                tmp = tmp -> left;
            else if (el >= tmp -> inf && tmp -> right)
                tmp = tmp -> right;
            else
                fl = false;
        if (el < tmp -> inf)
            tmp -> left = new Node<T>(el);
        else
            tmp -> right = new Node<T>(el);
    }
}

template <typename T>
void Tree<T>::LKP(Node<T> *root){
    if (!root)
        return;
    LKP(root -> left);
    cout << root->inf <<" ";
    LKP(root -> right);
}

template <typename T>
void Tree<T>::LKP(){
    LKP(root);
    cout << '\n';
}

template <typename T>
void Tree<T>::Clear(){
    Clear(root);
}

template <typename T>
void Tree<T>::Clear(Node<T> *root){
    if (!root)
        return;
    Clear(root -> left);
    Clear(root -> right);
    delete root;
}

template <typename T>
void Tree<T>::Add(T el){
    Add(el, root);
}

template <typename T>
void Tree<T>::Add(T el, Node<T> *&root){
    if (!root)
        root = new Node<T>(el);
    else if (el < root -> inf)
        Add(el, root -> left);
    else
        Add(el, root -> right);
}

template <typename T>
void Tree<T>::Delete(T el){
    Delete(el, root);
}

template <typename T>
void Tree<T>::Delete(T el, Node<T> *&root){
    if (!root)
        return;
    else if (el == root -> inf) {
        if (!root->left){
             Node<T> * tmp = root;
             root = root -> right;
             delete tmp;
        } else if (!root->right){
             Node<T> * tmp = root;
             root = root -> left;
             delete tmp;
        } else {
            Node<T> * tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            root->inf = tmp->inf;
            Delete(root->inf, root->left);
        }

    } else if (el < root -> inf)
        Delete(el, root -> left);
    else
        Delete(el, root -> right);
}


template <typename T>
bool Tree<T>::Find(T el){
    return Find(el, root);
}

template <typename T>
bool Tree<T>::Find(T el, Node<T> *root){
    if (!root)
        return false;
    if (root -> inf == el)
        return true;
    if (el < root -> inf)
        return Find(el, root->left);
    return Find(el, root->right);
}

template <typename T>
Node<T> * Tree<T>::Get(T el){
    return Get(el, root);
}

template <typename T>
Node<T> * Tree<T>::Get(T el, Node<T> *root){
    if (!root)
        return nullptr;
    if (root -> inf == el)
        return root;
    if (el < root -> inf)
        return Get(el, root->left);
    return Get(el, root->right);
}


int main()
{
    Tree<int> t;
    t.Add(5);
    t.Add(10);
    t.Add(3);
    t.Add(2);
    t.Add(7);
    t.Add(11);
    t.LKP();
    t.Get(11)->inf += 1;
    t.Delete(5);
    t.LKP();

    cout << t.Find(21);

    Tree<double> t2;
    t2.Add(2.3);
    t2.Add(4.5);
    t2.LKP();

    Tree<string> t3;
    t3.Add("123");
    t3.LKP();

//    cout << "Hello world!" << endl;
    return 0;
}
