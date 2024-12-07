#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ifstream inputFile("input");
  int n;
  vector<int> l1;
  vector<int> l2;
  
  for(int i = 0; i < 2000; i++){
    inputFile >> n;
    if(i%2==0){
      l1.push_back(n);
    }else{
      l2.push_back(n);
    }
  }

  sort(l1.begin(), l1.end());
  sort(l2.begin(), l2.end());
  
  int diff = 0;
  for(int i = 0; i < 1000; i++){
    diff = diff + abs(l1[i] - l2[i]);
  }
  cout<<diff;
  inputFile.close();
}