#include<cstdio>
#include<queue>
using namespace std;
struct node {
	int x, y, z;
} Node; 

int n, m, slice, T;
int pixel[1290][130][61];
bool inq[1290][130][61] = {false};
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

bool judge(int x, int y, int z) {
	// 越界 
	if (x >= n || x < 0 || y >= m || y < 0 || z >= slice || z < 0) {
		return false;
	}
	//当前位置为0 或者已经入队 则返回false
	if (pixel[x][y][z] == 0 || inq[x][y][z] == true) {
		return false;
	} 
	return true;
}

int BFS(int x, int y, int z) {
	int tot = 0; // 定义当前块中1的个数 
	queue<node> q; // 定义队列
	Node.x = x, Node.y = y, Node.z = z;
	q.push(Node); // 将节点入队
	inq[x][y][z] = true;
	
	while(!q.empty()) {
		node top = q.front(); // 取出队首元素
		q.pop(); // 队首元素出队 
		tot++; // 当前块中1的个数加一
		 
		for (int i = 0; i < 6; i++) {
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			
			if (judge(newX, newY, newZ)) {
				Node.x = newX, Node.y = newY, Node.z = newZ;
				q.push(Node);
				inq[newX][newY][newZ] = true; 
			}
		} 
	}
	
	if (tot >= T) return tot;
	else return 0; 
}
int main() {
	scanf("%d%d%d%d", &n, &m, &slice, &T);
	for (int z = 0; z < slice; z++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				scanf("%d", &pixel[x][y][z]);
			}
		}
	}
	int ans = 0;
		for (int z = 0; z < slice; z++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (pixel[x][y][z] == 1 && inq[x][y][z] == false) {
					ans += BFS(x, y, z);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
