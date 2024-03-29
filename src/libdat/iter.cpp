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
\brief Definitions for dat::iter
*/


#include "libdat/iter.h"


namespace dat
{
namespace iter
{

std::size_t
activeEndFor
	( std::size_t const & sourceSize
	, std::size_t const & useSize
	)
{
	std::size_t lastEnd{ dat::nullValue<std::size_t>() };
	if (useSize <= sourceSize)
	{
		lastEnd = sourceSize - useSize + 1u;
	}
	return lastEnd;
}

std::size_t
activeEndFor
	( std::size_t const & sourceSize
	, std::size_t const & patchSize
	, std::size_t const & numLooks
	)
{
	std::size_t end{ dat::nullValue<std::size_t>() };
	std::size_t const & sourceEnd = sourceSize;
	if ((0u < patchSize) && (0u < numLooks))
	{
		std::size_t const patchEnd{ activeEndFor(sourceEnd, patchSize) };
		if (dat::isValid(patchEnd))
		{
			std::size_t const searchEnd{ activeEndFor(patchEnd, numLooks) };
			if (dat::isValid(searchEnd))
			{
				end = searchEnd;
			}
		}
	}
	return end;
}

}
}

