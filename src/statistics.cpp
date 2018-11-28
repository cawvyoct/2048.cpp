#include "statistics.hpp"
#include <fstream>

bool Stats::collectStatistics() {

  std::ifstream statistics("../data/statistics.txt");
  if (statistics.fail()) {
    return false;
  }

  statistics >> bestScore >> gameCount >> winCount >> totalMoveCount >>
      totalDuration;
  return true;
}
