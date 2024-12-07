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
  
  int sum = 0;
  for(int i = 0; i < 1000; i++){
      int c = count(l2.begin(), l2.end(), l1[i]);
      if(c!=0){
        sum = sum + l1[i]*c;
      }
    }

  cout<<sum;
  inputFile.close();
}