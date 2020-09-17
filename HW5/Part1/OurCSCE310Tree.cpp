/*
 * OurCSCE310Tree.cpp
 *
 *  Created on: Nov 13, 2018
 *      Author: Taylor
 */

#include "OurCSCE310Tree.h"
#include <iostream>
#include <cmath>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

/*
class OurCSCE310Tree{
 public:
  OurCSCE310Tree(void);
  OurCSCE310Tree(OurCSCE310Tree&);
  ~OurCSCE310Tree(void);
  void operator=(OurCSCE310Tree&);
  OurCSCE310Tree* getParent(void);
  OurCSCE310Tree* getLeft(void);
  OurCSCE310Tree* getRight(void);
  int getValue(void);
  void setParent(OurCSCE310Tree*);
  void setLeft(OurCSCE310Tree*);
  void setRight(OurCSCE310Tree*);
  void setValue(int);
  void insert(int);
  void printPreorder(void);
  void printInorder(void);
  void printPostorder(void);
  void rotateLeft(void);
  void rotateRight(void);
  void rotateLeftRight(void);
  void rotateRightLeft(void);
  void deleteNode(int);
  int getHeight();

 private:
  int value;
  OurCSCE310Tree* parent;
  OurCSCE310Tree* left;
  OurCSCE310Tree* right;
};
 */

OurCSCE310Tree::OurCSCE310Tree(){
	value = 0;
	parent = NULL;
	left = NULL;
	right = NULL;
}

OurCSCE310Tree::OurCSCE310Tree( OurCSCE310Tree& other){
	delete parent;
	delete left;
	delete right;
	value = other.getValue();
	parent = other.getParent();
	left = other.getLeft();
	right = other.getRight();
}

void OurCSCE310Tree::operator=( OurCSCE310Tree& other){
	delete parent;
	delete left;
	delete right;
	value = other.getValue();
	parent = other.getParent();
	left = other.getLeft();
	right = other.getRight();
}

OurCSCE310Tree::~OurCSCE310Tree(){
	delete left;
	left = NULL;
	delete right;
	right = NULL;
	value = 0;
}

OurCSCE310Tree* OurCSCE310Tree::getParent(){
	return parent;
}

OurCSCE310Tree* OurCSCE310Tree::getLeft(){
	return left;
}

OurCSCE310Tree* OurCSCE310Tree::getRight(){
	return right;
}

int OurCSCE310Tree::getValue(){
	return value;
}

void OurCSCE310Tree::setParent( OurCSCE310Tree* par ){
	parent = par;
}

void OurCSCE310Tree::setLeft( OurCSCE310Tree* lft ){
	left = lft;
}

void OurCSCE310Tree::setRight( OurCSCE310Tree* rght ){
	right = rght;
}

void OurCSCE310Tree::setValue( int val ){
	value = val;
}

void OurCSCE310Tree::insert( int val ){
	if( !getValue() ){
		setValue( val );
	}
	else if( ( val < getValue() && !getLeft() ) || ( val < getValue() && !getLeft()->getValue() ) ){
		left = new OurCSCE310Tree();
		left->setParent( this );
		left->setValue( val );
	}
	else if( ( val > getValue() && !getRight() ) || ( val > getValue() && !getRight()->getValue() ) ){
		right = new OurCSCE310Tree();
		right->setParent( this );
		right->setValue( val );
	}
	else if( val < getValue() ){
		getLeft()->insert( val );
	}
	else{
		getRight()->insert( val );
	}

	if( (getLeft() && getLeft()->getRight() && !getRight()) || (getLeft() && getLeft()->getRight() && getRight() && getLeft()->getHeight() > getRight()->getHeight() + 1 && getLeft()->getRight()->getHeight() > getLeft()->getLeft()->getHeight() + 1) ){
		rotateLeftRight();
	}
	else if( (getRight() && getRight()->getLeft() && !getLeft()) || (getRight() && getRight()->getLeft() && getLeft() && getRight()->getHeight() > getLeft()->getHeight() + 1 && getRight()->getLeft()->getHeight() > getRight()->getRight()->getHeight() + 1) ){
		rotateRightLeft();
	}
	else if( (getLeft() && !getRight() && getLeft()->getHeight() > 1) || (getLeft() && getRight() && getLeft()->getHeight() > getRight()->getHeight() + 1) ){
		rotateRight();
	}
	else if( (getRight() && !getLeft() && getRight()->getHeight() > 1) || (getRight() && getLeft() && getRight()->getHeight() > getLeft()->getHeight() + 1) ){
		rotateLeft();
	}
}

void OurCSCE310Tree::printPreorder(){
	if( getValue() ){
		cout << getValue();
	}
	if( getLeft() && getLeft()->getValue() ){
		cout << ",";
		getLeft()->printPreorder();
	}
	if( getRight() && getRight()->getValue() ){
		cout << ",";
		getRight()->printPreorder();
	}
}

void OurCSCE310Tree::printInorder(){
	if( getLeft() && getLeft()->getValue() ){
		getLeft()->printInorder();
		cout << ",";
	}
	if( getValue() ){
		cout << getValue();
	}
	if( getRight() && getRight()->getValue() ){
		cout << ",";
		getRight()->printInorder();
	}
}

