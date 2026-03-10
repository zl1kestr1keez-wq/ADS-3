// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxValue = num;
  while (num > 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = num * 3 + 1;
    }
    if (num > maxValue) {
      maxValue = num;
    }
  }
  return maxValue;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
  while (num > 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = num * 3 + 1;
    }
    len++;
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int maxLen = 0;
  unsigned int bestNum = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    unsigned int curLen = collatzLen(i);
    if (curLen > maxLen) {
      maxLen = curLen;
      bestNum = i;
    }
  }
  *maxlen = maxLen;
  return bestNum;
}
