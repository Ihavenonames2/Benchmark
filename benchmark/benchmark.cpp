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
    void SetIterationCount(int count)
    {
        IterationCount = count;
    }
    void SetTestCode(std::function<void()> callback)
    {
        this->callback = callback;
    }
    double run()
    {
        auto starttime = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < IterationCount; ++i)
        {
            callback();
        }
        auto endtime = std::chrono::high_resolution_clock::now();
        
        ExecuteTime = (std::chrono::duration_cast<T>(endtime - starttime).count()) / static_cast<double>(IterationCount);
        return ExecuteTime;
    }

    bool operator>(Benchmark benchmark)
    {
        return run() > benchmark.run();
    }
    bool operator<(Benchmark benchmark)
    {
        return run() < benchmark.run();
    }
    bool operator==(Benchmark benchmark)
    {
        return run() == benchmark.run();
    }
    bool operator!=(Benchmark benchmark)
    {
        return run() != benchmark.run();
    }
};

void func(std::vector<int>& vec)
{
    for (auto it : vec)
        std::cout << it << " ";
}

int main()
{

    Benchmark<std::chrono::nanoseconds> benchmark;
    Benchmark<std::chrono::nanoseconds> benchmark1;
    /*
    benchmark.SetIterationCount(100000);
    benchmark.SetTestCode([]
    ()
        { std::string name = "vasya"; }
    );



    benchmark1.SetIterationCount(100000);
    benchmark1.SetTestCode([]
    ()
        { char name[6]; strcpy_s(name, "vasya"); }
    );

    benchmark1.SetTestCode(func);

    std::cout << benchmark.run()<<std::endl;
    std::cout << benchmark1.run();
    std::cout << std::boolalpha<< std::endl;
    std::cout << (benchmark > benchmark1) << std::endl;
    std::cout << (benchmark < benchmark1) << std::endl;
    std::cout << (benchmark == benchmark1) << std::endl;
    std::cout << (benchmark != benchmark1) << std::endl;
    */

    std::vector<int> vec {1, 2, 3 };
    std::vector<int> vec1 {1, 2, 3 };

    benchmark.SetIterationCount(10000000);
    benchmark.SetTestCode([&](){
        int sum = 0;
        for (auto it : vec)
        sum+=it; });

    benchmark1.SetIterationCount(10000000);
    benchmark1.SetTestCode([&]() {
        int sum = 0;  
        auto print = [&sum](const int& n) 
        { sum += n; };

    std::for_each(vec1.begin(), vec1.end(), print); });

    std::cout << std::fixed << benchmark.run() << std::endl;
    std::cout << benchmark1.run();

    




    return 0;
}

