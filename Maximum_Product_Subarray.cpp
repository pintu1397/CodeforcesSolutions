
// C++ program to find Maximum Product Subarray
#include <bits/stdc++.h>
using namespace std;
  
/* Returns the product of max product subarray.*/
int maxSubarrayProduct(int arr[], int n)
{
    
    int result = arr[0];
  
    for (int i = 0; i < n; i++) 
    {
        int mul = arr[i];
      
        for (int j = i + 1; j < n; j++) 
        {
           
            result = max(result, mul);
            mul *= arr[j];
        }
        
        result = max(result, mul);
    }
    return result;
}
  
// Driver code
int main()
{
    int arr[] = { 1, -12, -3, 0, 7, 11 , -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "
         << maxSubarrayProduct(arr, n);
    return 0;
}
