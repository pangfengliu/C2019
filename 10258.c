#include <stdio.h>

int distance(int dist[], int from, int to)
{
  int max = (from > to)? from : to;
  int min = (from < to)? from : to;
  int d = 0;
  for (int i = min - 1; i < max - 1; i++)
    d += dist[i];

  return d;
}

#define R 0
#define G 1
#define B 2

int stationDistance(int R_distance[], int G_distance[], int B_distance[],
		    int R_connect, int B_connect,
		    int startStation[], int endStation[])
{
  int startLine = startStation[0];
  int startIndex = startStation[1];
  int endLine = endStation[0];
  int endIndex = endStation[1];

  int GTotalDistance = 0;
  int GnumStation = 1;
  
  for (int i = 0; G_distance[i] != 0; i++, GnumStation++)
    GTotalDistance += G_distance[i];

  if (startLine == endLine) {
    switch (startLine) {
    case R:
      return distance(R_distance, startIndex, endIndex);
    case G:
      return distance(G_distance, startIndex, endIndex);
    case B:
      return distance(B_distance, startIndex, endIndex);
    }
  }
  switch (startLine) {
  case G:
    switch (endLine) {
    case R:
      return distance(G_distance, startIndex, 1) + 
	distance(R_distance, R_connect, endIndex); 
    case B:
      return distance(G_distance, startIndex, GnumStation) + 
	distance(B_distance, B_connect, endIndex); 
    }
  case R:
    switch (endLine) {
    case G:			/* R -> G */
      return distance(R_distance, R_connect, startIndex) +
	distance(G_distance, endIndex, 1);
    case B:			/* R -> G -> B */
      return distance(R_distance, startIndex, R_connect) + 
	GTotalDistance + 
	distance(B_distance, B_connect, endIndex); 
    }
  
  case B:
    switch (endLine) {
    case G:			/* B -> G */
      return distance(B_distance, B_connect, startIndex) +
	distance(G_distance, endIndex, GnumStation);
    case R:			/* B -> G -> R */
      return distance(B_distance, startIndex, B_connect) + 
	GTotalDistance + 
	distance(R_distance, R_connect, endIndex); 
    }
  }
      
  return 0;
}
