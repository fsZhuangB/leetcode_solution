#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& V1, int m, vector<int>& V2, int n)
{
    // p1 pointer to tmp, p2 pointer to V2
    // i pointer to V1
    int p1, p2, i;
    p1 = p2 = i = 0;
    vector<int> tmp(V1.begin(), V1.begin() + m);

    while (p1 < m && p2 < n)
    {
        V1[i++] = (tmp[p1] < V2[p2]) ? tmp[p1++] : V2[p2++];
    }
    while (p1 < m)
        V1[i++] = tmp[p1++];
    while (p2 < n)
        V1[i++] = V2[p2++];
}
int main()
{
    vector<int> v1{4, 5, 6, 0, 0, 0, 0};
    vector<int> v2{2, 3, 4, 7};
    merge(v1, 3, v2, 4);
    for (auto i : v1)
        cout << i;
}