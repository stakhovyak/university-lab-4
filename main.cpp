#include <iostream>
#include <fstream>
#include <stdexcept>
#include "include/node-list.h"

using std::cout, std::endl, std::ifstream, std::cerr, std::cin, std::string;

enum Command
  {
    create = 1,
    print = 2,
    reverse = 3,
    add = 4,
    insert = 5,
    length = 6,
    deleteCommand = 7,
    show = 8,
    save = 9,
    quit = 10,
    import = 11
  }; 

// Function to prompt for yes/no response
bool prompt(const std::string &message)
{
  while (true)
    {
      cout << message << " (y/n): ";
      std::string response;
      std::cin >> response;

      if (response == "y" || response == "Y")
        {
          return true;
        }
      else if (response == "n" || response == "N")
        {
          return false;
        }
      else
        {
          cout << "Invalid response. Please enter 'y' or 'n'." << endl;
        }
    }
}

int main (void)
{
  Linkedlist<unsigned int> buffer;
  string command;
  int value;
  int position;

  cout << "1) создать пустой список" << endl;
  cout << "2) вывести список на экран" << endl;
  cout << "3) развернуть список" << endl;
  cout << "4) добавить элемент в конец списка" << endl;
  cout << "5) добавить элемент на указанную позицию" << endl;
  cout << "6) показать длину списка" << endl;
  cout << "7) удалить элемент на указанной позиции" << endl;
  cout << "8) показать элемент на определенной позиции" << endl;
  cout << "9) сохранить в input.txt" << endl;
  cout << "10) выйти из программы" << endl;
  cout << "11) импортировать список из input.txt" << endl;

  while(true)
    {
      cout << "Введите команду: ";
      cin >> command;
    
      switch (static_cast<Command>(stoi(command)))
        {
        case create:
          {
            Linkedlist<unsigned int> buffer;
            break;
          }
        case print:
          buffer.printList();
          break;
        case reverse:
          buffer.reverseList();
          break;
        case add:
          cout << "Введите значение элемента: ";
          cin >> value;
          buffer.insertNode(value);
          break;
        case insert:
          cout << "Введите значение элемента: ";
          cin >> value;
          cout << "Введите позицию: ";
          cin >> position;
          buffer.insertNode(value, position);
          break;
        case length:
          cout << "Длина списка: " << buffer.listLength() <<
            endl;
          break;
        case deleteCommand:
          cout << "Введите позицию: ";
          cin >> position;
          buffer.deleteNode(position);
          break;
        case show:
          {
            cout << "Введите позицию: ";
            cin >> position;
            Node<unsigned int> *example = buffer.index(position);
            cout << "Элемент на позиции " << position << ": " <<
              example->data << endl;
            break;
          }
        case save:
          {
            bool answer = prompt("Хотите сохранить список?");
            if (answer)
              buffer.write();
            else
              cout << "Ладно, можно и без этого обойтись..." << endl;
            break;
          }
        case quit:
          return 0;
        case import:
          {
            bool answer1 = prompt("Хотите импортировать список из input.txt?");
            if (answer1)
              {
                Linkedlist<unsigned int> buffer;
                // Read input from file
                ifstream inputFile("input.txt");
                if (!inputFile)
                  {
                    cerr << "Не удалось открыть файл ввода." << endl;
                    return 1;
                  }
                int data;
                while (inputFile >> data)
                  {
                    buffer.insertNode(data);
                  }
                if (!buffer.isIncreasing())
                  {
                    throw std::invalid_argument("Change the input.txt");
                  }
                inputFile.close();
              }
            else
              cout << "Ладно, можно и без этого обойтись..." << endl;
          }
        }
    }
  
  return 0;
}
