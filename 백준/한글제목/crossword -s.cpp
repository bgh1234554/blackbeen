#include <stdio.h>

int n, m, u, l, r, d;

int main(){
    scanf("%d %d\n%d %d %d %d", &n, &m, &u, &l, &r, &d);
    char arr[n][m];
    for(int i=0; i<n; i++){
        scanf("%s", &arr[i]);
    }
    for(int i=0-u; i<n+d; i++){
        for(int j=0-l; j<m+r; j++){
            int x = i+u;
            int y = j+l;
            if( i < 0 || i >= n || j < 0 || j >= m){
                if( (x+y)%2 ) printf(".");
                else printf("#");
            }
            else printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}
