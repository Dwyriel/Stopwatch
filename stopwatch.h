#ifndef STOPWATCH_STOPWATCH_H
#define STOPWATCH_STOPWATCH_H

#include <chrono>

class Stopwatch{
    bool isRunning = false;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_end;

public:
    void start();

    void stop();

    uint64_t elapsedNanoseconds();

    uint64_t elapsedMicroseconds();

    uint64_t elapsedMilliseconds();

    double elapsedSeconds();
};

#endif //STOPWATCH_STOPWATCH_H
