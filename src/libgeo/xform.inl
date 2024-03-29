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


/*! \file
\brief Inline definitions for geo::xform
*/


namespace geo
{
namespace xform
{

	inline
	geo::Triangle
	apply
		( ga::Rigid const & xBwrtA
		, geo::Triangle const & triangleInA
		)
	{
		return geo::Triangle
			( xBwrtA(triangleInA[0])
			, xBwrtA(triangleInA[1])
			, xBwrtA(triangleInA[2])
			);
	}

	template <typename FwdIter>
	inline
	std::vector<geo::Triangle>
	apply
		( ga::Rigid const & xBwrtA
		, FwdIter const & triBeg
		, FwdIter const & triEnd
		)
	{
		std::vector<geo::Triangle> trianglesInB;
		std::size_t const numTri
			{ static_cast<std::size_t>(std::distance(triBeg, triEnd)) };
		trianglesInB.reserve(numTri);
		for (FwdIter iter{triBeg} ; triEnd != iter ; ++iter)
		{
			trianglesInB.emplace_back(apply(xBwrtA, *iter));
		}
		return trianglesInB;
	}

	inline
	geo::Ray
	apply
		( ga::Rigid const & xBwrtA
		, geo::Ray const & rayInA
		)
	{
		ga::Vector const & startInA = rayInA.theStart;
		ga::Vector const & dirInA = rayInA.theDir;
		ga::Vector const startInB(xBwrtA(startInA));
		ga::Vector const dirInB(xBwrtA.transformedDirection(dirInA));
		return geo::Ray(startInB, dirInB);
	}

}
}

