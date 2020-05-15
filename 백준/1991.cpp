#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

//벡터의 크기를 정하면 그냥 대입 가능함. 
pair<char,char> v[30];

void preorder(char vtx){	
	char left = v[vtx-'A'].first;
	char right = v[vtx-'A'].second;
	
	printf("%c", vtx);
	if(left != '.')preorder(left);
	if(right != '.')preorder(right);
}

void inorder(char vtx){	
	char left = v[vtx-'A'].first;
	char right = v[vtx-'A'].second;
	
	if(left != '.')inorder(left);
	printf("%c", vtx);
	if(right != '.')inorder(right);
}

void postorder(char vtx){	
	char left = v[vtx-'A'].first;
	char right = v[vtx-'A'].second;
	
	if(left != '.')postorder(left);	
	if(right != '.')postorder(right);
	printf("%c", vtx);
}

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		char vtx, left, right;
		scanf(" %c %c %c",&vtx,&left,&right);
		v[vtx-'A'] = make_pair(left,right);
	}
	
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
}

