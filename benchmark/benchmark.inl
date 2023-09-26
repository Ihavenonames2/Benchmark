template<class T>
void Benchmark<T>::SetIterationCount(int count)
{
    IterationCount = count;
}

template<class T>
void Benchmark<T>::SetTestCode(std::function<void()> callback)
{
    this->callback = callback;
}

template<class T>
double Benchmark<T>::run()
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

template<class T>
bool Benchmark<T>::operator>(Benchmark<T> benchmark)
{
    return run() > benchmark.run();
}

template<class T>
bool Benchmark<T>::operator<(Benchmark<T> benchmark)
{
    return run() < benchmark.run();
}

template<class T>
bool Benchmark<T>::operator==(Benchmark<T> benchmark)
{
    return run() == benchmark.run();
}

template<class T>
bool Benchmark<T>::operator!=(Benchmark<T> benchmark)
{
    return run() != benchmark.run();
}


