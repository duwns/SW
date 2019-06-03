#include <string>
#include <vector>

using namespace std;

int answer = 0;

void change(string name, int index){
	int a=name[index] - 'A';  //a 정방향 이동 b 역방향 이동  
	int b='Z' - name[index] + 1;
	if(a>b)	answer+=b;
	else answer+=a;
	//printf("%d ", answer);
}


int solution(string name) {
   
    int i, nota=0;
	int index=0; //처음 시작은 무조건 0번째 인덱스 이다.  
    
    for(i=0; i<name.size(); i++)  // A가 아닌 문자 수 
    	if(name[i]!='A') nota++;  
   // printf("%d", nota);
    while(nota!=0){
    	
    	int right=0, left=0;
		int rindex=index;
		int lindex=index;
		
    	while(name[rindex]=='A'){
    		rindex++;	
    		right++;
    		if(rindex>=name.size()) rindex=0;  //rindex가 크기를 넘으면 가장 처음으로 
		} 
    	while(name[lindex]=='A'){
    		lindex--;
			left++;	
    		if(lindex<0) lindex=name.size()-1;
		} 
        printf("%d %d\n", left, right);
    	if(right > left){
    		answer+=left;
    		index=lindex;
		} 
    	else {
    		answer+=right;
    		index=rindex;
		}
		
		change(name, index);  //해당 인덱스의 문자를 'A'로 바꿔준다.  
    	name[index]='A';
    	nota--;
    	if(nota == 0) break;
    	
	}
    
    return answer;
}
