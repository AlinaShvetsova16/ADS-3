// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxValue = num;
  while (num != 1) {
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
  unsigned int length = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = num * 3 + 1;
    }
    length++;
  }
  return length;

}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int maxLenght = 0;
  uint64_t top = lbound;
  for (uint64_t n = lbound; n <= rbound; n++) {
    uint64_t cur = n;
    unsigned int length = 1;
    while (cur != 1){
      if (cur % 2 == 0){
        cur = cur / 2;
      } else {
        cur = cur * 3 + 1;
      }
      length++;
    }
    if (length > maxLenght) {
      maxLenght = length;
      top = n;
    }
  }
  *maxlen = maxLenght;
  return top;
}
