#include "bits/stdc++.h"
using namespace std;
class AllOne
{
    unordered_map<string, int> dict; // in pair its level,index
    unordered_map<int, unordered_set<string>> level;
    int currentMin = 0;
    int currentMax = 0;

public:
    AllOne()
    {
    }

    void inc(string key)
    {
        int tmp = dict[key]; // old level
        level[tmp].erase(key);

        dict[key]++;
        if (dict[key] > currentMax && dict[key] != 0)
        {
            currentMax = dict[key];
        }
        if (dict[key] < currentMin && dict[key] != 0)
        {
            currentMin = dict[key];
        }
        if (dict[key] != 0)
        {
            level[dict[key]].insert(key);
        }

        while (level[currentMin].empty() && currentMin < currentMax)
        {
            currentMin++;
        }
        while (level[currentMax].empty() && currentMin < currentMax)
        {
            currentMax--;
        }
    }

    void dec(string key)
    {

        int tmp = dict[key]; // old level
        level[tmp].erase(key);

        dict[key]--;

        if (dict[key] > currentMax && dict[key] != 0)
        {
            currentMax = dict[key];
        }
        if (dict[key] < currentMin && dict[key] != 0)
        {
            currentMin = dict[key];
        }
        if (dict[key] != 0)
        {
            level[dict[key]].insert(key);
        }

        while (level[currentMax].empty() && currentMin < currentMax)
        {
            currentMax--;
        }
        while (level[currentMin].empty() && currentMin < currentMax)
        {
            currentMin++;
        }
    }

    string getMaxKey()
    {
        cout << currentMin << " " << currentMax << endl;

        if (level[currentMax].empty())
        {
            return "";
        }
        else
        {
            return *level[currentMax].begin();
        }
    }

    string getMinKey()
    {
        cout << currentMin << " " << currentMax << endl;

        if (level[currentMin].empty())
        {
            return "";
        }
        else
        {
            return *level[currentMin].begin();
        }
    }
};
