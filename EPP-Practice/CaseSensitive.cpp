#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct names{
  string fullname;
  names(string _full): fullname(_full){}
};

string transform(string _search);

int main(){
vector<names> log;
string search;
string fsearch;
cout << "Search a name: ";
getline(cin, search);
cout << endl;
//call takes string and converts all ascii values to uppercase
search = transform(search);
//finally we get ride of spaces
for (int i=0; i<search.size(); i++){
  if(search[i] == 32){
    continue;
  }
  else
    fsearch += search[i];
}
//simple conversion when they were stored away they were converted to
//all uppercase by ascii values and spaces removed
cout << fsearch << " " << fsearch.size() << "\n";
log.push_back(names("JOHNHENRY"));
log.push_back(names("JONNYDI"));
log.push_back(names("SALLYSUE"));
log.push_back(names("KELSEYTUK"));

for(int i = 0; i < log.size(); i++){
    if(log.at(i).fullname == fsearch)
      cout << "SEARCH FOUND\n";
  }
return 0;
}

//transform function converts lower case to uppercase
string transform(string _search){
  for(int i = 0; i<_search.size(); i++){
    if(_search[i] >= 97 && _search[i] <= 122)
      _search[i] = _search[i] - 32;
  }
  return _search;
}
