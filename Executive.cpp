#include "Executive.h"

Executive::Executive()
{
  hashSize = 1000003;
  hashTableQ = new Hash(hashSize);
  hashTableD = new Hash(hashSize);
}

void Executive::Run()
{

}

void Executive::PrintMenu()
{
  std::cout << "\nChoose one of the options below: \n\n";
  std::cout << "\t 1. IsFull\n"
            << "\t 2. AddMovie\n"
            << "\t 3. RemoveMovie\n"
            << "\t 4. Leaf\n"
            << "\t 5. PrintLeaves\n"
            << "\t 6. PrintTreeHeight\n"
            << "\t 7. Preorder\n"
            << "\t 8. Postorder\n"
            << "\t 9. Inorder\n"
            << "\t10. Levelorder\n"
            << "\t11. Exit\n\n";
  std::cout << "Your choice: ";
}

void Executive::WrongInputTypeCheck(int &num)
{
  std::cin >> num;
  while(1)
    {
      if(cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input a NUMBER please. \n\n";
        cout << "Your choice: ";
        cin >> num;
      }
      else
        break;
    }
}

void Executive::InitializeHash(double multiplier)
{
  srand(time(NULL));
  std::cout << "Inserting " << floor(multiplier*hashSize) << " random numbers into hash table using quadratic probing...\n";
  int randomNumber;
  clock_t begin, end;

  int a[hashSize];
  begin = clock();
  for(int i = 0; i < floor(multiplier*hashSize); i++)
  {
    randomNumber = rand() % 5000000 + 1; //1-5,000,000
    hashTableQ->InsertQuad(randomNumber);
  }
  end = clock();
  std::cout << "\n\nDONE\n";

  double time_interval = double(end-begin)/CLOCKS_PER_SEC;

  std::cout << "Inserting " << floor(multiplier*hashSize) << " random numbers into hash table";
}
