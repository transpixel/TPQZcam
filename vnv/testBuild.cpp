

#include "libdat/info.h"
#include "libga/ga.h"
#include "libcam/Camera.h"

#include <iostream>

int
main
	( int argc
	, char * * argv
	)
{
	std::cout << argv[0] << std::endl;

	std::cout << dat::infoString(1.25, "1.25") << std::endl;

	ga::Vector const vec{ 1., 2., 3. };
	std::cout << dat::infoString(ga::vZero, "ga::vZero") << std::endl;

	cam::Camera const cam(2.5, dat::Extents{ 100u, 200u });
	std::cout << dat::infoString(cam, "cam") << std::endl;
}

