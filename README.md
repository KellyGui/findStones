# findStones

## Question A
  (1) write a function F to find out the fisrt pair of numbers in the given array with a difference of D, i.e $\|nums[i]-nums[j]|==D\$.   
  (2) Input:  an array with size N and the difference D. nums[i] is the weight of stone i. The elements could be integers or floating point numbers.  
  (3) Output: the indexes(i,j) of the fisrt pair of numbers with a difference to  D, so that  $0 <= i < j < N$ and $\|array[i]-array[j]| == D\$.  
                         
             

## Question B 
Please check the code, the function name is find_onepair.
For int type , using hash map solves the problem.  
Time: $O(n)$  
Space: $O(n)$  
For floating point numbers, due to the precision, I use tow pointer to find the wanted piar.  
Time: $O(nlogn)$  
Space: $O(n)$  
## Question C
Please check the code, the function name is find_pairs.
