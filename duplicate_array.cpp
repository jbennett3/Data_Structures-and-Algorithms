//Programmer: Justin Bennett
//Program Description: intersection function takes into 2 vectors and returns the elements that apprear in both vectors
#include <iostream>
#include <vector>
using namespace std;

const int NUM_ELEM = 15;
const int MAX_VAL = 100;

vector<int> intersection(const vector<int>&a, const vector<int>& b);

int main() {
    vector<int> a = {2,3,3,5,5,6,7,8,8,12};
    vector<int> b = {5,5,6,8,8,9,10,10};

    vector<int> c = intersection(a,b);
    for (auto elem : c)
        cout << elem << " ";
    cout << endl;

    return 0;

}

vector<int> intersection(const vector<int>&a, const vector<int>& b) {
 vector<int> common;//temporary container that will hold intersection values

unsigned int index_of_first = 0;//index for the vector a
unsigned int index_of_second = 0;//index for the vector  b
while(index_of_first <a.size()&&index_of_second<b.size())//have loop run until loop index_second runs through vector b
{

  if(a.at(index_of_first) == b.at(index_of_second))//if there is a value in the intersection push it into vector c
  {
      common.push_back(b.at(index_of_second));
      index_of_first++;// if else keep indexing through loop
      index_of_second++;
  }
else
{
    index_of_first++;
}

}
unsigned int v = 0;//index for vector c
while(v<common.size())//have a loop that will erase the duplicates in the intersection vector v
{
    if(common.at(v) == common.at(v+1))//find duplicates and use erase function to erase duplicates in the vector c
        common.erase(common.begin()+v);
        v++;
}
return common;// return the intersection vector
}
