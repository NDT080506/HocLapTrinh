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


void backtracking(int i, int j){
	visit[i][j] = 1;
	maze[i][j] = ' ';
	
	vector<int> dirs = {0,1,2,3};
	random_shuffle(dirs.begin(), dirs.end());
	
	for(int k: dirs){
		int ni = i + diry[k] * 2;
		int nj = j + dirx[k] * 2;
		
		if (ni >= 0 && ni < height && nj >= 0 && nj < width){
			if (!visit[ni][nj]){
				maze[(i + ni)/2][(j + nj)/2] = ' ';
				backtracking(ni, nj);
			}
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
	
	backtracking(1, 1);
	
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

