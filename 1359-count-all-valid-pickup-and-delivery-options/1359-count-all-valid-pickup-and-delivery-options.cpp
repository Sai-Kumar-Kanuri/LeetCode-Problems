class Solution {
    public:
    int MOD = (int)1e9 + 7;  // Modulus for calculations

    long long calculateOrdersCount(long long remainingPairs) {
        // Base case: No remaining pairs, return 1
        if (remainingPairs == 0)
            return 1;

        // Calculate the number of valid orders for the remaining pairs
        long long currentResult = calculateOrdersCount(remainingPairs - 1) * (2 * remainingPairs - 1) * remainingPairs % MOD;

        return currentResult;
    }

    int countOrders(int numPairs) {
        // Calculate and return the count of valid orders
        return calculateOrdersCount(numPairs);
    }
};