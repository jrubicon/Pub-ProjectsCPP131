#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Booking {
private:
  string firstname;
  string lastname;
  string pclass;

vector<Booking> myvec;
vector<Booking> boardingorder;
public:
  void checkin(string _firstname, string _lastname, string _pclass);
  void printorder();
  Booking();
  Booking(string _firstname, string _lastname, string _pclass);
  void sortorder();
};
Booking::Booking(string _firstname, string _lastname, string _pclass){
  firstname = _firstname;
  lastname = _lastname;
  pclass = _pclass;
}

Booking::Booking(){
  firstname = "";
  lastname = "";
  pclass = "";
}

void Booking::checkin(string _firstname, string _lastname, string _pclass){
  myvec.push_back(Booking(_firstname, _lastname, _pclass));
  //where I had the sortoder that caused the bug.
}

void Booking::printorder(){
  sortorder();
  for (int i=0; i<boardingorder.size(); i++){
    cout << boardingorder.at(i).firstname << " " << boardingorder.at(i).lastname
         << " " << "(" << boardingorder.at(i).pclass << ")" << "\n";
  }
}
void Booking::sortorder(){

  for (int i = 0; i<myvec.size(); i++){
    if(myvec.at(i).pclass == "First"){
      boardingorder.push_back(Booking(myvec.at(i).firstname,
      myvec.at(i).lastname,myvec.at(i).pclass));
    }
  }
  for (int i = 0; i<myvec.size(); i++){
    if(myvec.at(i).pclass == "Business"){
      boardingorder.push_back(Booking(myvec.at(i).firstname,
      myvec.at(i).lastname,myvec.at(i).pclass));
    }
  }
  for (int i = 0; i<myvec.size(); i++){
    if(myvec.at(i).pclass == "Economy"){
      boardingorder.push_back(Booking(myvec.at(i).firstname,
      myvec.at(i).lastname,myvec.at(i).pclass));
    }
  }
}
