#include "src/Functions/Functions.hpp"
int main()
{
	std::vector<BusRoute> busRoutes;

	std::ifstream fileIn("src/Resources/busRoutes.txt");
	fileToBusVect(busRoutes, fileIn);
	fileIn.close();
	
	routesSort(busRoutes);
	printRoutesVect(busRoutes);

	std::map<size_t,BusRoute> routesMapCont;
	

	return 0;
}
