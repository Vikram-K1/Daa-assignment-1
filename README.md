# Daa-assignment-1
Implementing the solution for Maximum Sum Subarray Problem

In this assignment, we were given an array of non-zero integers, containing only positive and negative integers and we needed to find out a subarray of elements whose sum would be greatest. The approach here was based on Divide and Conquer. Following is the Divide and Conquer algorithm:

        1.Divide the given array in two halves.
        2.Return the maximum of following three
              a)Maximum subarray sum in left half (Make a recursive call. 
              b)Maximum subarray sum in right half (Make a recursive call)
              c)Maximum subarray sum such that the subarray crosses the midpoint

The above algorithm is implemented in C++ language.

The following array is taken as example:

                  12	54	-2	6	-54	6	-33	30	-8	5	21	-34	76	9


Solution:

![image](https://user-images.githubusercontent.com/113958925/191564411-6a9daf2a-2da8-48fc-85b3-b970fb8da5be.png)


The time complexity of the above divide-and-conquer solution is O(n.log(n)) as for the given array of size n, we make two recursive calls on input size n/2 and finding the maximum subarray crosses midpoint takes O(n) time in the worst case. Therefore, recurrence relation becomes T(n) = 2T(n/2) + O(n) = O(n.log(n)).

Observations:
If first and last elements are turned negative, they are excluded in subarray as they reduces the Max sum.

For Eg, in the following array where first and last elements are made negative:
  
                   -12	54	-2	6	-54	6	-33	30	-8	5	21	-34	76	-9
        
  The output is:
                   
![image](https://user-images.githubusercontent.com/113958925/191565612-5a694a0d-d83b-4fc2-bbd2-81798d5096ff.png)


We can observe that last element is excluded from the sum.

We can also observe that these extreme negative elements will never be included in subarray as long as there is one positive element present in whole array, as they will always bring down the total max sum.
Positive extreme elements are included if they have significant magnitude so that it may contribute to maximum sum.

In the first example, we can see the first element wasn't included because of its neighbour negative elements.

![image](https://user-images.githubusercontent.com/113958925/191564411-6a9daf2a-2da8-48fc-85b3-b970fb8da5be.png)
