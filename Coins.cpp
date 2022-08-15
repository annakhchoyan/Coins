#include <iostream>
#include <vector>

int coin_change(const std::vector<int>& coins, int amount)
{
	if(amount == 0)
	{
		return 0;
	}
	if(amount < 0)
	{
		return -1;
	}

	std::vector<int> x((amount + 1), amount + 1);
	x[0] = 0;

	for(int i = 1; i <= amount; ++i)
	{
		for(auto j : coins)
		{
			if((i - j) >= 0)
			{
				x[i] = std::min(x[i], 1 + x[i - j]);
			}
		}
	}
	return x[amount] == amount + 1 ? -1 : x[amount];
}

int main()
{
	int amount;
	std::vector<int> coins = {10, 20, 50, 100, 200, 500};

	std::cout << "Enter the amount: ";
	std::cin >> amount;
	std::cout << "The number of steps to get it with coins: " << coin_change(coins, amount) << std::endl;

	return 0;
}
