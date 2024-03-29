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

#ifndef math_CircleTab_INCL_
#define math_CircleTab_INCL_

/*! \file
\brief Declarations for math::CircleTab
*/


#include "libmath/math.h"

#include <string>
#include <vector>

#include <iostream>


namespace math
{

/*! \brief Interpolation table for values associated with angles.

\par Example
\dontinclude testmath/uCircleTab.cpp
\skip ExampleStart
\until ExampleEnd
*/
template <typename Value>
class CircleTab
{

	std::vector<Value> theTabValues;
	double theIndexPerAngle;

public: // static methods

	//! Version of orig smoothed by window with halfSize
	inline
	static
	CircleTab
	smoothed
		( CircleTab const & orig
		, double const & filterHalfAngle //!< Smoothing filter *half* extent
		);

public: // methods

	//! default null constructor
	inline
	CircleTab
		();

	//! Create table with numNodes from irregularly spaced samples
	inline
	explicit
	CircleTab
		( std::vector<std::pair<double, Value> > const & avPairs
			//!< Angle/Value pairs - angle spacing may be irregular !
		, std::size_t const & numNodes
			//!< Interpolation table granularity
		);

	// copy constructor -- compiler provided
	// assignment operator -- compiler provided
	// destructor -- compiler provided

	//! Check if instance is valid
	inline
	bool
	isValid
		() const;

	//! Nearest value from linear interpolation table
	inline
	Value
	nearestTableValue
		( double const & principalAngle
		) const;

	//! Descriptive information about this instance.
	inline
	std::string
	infoString
		( std::string const & title = std::string()
		) const;

	//! Descriptive information about this instance.
	inline
	std::string
	infoStringContents
		( std::string const & title = std::string()
		, std::string const & fmt = std::string("%12.6f")
		) const;

};

}

// Inline definitions
#include "libmath/CircleTab.inl"

#endif // math_CircleTab_INCL_

