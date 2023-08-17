#include "stopwatch.h"

bool Stopwatch::isRunning = false;

std::chrono::time_point<std::chrono::high_resolution_clock> Stopwatch::m_start = std::chrono::high_resolution_clock::now();

std::chrono::time_point<std::chrono::high_resolution_clock> Stopwatch::m_end = std::chrono::high_resolution_clock::now();

template<class Ratio>
double Stopwatch::elapsedByPrecision() {
    if (isRunning)
        m_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, Ratio> elapsed = m_end - m_start;
    return elapsed.count();
}

void Stopwatch::start() {
    isRunning = true;
    m_start = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stop() {
    m_end = std::chrono::high_resolution_clock::now();
    isRunning = false;
}

double Stopwatch::elapsedPicoseconds() {
    return elapsedByPrecision<std::pico>();
}

double Stopwatch::elapsedNanoseconds() {
    return elapsedByPrecision<std::nano>();
}

double Stopwatch::elapsedMicroseconds() {
    return elapsedByPrecision<std::micro>();
}

double Stopwatch::elapsedMilliseconds() {
    return elapsedByPrecision<std::milli>();
}

double Stopwatch::elapsedSeconds() {
    return elapsedByPrecision<std::ratio<1>>();
}

bool StopwatchSC::isRunning = false;

std::chrono::time_point<std::chrono::steady_clock> StopwatchSC::m_start = std::chrono::steady_clock::now();

std::chrono::time_point<std::chrono::steady_clock> StopwatchSC::m_end = std::chrono::steady_clock::now();

template<class Ratio>
double StopwatchSC::elapsedByPrecision() {
    if (isRunning)
        m_end = std::chrono::steady_clock::now();
    std::chrono::duration<double, Ratio> elapsed = m_end - m_start;
    return elapsed.count();
}

void StopwatchSC::start() {
    isRunning = true;
    m_start = std::chrono::steady_clock::now();
}

void StopwatchSC::stop() {
    m_end = std::chrono::steady_clock::now();
    isRunning = false;
}

double StopwatchSC::elapsedPicoseconds() {
    return elapsedByPrecision<std::pico>();
}

double StopwatchSC::elapsedNanoseconds() {
    return elapsedByPrecision<std::nano>();
}

double StopwatchSC::elapsedMicroseconds() {
    return elapsedByPrecision<std::micro>();
}

double StopwatchSC::elapsedMilliseconds() {
    return elapsedByPrecision<std::milli>();
}

double StopwatchSC::elapsedSeconds() {
    return elapsedByPrecision<std::ratio<1>>();
}
