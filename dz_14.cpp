#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

void Init(int** weight, int** cost, int** res, int size)
{
  int  i = 0;

  *weight = new int[size];
  *cost = new int[size];
  *res = new int[size];
  for (i = 0; i < size; i++)
    (*res)[i] = 0;
}

void FileRead(int* size, int* W, int* C, int** weight, int** cost, int** res)
{
  int i = 0;

  cin >> *size;
  cin >> *W;
  cin >> *C;

  //fscanf(f, "%i %i %i", size, W, C);
  Init(weight, cost, res, (*size));
  for (i = 0; i < (*size); i++)
    cin >> (*weight)[i];
  for (i = 0; i < (*size); i++)
    cin >> (*cost)[i];
}

int FindSolution(int number, int* weight, int* cost, int** res, int W, int C, int size, int loseCost, int sumCost, int curSum, int* sumW)
{
  int i = 0, result = 0;

  if (curSum >= C)
    return 1;
  else if (number > size)
    return 0;
  else
  {
    loseCost += cost[number - 1];
    if (sumCost - loseCost >= C)
    {
      result = FindSolution(number + 1, weight, cost, res, W, C, size, loseCost, sumCost, curSum, sumW);
      if (result == 1)
        return result;
    }
    loseCost -= cost[number - 1];
    (*sumW) += weight[number - 1];
    (*res)[number - 1] = 1;
    curSum += cost[number - 1];
    if ((*sumW) <= W)
    {
      result = FindSolution(number + 1, weight, cost, res, W, C, size, loseCost, sumCost, curSum, sumW);
      if (result == 1)
        return result;
    }
    (*sumW) -= weight[number - 1];
    (*res)[number - 1] = 0;
    loseCost += cost[number - 1];
    return result;
  }

  if (curSum < C && number == size)
  {
    for (i = 0; i < size; i++)
      (*res)[i] = 0;
    return 0;
  }
}


int main(void)
{
  int* weight, *cost, *res, size = 0, W = 0, C = 0, i = 0, result = 0, sum = 0, loseCost = 0, sumW = 0;
  
  FileRead(&size, &W, &C, &weight, &cost, &res);

  for (i = 0; i < size; i++)
    sum += cost[i];

  result = FindSolution(1, weight, cost, &res, W, C, size, loseCost, sum, 0, &sumW);
  if (result)
  {
    for (i = 0; i < size; i++)
    {
      if (res[i])
        cout << "1 ";
      else
        cout << "0 ";
    }
  }
}
