#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
  tree_actions tree;

  tree.AddNewElem(3);
  tree.AddNewElem(1);
  tree.AddNewElem(5);
  tree.AddNewElem(10);

  if (tree.FindElem(2) != NULL)
    cout << "elem 2 is exist" << endl;
  else
    cout << "elem 2 is not exist" << endl;
  int sum = tree.ScoreElemsSum();
  cout << "sum is " << sum << endl;
}
