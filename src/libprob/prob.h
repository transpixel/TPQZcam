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

#ifndef prob_prob_INCL_
#define prob_prob_INCL_

/*! \file
\brief Declarations for namespace prob
*/


#include <array>


/*! \brief Declarations and Definitions for libprob.

\par General Concept:

Probability and statistics operations useful for basic image processing.

\par Special Notes:

+ provides PDF and CDF structs/functions
+ support for histogram based information and operations


\par Example
\dontinclude testprob/uprob.cpp
\skip ExampleStart
\until ExampleEnd

*/
namespace prob
{
	//! Basic histogram - for 8-bit image intensity
	typedef std::array<std::size_t, 256u> Hist;

	//! Basic cumulative mass function - for 8-bit image intensity
	typedef std::array<double, 256u> CDF;

}

// Inline definitions
// #include "libprob/prob.inl"

#endif // prob_prob_INCL_

