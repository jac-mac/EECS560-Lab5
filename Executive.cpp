#include "Executive.h"

Executive::Executive()
{
  hashTableQ = new Hash(hashSize);
  hashTableD = new Hash(hashSize);
  for(int i = 0; i < 5; i++)
  {
    itemsFoundQ[i] = 0;
    itemsFoundD[i] = 0;
    itemsNotFoundQ[i] = 0;
    itemsNotFoundD[i] = 0;
  }
}

void Executive::Run()
{
  double m = 0.1;
  //double n = 0.01;
  int ind = 0;

  while(m <= 0.5)
  {
    srand(time(NULL));
    InitializeHashQ(m, ind);
    InitializeHashD(m, ind);
    m+=0.1;
    std::cout << "\n\n\n";
    SearchHashQ(ind);
    SearchHashD(ind);
    //n+=0.01;
    ind++;
  }
  PrintResultsQ();
  PrintResultsD();
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

void Executive::InitializeHashQ(double multiplier, int index)
{
  std::cout << "Inserting " << (int)(multiplier*hashSize) << " random numbers into hash table using QUADRATIC PROBING...\n";
  clock_t begin, end;

  begin = clock();
  for(int i = 0; i < (int)(multiplier*hashSize); i++)
  {
    hashTableQ->InsertQuad(rand() % 5000000 + 1);
  }
  end = clock();
  std::cout << "DONE\n";

  double time_interval = double(end-begin)/CLOCKS_PER_SEC;

  timeQ[index] = time_interval;
}

void Executive::InitializeHashD(double multiplier, int index)
{
  std::cout << "Inserting " << (int)(multiplier*hashSize) << " random numbers into hash table using DOUBLE HASHING...\n";
  clock_t begin, end;

  begin = clock();
  for(int i = 0; i < (int)(multiplier*hashSize); i++)
  {
    hashTableD->InsertDouble(rand() % 5000000 + 1);
  }
  end = clock();
  std::cout << "DONE\n";

  double time_interval = double(end-begin)/CLOCKS_PER_SEC;

  timeD[index] = time_interval;
}

void Executive::SearchHashQ(int index)
{
  int a[(int)(floor(0.01*hashSize))];
  for(int i = 0; i < (int)(0.01*hashSize); i++)
  {
    a[i] = rand() % 5000000 + 1;
  }
  for(int i = 0; i < (int)(0.01*hashSize); i++)
  {
    if(hashTableQ->SearchQuad(a[i]))
    {
      itemsFoundQ[index]++;
    }
    else
    {
      itemsNotFoundQ[index]++;
    }
  }
}

void Executive::SearchHashD(int index)
{
  int a[(int)(floor(0.01*hashSize))];
  for(int i = 0; i < (int)(0.01*hashSize); i++)
  {
    a[i] = rand() % 5000000 + 1;
  }
  for(int i = 0; i < (int)(0.01*hashSize); i++)
  {
    if(hashTableD->SearchDouble(a[i]))
    {
      itemsFoundD[index]++;
    }
    else
    {
      itemsNotFoundD[index]++;
    }
  }
}

void Executive::PrintResultsQ()
{
  std::cout << "\n\n\n\n\n";
  std::cout << "_____________________Performance (Quadratic Probing)_____________________\n";
  std::cout << "_________________________________________________________________________\n";
  std::cout << "| Input Size          | 100,000 | 200,000 | 300,000 | 400,001 | 500,001 | \n";
  std::cout << "_________________________________________________________________________\n";
  std::cout << "| Build (s)           |" << timeQ[0] << " |" << timeQ[1] << " |" << timeQ[2] << " |" << timeQ[3] << " | " << timeQ[4] << "| \n";
  std::cout << "_________________________________________________________________________\n";
  std::cout << "| Number of Items\n";
  std::cout << "| Successfully Found  |  " << itemsFoundQ[0] << "     |  " << itemsFoundQ[1] << "     |  " << itemsFoundQ[2] << "     |  " << itemsFoundQ[3] << "     |  " << itemsFoundQ[4] << "     |  \n";
  std::cout << "_________________________________________________________________________\n";
  std::cout << "| Number of Items\n";
  std::cout << "| Not Found           |  " << itemsNotFoundQ[0] << "   |  " << itemsNotFoundQ[1] << "  |  " << itemsNotFoundQ[2] << "  |  " << itemsNotFoundQ[3] << "  |  " << itemsNotFoundQ[4] << "   |  \n";
  std::cout << "_________________________________________________________________________\n";
}

void Executive::PrintResultsD()
{
  std::cout << "\n\n\n\n\n";
  std::cout << "_____________________Performance (Double Hashing)_____________________\n";
  std::cout << "_________________________________________________________________________\n";
  std::cout << "| Input Size          | 100,000 | 200,000 | 300,000 | 400,001 | 500,001 | \n";
  std::cout << "_________________________________________________________________________\n";
  std::cout << "| Build (s)           |" << timeD[0] << " |" << timeD[1] << " |" << timeD[2] << " |" << timeD[3] << " | " << timeD[4] << "| \n";
  std::cout << "_________________________________________________________________________\n";
  std::cout << "| Number of Items\n";
  std::cout << "| Successfully Found  |  " << itemsFoundD[0] << "   |  " << itemsFoundD[1] << "   |  " << itemsFoundD[2] << "    |  " << itemsFoundD[3] << "    |  " << itemsFoundD[4] << "    |  \n";
  std::cout << "_________________________________________________________________________\n";
  std::cout << "| Number of Items\n";
  std::cout << "| Not Found           |  " << itemsNotFoundD[0] << "   |  " << itemsNotFoundD[1] << "  |  " << itemsNotFoundD[2] << "  |  " << itemsNotFoundD[3] << "  |  " << itemsNotFoundD[4] << "   |  \n";
  std::cout << "_________________________________________________________________________\n";

}