void OurCSCE310Tree::printPostorder(){
	if( getLeft() && getLeft()->getValue() ){
		getLeft()->printPostorder();
		cout << ",";
	}
	if( getRight() && getRight()->getValue() ){
		getRight()->printPostorder();
		cout << ",";
	}
	if( getValue() ){
		cout << getValue();
	}
}

int OurCSCE310Tree::getHeight(){
	if( getLeft() && getLeft()->getValue() && ( !getRight() || !getRight()->getValue() ) ){
		return getLeft()->getHeight() + 1;
	}
	else if( getRight() && getRight()->getValue() && ( !getLeft() || !getLeft()->getValue() ) ){
		return getRight()->getHeight() + 1;
	}
	else if( getRight() && getLeft() && getRight()->getValue() && getLeft()->getValue() ){
		return fmax( getRight()->getHeight() , getLeft()->getHeight() ) + 1;
	}
	else if( getValue() && ( !getLeft() || !getLeft()->getValue() ) && ( !getRight() || !getRight()->getValue() ) ){
		return 1;
	}
	return 0;
}

void OurCSCE310Tree::rotateLeftRight(){
	getLeft()->rotateLeft();
	rotateRight();
}

void OurCSCE310Tree::rotateRightLeft(){
	getRight()->rotateRight();
	rotateLeft();
}

//Implementation Note: There are a variety of ways to implement a binary tree.
//  With our implementation "this" points to 'P', however after the rotation
//  is completed "this" points to 'Q'.
/*
          Q                 P
         / \               / \
        /   \             /   \
       P     C    <==    A     Q
      / \                     / \
     /   \                   /   \
    A     B                 B     C

 */

void OurCSCE310Tree::rotateLeft(){

	int r = this->getValue();
	OurCSCE310Tree* NewLeft = new OurCSCE310Tree();
	NewLeft->setParent(this);
	NewLeft->setValue(r);

	if(this->getRight()->getLeft()){
		NewLeft->setRight(this->getRight()->getLeft());
		this->getRight()->getLeft()->setParent(NewLeft);
	}

	if(this->getLeft()){
		NewLeft->setLeft(this->getLeft());
		this->getLeft()->setParent(NewLeft);
	}

	this->setValue(this->getRight()->getValue());
	this->setLeft(NewLeft);

	if(this->getRight()->getRight()){
		this->setRight(this->getRight()->getRight());
		this->getRight()->setParent(this);
	}
}

//Implementation Note: There are a variety of ways to implement a binary tree.
//  With our implementation "this" points to 'Q', however after the rotation
//  is completed "this" points to 'P'.
/*
          Q                 P
         / \               / \
        /   \             /   \
       P     C    ==>    A     Q
      / \                     / \
     /   \                   /   \
    A     B                 B     C

 */

void OurCSCE310Tree::rotateRight(){

	int r = this->getValue();
	OurCSCE310Tree* NewRight = new OurCSCE310Tree();
	NewRight->setParent(this);
	NewRight->setValue(r);

	if(this->getLeft()->getRight()){
		NewRight->setLeft(this->getLeft()->getRight());
		this->getLeft()->getRight()->setParent(NewRight);
	}

	if(this->getRight()){
		NewRight->setRight(this->getRight());
		this->getRight()->setParent(NewRight);
	}

	this->setValue(this->getLeft()->getValue());
	this->setRight(NewRight);

	if(this->getLeft()->getLeft()){
		this->setLeft(this->getLeft()->getLeft());
		this->getLeft()->setParent(this);
	}

}

void OurCSCE310Tree::deleteNode( int key ){

	/*if(this->getValue() > key){
		this->getLeft()->deleteNode(key);
	}else if(this->getValue() < key){
		this->getRight()->deleteNode(key);
	}else if(this->getValue() == key){


		if(!(this->getLeft())){

			if(this->getParent()->getLeft() == this){
				this->getRight()->setParent(this->getParent());
				this->getParent()->setLeft(this->getRight());
			}else{
				this->getRight()->setParent(this->getParent());
				this->getParent()->setRight(this->getRight());
			}

		}else if(!(this->getRight())){

			if(this->getParent()->getLeft() == this){
				this->getLeft()->setParent(this->getParent());
				this->getParent()->setLeft(this->getLeft());
			}else{
				this->getLeft()->setParent(this->getParent());
				this->getParent()->setRight(this->getLeft());
			}

		}else{
			OurCSCE310Tree* TempNode = this;

			if(this->getLeft()->getLeft()){
				TempNode = this->getRight();
				while(TempNode->getLeft()){
					TempNode = TempNode->getLeft();
				}

				this->setValue(TempNode->getValue());
				this->getRight()->deleteNode(this->getValue());
			}else{

				TempNode = this->getLeft();
				while(TempNode->getRight()){
					TempNode = TempNode->getRight();
				}

				this->setValue(TempNode->getValue());
				this->getLeft()->deleteNode(this->getValue());
			}
		}


	}*/

}
