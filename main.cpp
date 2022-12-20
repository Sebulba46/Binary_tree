#include<iostream>
using namespace std;

template <typename T>
struct myNode {
    T data;
    myNode* left;
    myNode* right;
};

template <typename T>
myNode<T>* GetNewNode(T data) {
    auto* newNode = new myNode<T>();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

template <typename T>
myNode<T>* Insert(myNode<T>* root,int data) {
    if(root == nullptr) {
        root = GetNewNode(data);
    }

    else if(data <= root->data) {
        root->left = Insert(root->left,data);
    }

    else {
        root->right = Insert(root->right,data);
    }
    return root;
}

template <typename T>
bool Search(myNode<T>* root,int data) {
    if(root == nullptr) {
        return false;
    }
    else if(root->data == data) {
        return true;
    }
    else if(data <= root->data) {
        return Search(root->left,data);
    }
    else {
        return Search(root->right,data);
    }
}


int main() {
    myNode<int>* root = nullptr;

    root = Insert(root,13);
    root = Insert(root,15);
    root = Insert(root,233);
    root = Insert(root,5);
    root = Insert(root,2);
    root = Insert(root,111);

    int number;
    cout<<"Enter number \n";
    cin>>number;

    if(Search(root, number)) cout << "Found\n";
    else cout<<"Not Found\n";
}