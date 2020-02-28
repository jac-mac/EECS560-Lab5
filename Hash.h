#ifndef HASH_H
#define HASH_H

class Hash
{
  private:
  int* arr;
  int size = 1000003; //1,000,003
  bool* b_arr;

  public:
  Hash();
  ~Hash();

  int HashFunction(int input);
  int HashFunction2(int input);
  void InsertQuad(int input);
  void InsertDouble(int input);
  bool HasOccupied(int input);

};
#endif
