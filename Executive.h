#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <limits>
#include <stdexcept>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include "Hash.h"

using namespace std;

class Executive
{
  private:
  Hash* hashTableQ;
  Hash* hashTableD;
  int hashSize;

  public:
  Executive();
  void Run();
  void PrintMenu();
  void WrongInputTypeCheck(int &num);
  void InitializeHash(double multiplier);
};
#endif
