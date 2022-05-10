#include "ThreadSafeVector.hpp"

n3tw0rk::ThreadSafeVector<size_t> threadSafeVector;

#define RUNNING_ITERATIONS 100
#define RANDOM_SLEEP_ITERATION_MILLISECONDS 1000

void threaded(size_t value)
{
    size_t sleepFor = rand() % RANDOM_SLEEP_ITERATION_MILLISECONDS + 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepFor));
    for(size_t i = 0; i < RUNNING_ITERATIONS; i++) {
        threadSafeVector.push_back(value);
    }
}

int main()
{
    std::vector<std::thread> threads;

    size_t runningThreads = RUNNING_ITERATIONS;

    for (size_t i = 0; i < runningThreads; i++) {
        threads.push_back(std::thread(threaded, i));
    }

    for (size_t i = 0; i < runningThreads; i++) {
        threads.at(i).join();
    }

    threads.empty();

    for (std::vector<size_t>::iterator iterator = threadSafeVector.begin(); iterator != threadSafeVector.end(); iterator++) {
        std::cout << *iterator << std::endl;
    }

    threadSafeVector.empty();

    return 0;
}
