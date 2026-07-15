class Solution {
public:
    int fib(int n) {
        // Base Case
        if (n <= 1)
            return n;

        // Recursive Case
        return fib(n - 1) + fib(n - 2);
    }
};