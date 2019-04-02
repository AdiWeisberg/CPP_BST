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
Node* current = search(value, this->node_root);
// if(current == NULL) return;
if(current != NULL){
  Node* father = current->parent;
  //case1: leaf(no childrens)
  if(current->leftChild == NULL && current->rightChild == NULL){//the leaf is the root
    if(current->parent == NULL){
      //delete this->node_root;
      // this->node_root=NULL;
      // free(this->node_root);
      free(current);
      this->node_root=NULL;
    }
    else if(father->rightChild->data == current->data){
      father->rightChild = NULL;
      delete current;
      // free(current);
  }
    else{//the leaf is from the left
      father->leftChild = NULL;
      delete current;
      // free(current);
    }  
  }
  //case2:one child
  else if(current->leftChild == NULL){ //has no left child
    if (father == NULL) { //the root
      this->node_root = current->rightChild;
      delete this->node_root; 
      // free(current);
    }
    else if(father->rightChild != NULL){
        if(father->rightChild->data == current->data){
        father->rightChild = current->rightChild;
        current->rightChild->parent = father;
        delete current;
        // free(current);
      }
   }
    else
    {
      if(father->leftChild != NULL){
      father->leftChild = current->rightChild; 
      current->rightChild->parent = father;
      delete current;
      // free(current);
      }
    }
  } 
  else if(current->rightChild == NULL){ //has no right child
    if (father == NULL) { //the root
      // delete this->node_root;
      this->node_root = current->leftChild; 
      // free(current);
      delete current;
    }
    else if(father->rightChild != NULL) {
    if(father->leftChild->data == current->data){
      father->leftChild = current->leftChild;
      current->leftChild->parent = father;
      delete current;
      //current=NULL;
      // free(current);
      }
    }
    else{
      if(father->leftChild != NULL){
      father->rightChild = current->leftChild; 
      current->leftChild->parent = father;
      delete current;
      // free(current);
    }
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
      temp->parent->leftChild = temp->rightChild;

    }
    else{
      temp->parent->leftChild = NULL;
    }
    // Node* toDelete = search(newValue);
    delete temp;
    //temp=NULL;
    // free(temp);
    current->data = newValue;
    cout << "hiiiii" << endl;
    // if(current->parent == NULL) this->node_root->data = newValue;
  }
this->count--;
}
else throw string(to_string(value) + " doesn't exist."); 
}

int Tree::size(){
return this->count; 
}

bool Tree::contains(int value){
if(this->node_root==NULL){
  return false;
}
else return contain(value,this->node_root);
}

int Tree::root(){
if(this->node_root != NULL){
int valueRoot = this->node_root->data;
return valueRoot;
}
else throw string("doesn't exist."); 
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
//   tre.insert(20);
//   tre.insert(30);
//   tre.insert(25);
//   tre.insert(24);
//   tre.insert(27);
//   tre.insert(40);
//   tre.insert(35);
//   tre.insert(60);
//   tre.print();
  
//   cout << tre.size() << endl;
//   cout << tre.root() << endl;
  
//   tre.remove(20);

//   cout << tre.root() << endl;
//   cout << tre.size() << endl;
 
 
//   // tre.print();
//   // tre.remove(30);
//   // cout << tre.size() << endl;
//   // tre.remove(25);
//   // cout << tre.size() << endl;
//   // tre.print();
//   return 0;
// }
