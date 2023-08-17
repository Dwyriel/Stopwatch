#ifndef STOPWATCH_STOPWATCH_H
#define STOPWATCH_STOPWATCH_H

#include <chrono>

/**
 * <br>Uses std::chrono::high_resolution_clock
 */
class StopwatchHighRes {
    static bool isRunning;
    static std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_end;
    static double overheadInPico;

    template<class Ratio>
    static inline double elapsedByPrecision();

public:
    StopwatchHighRes() = delete;

    static void start();

    static void stop();

    /**
     * <br>Should not be called after calling start.
     */
    static void calculateOverhead();

    static void resetOverhead();

    /**
     * @return overhead in picoseconds.
     */
    static double overhead();

    static double elapsedPicoseconds();

    static double elapsedNanoseconds();

    static double elapsedMicroseconds();

    static double elapsedMilliseconds();

    static double elapsedSeconds();
};

/**
 * <br>Uses std::chrono::steady_clock
 */
class StopwatchSteady {
    static bool isRunning;
    static std::chrono::time_point<std::chrono::steady_clock> m_start, m_end;
    static double overheadInPico;

    template<class Ratio>
    static inline double elapsedByPrecision();

public:
    StopwatchSteady() = delete;

    static void start();

    static void stop();

    /**
     * <br>Should not be called after calling start.
     */
    static void calculateOverhead();

    static void resetOverhead();

    /**
     * @return overhead in picoseconds.
     */
    static double overhead();

    static double elapsedPicoseconds();

    static double elapsedNanoseconds();

    static double elapsedMicroseconds();

    static double elapsedMilliseconds();

    static double elapsedSeconds();
};

/**
 * <br>Default Stopwatch, uses std::chrono::high_resolution_clock
 */
using Stopwatch = StopwatchHighRes;

#endif //STOPWATCH_STOPWATCH_H
