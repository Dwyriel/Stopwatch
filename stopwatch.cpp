#include "stopwatch.h"

const int totalOverheadCalcPasses = 10;

bool StopwatchHighRes::isRunning = false;

std::chrono::time_point<std::chrono::high_resolution_clock> StopwatchHighRes::m_start = std::chrono::high_resolution_clock::now();

std::chrono::time_point<std::chrono::high_resolution_clock> StopwatchHighRes::m_end = std::chrono::high_resolution_clock::now();

double StopwatchHighRes::overheadInPico = 0;

template<class Ratio>
double StopwatchHighRes::elapsedByPrecision() {
    if (isRunning)
        m_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, Ratio> elapsed = m_end - m_start;
    double convertedOverhead = overheadInPico * (static_cast<double>(Ratio::den) / static_cast<double>(std::pico::den));
    return elapsed.count() - convertedOverhead;
}

void StopwatchHighRes::start() {
    isRunning = true;
    m_start = std::chrono::high_resolution_clock::now();
}

void StopwatchHighRes::stop() {
    m_end = std::chrono::high_resolution_clock::now();
    isRunning = false;
}

void StopwatchHighRes::calculateOverhead() {
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

void StopwatchHighRes::resetOverhead() {
    overheadInPico = 0;
}

double StopwatchHighRes::overhead() {
    return overheadInPico;
}

double StopwatchHighRes::elapsedPicoseconds() {
    return elapsedByPrecision<std::pico>();
}

double StopwatchHighRes::elapsedNanoseconds() {
    return elapsedByPrecision<std::nano>();
}

double StopwatchHighRes::elapsedMicroseconds() {
    return elapsedByPrecision<std::micro>();
}

double StopwatchHighRes::elapsedMilliseconds() {
    return elapsedByPrecision<std::milli>();
}

double StopwatchHighRes::elapsedSeconds() {
    return elapsedByPrecision<std::ratio<1>>();
}

bool StopwatchSteady::isRunning = false;

std::chrono::time_point<std::chrono::steady_clock> StopwatchSteady::m_start = std::chrono::steady_clock::now();

std::chrono::time_point<std::chrono::steady_clock> StopwatchSteady::m_end = std::chrono::steady_clock::now();

double StopwatchSteady::overheadInPico = 0;

template<class Ratio>
double StopwatchSteady::elapsedByPrecision() {
    if (isRunning)
        m_end = std::chrono::steady_clock::now();
    std::chrono::duration<double, Ratio> elapsed = m_end - m_start;
    double convertedOverhead = overheadInPico * (static_cast<double>(Ratio::den) / static_cast<double>(std::pico::den));
    return elapsed.count() - convertedOverhead;
}

void StopwatchSteady::start() {
    isRunning = true;
    m_start = std::chrono::steady_clock::now();
}

void StopwatchSteady::stop() {
    m_end = std::chrono::steady_clock::now();
    isRunning = false;
}

void StopwatchSteady::calculateOverhead() {
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

void StopwatchSteady::resetOverhead() {
    overheadInPico = 0;
}

double StopwatchSteady::overhead() {
    return overheadInPico;
}

double StopwatchSteady::elapsedPicoseconds() {
    return elapsedByPrecision<std::pico>();
}

double StopwatchSteady::elapsedNanoseconds() {
    return elapsedByPrecision<std::nano>();
}

double StopwatchSteady::elapsedMicroseconds() {
    return elapsedByPrecision<std::micro>();
}

double StopwatchSteady::elapsedMilliseconds() {
    return elapsedByPrecision<std::milli>();
}

double StopwatchSteady::elapsedSeconds() {
    return elapsedByPrecision<std::ratio<1>>();
}
