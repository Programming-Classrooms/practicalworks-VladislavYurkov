#include "src/Functions/Functions.hpp"
int main()
{
	std::vector<BusRoute> busRoutes;

	std::ifstream fileIn("src/Resources/busRoutes.txt");
	fileToBusVect(busRoutes, fileIn);
	fileIn.close();
	
	routesSort(busRoutes);
	//printRoutesVect(busRoutes);

	std::map<size_t,BusRoute> routesMapCont;
	vectToMap(busRoutes, routesMapCont);
	//printRoutesMap(routesMapCont);

	//printByRouteNum(busRoutes, 100);
	//printDriversByMark(busRoutes, "Икарус");

	//std::cout << maxDiffMarks(busRoutes) << '\n';

	//deleteByKey(routesMapCont, 21);
	//printRoutesMap(routesMapCont);
	

	return 0;
}
