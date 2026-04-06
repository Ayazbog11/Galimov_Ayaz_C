#include <stdio.h>

int main() {
int max,num,n;
scanf("%d", &n);
scanf("%d", &num); 
max = num; 
for(int i = 1; i < n; i++) {
    scanf("%d", &num);
    if(num > max) max = num;
}
printf("%d", max);
}