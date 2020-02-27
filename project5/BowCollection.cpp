#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BowCollection.hpp"
#include <vector>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::pair;
using std::vector;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
  unsigned int d = barcode/10000;
  d = d%10;
  return d;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
  unsigned int d = barcode/1000;
  d = d%10;
  return d;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
  unsigned int d = barcode/100;
  d = d%10;
  return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
  unsigned int d = barcode/10;
  d = d%10;
  return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
  unsigned int d = barcode/1;
  d = d%10;
  return d;
}

// Constructor for struct Bow
Bow::Bow(string bowColor, string bowShape, string bowTexture,
		 unsigned int barcode):bowColor_(bowColor),bowShape_(bowShape),
				       bowTexture_(bowTexture),
				       barcode_(barcode)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void BowCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string bowColor;
    string bowShape;
    string bowTexture;
    unsigned int barcode;
    while (myfile >> bowColor >> bowShape >> bowTexture >> barcode) {
			if (bowColor.size() > 0)
      	addBow(bowColor, bowShape, bowTexture, barcode);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void BowCollection::addBow(string bowColor, string bowShape, string bowTexture, unsigned int barcode) {
  // TO BE COMPLETED
  // function that adds the specified bow to Minnie's collection of bows (i.e., to all hash tables)
  Bow newbow = {bowColor, bowShape, bowTexture, barcode};
/*  ALT INSERT FUNCTIONS
hT1.insert(pair<unsigned int, Bow>(barcode, newbow));
hT2.insert(pair<unsigned int, Bow>(barcode, newbow));
hT3.insert(pair<unsigned int, Bow>(barcode, newbow));
hT4.insert(pair<unsigned int, Bow>(barcode, newbow));
hT5.insert(pair<unsigned int, Bow>(barcode, newbow));
*/

  hT1.emplace(barcode, newbow);
  hT2.emplace(barcode, newbow);
  hT3.emplace(barcode, newbow);
  hT4.emplace(barcode, newbow);
  hT5.emplace(barcode, newbow);

return;
}

bool BowCollection::removeBow(unsigned int barcode) {
  // TO BE COMPLETED
  // function that removes the bow specified by the barcode from the collection
  // if bow is found, then it is removed and the function returns true
  // else returns false
  std::unordered_map<unsigned int, Bow, decltype(&hashfct1)>::iterator it;
  it = hT1.find(barcode); //checks if barcode is in hashtable 1
  //if not, its not in the others
      if( it != hT1.end()){
        hT1.erase(barcode);
        hT2.erase(barcode);
        hT3.erase(barcode);
        hT4.erase(barcode);
        hT5.erase(barcode);
      return true;
    }
    else
      return false;
}

unsigned int BowCollection::bestHashing() {
  //push all index bucket sizes to their own unique vector
  vector<int> ht1, ht2, ht3, ht4, ht5;
  	 for (unsigned i=0; i<10; ++i) {
      ht1.push_back(hT1.bucket_size(i)); // Call bucket_size() to get the size of each bucket
      ht2.push_back(hT2.bucket_size(i));
      ht3.push_back(hT3.bucket_size(i));
      ht4.push_back(hT4.bucket_size(i));
      ht5.push_back(hT5.bucket_size(i));
    }

//initiate and set smalls and largest variables
int small1 = ht1.at(0), small2 = ht2.at(0), small3 = ht3.at(0), small4 = ht4.at(0), small5 =ht5.at(0);
int largest1 = 0, largest2 = 0, largest3 = 0, largest4 = 0, largest5 = 0;
//loop throught and check for the smallest and largest and set variables for each hashtable
    for(unsigned i=0; i<10; ++i){
      // hT1
        int temp1 = ht1.at(i);
          if(temp1 < small1)
            small1 = temp1;
          if(temp1 > largest1)
            largest1 = temp1;
        //hT2
        int temp2 = ht2.at(i);
          if(temp2 < small2)
            small2 = temp2;
          if(temp2 > largest2)
            largest2 = temp2;
        //hT3
        int temp3 = ht3.at(i);
          if(temp3 < small3)
            small3 = temp3;
          if(temp3 > largest3)
            largest3 = temp3;
        //hT4
        int temp4 = ht4.at(i);
          if(temp4 < small4)
            small4 = temp4;
          if(temp4 > largest4)
            largest4 = temp4;
        //hT5
        int temp5 = ht5.at(i);
          if(temp5 < small5)
            small5 = temp5;
          if(temp5 > largest5)
            largest5 = temp5;
    }
//determine the balance factor, largest bucket size minus smallest
    int bal1 = largest1 - small1;
    int bal2 = largest2 - small2;
    int bal3 = largest3 - small3;
    int bal4 = largest4 - small4;
    int bal5 = largest5 - small5;
//push balance factors to their own vector to match their index+1
    vector<int> results;
    results.push_back(bal1);
    results.push_back(bal2);
    results.push_back(bal3);
    results.push_back(bal4);
    results.push_back(bal5);

    int result = 0;
    int temp = results.at(0);
    //loop through and find the smallest balance factor and return after
    for(int i =0; i< 4; ++i){
      if(temp > results.at(i)){
          result = i + 1;
          temp = results.at(i);
        }
    }
return result;
}

// ALREADY COMPLETED
size_t BowCollection::size() {
	if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size()))
  	throw std::length_error("Hash table sizes are not the same");
	return hT1.size();
}

/* //PRINT HASH TABLES FUNCTION WITH BUCKETS AND ELEMENTS FOR DEBUGGING
void BowCollection::printHTables(){
      cout << "hT1's buckets contain:\n";
         for ( unsigned i = 0; i < hT1.bucket_count(); i++) {
           std::cout << "bucket #" << i << " contains:";
           for ( auto it = hT1.begin(i); it!= hT1.end(i); it++ )
             cout << " " << it->first << ":" << it->second.barcode_;
        cout << std::endl;
     }
     cout << "hT2's buckets contain:\n";
        for ( unsigned i = 0; i < hT2.bucket_count(); i++) {
          std::cout << "bucket #" << i << " contains:";
          for ( auto it = hT2.begin(i); it!= hT2.end(i); it++ )
            cout << " " << it->first << ":" << it->second.barcode_;
       cout << std::endl;
    }
    cout << "hT3's buckets contain:\n";
       for ( unsigned i = 0; i < hT3.bucket_count(); i++) {
         std::cout << "bucket #" << i << " contains:";
         for ( auto it = hT3.begin(i); it!= hT3.end(i); it++ )
           cout << " " << it->first << ":" << it->second.barcode_;
      cout << std::endl;
    }
    cout << "hT4's buckets contain:\n";
       for ( unsigned i = 0; i < hT4.bucket_count(); i++) {
         std::cout << "bucket #" << i << " contains:";
         for ( auto it = hT4.begin(i); it!= hT4.end(i); it++ )
           cout << " " << it->first << ":" << it->second.barcode_;
      cout << std::endl;
    }
    cout << "hT5's buckets contain:\n";
       for ( unsigned i = 0; i < hT5.bucket_count(); i++) {
         std::cout << "bucket #" << i << " contains:";
         for ( auto it = hT5.begin(i); it!= hT5.end(i); it++ )
           cout << " " << it->first << ":" << it->second.barcode_;
      cout << std::endl;
    }
} */
