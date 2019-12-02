#include <stdio.h>

int Bursa(int *arr, int arr_len, int *buy, int *sell)
{
	int buy_in = 0, sell_in = 1, max_profit = 0, temp_profit = 0;
	
	while (sell_in < arr_len)
	{
		temp_profit = arr[sell_in] - arr[buy_in];
		
		if (0 > temp_profit)
		{
			buy_in = sell_in;
		}
		else if (max_profit < temp_profit)
		{
			max_profit = temp_profit;
			*buy = buy_in;
			*sell = sell_in;
		}
		
		++sell_in;
	}

	return max_profit;
}

int main()
{
	int arr[] = {6, 12, 3, 5, 1, 4, 9, 2};
	int sell = 0, buy = 0;
	
	printf("max profit: %d\n", Bursa(arr, 8, &buy, &sell));
	printf("buy index: %d, sell index: %d\n", buy, sell);
	
	return 0;
} 
