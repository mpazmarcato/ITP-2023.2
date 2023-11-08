#include <stdio.h>

void putElements(int n, int v[n]) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
}

int main()
{
    
    int n1;
    int count = 0;
    scanf("%d", &n1);
    
    int v1[n1];

    putElements(n1, v1);

    for(int i = n1-1; i > 0; i--) {
        if ((v1[i]-v1[i-1])%2 == 0) {
            count++;
        }
    }
    
    if(count == n1-1) printf("Legal");
    else printf("Chato");
    
  return 0;
}