#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str[250];
    while (fgets(str, sizeof( str ), stdin ))
    {
        str[ strcspn( str, "\n" ) ] = '\0';
        char *front = str;
        char *back = str + strlen(str) - 1;
        bool flag = 1;
        while (front < back)
        {
            if (*back != *front)
            {
                flag = 0;
                break;
            }
            front++;
            back--;
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}