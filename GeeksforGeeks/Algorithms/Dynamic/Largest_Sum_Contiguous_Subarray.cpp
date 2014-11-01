/*
Kadane’s Algorithm:

Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far
*/

#include <stdio.h>
int max(int a, int b){
	return (a>b)?a:b;
}

//Kadane’s Algorithm:
int maxSubArraySum_Kadane(int a[], int n){
	int max_so_far = 0; max_ending_here = 0;
	for(int i=0; i<n; i++){
		max_ending_here = max_ending_here + a[i];
		if(max_ending_here < 0){
			max_ending_here = 0;
		}else if{max_so_far < max_ending_here}{
			max_so_far = max_ending_here;
		}
	}
	return max_so_far;
}

//Dynamic_Programming

int maxSubArraySum_DP(int a[], int n){
	int max_so_far = a[0];
	int cur_max = a[0];
	for(int i=1; i<n; i++){
		cur_max = max(a[i], cur_max+a[i]);
		max_so_far = max(max_so_far, cur_max);
	}
	return max_so_far;
}

int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum_Kadane(a, n);
   printf("Maximum contiguous sum is %d\n", max_sum);
   int max_sum_dp = maxSubArraySum_DP(a, n);
   printf("Maximum contiguous sum by DP is %d\n", max_sum_dp);
   return 0;
}