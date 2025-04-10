#include <iostream>
#include <vector>

using namespace std;

vector<int> no; //numbers that don't reach Kaprekar's Constant
vector<int> yes; //numbers that do reach Kaprekar's Constant

int orderInt(int num, bool order){ //order the digits of an integer in numerical order. True is ascending, False is descending.
  int outa[4];
  int temp = num;
  int digit;
  //convert num to array. This accidentally reverses the order of the digits but they're going to be reordered anyway so whatever.
  for (int i=0; i<4; i++){
    outa[i] = temp % 10;
    temp = temp/10;
  }
  
  //order array
  for (int i=0; i<4; i++){
    for (int j=0; j<4; j++){
      if(order){ //acending
        if(outa[i] > outa[j]){
          temp = outa[j];
          outa[j] = outa[i];
          outa[i] = temp;
        }
      }else{ //descending
        if(outa[i] < outa[j]){
          temp = outa[j];
          outa[j] = outa[i];
          outa[i] = temp;
        }
      }
    }
  }
  
  int out = outa[0]*1000 + outa[1]*100 + outa[2]*10 +outa[3];
  return out;
  
}

bool kaprekar(int num){
  if(num == 6174) return true;
  if(num < 1000 || num < 0) return false;
  int b = orderInt(num, true);
  int s = orderInt(num, false);
  int res = b-s;
  cout << b << " - " << s << " = " << res << endl;
  
  /*for (int i = 0; i < no.size(); i++){
    if(res == no[i]) return false;
  }
  for (int i = 0; i < yes.size(); i++){
    if(res == yes[i]) return true;
  }*/
  
  return kaprekar(res);
  
}

int main(){
  for (int i = 1000; i < 10000; i++){
    cout << i << endl; 
    bool isKap = kaprekar(i);
    if(isKap){
      yes.push_back(i);
    }else{
      no.push_back(i);
    }
  }
  
  cout << "Numbers that don't reach Kaprekar's Constant:\n";
  for (int i = 0; i < no.size(); i++){
    cout << no[i] << endl;
  }
}