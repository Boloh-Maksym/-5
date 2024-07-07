#include <stdio.h>

#define MOD 12345

int count_sequences(int n) {
    if (n == 1) return 2;
    if (n == 2) return 4;

    
    int dp[n+1];
    dp[1] = 2; // "0", "1"
    dp[2] = 4; // "00", "01", "10", "11"
    dp[3] = 7; // "000", "001", "010", "011", "100", "101", "110"

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


