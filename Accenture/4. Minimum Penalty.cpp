/*
You are given a set of numbers and you can arrange them in any order but this
penalty equal to the sum of the absolute differences between contiguous numbers
You are needed to return the minimum penalty that should be paid
Input Format
Input 1: Size of the array of integer numbers (2<input< 10001)
Input 2: Integer Array (1<=input<=10000 )
Example 1:
Input 1: 3
3=13-1+1
Input 2: {1,3,2}
2
|2-1|+ |3-2|
Output: 2

1,3,2  -- > |3-1|+|2-3|= 3
1,2,3 --> |2-1|+|3-2| = 2 (sorted in increased order)
2,3,1 --> |3-2|+|1-3|=3
2,1,3 --> |1-2|+|3-1| =3
3,1,2 --> |1-3|+|2-1| =3
3,2,1 --> |2-3|+|1-2| =2 (sorted in reverse order)

*/

int soln(int arr[], int n){
  int sum=0;
  sort(arr, arr+n) ;
  for (int i=1;i<n;i++){
    sum+=abs(arr[i]-arr[i+1]);
  }
  return sum;
}
