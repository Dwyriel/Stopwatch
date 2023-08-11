#include "stopwatch.h"

bool Stopwatch::isRunning = false;

std::chrono::time_point<std::chrono::high_resolution_clock> Stopwatch::m_start = std::chrono::high_resolution_clock::now();

std::chrono::time_point<std::chrono::high_resolution_clock> Stopwatch::m_end = std::chrono::high_resolution_clock::now();

void Stopwatch::start() {
    isRunning = true;
    m_start = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stop() {
    m_end = std::chrono::high_resolution_clock::now();
    isRunning = false;
}

double Stopwatch::elapsedNanoseconds() {
    if (isRunning)
        m_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> elapsed = m_end - m_start;
    return elapsed.count();
}

double Stopwatch::elapsedMicroseconds() {
    if (isRunning)
        m_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = m_end - m_start;
    return elapsed.count();
}

double Stopwatch::elapsedMilliseconds() {
    if (isRunning)
        m_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = m_end - m_start;
    return elapsed.count();
}

double Stopwatch::elapsedSeconds() {
    if (isRunning)
        m_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = m_end - m_start;
    return elapsed.count();
}
