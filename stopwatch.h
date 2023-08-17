#ifndef STOPWATCH_STOPWATCH_H
#define STOPWATCH_STOPWATCH_H

#include <chrono>

template<class clock = typename std::chrono::high_resolution_clock>
class Stopwatch {
    static const int totalOverheadCalcPasses = 10;

    static bool isRunning;
    static std::chrono::time_point<clock> m_start, m_end;
    static double overheadInPico;

    template<typename Ratio>
    static inline double elapsedByPrecision(){
        if (isRunning)
            m_end = clock::now();
        std::chrono::duration<double, Ratio> elapsed = m_end - m_start;
        double convertedOverhead = overheadInPico * (static_cast<double>(Ratio::den) / static_cast<double>(std::pico::den));
        return elapsed.count() - convertedOverhead;
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

    /**
     * <br>Should not be called after calling start() and before calling stop().
     */
    static void calculateOverhead() {
        overheadInPico = 0;
        double results[totalOverheadCalcPasses];
        for (double &result: results) {
            start();
            stop();
            result = elapsedPicoseconds();
        }
        double total = 0;
        for (double result: results)
            total += result;
        overheadInPico = total / totalOverheadCalcPasses;
    }

    static void resetOverhead(){
        overheadInPico = 0;
    }

    /**
     * @return overhead in picoseconds.
     */
    static double overhead() {
        return overheadInPico;
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

typedef Stopwatch<std::chrono::high_resolution_clock> StopwatchHighRes;
typedef Stopwatch<std::chrono::steady_clock> StopwatchSteady;

template<class clock>
bool Stopwatch<clock>::isRunning = false;

template<class clock>
std::chrono::time_point<clock> Stopwatch<clock>::m_start = clock::now();

template<class clock>
std::chrono::time_point<clock> Stopwatch<clock>::m_end = clock::now();

template<class clock>
double Stopwatch<clock>::overheadInPico = 0;

#endif //STOPWATCH_STOPWATCH_H
