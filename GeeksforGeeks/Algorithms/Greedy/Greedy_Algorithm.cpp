/*
Greedy Programming 
	1) 
	2) 

Typic topic
	(1)Activity Selection Problem
	(2)Kruskal’s Minimum Spanning Tree (MST)
	(3)Prim’s Minimum Spanning Tree
	(4)Dijkstra’s Shortest Path
	(5)Huffman Coding


*/

/*======================Activity Selection Problem======================*/
/*You are given n activities with their start and finish times. Select the 
maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time.*/

#include <stdio.H>

void printMaxActivities(int s[], int f[], int n)
{
	int i, j;
	i=0;
	printf("%d ", i);
	for(j=1; j<n; j++)
	{
		if(s[j]>=f[i]){
			printf("%d ", j);
			i=j;
		}
	}
}

int main()
{
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    getchar();
    return 0;
}