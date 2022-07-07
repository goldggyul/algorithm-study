#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

double calc(double o1, double o2, char op){
  if(op == '*'){
    return o1 * o2;
  }else if(op == '+'){
    return o1 + o2;
  }else if(op == '/'){
    return o1 / o2;
  }else if(op == '-'){
    return o1 - o2;
  }
}

int main(){
  int n;
  cin >> n;
  string expression;
  cin >> expression;
  map<char, int> operand;
  stack<double> st;
  for(int i = 0; i < expression.size(); i++){
    if(expression[i] >= 'A' && expression[i] <= 'Z'){
      if(operand.count(expression[i])){
        st.push(operand[expression[i]]);
      }else{
        int od;
        cin >> od;
        operand[expression[i]] = od;
        st.push(od);
      }
    }else{ // 연산자 
      double o1 = st.top();
      st.pop();
      double o2 = st.top();
      st.pop();
      double iresult = calc(o2, o1, expression[i]);
      st.push(iresult);
    }
  }
  cout << fixed;
  cout.precision(2);
  cout <<  st.top() << endl;
  return 0;
}