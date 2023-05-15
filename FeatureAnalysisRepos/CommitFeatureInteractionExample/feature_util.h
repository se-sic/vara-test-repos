#ifndef FEATURE_UTIL_H
#define FEATURE_UTIL_H

#include <chrono>
#include <exception>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <thread>

namespace fpcsc {
inline bool isFeatureEnabled(int argc, char *argv[], std::string FeatureName) {
  for (int CurrentArg = 1; CurrentArg < argc; ++CurrentArg) {
    if (argv[CurrentArg] == FeatureName) {
      return true;
    }
  }

  return false;
}

inline void busy_sleep_for_secs(unsigned Secs) {
  auto start_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now().time_since_epoch());
  auto end_ms = start_ms + std::chrono::seconds(Secs);
  auto current_ms = start_ms;

  while (current_ms < end_ms) {
    for (long counter = 0; counter < 100'000'000; ++counter) {
      asm volatile("" : "+g"(counter) : :); // prevent optimization
    }
    current_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now().time_since_epoch());
  }
}

inline void sleep_for_secs(unsigned Secs) {
  std::cout << "Sleeping for " << Secs << " seconds" << std::endl;
#ifdef USE_BUSY_SLEEPING
  busy_sleep_for_secs(Secs);
#else
  std::this_thread::sleep_for(std::chrono::seconds(Secs));
#endif
}

} // namespace fpcsc

#endif // FEATURE_UTIL_H
