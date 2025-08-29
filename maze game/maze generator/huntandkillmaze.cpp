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


vector<pair<int, int>> findneighbour(int i, int j){
	vector<pair<int,int>> res;
	
	vector<int> dirs = {0,1,2,3};
	for(int k: dirs){
		int ni = i + diry[k]*2;
		int nj = j + dirx[k]*2;
		
		if (ni >= 0 && ni < height && nj >= 0 && nj < width){
			if (!visit[ni][nj]){
				res.push_back({ni, nj});
			}
		}
	}
	return res;
}

void huntandkill(){
	srand(time(0));
	
	int x = (rand() % ((width-1)/2)) * 2 + 1;
	int y = (rand() % ((height-1)/2)) * 2 + 1;
	
	visit[y][x] = 1;
	maze[y][x] = ' ';
	
	while(1){
		
		vector<pair<int,int>> neigh = findneighbour(y, x);
		
		if (neigh.size() > 0){
			
			// phase kill
			auto its = neigh[rand() % neigh.size()];
			int nx = its.second;
			int ny = its.first;
			maze[(y+ny)/2][(x+nx)/2] = ' ';
			visit[ny][nx] = 1;
			maze[ny][nx] = ' ';
			
			y = ny; x = nx;
		}else{
			
			// phase hunt
			
			int found = 0;
			for(int i = 1; i < height-1 && !found; i+=2){
				for(int j = 1; j < width-1 && !found; j+=2){
					vector<pair<int,int>> neighbour = findneighbour(i, j);
					
					if (!neighbour.empty()){
						auto it = neighbour[rand() % neighbour.size()];
						int ni = it.first;
						int nj = it.second;
						found = 1;
						maze[(i+ni)/2][(j+nj)/2] = ' ';
						visit[ni][nj] = 1;
						maze[ni][nj] = ' ';
						
						y = ni; x = nj;
					}
				}
			}
			
			if (!found) break;
		}
	} 
}

int main(){
	cin >> height >> width;
	
	if (height % 2 == 0) height++;
	if (width % 2 == 0) width++;
	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			maze[i][j] = '#';
		}
	}
	
	huntandkill();
	
	//entry
	maze[1][0] = ' ';
	//exit
    maze[height-2][width-1] = ' ';

	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			cout << maze[i][j];
		}
		cout << "\n";
	}

    return 0;
}

