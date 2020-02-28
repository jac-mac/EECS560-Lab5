#include "Hash.h"

Hash::Hash()
{
  arr = new int[size];
  b_arr = new bool[size];

  for(int i = 0; i < size; i++)
  {
    arr[i] = -1;
    b_arr[i] = 0;
  }
}

Hash::~Hash()
{
  delete arr;
  delete b_arr;
}

int Hash::HashFunction(int input)
{
  return (input & size);
}

int Hash::HashFunction2(int input)
{
  int R = 773;
  return (R - (input % R));
}

void Hash::InsertQuad(int input)
{
  bool foundEmpty = false;
  if(arr[HashFunction(input)] == -1)
  {
    arr[HashFunction(input)] = input;
  }
  else
  {
    for(int i = 0; i < 25; i++)
    {
      if(arr[HashFunction(input)+(i*i)] == -1)
      {
        arr[HashFunction(input)+(i*i)] = input;
        foundEmpty = true;
        break;
      }
    }
  }
}

void Hash::InsertDouble(int input)
{
  bool foundEmpty = false;
  if(arr[HashFunction(input)] == -1)
  {
    arr[HashFunction(input)] = input;
  }
  else
  {
    for(int i = 0; i < 25; i++)
    {
      if(arr[HashFunction(input)+(i*(HashFunction2(input)))] == -1)
      {
        arr[HashFunction(input)+(i*(HashFunction2(input)))] = input;
        foundEmpty = true;
        break;
      }
    }
  }
}

bool Hash::HasOccupied(int input)
{
  if(b_arr[input] == 1)
    return true;

  return false;
}
