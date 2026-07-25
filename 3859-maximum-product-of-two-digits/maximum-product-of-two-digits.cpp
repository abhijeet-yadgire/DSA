class Solution {
public:
    int maxProduct(int n) {

        int first_digit = 0;
        int second_digit = 0;

        while(n > 0){
            int digit = n % 10;

            if(first_digit < second_digit){
                first_digit = max(first_digit, digit);
            }
            else{
                second_digit = max(second_digit, digit);
            }  
            n = n / 10;
        }

        
        return first_digit * second_digit;
    }
};