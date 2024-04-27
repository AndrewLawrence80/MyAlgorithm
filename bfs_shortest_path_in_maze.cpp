/*
大小为NxM的迷宫由通道和墙壁组成，每一步可走上下左右，求起点到终点的最小步数，假设一定可以从起点走到终点
N,M<=100
样例
N=10,M=10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/

#include <stdio.h>
#include <string.h>
#include <deque>
#include <limits.h>

using namespace std;

#define SIZE 100

char maze[SIZE][SIZE] = {0};
int dist[SIZE][SIZE];

int N = 0, M = 0;

typedef struct
{
    int x, y;
} Coordinate;

Coordinate start, dest;
Coordinate mv[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool operator==(const Coordinate &a, const Coordinate &b)
{
    return a.x == b.x && a.y == b.y;
}
Coordinate operator+(const Coordinate &a, const Coordinate &b)
{
    Coordinate c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

void init_distance()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            dist[i][j] = INT_MAX;
        }
    }
}

void read_input()
{
    scanf("N=%d,M=%d\n", &N, &M);
    for (int i = 0; i < N; ++i)
    {
        fgets(maze[i], SIZE, stdin);
        char *p = strchr(maze[i], '\n');
        if (p != NULL)
        {
            *p = 0;
        }
        p = strchr(maze[i], 'S');
        if (p != NULL)
        {
            start.x = i;
            start.y = p - maze[i];
            dist[start.x][start.y] = 0;
        }
        p = strchr(maze[i], 'G');
        if (p != NULL)
        {
            dest.x = i;
            dest.y = p - maze[i];
        }
    }
}

void bfs()
{
    deque<Coordinate> q;
    q.push_back(start);
    while (!q.empty())
    {
        Coordinate current_c = q.front();
        q.pop_front();
        for (int i = 0; i < 4; ++i)
        {
            Coordinate next_c = current_c + mv[i];
            if (next_c.x >= 0 && next_c.x < M && next_c.y >= 0 && next_c.y < N && maze[next_c.x][next_c.y] != '#' && dist[next_c.x][next_c.y] == INT_MAX)
            {
                dist[next_c.x][next_c.y] = dist[current_c.x][current_c.y] + 1;
                q.push_back(next_c);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    init_distance();
    read_input();
    bfs();
    printf("%d\n", dist[dest.x][dest.y]);
    return 0;
}
