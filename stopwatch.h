#ifndef STOPWATCH_STOPWATCH_H
#define STOPWATCH_STOPWATCH_H

#include <chrono>

class Stopwatch {
    static bool isRunning;
    static std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_end;

public:
    Stopwatch() = delete;

    static void start();

    static void stop();


    static double elapsedNanoseconds();

    static double elapsedMicroseconds();

    static double elapsedMilliseconds();

    static double elapsedSeconds();
};

#endif //STOPWATCH_STOPWATCH_H
