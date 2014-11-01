#include <stdio.h>

//A recursive solution
bool isSubsetSum_Recursive(int set[], int n, int sum){
	if(sum==0){
		return true;
	}
	if(n==0 && sum!=0){
		return false;
	}
	if(set[n-1] > sum){
		return isSubsetSum(set, n-1, sum);
	}
	return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

//Dynamic programming
bool isSubsetSum_DP(int set[], int n, int sum){
	bool subset[sum+1][n+1];
	for(int i=0;i<=n;i++){
		subset[0][i]=true;
	}
	for(int i=0;i<=sum;i++){
		subset[i][0]=false;
	}
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=n;j++){
			subset[i][j] = subset[i][j-1];
			if(set[j-1]<=i){
				return subset[i][j] || subset[i-set[j-1]][j-1];
			}
		}
	}
	return subset[sum][n];
}

int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum_Recursive(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
 if (isSubsetSum_DP(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}