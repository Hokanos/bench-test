//
// Created by hokanos on 19.09.16.
//

#include "Fibonacci.h"

namespace some_namespace {

std::int64_t fibonacci(unsigned int n) {
  if (n < 2)
    return n;

  std::int64_t f_1 = 1;
  std::int64_t f_2 = 0;

  for (unsigned int i = 2;i <= n; i++) {
    auto tmp = f_1 + f_2;
    f_2 = f_1;
    f_1 = tmp;
  }

  return f_1;
//  return fibonacci(n - 1) + fibonacci(n - 2);
}

}