package main

import (
  "fmt"
)
var pl = fmt.Println
var pf = fmt.Printf

//PROGRAM START

const MX = 10000
var prime_arr [MX]bool

func sieve(n int) {
  for i := 3; i <= n; i += 2 {
    if !prime_arr[i] {
      for j := i * i; j <= n; j += i {
        prime_arr[j] = true
      }
    }
  }
}

func isPrime(n int) bool {
  if n == 2 {
    return true
  }

  if n <= 1 || n % 2 == 0 {
    return false
  }
  return !prime_arr[n];
}



func main() {
  sieve(50)

  for i := 0; i <= 50; i++ {
    ans := isPrime(i);
    if ans {
      pf("%d : is a prime number\n", i);
    } else {
      pf("%d : is not a prime number\n", i);
    }
  }

} 
