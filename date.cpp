#include <iostream>

using namespace std;

int main()
{
  int day, month, year;
  bool isLeapYear, isLastDayinMonth, error;
  cout << "Please input the date (AD): \n";
  cout << "Day: ";
  cin >> day;
  cout << "Month: ";
  cin >> month;
  cout << "Year: ";
  cin >> year;

  isLeapYear = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  error = day < 1 || month < 1 || year < 1 || month > 12;

  if (month == 4 || month == 6 || month == 9 || month == 11) //check if date is last day of the month and error
  {
    if (day == 30)
      isLastDayinMonth = true;
    else
      isLastDayinMonth = false;
    if (day > 30)
      error = true;
  }
  else if (month == 2)
  {
    if (isLeapYear)
    {
      if (day == 29)
        isLastDayinMonth = true;
      else
        isLastDayinMonth = false;
      if (day > 29)
        error = true;
    }
    else
    {
      if (day == 28)
        isLastDayinMonth = true;
      else
        isLastDayinMonth = false;
      if (day > 28)
        error = true;
    }
  }
  else
  {
    if (day == 31)
      isLastDayinMonth = true;
    else
      isLastDayinMonth = false;
    if (day > 31)
      error = true;
  }
  if (error)
  {
    cout << "Invalid Date, please retry \n";
    return -1;
  }

  if (isLastDayinMonth)
  {
    if (month == 12)
      cout << "The next day is 1/1/" << year + 1 << endl;
    else
      cout << "The next day is 1/" << month + 1 << "/" << year << endl;
  }
  else
    cout << "The next day is " << day + 1 << "/" << month << "/" << year << endl;
  return 0;
}
