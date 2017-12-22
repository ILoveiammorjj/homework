#include "tree.h"
#include <iostream>
#include <assert.h>

tree_t *RecFindElem(int key, tree_t *root)
{
  if (root == NULL || (root != NULL && root->key == key))
    return root;
  if (key < root->key)
    RecFindElem(key, root->left);
  else
    RecFindElem(key, root->right);
}

void DeleteTree(tree_t **root)
{
  if (*root != NULL)
  {
    DeleteTree(&((*root)->left));
    DeleteTree(&((*root)->right));
    delete *root;
  }
}

tree_actions::~tree_actions()
{
  DeleteTree(&(tree_actions::tree));
}

tree_t *tree_actions::FindElem(int key)
{
  return RecFindElem(key, tree_actions::tree);
}

tree_t* RecAddElem(tree_t* root, int key)
{
  if (root == NULL)
  {
    tree_t *new_root = new tree_t;
    new_root->left = NULL;
    new_root->right = NULL;
    new_root->key = key;
    return new_root;
  }

  if (key < root->key)
  {
    root->left = RecAddElem(root->left, key);
  }
  else
  {
    root->right = RecAddElem(root->right, key);
  }
  return root;
}

void tree_actions::AddNewElem(int key)
{
  tree_t *new_root;
  assert(key >= 0);
  
  //если такой ключ уже есть в множестве не добавляем его 
  if (tree_actions::FindElem(key) != NULL)
    return;

  //add new elem
  tree_actions::tree = RecAddElem(tree_actions::tree, key);
}

void RecScoreElemsSum(tree_t *tree, int *sum)
{
  if (tree != NULL)
  {
    (*sum) += tree->key;
    RecScoreElemsSum(tree->left, sum);
    RecScoreElemsSum(tree->right, sum);
  }
}

int tree_actions::ScoreElemsSum()
{
  int sum = 0;
  RecScoreElemsSum(tree_actions::tree, &sum);
  return sum;
}
