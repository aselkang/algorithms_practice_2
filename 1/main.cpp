#include <iostream>
#include <queue>
#include <climits>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    ifstream fin;
    ofstream fout;

    if (argc == 1)
    {
        fin.open("input.txt");
        fout.open("output.txt");
    }
    else if (argc == 2)
    {
        fin.open(argv[1]);
        fout.open("output.txt");
    }
    else
    {
        fin.open(argv[1]);
        fout.open(argv[2]);
    }
    int n, m, type, i, j, k, s, f;
    fin >> s >> f;
    s--; f--;
    fin >> n >> m >> type;
    int **a = new int*[n];
    bool *seen = new bool[n];
    int *d = new int[n];
    for (i = 0; i < n; i++)
    {
        a[i] = new int[n];
        seen[i] = false;
        d[i] = SHRT_MAX;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
    for (int t = 0; t < m; t++)
    {
        fin >> i >> j;
        k = 1;
        if ((type == 2) || (type == 4))
        {
            fin >> k;
        }
        a[i - 1][j - 1] = k;
        if ((type == 3) || (type == 4))
        {
            a[j - 1][i - 1] = k;
        }
    }
    queue <int> q;
    q.push(s);
    seen[s] = true;
    d[s] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        seen[p] = true;
        if (p == f)
        {

            break;
        }
        for (i = 0; i < n; i++)
        {
            if (a[p][i] && !seen[i])
            {
                if (d[i] > d[p] + a[p][i])
                {
                    d[i] = d[p] + a[p][i];
                }
                q.push(i);
            }
        }
    }
    fout << d[f];
    return 0;
}
