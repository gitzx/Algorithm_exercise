/*
Dynamic Programming 
	1) Overlapping Subproblems
	2) Optimal Substructure

Typic topic
	(1)Longest Increasing Subsequence (LIS)
	(2)Longest Common Sbusequence (LCS)
	(3)Longest Palindromic SubSequence (LPS)
	(4)0-1 Knapsack Problem
	(5)Edit Distance
	


*/

/*======================Longest Increasing Subsequence (LIS)======================*/
/*
	find the length of the longest subsequence of a given sequence such that all elements of 
	the subsequence are sorted in increasing order. For example, length of LIS for
    { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.
*/


// Following is a tabluated implementation for the LIS problem
#include <stdio.h>
#include <stdlib.h>
int lis_dp(int arr[], int n)
{
	int *lis;
	int i, j, max=0;
	lis = (int*)malloc(sizeof(int)*n);
	for(i=0; i<n; i++){
		lis[i]=1;
	}
	for(i=1; i<n; i++){
		for(j=0; j<i; j++){
			if(arr[j] <arr[i] && lis[i] < lis[j])
				lis[i] = lis[j] + 1;
		}
	}
	for(i=0; i<n; i++)
	{
		if(max < lis[i])
			max = lis[i];
	}
	free(lis);
	return max;
}

int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("lis_dp: %d\n", lis_dp(arr, n));
	getchar();
	return 0;
}


/*======================Longest Common Subsequence (LCS)======================*/
/*Given two sequences, find the length of longest subsequence present in both of them.*/

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return (a>b)? a:b;
}

//recursive implementation
int lcs_recursive(char *x, char *y, int m, int n)
{
	if(m==0 || n==0){
		return 0;
	}
	if(x[m-1] == y[n-1]){
		return 1+lcs_recursive(x, y, m-1, n-1);
	}else{
		return max(lcs_recursive(x, y, m, n-1), lcs(x, y, m-1, n));
	}
}

//Dynamic Programming implementation
int lcs_dp(char *x, char *y, int m, int n)
{
	int L[m+1][n+1];
	int i, j;
	for(i=0; i<=m; i++){
		for(j=0; j<=n; j++){
			if(i==0 || j==0){
				L[i][j] = 0;
			}else if(x[i-1] == y[j-x]){
				L[i][j] = L[i-1][j-1] + 1;
			}else{
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	return L[m][n];
}

int main()
{
	char x[] = "ABBBCCDD";
	char y[] = "BBCCDDEE"
	int m = strlen(x);
	int n = strlen(y);
	printf("lcs_recursive: %d\n", lcs_recursive(x,y,m,n));
	printf("lcs_dp: %d\n", lcs_dp(x,y,m,n));
	getchar();
	return 0;
}


/*======================Longest Palindromic SubSequence (LPS)======================*/
/*Given a sequence, find the length of the longest palindromic subsequence in it.*/

#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	return (a>b) ? a:b;
}

//recursive implementation
int lps_recursive(char *seq, int i, int j)
{
	if(i==j){
		return 1;
	}else if(seq[i]==seq[j] && i+1 == j){
		return 2;
	}else if(seq[i] == seq[j]){
		return lps_recursive(seq, i+1, j-1) +2;
	}else{
		return max(lps_recursive);
	}
}

//Dynamic Programming implementation
int lps_dp(char *seq)
{
	int n = strlen(seq);
	int i, j, cl;
	int L[n][n];
	for(i=0; i<n; i++){
		L[i][i] = 1;
	}
	for(cl=2; cl<=n; cl++){
		for(i=0; i<n-cl+1; i++){
			j=i+cl-1;
			if(seq[i] == seq[j] && cl==2){
				L[i][j]=2;
			}else if(seq[i] == seq[j]){
				L[i][j] = L[i+1][j-1] +2;
			}else{
				L[i][j] = max(L[i][j-1], L[i+1][j]);
			}
		}
	}
	return L[0][n-1];
}

int main()
{
    char seq[] = "GEEKS FOR GEEKS";
    int n = strlen(seq);
    printf ("lps_recursive: %d\n", lps_recursive(seq, 0, n-1));
    printf ("lps_dp: %d\n", lps_dp(seq));
    getchar();
    return 0;
}

/*======================0-1 Knapsack Problem======================*/
/*Given weights and values of n items, put these items in a knapsack 
of capacity W to get the maximum total value in the knapsack. */

#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	return (a>b) ? a:b;
}

//recursive implementation
int knapSack_recursive(int W, int wt[], int val[], int n)
{
   if (n == 0 || W == 0){
       return 0;   	
   }else if (wt[n-1] > W){
       return knapSack_recursive(W, wt, val, n-1);
   }else{
   		return max( val[n-1] + knapSack_recursive(W-wt[n-1], wt, val, n-1),
                    knapSack_recursive(W, wt, val, n-1));
   	}
}

//Dynamic Programming implementation
int knapSack_dp(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0){
           		K[i][w] = 0;
           }else if(wt[i-1] <= w){
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);           	
           }else{
                K[i][w] = K[i-1][w];           	
           }
       }
   }
   return K[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("knapSack_recursive:%d\n", knapSack_recursive(W, wt, val, n));
    printf("knapSack_dp:%d\n", knapSack_dp(W, wt, val, n));
    return 0;
}

/*======================Edit Distance======================*/
/*Given two strings of size m, n and set of operations replace (R), insert (I) and delete (D) 
all at equal cost. Find minimum number of edits (operations) required to convert one string into another.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTINEL (-1)
#define EDIT_COST (1)
 
inline int min(int a, int b) {
   return (a < b)? a : b;
}

//recursive implementation
int EditDistance_recursive( char *X, char *Y, int m, int n )
{
    if( m == 0 && n == 0 )
        return 0;
    if( m == 0 )
        return n; 
    if( n == 0 )
        return m;
    int left = EditDistance_recursive(X, Y, m-1, n) + 1;
    int right = EditDistance_recursive(X, Y, m, n-1) + 1;
    int corner = EditDistance_recursive(X, Y, m-1, n-1) + (X[m-1] != Y[n-1]);
    return Minimum(left, right, corner);
}

//Dynamic Programming implementation


int main()
{
    char X[] = "SUNDAY"; 
    char Y[] = "SATURDAY"; 
    printf("Minimum edits required to convert %s into %s is %d by recursion\n",
           X, Y, EditDistanceRecursion(X, Y, strlen(X), strlen(Y)));
    getchar();
    return 0;
}