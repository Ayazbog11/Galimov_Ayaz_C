#include <stdio.h>

int main() {
int N, num, count = 0;
scanf("%d", &N);
for(int i = 0; i < N; i++) {
    scanf("%d", &num);
    if(num > 0) count++;
}
printf("%d\n", count);
}