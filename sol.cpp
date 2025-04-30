
class Solution {
    public:
        int divide(int dividend, int divisor) {
            // Handle edge case
            if (dividend == divisor) return 1;
            if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    
            bool isPositive = (dividend > 0) == (divisor > 0);
    
            
            long long n = abs((long long)dividend);
            long long d = abs((long long)divisor);
    
            long long result = 0;
    
            while (n >= d) {
                int count = 0;
                while ((d << (count + 1)) <= n) {
                    count++;
                }
                n -= (d << count);
                result += (1LL << count);  // ensure no overflow
            }
    
            if (!isPositive) result = -result;
    
            return result > INT_MAX ? INT_MAX : (int)result;
        }
    };
    