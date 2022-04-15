#include <iostream>
#include "Node.h"
using namespace std;

Node::Node() {  //default constructor, sets default values of private attributes of Node class
   coef = 1.0;
   exp = 0;
   next = nullptr;            
}

Node::Node(double c, int e) { //overloaded constructor takes value in for parameter and sets variables equal to them
   coef = c;
   exp = e;
   next = nullptr;
}

//accessors return the value of the private variable
double Node::getCoef() const{
  return coef;
} 
    
int Node::getExp() const{
  return exp;
}
    
Node* Node::getNext() const{
  return next;
}

//mutators set the value of the private variable based on the value passed in
void Node::setCoef(double coefficient){
  coef = coefficient;
}

void Node::setExp(int exponent){
  exp = exponent;
}
    
void Node::setNext(Node* nextptr){
  next = nextptr;
}

//overloaded << operator, displays the contents of the node based on the values of the exponent and coefficient
ostream& operator<<(ostream &out, Node* n){
    //if coefficient is equal to 1, hide it
    if((n -> getCoef() == 1 || n -> getCoef() == -1)){
      if(n -> getExp() == 0){
        out << "x";
      }
      else
        out << "x^" << n -> getExp();
    }
    //if exponent is equal to 0, hide it as value is a constant
    else if(n -> getExp() == 0){
      if(n -> getCoef() < 0)
        out << -1*(n -> getCoef());
      else
        out << n -> getCoef();
    }
    //displays just x, if exponent is 1
    else if(n -> getExp() == 1){
      if(n -> getCoef() < 0)
        out << -1*(n -> getCoef()) << "x";
      else
        out << n -> getCoef() << "x";
    }
    //displays the node properly, coefficient(x^) exponent
    else{
      if(n -> getCoef() < 0)
        out << -1*(n -> getCoef()) << "x^" << n -> getExp();
      else  
        out << n -> getCoef() << "x^" << n -> getExp();
    }

    return out;
}