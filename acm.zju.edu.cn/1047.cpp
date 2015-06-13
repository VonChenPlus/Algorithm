#include <cstdio>
#include <queue>
using namespace std;

char table[20][21];
int rows, cols, x, y, len;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
struct Pos
{
int x, y;
};
void Perimeters(int x, int y)
{ 
queue<Pos> q;
Pos pos1, pos2;
pos1.x = x;
pos1.y = y;
q.push(pos1);
int i;
len = 0;
table[x][y] = '?';
while(!q.empty())
{
    pos2 = q.front(); q.pop();
    if(pos2.x + 1 >= rows || table[pos2.x + 1][pos2.y] == '.')
     len++;
    if(pos2.x - 1 < 0 || table[pos2.x - 1][pos2.y] == '.')
     len++;
    if(pos2.y - 1 < 0 || table[pos2.x][pos2.y - 1] == '.')
     len++;
    if(pos2.y + 1 >= cols || table[pos2.x][pos2.y + 1] == '.')
     len++;
    for(i = 0; i < 8; i++)
    {
     pos1.x = pos2.x + dx[i];
     pos1.y = pos2.y + dy[i];
     if(pos1.x >= 0 && pos1.x < rows && pos1.y >= 0 
      && pos1.y < cols && table[pos1.x][pos1.y] == 'X')
     {
      table[pos1.x][pos1.y] = '?';
      q.push(pos1);
     }
    }
}
}
int main()
{
int i;
while(scanf("%d%d%d%d", &rows, &cols, &x, &y) != EOF)
{
    if(rows == 0)
     break;
    for(i = 0; i < rows; i++)
     scanf("%s", table[i]);
    Perimeters(x - 1, y - 1);
    printf("%d\n", len);
}
return 0;
}
