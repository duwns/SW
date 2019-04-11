#include <iostream>
#include <vector>
#include <stack> 	
#include <queue>
using namespace std;

vector<int> dfsD;
vector<int> bfsD;
int a[1001][1001]={0,};
int ch[1001]={0,};
int ch2[1001]={0,};
//int count=0;

void dfs(int S, int N, int M){
	
	stack<int> stc;
	
    stc.push(S);             //시작정점을 스택에 추가
    int tmp;   	 //시작정점을 tmp애 추가
          
    while(!stc.empty()){
    //  if(count==N) break;
      	
		if(ch[stc.top()]==0){      				   //가장 작은 번호의 정점이 방문되지 않았다면
			tmp=stc.top();	
			ch[tmp]=1;
      		dfsD.push_back(tmp);				   //방문 정점 데이터에 추가			
      							   //방문 확인
      		//printf("%d ",stc.top());
     		stc.pop();	

     		for(int i=N; i>0; i--){       
            if(a[tmp][i]==1  && ch[i]==0)          //인덱스 정점과 i정점이 연결되어있고 i정점이 방문되어있지 않다면
            	stc.push(i);
        }   
		} else {
			stc.pop();
		}
    }
}

void bfs(int S, int N){
	int i, here;
	//ch2[S]=1;
	queue<int> que;
	que.push(S);
	int count[N+1]={0,};
	
	while(!que.empty())
	{    
		if(ch2[que.front()]==0){
		  	ch2[que.front()]=1;
		  	//("%d", que.front());
		  	bfsD.push_back(que.front());
		  	here=que.front();
		  	que.pop();	 
		  	for(i=1; i<=N; i++)
			{	
				if(a[i][here]==1 && i!=here && ch2[i]==0){
					//printf("%d", que.front());
					que.push(i);
				}
				
			} 		  	
		} else {
			que.pop();
		}	
	    
	}

}

int main() {
   int N, M, S, i;
   scanf("%d %d %d", &N, &M, &S);
   
   for(i=0; i<M; i++)
   {int b, c;
      scanf("%d %d", &b, &c);
      a[b][c]=a[c][b]=1;
      //if(i>0) a[i][i]=1;
   }
   
   
    dfs(S, N, M);
    for(i=0; i<dfsD.size(); i++)
		printf("%d ", dfsD[i]);
		
	printf("\n");
      
    bfs(S, N);
	for(i=0; i<bfsD.size(); i++)
		printf("%d ", bfsD[i]);
	
   return 0;
}