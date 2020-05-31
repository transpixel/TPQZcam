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
\brief Definitions for dat::NdxBegEnd
*/


#include "libdat/NdxBegEnd.h"

#include "libdat/algorithm.h"
#include "libdat/compare.h"

#include <cassert>
#include <iomanip>
#include <sstream>


namespace dat
{

// explicit
NdxBegEnd :: NdxBegEnd
	( std::size_t const & ndxBeg
	, std::size_t const & ndxEnd
	)
	: theNdxBeg{ ndxBeg }
	, theNdxEnd{ ndxEnd }
{
}

// explicit
NdxBegEnd :: NdxBegEnd
	( std::pair<std::size_t, std::size_t> const & bePair
	)
	: theNdxBeg{ bePair.first }
	, theNdxEnd{ bePair.second }
{
}

bool
NdxBegEnd :: isValid
	() const
{
	return
		(  dat::isValid(theNdxBeg)
		&& dat::isValid(theNdxEnd)
		&& (theNdxBeg < theNdxEnd)
		);
}

std::size_t const &
NdxBegEnd :: begin
	() const
{
	return theNdxBeg;
}

std::size_t const &
NdxBegEnd :: end
	() const
{
	return theNdxEnd;
}

std::size_t
NdxBegEnd :: size
	() const
{
	std::size_t num{ dat::nullValue<std::size_t>() };
	if (isValid())
	{
		num = end() - begin();
	}
	return num;
}

NdxBegEnd
NdxBegEnd :: centeredSubOfSize
	( std::size_t const & subSize
	) const
{
	NdxBegEnd sub{};
	if (isValid())
	{
		std::size_t const fullSize{ size() };
		assert(subSize <= fullSize);
		std::size_t const numResid{ fullSize - subSize };
		std::size_t const numEdge{ numResid / 2u }; // mod2 division
		std::size_t const subBeg{ theNdxBeg + numEdge };
		std::size_t const subEnd{ subBeg + subSize };
		sub = NdxBegEnd(subBeg, subEnd);
	}
	return sub;
}

NdxBegEnd
NdxBegEnd :: croppedCenterSize
	( std::size_t const & subCenter
	, std::size_t const & subSize
	) const
{
	NdxBegEnd subBE{};
	if (0u < subSize)
	{
		// perform operations with signed values
		long const loHalf{ long(subSize / 2u) };
		long const hiHalf{ long((subSize + 1u) / 2u) };
		long const tmpBeg{ long(subCenter) - loHalf };
		long const tmpEnd{ long(subCenter) + hiHalf };

		std::pair<long, long> const longRange
			{ long(theNdxBeg), long(theNdxEnd) };
		long const lBeg{ clamped(tmpBeg, longRange) };
		long const lEnd{ clamped(tmpEnd, longRange) };
		assert(0L <= lBeg);
		assert(0L <= lEnd);
		assert(lBeg <= long(size()));
		assert(lEnd <= long(size()));

		if (lBeg < lEnd) // else an empty interval
		{
			// cast back to unsigned indices
			subBE = NdxBegEnd{ std::size_t(lBeg), std::size_t(lEnd) };
		}
	}
	return subBE;
}

bool
NdxBegEnd :: nearlyEquals
	( NdxBegEnd const & other
	, std::size_t const & tol
	) const
{
	bool same{ false };
	if (isValid() && other.isValid())
	{
		long const lBegA{ long(theNdxBeg) };
		long const lEndA{ long(theNdxEnd) };
		long const lBegB{ long(other.theNdxBeg) };
		long const lEndB{ long(other.theNdxEnd) };
		long const lBegDel{ lBegA - lBegB };
		long const lEndDel{ lEndA - lEndB };
		std::size_t const difBeg{ std::size_t(std::abs(lBegDel)) };
		std::size_t const difEnd{ std::size_t(std::abs(lEndDel)) };
		same =
			(  dat::nearlyEquals(difBeg, std::size_t{0u}, tol)
			&& dat::nearlyEquals(difEnd, std::size_t{0u}, tol)
			);
	}
	return same;
}

std::string
NdxBegEnd :: infoString
	( std::string const & title
	) const
{
	std::ostringstream oss;
	if (! title.empty())
	{
		oss << std::setw(15u) << title << " ";
	}
	if (isValid())
	{
		oss
			<< "beg,end,size:"
			<< " " << dat::infoString(begin())
			<< " " << dat::infoString(end())
			<< "  "
			<< " " << dat::infoString(size())
			;
	}
	else
	{
		oss << " <null>";
	}
	return oss.str();
}

} // dat

