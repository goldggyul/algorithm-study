#include <iostream>
using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int time = 0, f = 0, work = 0;
  if (a > d)
    cout << 0 << endl;
  else{
    while(time < 24){
      f += a; 
      work += b;
      time++;
      if(time >= 24)  break;
      while((f + a) > d){
        if(time >= 24)  break;
        f -= c;
        if(f < 0) f = 0; 
        time++;
      }
    }    
    cout << work << endl;
  }
  return 0;
}