#include <iostream>
using namespace std;

#define MX 100000
bool prime_arr[MX];


void sieve(int n){
  for (int i = 3; i * i <= n; i+=2)
    if (!prime_arr[i])
      for(int j = i * i; j <= n; j+=i)
        prime_arr[j] = true;
}

bool isPrime(int x){
  if (x == 2) return true;
  if (x < 2 or !(x % 2)) return false;
  return !prime_arr[x];
}


int main(){
  sieve(MX);
  
  int count = 0;

  for (int i = 0; i <= 200; i++)
    if (isPrime(i))
    {
      cout << "PRIME : " << i << " " << endl;
      count++;
    }

  printf("TOTLA PRIME NUMBER IS : %d\n", count);

  return 0;
}
