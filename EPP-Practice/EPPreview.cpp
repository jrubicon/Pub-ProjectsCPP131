#include <iostream>
#include <vector>
using namespace std;


class contest {
private:
  int contNum;
  int SIZE;
  double * scores;
public:
  contest(int judges);
//  ~contest();
  void avg(vector<contest> &);
};

contest::contest(int judges){
  SIZE = judges;
  scores = new double[SIZE];
  cout << "Enter The Contestant Number\n";
  cin >> contNum;
  for (int i = 0; i < SIZE; i++){
    cout << "Enter the Contestant score for judge: " << i << "\n";
    cin >> scores[i];
  }
}
/*
contest::~contest(){
  delete[] scores;
}
*/
void contest::avg(vector<contest> & pool){
  int avg = 0;
  int temp = 0;
  int high = 0;

  for(int i= 0; i<pool.size(); i++){
    //*
    cout << pool.at(i).contNum;
    for(int j=0; j<SIZE; j++){
      avg += pool.at(i).scores[j];
      }
      avg = avg / SIZE;
      if (temp < avg){
          temp = avg;
          high = pool.at(i).contNum;
      cout << ": Average Score: " << avg << "\n";
    }
  //  cout << "The Highest Score is " << high << "with " << temp << "\n";
  }
  cout << "The Highest Score is contestant " << high << " with " << temp << "\n";
}

int main(){
char con;
int judges;

vector<contest> pool;
cout << "Enter the number of Judges\n";
cin >> judges;
//contest enter = {judges};
do {
contest enter = {judges};
pool.push_back(enter);
cout << "continue? (y/n)\n";
cin >> con;
if (con == 'n' || con == 'N'){
  enter.avg(pool);
}
} while (con != 'n' && con != 'N');


  return 0;
}
