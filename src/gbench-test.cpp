//
// Created by hokanos on 19.09.16.
//

#include <benchmark/benchmark.h>
#include <Fibonacci.h>

static void BM_Fib(benchmark::State& state) {
  while (state.KeepRunning())
    some_namespace::fibonacci(state.range_x());
}
// Register the function as a benchmark
BENCHMARK(BM_Fib)->Arg(10)->Arg(100)->Arg(1000)->Arg(100000)->Arg(10000000);

BENCHMARK_MAIN();