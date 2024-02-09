class Solution {
    fun maxProfit(prices: IntArray): Int {
        var ans = 0
        prices.toList().windowed(2).map { (a, b) ->
            ans += max(0, b - a)
        }
        return ans
    }
}