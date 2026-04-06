#include <stdio.h>

int main() {
int min_even = -1,num,n;; 
scanf("%d", &n);
for(int i = 0; i < n; i++) {
    scanf("%d", &num);
    if(num % 2 == 0) {
        if(min_even == -1 || num < min_even) min_even = num;
    }
}
if(min_even != -1) printf("%d", min_even);
}