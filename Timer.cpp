//
// Created by mhajd on 17.04.2023.
//

#include "Timer.h"

#include "Timer.h"

void Timer::startTime() {
    beginningTime = high_resolution_clock::now();
}

void Timer::stopTime() {
    finishingTime = high_resolution_clock::now();
}

long long  Timer::nanoMeasuredTime() {
    return duration_cast<nanoseconds>(Timer::finishingTime - Timer::beginningTime).count();
}

