#ifndef STOPWATCH_STOPWATCH_H
#define STOPWATCH_STOPWATCH_H

#include <chrono>

template<class clock>
class Stopwatch {
    static bool isRunning;
    static std::chrono::time_point<clock> m_start, m_end;

    template<typename Ratio>
    static inline double elapsedByPrecision(){
        if (isRunning)
            m_end = clock::now();
        std::chrono::duration<double, Ratio> elapsed = m_end - m_start;
        return elapsed.count();
    }

public:
    Stopwatch() = delete;

    static void start(){
        isRunning = true;
        m_start = clock::now();
    }

    static void stop(){
        m_end = clock::now();
        isRunning = false;
    }

    static double elapsedPicoseconds() {
        return elapsedByPrecision<std::pico>();
    }

    static double elapsedNanoseconds(){
        return elapsedByPrecision<std::nano>();
    }

    static double elapsedMicroseconds(){
        return elapsedByPrecision<std::micro>();
    }

    static double elapsedMilliseconds(){
        return elapsedByPrecision<std::milli>();
    }

    static double elapsedSeconds(){
        return elapsedByPrecision<std::ratio<1>>();
    }
};

typedef Stopwatch<std::chrono::high_resolution_clock> StopwatchHRC;
typedef Stopwatch<std::chrono::steady_clock> StopwatchSC;


template<class clock>
bool Stopwatch<clock>::isRunning = false;

template<class clock>
std::chrono::time_point<clock> Stopwatch<clock>::m_start = clock::now();

template<class clock>
std::chrono::time_point<clock> Stopwatch<clock>::m_end = clock::now();

#endif //STOPWATCH_STOPWATCH_H
