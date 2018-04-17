#include<iostream>
#include<stdio.h>
using namespace std;

enum RBColor {RED, BLACK};

template<class T>
class RBNode{
    public:
        T key;
        RBColor color;
        RBNode *left_child;
        RBNode *right_child;
        RBNode *parent;
        
        RBNode(T k, RBColor c, RBNode *l, RBNode *r, RBNode *p):
            key(k), color(c), left_child(l), right_child(r), parent(p){};
};

template<class T>
class RBTree{
    private:
        RBNode<T> *root;
        RBNode<T> *nil;
    public:
        RBTree();
        ~RBTree();
        // 插入函数
        void insert(T key);
        // 打印
        void prePrint();
        // 计算黑高
        int get_highth();

        bool printTree(RBNode<T> *node, int nLayer);

        RBNode<T> * get_root(){
            return root;
        }
    private:
        // 左旋
        void leftRotate(RBNode<T>* x);
        // 右旋
        void rightRotate(RBNode<T>* y);
        // 调整
        void RB_INSERT_FIXUP(RBNode<T> *node);
        void rbt_prePrint(RBNode<T> *node);
        void destory(RBNode<T> *node);
};

template<class T>
bool RBTree<T>::printTree(RBNode<T> *node, int nLayer){
    if(node == NULL) return false;
    printTree(node->right_child, nLayer+3);
    for(int i=0;i<nLayer;i++)
        printf(" ");
    printf("%c\n", node->key);
    printTree(node->left_child, nLayer+3);
    return true;
}

template<class T>
int RBTree<T>::get_highth(){
    RBNode<T> *node = root;
    if(node == nil) return 0;
    int count = 0;
    while(node->left_child != NULL){
        node = node->left_child;
        if(node->color == BLACK)
            count++;
    }
    return count;
}



template<class T>
RBTree<T>::RBTree(){
    nil = new RBNode<T>(static_cast<T>(0), BLACK, NULL, NULL, NULL);
    root = nil;
}

template<class T>
RBTree<T>::~RBTree(){
    destory(root);
}

template<class T>
void RBTree<T>::destory(RBNode<T> *node){
    if(node == nil) 
        return;
    if(node->left_child !=nil)
        return destory(node->left_child);
    if(node->right_child !=nil)
        return destory(node->right_child); 
    delete node;
    node = nil;
}

template<class T>
void RBTree<T>::insert(T key){
    RBNode<T> *node = NULL;
    if((node = new RBNode<T>(key, RED, NULL, NULL, NULL)) == NULL)
        return;
    RBNode<T> *parent = nil;
    RBNode<T> *cur = root;
    while(cur != nil){
        parent = cur;
        if(cur->key > node->key)
            cur = cur->left_child;
        else 
            cur = cur->right_child;
    }
    node->parent = parent;
    if(parent == nil)
        root = node;
    else if((parent != nil) &&node->key > parent->key)
        parent->right_child = node;
    else if((parent != nil) &&node->key <= parent->key)
        parent->left_child = node;
    node->left_child = nil;
    node->right_child = nil;
    RB_INSERT_FIXUP(node);
}

template<class T>
void RBTree<T>::RB_INSERT_FIXUP(RBNode<T> *node){
    while(node->parent->color == RED){
        if(node->parent == node->parent->parent->left_child){
            RBNode<T> *uncle = node->parent->parent->right_child;
            if(uncle == NULL) break;//************
            //case 1
            if(uncle->color == RED){
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
                continue;//************
            }
            //case 2
            else if(node == node->parent->right_child){
                node = node->parent;
                leftRotate(node);
            }
            //case 3
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            rightRotate(node->parent->parent);
        }
        else {
            RBNode<T> *uncle = node->parent->parent->left_child;
            //case 1
            if(uncle == NULL) break;//************
            if(uncle->color == RED){
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
                continue; //************
            }
            //case 2
            else if(node == node->parent->left_child){
                node = node->parent;
                rightRotate(node);
            }
            //case 3
            if(node->parent != nil) 
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            leftRotate(node->parent->parent);
        }
    }
    root->color = BLACK;
}

template<class T>
void RBTree<T>::rightRotate(RBNode<T> *y){
    RBNode<T> *x = y->left_child;  //set y
    y->left_child = x->right_child;
    if(x->right_child != nil)
        x->right_child->parent = y;
    x->parent = y->parent;
    if(y->parent == nil)
        root = x;
    else if(y == y->parent->right_child)
        y->parent->right_child = x;
    else 
        y->parent->left_child = x;
    x->right_child = y;
    y->parent = x;
}

template<class T>
void RBTree<T>::leftRotate(RBNode<T> *x){
    RBNode<T> *y = x->right_child;  //set y
    x->right_child = y->left_child;
    if(y->left_child != nil)
        y->left_child->parent = x;
    y->parent = x->parent;
    if(x->parent == nil)
        root = y;
    else if(x == x->parent->left_child)
        x->parent->left_child = y;
    else 
        x->parent->right_child = y;
    y->left_child = x;
    x->parent = y;
}

template<class T>
void RBTree<T>::rbt_prePrint(RBNode<T> *node) {
    if(nil == node){
        printf("%d ",node->key);
        return;
    }
    if(node->color == RED)
        printf("%c ",node->key);
    else
        printf("%c ",node->key);
    rbt_prePrint(node->left_child);
    rbt_prePrint(node->right_child);
}

template<class T>
void RBTree<T>::prePrint(){
    rbt_prePrint(root);
}