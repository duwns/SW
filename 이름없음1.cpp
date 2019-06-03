#include <iostream>
#include <queue>

using namespace std;

int level[100001]={0,};
queue<int> que;
int bfs(int sis, int bro){
//	if(sis==bro)
//	{
//		return 0;
//	}
//		que.push(sis-1);
//		que.push(sis+1);
//		que.push(sis*2);

	que.push(sis);

	while(que.front() != bro){
		
		if(que.front() != bro){
		    
			printf("%d \n", que.front());
			
			int tmp=que.front();
			que.pop();
			
			if(levxel[tmp-1]==0 && tmp-1>=0){
				que.push(tmp-1);
				level[tmp-1] = level[tmp] +1;
			}
			if(level[tmp+1]==0 && tmp+1<=100000)
			{
				que.push(tmp+1);
				level[tmp+1] = level[tmp] +1;
			}
			if(level[tmp*2]==0 && tmp*2<=100000)
			{
				que.push(tmp*2);
				level[tmp*2] = level[tmp]+1;
			}	
			
		    
		}
		
	}
	return level[bro];
	

}


int main(){

	int sis, bro;
	scanf("%d %d", &sis, &bro);

	int result = bfs(sis, bro);
	printf("%d", result);


	return 0;
}
