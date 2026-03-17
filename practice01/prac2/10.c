#include <stdio.h>

int main() {
long long prod = 1; 
int found = 0,n;
scanf("%d", &n);
for (int i = 1; i <= n; i++) {
    if (i % 3 == 0) {
        prod *= i;
        found = 1;
    }
}
if (found) printf("%lld\n", prod);
else printf("0\n");
}
