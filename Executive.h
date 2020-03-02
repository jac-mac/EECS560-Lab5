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
  int hashSize = 1000003;
  Hash* hashTableQ;
  Hash* hashTableD;
  double timeQ[5];
  double timeD[5];
  int itemsFoundQ[5];
  int itemsFoundD[5];
  int itemsNotFoundD[5];
  int itemsNotFoundQ[5];

  public:
  Executive();
  void Run();
  void PrintMenu();
  void WrongInputTypeCheck(int &num);
  void InitializeHashQ(double multiplier, int index);
  void InitializeHashD(double multiplier, int index);
  void SearchHashQ(int index);
  void SearchHashD(int index);
  void PrintResultsQ();
  void PrintResultsD();
};
#endif
