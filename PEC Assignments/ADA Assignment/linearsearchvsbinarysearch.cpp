#include<bits/stdc++.h>
#include<random>
using namespace std;

int binarysearch(int *arr, int target, int st, int ed)

{
    int mid = (st+ed)/2;

    if(st>ed)
    {
        return -1;
    }
    if(arr[mid]==target)
    {
        return mid;
    }
    else if(arr[mid]>target)
    {
        return binarysearch(arr, target, st, mid-1);
    }
    else if(arr[mid]<target)
    {
        return binarysearch(arr, target, mid+1, ed);
    }
    return -1;
}

int linear_search(int *arr, int size, int target)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}




int main()
{
    int list[4] = {40, 400, 4000, 40000};
    int k = 0;
    while (k < 4)
    {
        int n = list[k];
        cout << "Size of array: " << n << endl;
        random_device rd;
        mt19937 gen(100);
        uniform_int_distribution<> distr(1, 2 * n);

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[n] = distr(gen);
        }

        // sort(arr, arr+n);

        clock_t begin = clock();
        int ans = linear_search(arr, n,n*1.5);

        clock_t end = clock();

        cout<<"Element to be found: "<<n*1.5<<endl;


        cout << "Executed in: " << double(end - begin) / CLOCKS_PER_SEC * 1000  << "ms" << endl;

        if(ans==-1)
            cout<<"Element is not present in array"<<endl;
        else
            cout<<"Element is present in array at index: "<<ans<<endl;

        cout << endl;
        k++;
    }

return 0;
}