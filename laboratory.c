#include <stdio.h>
#include "intqueue.h"

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  IntQueue q;
  Initialize(&q, n * m);

  int dx[] = {0, 0, -1, 1};
  int dy[] = {-1, 1, 0, 0};
  int count = 0;
  int best[3] = {0, 0, 0};

  int map[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%d", &map[i][j]);
    }
  }
  for (int i = 0; i < m * n; i++)
  {
    for (int j = i + 1; j < m * n; j++)
    {
      for (int k = j + 1; k < m * n; k++)
      {
        int map_tmp[n][m];
        for (int a = 0; a < n; a++)
        {
          for (int b = 0; b < m; b++)
          {
            map_tmp[a][b] = map[a][b];
            if (map_tmp[a][b] == 2)
            {
              Push(&q, a);
              Push(&q, b);
            }
          }
        }
        if (
            map_tmp[i / m][i % m] == 0 &&
            map_tmp[j / m][j % m] == 0 &&
            map_tmp[k / m][k % m] == 0)
        {
          map_tmp[i / m][i % m] = 1;
          map_tmp[j / m][j % m] = 1;
          map_tmp[k / m][k % m] = 1;
        }
        else
        {
          Clear(&q);
          continue;
        }
        int x, y;
        Pop(&q, &y);
        Pop(&q, &x);
        while (1)
        {
          for (int a = 0; a < 4; a++)
          {
            if (
                y + dy[a] > -1 &&
                y + dy[a] < n &&
                x + dx[a] > -1 &&
                x + dx[a] < m &&
                map_tmp[y + dy[a]][x + dx[a]] == 0)
            {
              map_tmp[y + dy[a]][x + dx[a]] = 2;
              Push(&q, y + dy[a]);
              Push(&q, x + dx[a]);
            }
          }
          if (Pop(&q, &y) == -1 || Pop(&q, &x) == -1)
          {
            break;
          }
        }
        int count_tmp = 0;
        for (int a = 0; a < n * m; a++)
        {
          if (map_tmp[a / m][a % m] == 0)
          {
            count_tmp++;
          }
        }
        if (count_tmp > count)
        {
          count = count_tmp;
          best[0] = i;
          best[1] = j;
          best[2] = k;
        }
      }
    }
  }

  printf("%d", count);

  Terminate(&q);
  return 0;
}