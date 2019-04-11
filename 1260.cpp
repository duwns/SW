#include <iostream>
#include <vector>
#include <stack> 	
#include <queue>
using namespace std;

vector<int> dfsD;
vector<int> bfsD;
int a[1002][1002]={0,};
int ch[1002]={0,};
int ch2[1002]={0,};
//int count=0;

void dfs(int S, int N, int M){
	
	stack<int> stc;
	
    stc.push(S);
    int tmp=stc.top();
          
    while(!stc.empty()){
    //  if(count==N) break;
      	
		if(ch[stc.top()]==0){
			
      		dfsD.push_back(stc.top());
     		tmp=stc.top();
      		ch[stc.top()]=1;
      		//printf("%d ",stc.top());
     		stc.pop();	
		} else {
			stc.pop();
		}
      
        for(int i=N; i>0; i--){       
            if(a[tmp][i]==1  && ch[i]==0)
            stc.push(i);
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
		} else {
			que.pop();
	}
		
		for(i=1; i<=N; i++)
		{	
			if(a[i][here]==1 && i!=here && ch2[i]==0){
				//printf("%d", que.front());
				que.push(i);
			}
			
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