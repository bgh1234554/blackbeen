#include <stdio.h>
#include <string.h>

int vowel(char a[]){
	int count = 0;
	for(int i=0; i<strlen(a); i++){
		if(a[i]== 'a'|| a[i]== 'e'|| a[i]== 'i'|| a[i]== 'o'||a[i]== 'u'){
			count+=1;
		}
	}
	return count;	
}

int main(){
	char x[101] = {};
	scanf("%s", x);
	int y = vowel(x);
	printf("%d",y);
}
