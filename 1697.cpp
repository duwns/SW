#include <iostream>
#include <queue>

using namespace std;

int level=0;
queue<int> que;

int bfs(int sis, int bro){
	if(sis==bro)
	{
		return 0;
	}
		que.push(sis-1);
		que.push(sis+1);
		que.push(sis*2);

	while(que.front() != bro){
		
		if(que.front() != bro){
		    
			//printf("%d \n", que.front());
			
			int tmp=que.front();
			que.push(tmp-1);
			que.push(tmp+1);
			que.push(tmp*2);
			if(tmp==sis-(level+1)) level++;
			que.pop();
			
		    if(que.front() == bro)
			return level;
		}
		
	}
	
	
	

}


int main(){

	int sis, bro;
	scanf("%d %d", &sis, &bro);

	int result = bfs(sis, bro);
	printf("%d", result);


	return 0;
}