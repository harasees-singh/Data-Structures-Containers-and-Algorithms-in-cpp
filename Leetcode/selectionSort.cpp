#include<bits/stdc++.h>
using namespace std;

int find_min_element(int i, vector<int> &arr){
    int minima = i;

    for(int j = i + 1; j < arr.size(); j++){
        if(arr[j] < arr[minima]) minima = j; 
    }
    return minima;
}

void SelectionSort(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        int index = find_min_element(i, arr);
        swap(arr[i], arr[index]);
    }
    return;
}

int32_t main(){
    vector<int> input = {2, 4, 7, 9, 10, 4, 6, 11};
    SelectionSort(input);
    for(int i = 0; i < input.size(); i++) 
        cout << input[i] << ' '; 
        
    cout << endl;
    cout << "Harasees Singh, SID: 20103074" << endl;
    return 0;
    
}
// Time Complexity Analysis
// Since the find_min_element(i, arr) function compares all the n - i - 1 (n is the size of the arr) 
// elements with the ith element and SelectionSort(arr) 
// calls this function for every i from 0 to n - 1 therefore the total number of comparisons = 
// SUMMATION(n - i - 1)  where i ranges from 0 to n - 1
// this summation evaluates out to be n*(n - 1)/2 . Also for each element we swap it atmost once.
// Therefore the total number of operations = n*(n - 1)/2 + n in the worst case.
// Therefore Time complexity = O(n^2), since n^2 + n ~ n^2 in big O notation. Also since we are ignoring the linear factor (n) 
// the average and the best case (linear factor n=0 since there are no swaps for the best case) time complexities also boil down to O(n^2) 
// Best case :                  O(n^2)       
// Average case :               O(n^2)       
// Worst case :                 O(n^2)    
// Space Complexity Analysis
// Since Selection Sort is an in-place sorting algorithm 
// therefore we need only a constant amount (independent of the size of arr) of auxiliary space. Hence the space complexity boils down to 
// O(1) .
// Best case :                  O(1)
// Average case :               O(1)
// Worst case :                 O(1
// Examples :
// Best case :                  sorted array like {1, 2, 3, 4, 5, 7} etc. {no swaps required}
// Average case :               any random array with some elements in their sorted postions like {1, 3, 2, 4} etc.
// Worst case :                 reverse sorted array like {6, 4, 2, 1} etc. {n - 1 swaps required