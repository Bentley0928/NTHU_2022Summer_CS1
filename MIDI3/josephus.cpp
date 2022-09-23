#include <bits/stdc++.h>
using namespace std;
list<string> l;
list<string>::iterator it;
/*int josephusCircle(int n, int k)
{
    while (l.size() > 1)
    {

        for (int i = 1; i < k; i++)
        {
            it++;

            if (it == l.end())
            {
                // if iterator reaches the end,then we change it to begin of the list//
                it = l.begin();
            }
        }

        it = l.erase(it);

        if (it == l.end())
        {
            // if iterator reaches the end,then we change it to begin of the list//
            it = l.begin();
        }
    }

    return l.front(); // returns front element of the list//
}*/

void next(int t)
{
    for (int i = 0; i < t - 1; i++)
    {
        it++;
        if (it == l.end())
        {
            // if iterator reaches the end,then we change it to begin of the list//
            it = l.begin();
        }
    }
    cout << "remove " << *it << endl;
    it = l.erase(it);
    if (it == l.end())
    {
        // if iterator reaches the end,then we change it to begin of the list//
        it = l.begin();
    }
}
void prev(int t)
{
    for (int i = 0; i < t - 1; i++)
    {
        if (it == l.begin())
        {
            // if iterator reaches the end,then we change it to begin of the list//
            it = l.end();
            it--;
        }
        else
            it--;
    }
    cout << "remove " << *it << endl;
    it = l.erase(it);
    if (it == l.begin())
    {
        // if iterator reaches the end,then we change it to begin of the list//
        it = l.end();
        it--;
    }
    it--;
}
/* Driver program to test above functions */
int main()
{
    int n, m;
    cin >> n >> m;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        l.push_back(tmp);
    }
    it = l.begin();
    while (m--)
    {
        string inp;
        cin >> inp;
        if (inp == "print")
        {
            int len = l.size();
            if(l.empty()){
                cout << "None" << endl;
            }
            else if (len == 1)
            {
                cout << l.front() << endl;
            }
            else
            {
                auto ittmp = it;
                cout << len << endl;
                for (int i = 0; i < len; i++)
                {
                    cout << *it << endl;
                    it++;
                    if (it == l.end())
                    {
                        // if iterator reaches the end,then we change it to begin of the list//
                        it = l.begin();
                    }
                }
                it = ittmp;
            }
        }
        else if (inp == "next")
        {
            if (l.size() == 1)
            {
                cout << "remove " << l.front() << endl;
                l.clear();
            }
            else
            {
                int t;
                cin >> t;
                next(t);
            }
        }
        else
        {
            if (l.size() == 1)
            {
                cout << "remove " << l.front() << endl;
                l.clear();
            }
            else
            {
                int t;
                cin >> t;
                prev(t);
            }
        }
    }
    return 0;
}