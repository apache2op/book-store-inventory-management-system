#include <iostream>
#include <string.h>
using namespace std;

class book
{
  char author[50], title[50], publisher[50];
  int price, stock;

public:
  book();
  void get_data();
  void display_data();
  int search(char[], char[]);
  void copies(int);
};
book::book()
{
  char *author = new char[50];
  char *title = new char[50];
  char *publisher = new char[50];
  price = 0;
  stock = 0;
}

void book::get_data()
{
  cout << "\nEnter name of the author: ";
  cin >> author;
  cout << "\nEnter title of the book: ";
  cin >> title;
  cout << "\nEnter publisher of the book: ";
  cin >> publisher;
  cout << "\nEnter price of the book: ";
  cin >> price;
  cout << "\nEnter stock of book: ";
  cin >> stock;
}

void book::display_data()
{
  cout << "\n";
  cout << author << "\t" << title << "\t" << publisher << "\t" << price << "\t" << stock;
}

int book::search(char a[50], char b[50])
{

  if (strcmp(author, a) && strcmp(title, b))
  {
    return 1;
  }
  else
    return 0;
}

void book::copies(int cop)
{
  if (stock >= cop)
  {
    cout << "\nPrice for " << cop << " copies is: " << (price * cop);
  }
  else
    cout << "\n*Not available*";
}

int main()
{
  system("cls");
  cout << "\t\t***Book Inventory***";
  int i, choice, flag, n, key, c;
  char con;
  char s_author[50], s_title[50];
  book b[50];
  do
  {
    cout << "\n1)Upgrade the inventory\n2)Display\n3)Search the book\n4)Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      cout << "\nHow many books do you want to involve: ";
      cin >> n;
      for (i = 0; i < n; i++)
      {
        b[i].get_data();
      }
      break;
    }
    case 2:
    {
      cout << "\nAuthor\tTitle\tPublisher\tPrice\tStock";
      for (i = 0; i < n; i++)
      {
        b[i].display_data();
      }
      break;
    }
    case 3:
    {
      cout << "\nEnter the name of the author: ";
      cin >> s_author;
      cout << "\nEnter the title of the book: ";
      cin >> s_title;
      for (i = 0; i < n; i++)
      {
        if (b[i].search(s_author, s_title))
        {
          key = i;
          flag = 1;
          if (flag == 1)
          {
            cout << "\nBook is available";
          }
          else
          {
            cout << "\nNo such book in the inventory";
            break;
          }
        }
      }
      if (flag == 1)
      {
        cout << "\nEnter no. of copies you want: ";
        cin >> c;
        b[key].copies(c);
      }
      break;
    }
    case 4:
      cout << "\nBye Bye";
      return 0;
    }
    cout << "\nDo you want to continue(y/n): ";
    cin >> con;
    system("cls");
  } while (con != 'n');
  return 0;
}