#include "statistics.hpp"
#include <fstream>

namespace {

Stats loadFromFileStatistics(std::istream &is) {
  Stats stats;
  is >> stats;
  return stats;
}

} // namespace

load_stats_status_t collectStatistics() {
  std::ifstream statistics("../data/statistics.txt");
  if (statistics) {
    Stats stats = loadFromFileStatistics(statistics);
    return load_stats_status_t{true, stats};
  }
  return load_stats_status_t{false, Stats{}};
}

std::istream &operator>>(std::istream &is, Stats &s) {
  is >> s.bestScore >> s.gameCount >> s.winCount >> s.totalMoveCount >>
      s.totalDuration;
  return is;
}

std::ostream &operator<<(std::ostream &os, Stats &s) {
  os << s.bestScore << "\n"
     << s.gameCount << "\n"
     << s.winCount << "\n"
     << s.totalMoveCount << "\n"
     << s.totalDuration;
  return os;
}
