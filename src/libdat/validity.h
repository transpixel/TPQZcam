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

#ifndef dat_validity_INCL_
#define dat_validity_INCL_

/*! \file
\brief Declarations for dat::validity
*/


#include "libdat/null.h" // bulk of operations now implemented here

#include <cmath>
#include <functional>
#include <limits>
#include <string>
#include <type_traits>
#include <utility>


namespace dat
{
// functions to manage data validity

	// most operations in "libdat/null.h" now

	//! Invalid float
	constexpr float badFlt
		{ std::numeric_limits<float>::quiet_NaN() };

	//! Invalid double
	constexpr double badDub
		{ std::numeric_limits<double>::quiet_NaN() };

	//! Simple functor returning null value
	template <typename OutType, typename InType>
	constexpr //inline
	std::function<OutType(InType const &)>
	nullFunc
		()
	{
		return ( [] (InType const &) { return nullValue<OutType>(); } );
	}

}

// Inline definitions
// #include "libdat/validity.inl"

#endif // dat_validity_INCL_

