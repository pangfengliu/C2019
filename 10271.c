#include <stdio.h>
#include "BuildTree.h"

typedef struct list {
  Node *ptr;
  int length;
} List;

int listLength(Node *node)
{
  int length = 0;
  while (node != NULL) {
    node = node->left;
    length++;
  }
  return length;
}

int secondLength(int n)
{
  return n / 2;
}

int firstLength(int n)
{
  return n - secondLength(n);
}

Node *skip(Node *head, int n)
{
  Node *ptr = head;
  for (int i = 0; i < n - 1; i++)
    ptr = ptr->left;

  Node *second = ptr->left;
  ptr->left = NULL;
  return second;
}

void cut(List list, List *first, List *second)
{
  List none = {NULL, 0};
  if (list.ptr == NULL) {
    *first = *second = none;
    return;
  } 

  first->ptr = list.ptr;
  first->length = firstLength(list.length); 
  second->ptr = skip(first->ptr, first->length);
  second->length = secondLength(list.length); 
}

Node *BuildListTree(List list1, List list2)
{
  if (list1.ptr == NULL)
    return list2.ptr;
  if (list2.ptr == NULL)
    return list1.ptr;

  Node *root;
  if (list1.ptr->val < list2.ptr->val) {
    root = list1.ptr;
    list1.ptr = list1.ptr->left;
    list1.length--;
  } else {
    root = list2.ptr;
    list2.ptr = list2.ptr->left;
    list2.length--;
  }

  List list1first, list1second;
  List list2first, list2second;
  cut(list1, &list1first, &list1second);
  cut(list2, &list2first, &list2second);
  root->left = BuildListTree(list1first, list2first);
  root->right = BuildListTree(list1second, list2second);
  return root;
}


Node* BuildTree(Node* lst1, Node* lst2)
{
  List list1 = {lst1, listLength(lst1)}; 
  List list2 = {lst2, listLength(lst2)};
  return BuildListTree(list1, list2);
}
