#include <iostream>
#include <string>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){
    string chromosome;
    cin >> chromosome;
    bool isInfected = true;
    if(chromosome[0] != 'A' && chromosome[0] != 'B' && chromosome[0] != 'C' && chromosome[0] != 'D' && chromosome[0] != 'E' && chromosome[0] != 'F')
      isInfected = false;
    else{
      if(chromosome[0] == 'A'){
        if(chromosome[1] != 'A' && chromosome[1] != 'F')  isInfected = false;
        else{
          string pre = "A";
          int lastIdx = -1;
          for(int i = 1; i < chromosome.size(); i++){
            if(chromosome[i] == 'A' && pre == "A"){
              pre = "A";
              continue;
            }
            if(chromosome[i] == 'F' && (pre == "A" || pre == "F")){
              pre = "F";
              continue;
            }
            if(chromosome[i] == 'C' && (pre == "F" || pre == "C")){
              pre = "C";
              lastIdx = i;
              continue;
            }
            if(pre == "C"){
              if(chromosome[0] != 'A' && chromosome[0] != 'B' && chromosome[0] != 'C' && chromosome[0] != 'D' && chromosome[0] != 'E' && chromosome[0] != 'F'){
                isInfected = false;
                break;
              }
              else{
                if(lastIdx + 2 <= chromosome.size()){
                  isInfected = false;
                  break;
                }  
              }
            }
            isInfected = false; 
          }
        }
       
      }else{
        if(chromosome[1] != 'A')  isInfected = false;
        else{
          string pre = "A";
          int lastIdx = -1;
          for(int i = 1; i < chromosome.size(); i++){
            if(chromosome[i] == 'A' && pre == "A"){
              pre = "A";
              continue;
            }
            if(chromosome[i] == 'F' && (pre == "A" || pre == "F")){
              pre = "F";
              continue;
            }
            if(chromosome[i] == 'C' && (pre == "F" || pre == "C")){
              pre = "C";
              lastIdx = i;
              continue;
            }
            if(pre == "C"){
              if(chromosome[0] != 'A' && chromosome[0] != 'B' && chromosome[0] != 'C' && chromosome[0] != 'D' && chromosome[0] != 'E' && chromosome[0] != 'F'){
                isInfected = false;
                break;
              }
              else{
                if(lastIdx + 2 <= chromosome.size()){
                  isInfected = false;
                  break;
                }  
              }
            }  
            isInfected = false;
          }
        }
      }
    } 
    if(isInfected)  cout << "Infected!" << endl;
    else  cout << "Good" << endl;

  }



  return 0;
}