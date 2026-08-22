#ifndef currentTime_H
#define currentTime_H

#include <string>
#include <chrono>
#include <ctime>

/**
 * @file currentTime.h
 * @brief Provides a utility function for retrieving the current local date.
 */

 /**
  * @brief Returns the current local date as a formatted string.
  *
  * The date is obtained from the system clock and converted to
  * the local time zone.
  *
  * @return The current date in YYYY-MM-DD format.
  */


inline std::string getCurrentDate() {
    auto currentDatePoint = std::chrono::system_clock::now();    
    std::time_t currentTime = std::chrono::system_clock::to_time_t(currentDatePoint);
    std::tm localTime;    
    localtime_s(&localTime, &currentTime);

    std::string dateString = std::to_string(localTime.tm_year + 1900) + '-'
        + (localTime.tm_mon + 1 < 10 ? "0" : "")
        + std::to_string(localTime.tm_mon + 1) + '-'
        + (localTime.tm_mday < 10 ? "0" : "")
        + std::to_string(localTime.tm_mday);

    return dateString;
}
#endif