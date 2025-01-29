#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int item;
    Node*left;
    Node*right;
    int height;
};
class Avl_tree
{
    private:
        Node*root;
    protected:
        int getheight(Node*);
        Node* insertion(Node*,int);
        Node*deletion(Node*,int);
    public:
    Avl_tree();
    Avl_tree(int);
    ~Avl_tree();
    void insert(int);
    int get_balance_factor(Node*);
    Node* rightrotate(Node*);
    Node* leftrotate(Node*);
    void del(int);
    Node* minvaluenode(Node*);

};
Node* Avl_tree::minvaluenode(Node*ptr){
    Node*current=ptr;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}
Avl_tree::~Avl_tree(){
    while(root){
        del(root->item);
    }
}

Node* Avl_tree::deletion(Node*ptr,int data){
    if(ptr==NULL)
        return ptr;
    else if(data<ptr->item){
        ptr->left=deletion(ptr->left,data);
    }
    else if(data>ptr->item){
        ptr->right=deletion(ptr->right,data);
    }
    else{
        if((ptr->left==NULL)||(ptr->right==NULL)){
            Node*temp=ptr->left?ptr->left:ptr->right;
            // No child
            if(temp==NULL){
                temp=ptr;
                ptr=NULL;
            }
            else{
                *ptr=*temp;
            }
            free(temp);
        }
        else{
            // Node with 2 child 
            Node*temp=minvaluenode(ptr->right);
            ptr->item=temp->item;
            // deleting succ.
            ptr->right=deletion(ptr->right,temp->item);

        }
    }

    //if tree has only 1 Node
    if(ptr==NULL)
    {
        return ptr;
    }
    ptr->height=1+max(getheight(ptr->left),getheight(ptr->right));
    int balance=get_balance_factor(ptr);

    //if beocme unbalanced there are 4 cases 
    // Left left case .
    if(balance>1&&data<ptr->left->item)
    {
        return rightrotate(ptr);
    }
    // right right case
    if(balance <-1&&data>ptr->right->item){
        return leftrotate(ptr);
    }
    // right left case
    if(balance>1&&data<ptr->left->item){
        ptr->left=leftrotate(ptr->left);
        return rightrotate(ptr);
    }
    // left right case
    if(balance <-1 && data<ptr->right->item){
        ptr->right=rightrotate(ptr->right);
        return leftrotate(ptr);
    }

    return ptr;


}
void Avl_tree::del(int data){
    root=deletion(root,data);
}
Node* Avl_tree::insertion(Node*ptr,int data){
    Node*n;
    
    if(ptr==NULL){
        n=new Node;
        n->item=data;
        n->left=NULL;
        n->right=NULL;
        n->height=1;
        return n;
    }
    else if(data<ptr->item){
        ptr->left=insertion(ptr->left,data);
    }
    else if(data>ptr->item)
    {
        ptr->right=insertion(ptr->right,data);
    }
    else{
        return ptr;
    }
    // calculating height of Nodes 
    ptr->height=1+max(getheight(ptr->left),getheight(ptr->right));
    // het the balance factor of this ancestor Node to check if
    // become unbalanced or not.
    int balance=get_balance_factor(ptr);

    //if beocme unbalanced there are 4 cases 
    // Left left case .
    if(balance>1&&data<ptr->left->item)
    {
        return rightrotate(ptr);
    }
    // right right case
    if(balance <-1&&data>ptr->right->item){
        return leftrotate(ptr);
    }
    // right left case
    if(balance>1&&data<ptr->left->item){
        ptr->left=leftrotate(ptr->left);
        return rightrotate(ptr);
    }
    // left right case
    if(balance <-1 && data<ptr->right->item){
        ptr->right=rightrotate(ptr->right);
        return leftrotate(ptr);
    }

    return ptr;

}
void Avl_tree::insert(int data){
    root=insertion(root,data);
}
Node* Avl_tree::rightrotate(Node*A){
    Node*B=A->left;
    Node*RT=B->right;
    B->right=A;
    A->left=RT;

    // heights adjust;
    A->height=max(getheight(A->left),getheight(A->right))+1;
    B->height=max(getheight(B->left),getheight(B->right))+1;
    return B;

}
Node* Avl_tree::leftrotate(Node*A){
    Node*B=A->right;
    Node*LT=B->left;
    B->left=A;
    A->right=LT;
    
    // Adjusting heights 
    A->height=max(getheight(A->left),getheight(A->right))+1;
    B->height=max(getheight(B->left),getheight(B->right))+1;
    return B;

}
int Avl_tree::getheight(Node*ptr){
    if(ptr==NULL)
        return 0;
    return ptr->height;
}
int Avl_tree::get_balance_factor(Node*ptr){
    if(ptr==NULL)
        return 0;
    return getheight(ptr->left)-getheight(ptr->right);
}
Avl_tree::Avl_tree(int val){
    Node*n=new Node;
    n->item=val;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    root=n;
}
Avl_tree::Avl_tree()
{
    root=NULL;
}
int max(int a,int b){
    if(a>=b)
        return a;
    return b;
}
 
int main()
{
   return 0;
}