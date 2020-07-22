#include "stdafx.h"
#include "Merge.h"

void Merge::Partition(vector<MYRECT>& a, int l, int r)
{
    if (l >= r) return;
    int m = (l + r) / 2;
    Partition(a, l, m);
    Partition(a, m + 1, r);

    MergeSort(a, l, r, m);

}

void Merge::MergeSort(vector<MYRECT>& a, int l, int r, int m)
{
    vector<MYRECT> copy(r + 1);
    int copyIndex = 0;
    int i = l, j = m + 1;
    while (i <= m && j <= r)
    {
        if (a[i].bottom < a[j].bottom) copy[copyIndex++] = a[i++];
        else copy[copyIndex++] = a[j++];
    }

    while (i <= m) copy[copyIndex++] = a[i++];
    while (j <= r) copy[copyIndex++] = a[j++];

    for (int k = l, copyIndex = 0; k <= r; k++, copyIndex++)
        a[k] = copy[copyIndex];

}