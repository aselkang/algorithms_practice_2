#include <iostream>
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
    int s, f, m, n, type, i, j, ans;
    fin >> s >> f;
    s--; f--;
    fin >> n >> m >> type;
    int *u = new int[m];
    int *v = new int[m];
    int *w = new int[m];
    for (int t = 0; t < m; t++)
    {
        fin >> u[t] >> v[t];
        u[t]--; v[t]--;
        w[t] = 1;
        if ((type == 2) || (type == 4))
        {
            fin >> w[t];
        }
    }

    int *d = new int[n];
    for (i = 0; i < n; i++)
    {
        d[i] = SHRT_MAX;
    }
    d[s] = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (d[u[j]] < SHRT_MAX)
            {
                if (d[v[j]] > d[u[j]] + w[j])
                {
                    d[v[j]] = d[u[j]] + w[j];
                }
            }
        }
    }

    if (d[f] < SHRT_MAX)
    {
        ans = d[f];
    }
    else
    {
        ans = 0;
    }

    for (i = 0; i < m; i++)
    {
        if (d[u[i]] < SHRT_MAX)
        {
            if (d[u[i]] + w[i] < d[v[i]])
            {
                ans = -1;
            }
        }
    }
    fout << ans;
    return 0;
}
