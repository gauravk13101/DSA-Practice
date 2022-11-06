#include <bits/stdc++.h>
using namespace std;

vector<int> sort(vector<int> &a)
{
    int j = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
            a[j] = a[i], j++;
    }

    while (j < a.size())
        a[j++] = 1;

    return a;
}

int main()
{
    vector<int> arr = {0, 1, 0, 1, 0, 1};
    sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}