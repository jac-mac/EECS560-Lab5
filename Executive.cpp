#include "Executive.h"

Executive::Executive()
{
  hashTable = new Hash;
}

void Executive::Run()
{
  srand(time(NULL));
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
