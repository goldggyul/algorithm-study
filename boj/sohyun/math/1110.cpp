#include <iostream>
using namespace std;

int main()
{
  int n, first, second, result;
  int c = 0;

  cin >> n;
  if (n < 0 || n > 99)
    return 0;
  if (n < 10){
    first = 0;
    second = n;
  }
  else{
    first = n / 10;
    second = n % 10;
  }
  while (1){
    result = first + second;
    c++;
    first = second;
    second = result % 10;
    if (first == n / 10 && second == n % 10)
      break;
  }
  cout << c << endl;
  return 0;
}
