#include<iostream>
using namespace std;

template<typename E>
struct Node {
int _accountnumber;
Node<E> * _next;
Node(int acc, int * ptr): _accountnumber(acc), _next(nullptr){};
};


template<typename E>
class SLL {
private:
  Node<E> * head;
  int length;
public:
  SLL(): head(nullptr), length(0){};
void pushfront(int acc);
void printlist(Node<E> * ptr);
void printhelp(){
  printlist(head);
}

Node<E> * gethead();
};
template<typename E>
Node<E> * SLL<E>::gethead(){
  return head;
}

template<typename E>
void SLL<E>::pushfront(int acc){
  Node<E> *anew;
  anew->_accountnumber = acc;
  //anew->_next = nullptr;

  if (head == nullptr){
    head = anew;
    length++;
  }
  else {
    anew->_next = head;
    head = anew;
    length++;
  }
}

template<typename E>
void SLL<E>::printlist(Node<E> * ptr){
  if (ptr->_next == nullptr)
    return;
  else{
      //cout << ptr->_accountnumber << "\n";
      printlist(ptr->_next);
      cout << ptr->_accountnumber << "\n";
    }
  }



int main(){

SLL<int> list1;
char cont = 'Y';

do{
int acc;
cout << "Enter your account #\n";
cin >> acc;
list1.pushfront(acc);
cout << (list1.gethead())->_accountnumber;
cout << "continue?\n";
cin >> cont;
} while (cont=='Y' || cont=='y');

list1.printhelp();


  return 0;
}
