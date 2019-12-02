#include <stdio.h>

int WhoStayed(int *landings, int *departures, size_t land_size, size_t dep_size)
{
	size_t last_one = 0;
	size_t i = 0, j = 0;
	
	for (i = 0; i < land_size; ++i)
	{
		last_one += landings[i];
	}
	for (j = 0; j < dep_size; ++j)
	{
		last_one -= departures[j];
	}
	
	return last_one;
}

int WhoStayedOneArray(int *airplaines, size_t size)
{
	size_t i = 0;
	
	for (i = 0; i < size - 1; ++i)
	{
		airplaines[i + 1] ^= airplaines[i];
	}
	
	return airplaines[i];
}

int main()
{
	int landing[] = {1,2,5,4,3,6,9,8,7};
	int departure[] = {2,1,5,7,9,3,8,6};
	int airplanes[] = {1,1,2,3,2,4,3,6,6};
	
	printf("%d\n", WhoStayed(landing, departure, 9, 8));
	
	printf("%d\n", WhoStayedOneArray(airplanes, 9));
	
	return 0;
}
