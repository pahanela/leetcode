int maxProfit(int* prices, int pricesSize) {
    int buyDay = 0;
    int sellDay = 0;
    int maxDiff = 0;
    while (buyDay < pricesSize){
        sellDay = buyDay + 1;
        while (sellDay < pricesSize){
            if (prices[sellDay] - prices[buyDay] > maxDiff)
                maxDiff = prices[sellDay] - prices[buyDay];
            sellDay++;
        }
        buyDay++;
    }
    return maxDiff;
}

