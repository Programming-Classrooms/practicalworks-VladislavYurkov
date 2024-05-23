#include "src/Functions/Functions.hpp"

int main()
{
	fishList lake;
	fillLake(lake);

	fisherList fishers;
	const size_t catchedFishesNum = 2;
	catchFishes(fishers, lake, catchedFishesNum);
	
	fishersInfo(fishers);

	sameFishes(fishers);
	
	notCatched(lake, fishers);

	return 0;
}
