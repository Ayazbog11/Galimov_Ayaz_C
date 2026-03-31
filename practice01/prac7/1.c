#include <stdio.h>
long long sum(long long n) {
    long long result = 0;
    for (int i = 1; i < n; i++) {
        result += i;
    }
    return result;
}
int main(){
    long long n;
    printf("Введите число: ");
    scanf("%lld", &n);
    printf("Сумма чисел от 1 до %d равна %lld\n", n, sum(n));
}