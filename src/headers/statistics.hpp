#ifndef STATISTICS_H
#define STATISTICS_H

#include "global.hpp"
#include <iosfwd>

class Stats {
public:
  bool collectStatistics();
  ull bestScore;
  ull totalMoveCount;
  int gameCount;
  double totalDuration;
  int winCount;

  friend std::istream& operator>>(std::istream& is, Stats &s);
  friend std::ostream& operator<<(std::ostream& os, Stats &s);
};


#endif
