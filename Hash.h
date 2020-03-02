#ifndef HASH_H
#define HASH_H

class Hash
{
  private:
  int* arr;
  int size;
  bool* b_arr;

  public:
  Hash(int newSize);
  ~Hash();

  int HashFunction(int input);
  int HashFunction2(int input);
  void InsertQuad(int input);
  void InsertDouble(int input);
  bool SearchQuad(int input);
  bool SearchDouble(int input);
  bool HasOccupied(int input);

};
#endif
