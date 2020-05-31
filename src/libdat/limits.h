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

#ifndef dat_limits_INCL_
#define dat_limits_INCL_

/*! \file
\brief Declarations for dat::limits
*/


#include "libdat/template.h"

#include <limits>


namespace dat
{
// Items related to critical values of data

	//! A reasonably "small" value for general algorithm/code verification.
	template <typename Type>
	inline
	constexpr
	typename std::enable_if
		< std::is_floating_point<Type>::value
		, Type
		>::type
	smallValue
		()
	{
		return (256. * std::numeric_limits<Type>::epsilon());
	}

	//! For integral types - assume "small" is zero
	template <typename Type>
	inline
	constexpr
	typename std::enable_if
		< std::is_integral<Type>::value
		, Type
		>::type
	smallValue
		()
	{
		return static_cast<Type>(0);
	}

}

// Inline definitions
// #include "libdat/limits.inl"

#endif // dat_limits_INCL_

