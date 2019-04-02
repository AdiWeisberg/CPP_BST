#include <iostream>
#include <stdio.h>
#include "Tree.hpp"
using namespace ariel;

Tree::Tree(){
    this->node_root=NULL;
    this->count = 0;
}

Tree::~Tree(){
    destroy(this->node_root);
    cout << "The tree has been deleted successfully!" << endl;
}

void Tree::insert(int value){
   if(this->node_root!=NULL){
      insert(value,this->node_root);
    }
    else
    {
      this->node_root = new Node(value);
      count++;
    }
}

void Tree::insert(int value,Node *current){
  if(contains(value)){
    throw std::invalid_argument("existed value recived");
    return;
  }
    if(value > current->data){
      if(current->rightChild!=NULL)
        insert(value,current->rightChild);
      else {
        Node* insertNode = new Node(value);
        insertNode->parent = current;
        current->rightChild = insertNode;
        count++;
      }
    }
    else
    {
      if(current->leftChild!=NULL)
        insert(value,current->leftChild);
      else {
        Node* insertNode = new Node(value);
        insertNode->parent = current;
        current->leftChild = insertNode;
        count++;
      }
    }
  }
    
void Tree::remove(int value){
Node* current = search(value, this-> node_root);
if(current != NULL){
  Node* father = current->parent;
  //case1: leaf(no childrens)
  if(current->leftChild == NULL && current->rightChild == NULL){//the leaf is the root
    if(current->parent == NULL){
      delete this->node_root;
      this->node_root=NULL;
    }
    else if(father->rightChild->data == current->data){ //the leaf is from the right
      father->rightChild = NULL;
      delete current;
    }
    else{//the leaf is from the left
      father->leftChild = NULL;
      delete current;
    }  
  }
  //case2:one child
  else if(current->leftChild == NULL){ //has no left child
    if (father == NULL) { //the root
      delete this->node_root;
      this->node_root = current->rightChild; 
    }
    else if(father->rightChild->data == current->data){
      father->rightChild = current->rightChild;
      current->rightChild->parent = father;
      delete current;
    }
    else
    {
      father->leftChild = current->rightChild; 
      current->rightChild->parent = father;
      delete current;
    } 
  }

  else if(current->rightChild == NULL){ //has no right child
    if (father == NULL) { //the root
      delete this->node_root;
      this->node_root = current->leftChild; 
    }
    else if(father->rightChild->data == current->data){
      father->rightChild = current->leftChild;
      current->leftChild->parent = father;
      delete current;
      current=NULL;
    }
    else{
      father->leftChild = current->leftChild; 
      current->rightChild->parent = father;
      delete current;
    }
  }
  else{
    Node* temp = current->rightChild;
    while(temp->leftChild != NULL){
      temp = temp->leftChild;
    }
    int newValue = temp->data;
    if(temp->rightChild !=NULL ){
      temp->rightChild->parent = temp->parent;
      temp->parent->rightChild = temp->rightChild;
    }
    temp=NULL;
    delete temp;
    current->data = newValue;

  }
this->count--;
}
else throw string(to_string(value) + " doesn't exist."); 
}

int Tree::size(){
return count; 
}

bool Tree::contains(int value){
if(this->node_root==NULL){
  return false;
}
else return contain(value,this->node_root);
}

int Tree::root(){
int valueRoot = this->node_root->data;
return valueRoot;
}

int Tree::parent(int value){
Node* currentNode = search(value,this->node_root);
  if(currentNode!=NULL){
    if(currentNode->parent != NULL)
    return currentNode->parent->data;

    else throw string(to_string(value) + "this is the root");
 }
else throw string(to_string(value) + " the value is not existed");
}

int Tree::right(int value){
Node* currentNode = search(value,this->node_root);
  if(currentNode!=NULL){
    if(currentNode->rightChild != NULL){
      int res = currentNode->rightChild->data;
      return res;
    }
 }
 throw string(to_string(value) + " does not have right Child.");
}

int Tree::left(int value){
  Node* currentNode = search(value,this->node_root);
  if(currentNode!=NULL){
    if(currentNode->leftChild != NULL){
      return currentNode->leftChild->data;
    }
  }
throw string(to_string(value) + " does not have left Child.");
}

void Tree::print(){
inorder(this->node_root);
}

Node* Tree::search(int value,Node *current){
if(current!=NULL){
  if(current->data==value){
    return current;
  }
  else if(value > current->data){
    return search(value,current->rightChild);
  }
  else return search(value,current->leftChild);
}
else return NULL;
}


bool Tree::contain(int value,Node *current){
if(current!=NULL){
  if(current->data==value){
    return true;
  }
  else if(value > current->data){
    return contain(value,current->rightChild);
  }
  else return contain(value,current->leftChild);
}
else return false;
}  

void Tree::inorder(Node *head){
if(head == NULL) return;
inorder(head->leftChild);
cout << head->data << " -- ";
inorder(head->rightChild);
}

void Tree::destroy(Node* head){
  Node* current = head;
  if(head != NULL){
    if(current->leftChild != NULL){
      destroy(current->leftChild);
    }
    if(current->rightChild != NULL){
          destroy(current->rightChild);
    }
    delete(current);
  }

}

// int main (){
//   ariel::Tree tre;
//   tre.
//   return 0;
// }
