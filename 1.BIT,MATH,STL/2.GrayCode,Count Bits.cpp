
#include<bits/stdc++.h>
using namespace std;

string tO_binary(int x){
  string ans;
  while(x){
    ans += (x % 2) + '0';
    x /= 2;
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
int to_decimal(string s){
  int ans = 0;
  for(auto x : s)
    ans = 2*ans + x-'0';
  return ans;
}

int cnt_set_bits(int x){
  int ans = 0;
  while(x){
    int rmsbm = x & -x;
    x = x - rmsbm;
    ans++;
  }
  return ans;
}
vector<string>graycode(int x){
  if(x == 1) return {"0","1"};

  vector<string>rres = graycode(x-1);  //HAVE COMPLETE FAITH ON REC KI WO x-1 ka ans janta hai and le ayega.

  vector<string>res;                   //NOW SIMPLY CONNECT EXPECTAION & FAITH.

  for(int i = 0 ; i < rres.size();i++){
    res.push_back("0" + rres[i]);
  }
  for(int i = rres.size()-1;i >= 0;i--)
    res.push_back("1" + rres[i]);

  return res;
}

int main(){
  int x; cin>>x;
  string s = tO_binary(x);

  cout<<s;
  cout<<endl<<to_decimal(s)<<endl;
  
  //ON 3rd BIT
  int onmask = (1<<3);
  cout<<"Onmask : "<<tO_binary(onmask)<<endl;
  x = x | onmask;

  cout<<"After Switching 3rd BIT : "<<tO_binary(x)<<endl;

  //OFF 3rd BIT 
  int offmask = ~(1<<3);

  x = x & offmask;

  cout<<"After turning OFF 3rd BIT : "<<tO_binary(x)<<endl;

  //TOGGLE 3rd BIT
  int togmask = (1<<3);
  x = x ^ togmask;

  cout<<"After toggling 3rd BIT : "<<tO_binary(x)<<endl;

  //Check 3rd bit

  int checkmask = (1<<3);

  if((x & checkmask) == 0) cout<<"3rd BIT is OFF"<<endl;
  else cout<<"3rd BIT is ON"<<endl;
  
  //Checking no of set bits using KERMINGHAM ALGO in almost O(1)
  cout<<"No of set bits in "<<tO_binary(x)<<" is "<<cnt_set_bits(x)<<endl;

  //Printing Gray Code
  int y = 3;
  vector<string>grayCode = graycode(y);
  cout<<"Gray Code of "<<y<<" are :"<<endl;
  for(auto x: grayCode)
    cout<<x<<endl;

}
