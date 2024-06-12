#include <iostream>
using namespace std;

int readInput(string message)
{
  int inputNum;
  cout << message + "\n";
  cin >> inputNum;
  return inputNum;
}

void ReadArray(int arr[100], int &arrLength)
{
  cout << "\nEnter number of elements:\n";
  cin >> arrLength;
  cout << "\nEnter array elements: \n";
  for (int i = 0; i < arrLength; i++)
  {
    cout << "Element [" << i + 1 << "] : ";
    cin >> arr[i];
  }
  cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
  for (int i = 0; i < arrLength; i++)
    cout << arr[i] << " ";
  cout << "\n";
}

int randomNumber(int From, int To)
{ // Function to generate a random number
  int randNum = rand() % (To - From + 1) + From;
  return randNum;

  // Put the next line in main
  //  srand((unsigned)time(NULL));
}

int findMax(int arr[], int size)
{
  int max = arr[0];
  for (int i = 0; i < size; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

int findMin(int arr[], int size)
{
  int min = arr[0];
  for (int i = 0; i < size; i++)
  {
    if (arr[i] < min)
    {
      min = arr[i];
    }
  }
  return min;
}

int arrSum(int arr[], int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }
  return sum;
}

bool isPrime(int num)
{
  if (num == 1)
  {
    return false;
  }
  for (int i = 2; i <= num / 2; ++i)
  {
    if (num % i == 0)
    {
      return false;
    }
  }

  return true;
}
void shuffleArr(int arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    int x = randomNumber(0, size - 1),
        y = randomNumber(0, size - 1);
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
  }
}

void fillArrWithRandom(int arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    arr[i] = randomNumber(1, 100);
  }
}

void arrReverseCopy(int originArr[], int reverseArr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    reverseArr[size - 1 - i] = originArr[i];
  }
}

string generateWord(int length)
{
  string word = "";
  for (int i = 0; i < length; i++)
  {
    word += char(randomNumber(65, 90));
  }
  return word;
}

string generateKey(int length)
{
  string key = "";
  for (int i = 0; i < length; ++i)
  {
    key += generateWord(4);
    if (i != length - 1)
    {
      key += "-";
    }
  }
  return key;
}

void fillArrWithKeys(string arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    arr[i] = generateKey(4);
  }
}

int indexOf(int arr[], int size, int value)
{
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] == value)
    {
      return i;
    }
  }

  return -1;
}

void addElementToArr(int arr[], int &size, int element)
{
  arr[size] = element;
  size++;
}

void DynamicRead(int arr[], int &size)
{
  int choice;
  int num;
  cout << "Please Enter a number: ";
  cin >> num;
  addElementToArr(arr, size, num);

  cout << "Do You Want More? [0], [1]: ";
  cin >> choice;
  switch (choice)
  {
  case 0:
  {
    cout << "Array elements is: ";
    for (int i = 0; i < size; ++i)
    {
      cout << arr[i];
    }
    cout << "\n";
    cout << size << "\n";
    break;
  }
  case 1:
  {
    DynamicRead(arr, size);
    break;
  }
  }
}

bool isPalindrome(int arr[], int size)
{
  for (int i = 0; i <= size / 2; ++i)
  {
    if (arr[i] != arr[size - 1 - i])
    {
      return false;
    }
  }
  return true;
}

int countPostive(int arr[], int size)
{
  int count = 0;
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] > 0)
    {
      count++;
    }
  }
  return count;
}

int abs(int num)
{
  if (num < 0)
  {
    return (num * -1);
  }
  return num;
}

int countNegative(int arr[], int size)
{
  int count = 0;
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] < 0)
    {
      count++;
    }
  }
  return count;
}

int main()
{
  cout << isPrime(1);
  return 0;
}