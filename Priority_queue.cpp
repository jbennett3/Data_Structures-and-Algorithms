#include <iostream>
#include <queue>
#include <vector>
#include<time.h>
#include<cstdlib>
#include<cmath>
using namespace std;

const int MAX_VAL = 100;
const int NUM_ELEM = 15;

int find_median(priority_queue<int, vector<int>, greater<int>>& h_high, priority_queue<int>& h_low, int num);
template<typename T> void print_queue(T& q);

int main() {
    int current_median;
    priority_queue<int> lo; // Bottom half of numbers - max-heap (default)
    priority_queue<int, vector<int>, greater<int> > hi; // Top half of numbers - min-heap
    srand(time(0)); // Seed for random number generator
    for (int i = 0; i < NUM_ELEM; i++) {
        int n = rand() % MAX_VAL;
        current_median = find_median(hi, lo, n);
        cout <<  "Inserted " << n << " Median " << current_median << endl << endl;
         //print_queue(hi);
         //print_queue(lo);
    }
    return 0;
}

template<typename T> void print_queue(T& q) {
    T q_copy(q);
    while(!q_copy.empty()) {
        std::cout << q_copy.top() << " ";
        q_copy.pop();
    }
    std::cout << '\n';
}


int find_median(priority_queue<int, vector<int>, greater<int> >&h_high, priority_queue<int>&h_low, int num)
{
    int median;// median variable
  if(h_low.empty())// first set of if statements handle the insertion step
  {
      h_low.push(num);//determine if the max_heap is empty if it is insert num if not insert in the min_heap
  }
  else if(num>h_low.top())
  {
        h_high.push(num);
  }
  else if(h_high.empty())//if the min+heap is empty then insert the top of the max_heap
  {
      h_high.push(h_low.top());
      h_low.pop();
      h_low.push(num);
  }
  else
    h_low.push(num);
   //rebalance step
if (abs(h_low.size()-h_high.size())>1)//heaps can be of different sizes by one at most
{
    if(h_low.size()>h_high.size())// if the max_heap is greater than min_heap by one the put top of max into min
    {
        h_high.push(h_low.top());
        h_low.pop();//shrink max_heap by one
    }
    else//if min_heap size is lower then push min_heap top into the max_heap and  pop top of the min_heap
        h_low.push(h_high.top());
        h_high.pop();
}//determine median
if (h_high.empty())//simply pick the top value of the max_heap if the min_heap is empty
{
    median = h_low.top();
}
else if (h_high.size()<h_low.size())//if the max_heap is bigger then pick the top of max_heap as median
{
    median = h_low.top();
}
else//if not pick the top of the min_heap
{
    median = h_high.top();
}
return median;
}
