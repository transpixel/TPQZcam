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
\brief Definitions for geo::Triangle
*/


#include "libgeo/Triangle.h"

#include <sstream>

#include "libdat/info.h"
#include "libio/stream.h"


namespace geo
{

Triangle :: Triangle
	()
	: theVerts
		{{ ga::Vector::null()
		 , ga::Vector::null()
		 , ga::Vector::null()
		}}
{
}

// explicit
Triangle :: Triangle
	( ga::Vector const & v1
	, ga::Vector const & v2
	, ga::Vector const & v3
	)
	: theVerts{{ v1, v2, v3 }}
{
}

bool
Triangle :: isValid
	() const
{
	return
		(  dat::isValid(theVerts[0])
		&& dat::isValid(theVerts[1])
		&& dat::isValid(theVerts[2])
		);
}

ga::Vector const &
Triangle :: operator[]
	( std::size_t const & ndx
	) const
{
	return theVerts[ndx];
}

std::string
Triangle :: infoString
	( std::string const & title
	) const
{
	std::ostringstream oss;
	if (! title.empty())
	{
		oss << title << std::endl;
	}
	if (isValid())
	{
		oss 
			<< dat::infoString(theVerts[0])
			<< '\n'
			<< dat::infoString(theVerts[1])
			<< '\n'
			<< dat::infoString(theVerts[2])
			;
	}
	else
	{
		oss << " <null>";
	}
	return oss.str();
}

}

