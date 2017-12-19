#pragma once
#include <cstdlib>

typedef struct tree_t
{
  int key;
  struct tree_t *left;
  struct tree_t *right;
}tree_t;

class tree_actions
{
private:
  tree_t *tree;
public:
  tree_t* FindElem(int key);
  void AddNewElem(int key);
  int tree_actions::ScoreElemsSum();
  tree_actions()
  {
    tree = NULL;
  }
  ~tree_actions();
};
