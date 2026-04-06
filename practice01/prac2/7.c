#include <stdio.h>

int main() {
    int n,count=0;
    scanf("%d", &n);
for (int i = 1; i <= n; i++) {
    int sq = i * i;
    if (sq > 50) {
        printf("%d ", sq);
    }
} 
    return 0;
}
