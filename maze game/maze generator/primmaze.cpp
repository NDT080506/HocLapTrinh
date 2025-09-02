#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MaxN = 1 + 1e2;
const ll INF = 1e18;

int height, width;
char maze[1001][1001];
int visit[1001][1001];

int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, -1, 0, 1};

struct wall {
    int x, y;  
    int nx, ny;
};

vector<wall> walls;

void addwalls(int i, int j){
	
	for(int k = 0; k < 4; k++){
		int ni = i + diry[k] * 2;
		int nj = j + dirx[k] * 2;
		int wi = i + diry[k];	
		int wj = j + dirx[k];
		if (ni >= 0 && ni < height && nj >= 0 && nj < width){
			if (maze[ni][nj] == '#'){
				walls.push_back({wj, wi, nj, ni});
			}
		}
	}
}

void mark(int i, int j){
	visit[i][j] = 1;
	maze[i][j] = ' ';
	addwalls(i, j);
}

int main(){
	srand(time(0));
	cin >> height >> width;
	
	if (height % 2 == 0) height++;
	if (width % 2 == 0) width++;
	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			maze[i][j] = '#';
		}
	}
	
	int sx = 1 + rand() % (height/2) * 2;
    int sy = 1 + rand() % (width/2) * 2;
    mark(sx, sy);
	
	//entry
	maze[1][0] = ' ';
	//exit
    maze[height-2][width-1] = ' ';
	
	while(!walls.empty()){
		int idx = rand() % walls.size();
		wall w = walls[idx];
		walls.erase(walls.begin() + idx);
		
		if (!visit[w.ny][w.nx]){
			maze[w.y][w.x] = ' ';
			mark(w.ny, w.nx);
		}
	}
	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			cout << maze[i][j];
		}
		cout << "\n";
	}

    return 0;
}

