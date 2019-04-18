#include <iostream>
#include <queue>

using namespace std;

int map[25][25]={0,};
priority_queue<int,vector<int>,greater<int> > aresult;
int result[1000]={0,};
int house=0;

void floodfill(int i, int j){

	if(map[i][j]==1)
	{
		map[i][j]=0;
		result[house-1]++;

		floodfill(i, j+1);
		floodfill(i, j-1);
		floodfill(i+1, j);
		floodfill(i-1, j);
	}
}


int main() {

	int length, i, j;
	scanf("%d", &length);

	for(i=0; i<length; i++)	{

		for(j=0; j<length; j++)	{
			scanf("%1d", &map[i][j]);
		}
	}


	for(i=0; i<length; i++)	{

		for(j=0; j<length; j++)	{
		
			if(map[i][j]==1){
				house++;
				floodfill(i, j);
			}

		}
		
	}


	printf("%d\n", house);

	for(i=0; i<house; i++) 
		aresult.push(result[i]);

	while(!aresult.empty()){
		printf("%d\n", aresult.top()); 
		aresult.pop();
	}

	return 0;
}
