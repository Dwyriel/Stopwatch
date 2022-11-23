#include "stopwatch.h"

void Stopwatch::start() {
    isRunning = true;
    m_start = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stop() {
    m_end = std::chrono::high_resolution_clock::now();
    isRunning = false;
}

uint64_t Stopwatch::elapsedNanoseconds() {
    if(isRunning)
        m_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> elapsed = m_end - m_start;
    return (uint64_t)elapsed.count();
}

uint64_t Stopwatch::elapsedMicroseconds() {
    if(isRunning)
        m_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = m_end - m_start;
    return (uint64_t)elapsed.count();
}

uint64_t Stopwatch::elapsedMilliseconds() {
    if(isRunning)
        m_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = m_end - m_start;
    return (uint64_t)elapsed.count();
}

double Stopwatch::elapsedSeconds() {
    if(isRunning)
        m_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = m_end - m_start;
    return elapsed.count();
}
