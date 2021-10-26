#include<bits/stdc++.h>
using namespace std;

int main(){

   int x; cin>>x;
   int onbit,offbit,togbit,checkbit;
   cin>>onbit>>offbit>>togbit>>checkbit;
   
    //ON A BIT i.e, agar 0 to 1 kro and 1 to 1 hi rhne do so isme OR lelo 1 ke sath
   int onval = x;
   int onmask = (1 << onbit);
   onval = (onval | onmask);
   cout<<"After switching ON "<<onbit<<" bit -->"<<onval<<endl;
   
   //OFF A BIT i.e, agar 1 to 0 krdo and 0 to 0 hi rehne do isme AND lelo 0 ke sath.
   int offval = x;
   int offmask = ~(1 << offbit);
   offval = (offval & offmask);
   cout<<"After switching Off "<<offbit<<" bit -->"<<offval<<endl;

   //TOGGLE A BIT i.e, agar 1 to 0 krdo and vice versa using XOR.
    int togval = x;
   int togmask = (1 << togbit);
   togval = (togval ^ togmask);
   cout<<"After toggling "<<togbit<<" bit -->"<<togval<<endl;

   //CHECKING SET BIT i.e, koi given bit is 1 or not
   //1.Using And : Simple Funda bro ki mask 000010000 i.e, 1<<k phir bcoz x & 1 == xand lo 
   //agar 0 mtlb wo bit is zero

   
   int checkmaskand = (1 << checkbit);
   if((x & checkmaskand) == 0)
      cout<<checkbit<<" is OFF"<<endl;
   else 
      cout<<checkbit<<" is ON"<<endl;
   
   //2.Using OR: mask lo upar wale ka opposite i.e, jaha check krna wha 0 bcoz x | 0 == x and thora
   //dimag lagao ho jyga kaam

   int checkmaskor = ~(1<<checkbit);
   if((~(x| checkmaskor)) == 0)
      cout<<checkbit<<" is ON"<<endl;
   else 
      cout<<checkbit<<" is OFF"<<endl;


}
