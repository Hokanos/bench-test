//
// Created by lzaleski on 19.09.16.
//

#include "Fibonacci.h"
#include <vector>
#include <chrono>
#include <iostream>

enum {ITERATIONS = 1000000};

void doBenchmark(unsigned int n);
void workFunction(unsigned int n);

int main() {
  //>Arg(10)->Arg(100)->Arg(1000)->Arg(100000)->Arg(10000000);
  std::vector<unsigned int> cases = {10, 100, 1000, 100000, 10000000};

  for (auto &c : cases)
    doBenchmark(c);
}

void doBenchmark(unsigned int n) {
  auto begin = std::chrono::high_resolution_clock::now();

  workFunction(n);

  auto end = std::chrono::high_resolution_clock::now();

  double result = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count());
  double time = result / ITERATIONS;
  std::cout << n << " " << time << std::endl;
}

#pragma GCC push_options
#pragma GCC optimize ("O0")
void workFunction(unsigned int n) {
  for (int i = 0;i < ITERATIONS;i++)
    some_namespace::fibonacci(n);
}
#pragma GCC pop_options