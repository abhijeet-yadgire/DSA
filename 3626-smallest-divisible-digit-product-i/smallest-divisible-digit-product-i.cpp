class Solution {
public:

    int getProd(int num){
        int prod = 1;

        while(num > 0){
            prod *= num % 10;
            num /= 10; 
        }

        return prod;
    }

    int smallestNumber(int n, int t) {
        int result;
        int i = n;
        while(i < 101){
            int prod = getProd(i);

            if(prod % t == 0){
                return i; 
            }
            i++;
        }
        return 0;
    }
};