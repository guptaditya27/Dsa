#include <iostream>
using namespace std;
#define EMPTY_TREE 1
#define DATA_NOT_FOUND 2
struct Node {
    int item;
    Node* left;
    Node* right;
};

class Bst {
private:
    Node* root;
protected:
    void recpr(Node*);// recursive preorder.
    void recinor(Node*);// recursive inoreder.
    void recpor(Node*);// recursive postorder.
    void Inordercopy(Bst&,Node*);

public:
    Bst();
    Bst(int);
    ~Bst();
    Bst(Bst&);
    Bst& operator=(Bst&);
    void insert(int);
    bool is_empty();
    void preorder();
    void inorder();
    void postorder();
    Node* search(int);
    void del(int);
};
Bst& Bst::operator=(Bst&bst){
    while(root){
        del(root->item);
    }
    bst.Inordercopy(*this,bst.root);
    return *this;
}
void Bst::Inordercopy(Bst& bst,Node*ptr){
    if(ptr){
        Inordercopy(bst,ptr->left);
        bst.insert(ptr->item);
        Inordercopy(bst,ptr->right);
    }
}
Bst::Bst(Bst&bst){
    root=NULL;
    if(bst.root){
        bst.Inordercopy(*this,bst.root);
    }
}
void Bst::del(int val){
    Node*ptr,*parptr;  

    if(root==NULL)
        throw EMPTY_TREE;
    
    parptr=NULL;
    ptr=root;
    while(ptr!=NULL){
        if(ptr->item==val)
            break;
        else if(ptr->item<val){
            parptr=ptr;
            ptr=ptr->right;

        }
        else{
            parptr=ptr;
            ptr=ptr->left;
        }

    }
    if(ptr==NULL)
        throw DATA_NOT_FOUND;
    if(parptr==NULL&&ptr!=NULL){// deleting node is root node.
        if(ptr->left==NULL&&ptr->right==NULL){// Node has 0 child
            delete ptr;
            root=NULL;
        }
        else if(ptr->left&&ptr->right){// 2child in Node
            Node *suc,*parsuc;
            suc=ptr->right;
            parsuc=ptr;
            while(suc->left!=NULL)
            {
                parsuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            // Now deleting suc
            // suc can have 0,1 child;
            if(suc==parsuc->left){
                parsuc->left=suc->right;
            }
            else{
                parsuc->right=suc->right;
            }
            delete suc;


        }
        else{// 1child at Node
            if(ptr->left)
            {
                root=ptr->left;
            }
            else{
                root=ptr->right;
            }
            delete ptr;
        }
    }
    else{//Node is NOT root Node
        if(ptr->left==NULL&&ptr->right==NULL){
            if(ptr==parptr->left){
                parptr->left=NULL;
                delete ptr;
            }
            else{
                parptr->right=NULL;
                delete ptr;
            }
        }
        else if(ptr->left&&ptr->right){// 2 child
            Node *suc,*parsuc;
            suc=ptr->right;
            parsuc=ptr;
            while(suc->left!=NULL)
            {
                parsuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            // Now deleting suc
            // suc can have 0,1 child;
            if(suc==parsuc->left){
                parsuc->left=suc->right;
            }
            else{
                parsuc->right=suc->right;
            }
            delete suc;


        }
        else{// 1child
            if(ptr==parptr->left){
                if(ptr->left){
                    parptr->left=ptr->left;
                }
                else{
                    parptr->left=ptr->right;
                }
                delete ptr;
            }
            else{
                if(ptr->left){
                    parptr->right=ptr->left;
                }
                else{
                    parptr->right=ptr->right;
                }
            }
            delete ptr;
        }
    }
}
Node* Bst::search(int val)
{
    try{
        if(root==NULL)
            throw 1;
        Node *ptr=root;
        while(ptr!=NULL)
        {
            if(ptr->item==val)
                return ptr;
            else if(ptr->item<val)
                ptr=ptr->right;
            else{
                ptr=ptr->left;
            }
        }
        return NULL;
    }
    catch(int e){
        if(e==1)
            cout<<"BST Not Found !!"<<endl;
        return NULL;
    }
}
Bst::~Bst(){
    
    
    while(root){
        del(root->item);
         
    }
}
void Bst::postorder() {
    recpor(root);
}

void Bst::inorder() {
    recinor(root);
}

void Bst::preorder() {
    recpr(root);
}

bool Bst::is_empty() {
    return root == NULL;
}

void Bst::insert(int val) {
    
    try{
        Node* n = new Node;
        n->item = val;
        n->left = n->right = NULL;
        if(root==NULL)
            root=n;
        else{
            Node*ptr=root;
            while(ptr!=NULL)
            {
                if(ptr->item<val){
                    if(ptr->right==NULL)
                        break;
                    ptr=ptr->right;
                }
                else{
                    if(ptr->left==NULL)
                        break;
                    ptr=ptr->left;
                }

            }
            if(ptr->item==val)
            {
                delete n;
                throw 1;
            }
            else if(ptr->item<val)
                ptr->right=n;
            else{
                ptr->left=n;
            }

        }
    }
    catch(int e){
        if(e==1)
            cout<<"Duplicate value Encounterd !!"<<endl;
    }

    
}

Bst::Bst() : root(NULL) {}

Bst::Bst(int val) {
    root = new Node;
    root->left = NULL;
    root->right = NULL;
    root->item = val;
}

void Bst::recpor(Node* ptr) {
    if (ptr) {
        recpor(ptr->left);
        recpor(ptr->right);
        cout << ptr->item << " ";
    }
}

void Bst::recinor(Node* ptr) {
    if (ptr) {
        recinor(ptr->left);
        cout << ptr->item << " ";
        recinor(ptr->right);
    }
}

void Bst::recpr(Node* ptr) {
    if (ptr) {
        cout << ptr->item << " ";
        recpr(ptr->left);
        recpr(ptr->right);
    }
}

int main() {
    Bst B(10);
    B.insert(15);
    B.insert(9);
    B.insert(11);
    B.insert(61);
    B.insert(33);
    Bst M;
    M=B;
    B.inorder();
    cout<<endl;
    //B.del(10);
    M.inorder();
    // B.postorder();
    // cout<<endl;
    // B.preorder();
    return 0;
}
