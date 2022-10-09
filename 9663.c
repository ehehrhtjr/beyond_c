#include <stdio.h>

int N, visited[14][14], count = 0;

void DFS(int depth)
{
  if (depth == N)
  {
    count += 1;
  }
  else
  {
    for (int i = 0; i < N; i++)
    {
      if (visited[depth][i] == 0)
      {
        visited[depth][i] += 1;
        for (int j = 0; j < N; j++)
        {
          if (j != i)
            visited[depth][j] += 1;
          if (j != depth)
            visited[j][i] += 1;
          if (j > 0)
          {
            if (depth + j < N)
            {
              if (i + j < N)
                visited[depth + j][i + j] += 1;
              if (i - j >= 0)
                visited[depth + j][i - j] += 1;
            }
            if (depth - j >= 0)
            {
              if (i + j < N)
                visited[depth - j][i + j] += 1;
              if (i - j >= 0)
                visited[depth - j][i - j] += 1;
            }
          }
        }
        DFS(depth + 1);
        visited[depth][i] -= 1;
        for (int j = 0; j < N; j++)
        {
          if (j != i)
            visited[depth][j] -= 1;
          if (j != depth)
            visited[j][i] -= 1;
          if (j > 0)
          {
            if (depth + j < N)
            {
              if (i + j < N)
                visited[depth + j][i + j] -= 1;
              if (i - j >= 0)
                visited[depth + j][i - j] -= 1;
            }
            if (depth - j >= 0)
            {
              if (i + j < N)
                visited[depth - j][i + j] -= 1;
              if (i - j >= 0)
                visited[depth - j][i - j] -= 1;
            }
          }
        }
      }
    }
  }
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      visited[i][j] = 0;
    }
  }
  DFS(0);
  printf("%d\n", count);

  return 0;
}
