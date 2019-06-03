#include <string>
#include <vector>

using namespace std;

int answer = 0;

void change(string name, int index){
	int a=name[index] - 'A';  //a ������ �̵� b ������ �̵�  
	int b='Z' - name[index] + 1;
	if(a>b)	answer+=b;
	else answer+=a;
	//printf("%d ", answer);
}


int solution(string name) {
   
    int i, nota=0;
	int index=0; //ó�� ������ ������ 0��° �ε��� �̴�.  
    
    for(i=0; i<name.size(); i++)  // A�� �ƴ� ���� �� 
    	if(name[i]!='A') nota++;  
   // printf("%d", nota);
    while(nota!=0){
    	
    	int right=0, left=0;
		int rindex=index;
		int lindex=index;
		
    	while(name[rindex]=='A'){
    		rindex++;	
    		right++;
    		if(rindex>=name.size()) rindex=0;  //rindex�� ũ�⸦ ������ ���� ó������ 
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
		
		change(name, index);  //�ش� �ε����� ���ڸ� 'A'�� �ٲ��ش�.  
    	name[index]='A';
    	nota--;
    	if(nota == 0) break;
    	
	}
    
    return answer;
}
