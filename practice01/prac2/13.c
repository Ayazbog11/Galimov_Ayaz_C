#include <stdio.h>

int main() {
int num,sum = 0,n = 0;
scanf("%d", &n);
for(int i = 0; i < n; i++) {
    scanf("%d", &num);
    if(num > 10) printf("%d ", num);
}
}