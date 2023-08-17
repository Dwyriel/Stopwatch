#ifndef STOPWATCH_STOPWATCH_H
#define STOPWATCH_STOPWATCH_H

#include <chrono>

/**
 * <br>Default Stopwatch, uses std::chrono::high_resolution_clock
 */
class Stopwatch {
    static bool isRunning;
    static std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_end;

    template<class Ratio>
    static inline double elapsedByPrecision();

public:
    Stopwatch() = delete;

    static void start();

    static void stop();

    static double elapsedPicoseconds();

    static double elapsedNanoseconds();

    static double elapsedMicroseconds();

    static double elapsedMilliseconds();

    static double elapsedSeconds();
};

/**
 * <br>Uses std::chrono::high_resolution_clock
 */
using StopwatchHRC = Stopwatch;

/**
 * <br>Uses std::chrono::steady_clock
 */
class StopwatchSC {
    static bool isRunning;
    static std::chrono::time_point<std::chrono::steady_clock> m_start, m_end;

    template<class Ratio>
    static inline double elapsedByPrecision();

public:
    StopwatchSC() = delete;

    static void start();

    static void stop();

    static double elapsedPicoseconds();

    static double elapsedNanoseconds();

    static double elapsedMicroseconds();

    static double elapsedMilliseconds();

    static double elapsedSeconds();
};

#endif //STOPWATCH_STOPWATCH_H
