class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;
        
        for (int i = num1; i <= num2; ++i) {
            int x = i;
            int digits[10];
            int len = 0;
            
            while (x > 0) {
                digits[len++] = x % 10;
                x /= 10;
            }
            
            if (len >= 3) {
                for (int j = 1; j < len - 1; ++j) {
                    if (digits[j] > digits[j - 1] && digits[j] > digits[j + 1]) {
                        total++; // Peak
                    } else if (digits[j] < digits[j - 1] && digits[j] < digits[j + 1]) {
                        total++; // Valley
                    }
                }
            }
        }
        
        return total;
    }
};