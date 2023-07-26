#include <iostream>
#include <vector>

using namespace std;

#define MX 32000

vector<int> primes;

void sieve(){
  bool isPrime[MX];

  for (int i = 0; i < MX; i++) isPrime[i] = true;
  for (int i = 3; i * i <= MX; i+=2)
    if (isPrime[i])
      for (int j = i * i; j <= MX; j+=i)
        isPrime[j] = false;

  primes.push_back(2);
  for (int i = 3; i < MX; i+=2)
    if (isPrime[i]) primes.push_back(i);
}



void seg_sieve(long long left, long long right){
  bool isPrime[right - left + 1];

  for (int i = 0; i < right - left + 1; i++) isPrime[i] = true;
  if (left == 1) isPrime[0] = false;

  for (int i = 0; primes[i] * primes[i] <= right; i++){
    int c_Prime = primes[i];
    long long base = (left / c_Prime) * c_Prime;
    if (base < left) base += c_Prime;
    for (int j = base; j <= right; j += c_Prime) isPrime[j - left] = false;
    if (base == c_Prime) isPrime[base - left] = true;
  }

  for (int i = 0; i < right - left + 1; i++)
    if (isPrime[i])
      cout << (i + left) << endl;
}


int main(){
  sieve();

  int tt;
  cin >> tt;
  while (tt--) {
    long long left, right;
    cin >> left >> right;
    seg_sieve(left, right);
  }

  return 0;
}
