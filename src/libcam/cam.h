//
//
// MIT License
//
// Copyright (c) 2017 Stellacore Corporation.
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject
// to the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
// KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
// BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
// AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
// IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//

#ifndef cam_cam_INCL_
#define cam_cam_INCL_

/*! \file
\brief Declarations for namespace cam
*/


#include "libdat/Spot.h"

#include <string>
#include <vector>


/*! \brief Declarations and Definitions for libcam.

\par General Concept:

Basic photogrammetric imaging operations.

\par Special Notes:

+ XRefBase and typedefs provide object/image relationship mangement.


*/
namespace cam
{

	//! Type to identify (object space) point entities
	using PntNdx = std::size_t;

	//! Type to identify sensor acquisition events (imprint records)
	using AcqNdx = std::size_t;

	//! Descriptive point name/key
	using PntName = std::string;

	//! Descriptive acquisition name/key
	using AcqName = std::string;

	//! Image measurement for a single object space point
	struct MeaForOnePnt
	{
		std::string const thePntName;
		dat::Spot const theSpot;
		// Uncertainty - e.g. Covar matrix info
	};

	//! All image measurements associated with a single acquisition
	using MeaGroupOneAcq = std::vector<MeaForOnePnt>;

} // cam

// Inline definitions
// #include "libcam/cam.inl"

#endif // cam_cam_INCL_

