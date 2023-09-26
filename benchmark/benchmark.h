#pragma once

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <chrono>

template<class T>
class Benchmark
{
private:
    int IterationCount = 0;
    double ExecuteTime = 0;
    std::function<void()> callback;

public:
    void SetIterationCount(int count);
    
    void SetTestCode(std::function<void()> callback);
    
    double run();
        
    bool operator>(Benchmark benchmark);

    bool operator<(Benchmark benchmark);
    
    bool operator==(Benchmark benchmark);
   
    bool operator!=(Benchmark benchmark);
    
};

#include "benchmark.inl"

