#include <iostream>
#include <fstream>

using namespace std;

bool *seen;
int **a;
int n;

void dfs(int v)
{
    seen[v] = true;
    for (int i = 0; i < n; i++)
    {
        if (a[v][i] && !seen[i])
        {
            dfs(i);
        }
    }
}

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
    int s, f, m, type, i, j, k;
    fin >> s >> f;
    s--; f--;
    fin >> n >> m >> type;
    a = new int*[n];
    seen = new bool[n];
    for (i = 0; i < n; i++)
    {
        a[i] = new int[n];
        seen[i] = false;
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
    seen[s] = true;
    dfs(s);
    if (seen[f])
    {
        fout << 1;
    }
    else
    {
        fout << 0;
    }
    return 0;
}
