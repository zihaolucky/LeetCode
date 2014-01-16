/**
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 */
class Solution {
public:
    int reverse(int x) {
        int reversed=0;
        int i=0;
        while(x != 0) {
            reversed *= 10;
            reversed += x%10;
            i++;
            x = x/10;
        }
        return reversed;
    }
};