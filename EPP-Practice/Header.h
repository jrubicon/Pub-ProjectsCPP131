#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct passenger {
  string firstname;
  string lastname;
  string pclass;

  passenger();
  passenger(string _firstname, string _lastname, string _pclass);
};
passenger::passenger(){
  firstname = "";
  lastname = "";
  pclass = "";
}
passenger::passenger(string _firstname, string _lastname, string _pclass){
  firstname = _firstname;
  lastname = _lastname;
  pclass = _pclass;
}

class Booking {
private:
vector<passenger> myvec;
vector<passenger> boardingorder;
public:
  void checkin(string _firstname, string _lastname, string _pclass);
  void printorder();
  Booking();
  void sortorder();
};
Booking::Booking(){
    passenger temp;
}

void Booking::checkin(string _firstname, string _lastname, string _pclass){
  //temp.firstname = _firstname;
  //temp.lastname = _lastname;
  //temp.pclass = _pclass;
  passenger temp = {_firstname, _lastname, _pclass};
  myvec.push_back(temp);
}
void Booking::printorder(){
  sortorder();
  for (int i=0; i<boardingorder.size(); i++){
    cout << boardingorder.at(i).firstname << " " << boardingorder.at(i).lastname
         << " " << "(" << boardingorder.at(i).pclass << ")" << "\n";
  }
}
void Booking::sortorder(){
  passenger myse;

  for (int i = 0; i<myvec.size(); i++){
    if(myvec.at(i).pclass == "First"){
      myse.firstname = myvec.at(i).firstname;
      myse.lastname = myvec.at(i).lastname;
      myse.pclass = myvec.at(i).pclass;
      boardingorder.push_back(myse);
    }
  }
  for (int i = 0; i<myvec.size(); i++){
    if(myvec.at(i).pclass == "Business"){
      myse.firstname = myvec.at(i).firstname;
      myse.lastname = myvec.at(i).lastname;
      myse.pclass = myvec.at(i).pclass;
      boardingorder.push_back(myse);
    }
  }
  for (int i = 0; i<myvec.size(); i++){
    if(myvec.at(i).pclass == "Economy"){
      myse.firstname = myvec.at(i).firstname;
      myse.lastname = myvec.at(i).lastname;
      myse.pclass = myvec.at(i).pclass;
      boardingorder.push_back(myse);
    }
  }
}
