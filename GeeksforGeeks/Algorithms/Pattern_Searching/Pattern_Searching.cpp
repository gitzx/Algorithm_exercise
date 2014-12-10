/*
Pattern Searching 
	1) 
	2) 

Typic topic
	(1)Native Pattern Searching
	(2)KMP (Knuth Morris Pratt) Pattern Searching
	(3)
	(4)
	(5)


*/

/*======================(1)Native Pattern Searching======================*/

#include <stdio.h>
#include <string.h>

void search(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	for(int i=0; i<=N-M; i++){
		int j;
		for(j=0; j<M; j++){
			if(txt[i+j]!=pat[j]){
				break;
			}
		}
		if(j==M){
			printf("Pattern found at index %d \n", i);
		}
	}
}

int main()
{
   char *txt = "AABAACAADAABAAABAA";
   char *pat = "AABA";
   search(pat, txt);
   getchar();
   return 0;
}



/*======================(2)KMP Pattern Searching======================*/
/*KMP algorithm does some preprocessing over the pattern pat[] and constructs an
auxiliary array lps[] of size m (same as size of pattern). Here name lps indicates 
longest proper prefix which is also suffix.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0; 
    int i;
    lps[0] = 0; 
    i = 1;
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else 
       {
         if (len != 0)
         {
           len = lps[len-1];
         }
         else 
         {
           lps[i] = 0;
           i++;
         }
       }
    }

void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  
    computeLPSArray(pat, M, lps);
    int i = 0;  
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }
      else if (i < N && pat[j] != txt[i])
      {
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); 
}

int main()
{
   char *txt = "ABABDABACDABABCABAB";
   char *pat = "ABABCABAB";
   KMPSearch(pat, txt);
   return 0;
}