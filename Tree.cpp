#include <iostream>
#include <stdio.h>
#include "Tree.hpp"
using namespace ariel;

Tree::Tree(){
    this->node_root=NULL;
    this->count = 0;
}

Tree::~Tree(){

}

void Tree::insert(int value){
    this->node_root=new Node(value);
}

void Tree::insert(int value,Node *current){

}

void Tree::remove(int value){

}

int Tree::size(){
int res;
return res;
}

bool Tree::contains(int value){
bool res;
return res;
}

int Tree::root(){
int rootValue;
return rootValue;
}

int Tree::parent(int value){
int res;
return res;
}

int Tree::right(int value){
int res;
return res;
}

int Tree::left(int value){
int res;
return res;
}

void Tree::print(){

}

Node* Tree::search(int value,Node *current){
Node* node;
return node;
}
bool Tree::contain(int value,Node *current){
  bool res;
  return res;
}  
void Tree::inorder(Node *root){

}
void Tree::destroy(Node* Tree){

}
