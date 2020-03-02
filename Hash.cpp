#include "Hash.h"

Hash::Hash(int newSize)
{
  size = newSize;
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
    for(int i = 0; i < 25; i++)
    {
      if(arr[(HashFunction(input)+(i*i)) % size] == -1)
      {
        arr[(HashFunction(input)+(i*i)) % size] = input;
        break;
      }
      b_arr[(HashFunction(input)+(i*i)) % size] = 1;
    }
}

void Hash::InsertDouble(int input)
{
    for(int i = 0; i < 25; i++)
    {
      if(arr[(HashFunction(input)+(i*(HashFunction2(input)))) % size] == -1)
      {
        arr[(HashFunction(input)+(i*(HashFunction2(input)))) % size] = input;
        break;
      }
      b_arr[(HashFunction(input)+(i*(HashFunction2(input)))) % size] = 1;
    }
}

bool Hash::SearchQuad(int input)
{
    for(int i = 0; i < 25; i++)
    {
      if(arr[(HashFunction(input)+(i*i)) % size] == input)
      {
        return true;
      }
      else if(b_arr[(HashFunction(input)+(i*i)) % size] == 0 && arr[HashFunction(HashFunction(input)+(i*i))] != input)
      {
        return false;
      }
    }
    return false;
}

bool Hash::SearchDouble(int input)
{
    for(int i = 0; i < 25; i++)
    {
      if(arr[(HashFunction(input)+(i*(HashFunction2(input)))) % size] == input)
      {
        return true;
      }
      else if(b_arr[(HashFunction(input)+(i*(HashFunction2(input)))) % size] == 0)
      {
        return false;
      }
    }
    return false;
}

bool Hash::HasOccupied(int input)
{
  if(b_arr[input] == 1)
    return true;

  return false;
}
