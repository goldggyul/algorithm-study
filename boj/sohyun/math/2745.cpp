#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
  string N;
  int B;
  cin >> N >> B;
  int result = 0;

  for (int i = 0; i < N.length(); i++){
    if ((N.at(N.length() - (i + 1)) - '0') > 9)
      result += (N.at(N.length() - (i + 1)) - '7') * pow(B, i);
    else
      result += (N.at(N.length() - (i + 1)) - '0') * pow(B, i);
  }

  cout << result << endl;
  return 0;
}