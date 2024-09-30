#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

char map[35][35][35];
int vis[35][35][35];
int k, n, m, startX, startY, startZ, endX, endY, endZ;
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
struct Node {
    int x, y, z, step;
};

int check(int x, int y, int z) {
    if (vis[x][y][z] || x < 0 || y < 0 || z < 0 || x >= k || y >= n || z >= m || map[x][y][z] == '#') {
        return 1;
    }
    return 0;
}

int bfs() {
    Node start, next;
    queue<Node> Q;
    start.x = startX;
    start.y = startY;
    start.z = startZ;
    start.step = 0;
    vis[startX][startY][startZ] = 1;
    Q.push(start);
    while (!Q.empty()) {
        start = Q.front();
        Q.pop();
        if (start.x == endX && start.y == endY && start.z == endZ) {
            return start.step;
        }
        for (int i = 0; i < 6; ++i) {
            next = start;
            next.x = start.x + dx[i];
            next.y = start.y + dy[i];
            next.z = start.z + dz[i];
            if (check(next.x, next.y, next.z)) {
                continue;
            }
            vis[next.x][next.y][next.z] = 1;
            next.step = start.step + 1;
            Q.push(next);
        }
    }
    return 0;
}

int main() {
    while (scanf("%d%d%d", &k, &n, &m), k || n || m) {
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%s", map[i][j]);
                for (int r = 0; r < m; ++r) {
                    if (map[i][j][r] == 'S') {
                        startX = i;
                        startY = j;
                        startZ = r;
                    } else if (map[i][j][r] == 'E') {
                        endX = i;
                        endY = j;
                        endZ = r;
                    }
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        int result;
        result = bfs();
        if (result) {
            printf("Escaped in %d minute(s).\n", result);
        } else {
            printf("Trapped!\n");
        }
    }
    return 0;
}
