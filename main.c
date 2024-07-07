#include <stdio.h>

#define MOD 12345

int count_sequences(int n) {
    if (n == 1) return 2;
    if (n == 2) return 4;


    int dp[n+1];
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;

    for (int i = 4; i <= n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }

    return dp[n];
}

int main() {
    int n;
    printf("Введіть довжину послідовності n: ");
    scanf("%d", &n);

    if (n <= 1 || n >= 10000) {
        printf("Помилкове значення n. n повинно бути в діапазоні 2 < n < 10000.\n");
        return 1;
    }

    int result = count_sequences(n);
    printf("Кількість шуканих послідовностей: %d\n", result);

    return 0;
}

