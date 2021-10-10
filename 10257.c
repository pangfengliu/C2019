#include <stdio.h>
/* assume that the table has a 0 at the end */
int find(int key, int table[])
{
  for (int i = 0; table[i] != 0; i++)
    if (key == table[i])
      return i;

  return -1;
} 
double payment(int itemID[], double price[], int orderItemID[], 
	       int orderQuantity[], int onSaleItemID[])
{
  double total = 0.0;
  for (int i = 0; orderItemID[i] != 0; i++) {
    int index = find(orderItemID[i], itemID);
    if (index >= 0) {
      double p = price[index] * orderQuantity[i];
      if (find(orderItemID[i], onSaleItemID) >= 0)
	p *= 0.8;
      total += p;
    }
  }
  if (total < 490.0)
    total += 80;

  return total;
}
