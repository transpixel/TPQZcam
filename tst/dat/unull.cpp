//
//
// MIT License
//
// Copyright (c) 2020 Stellacore Corporation.
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
\brief  This file contains unit test for dat::null
*/


#include "libdat/null.h"

#include "libio/stream.h"

#include <array>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>


namespace
{

//! Check for signed integral types
std::string
dat_null_test0
	()
{
	std::ostringstream oss;

	{ // char
		char const gotNull{ dat::nullValue<char>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of char validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // short
		short const gotNull{ dat::nullValue<short>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of short validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // int
		int const gotNull{ dat::nullValue<int>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of int validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // long
		long const gotNull{ dat::nullValue<long>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of long validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // long long
		long long const gotNull{ dat::nullValue<long long>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of long long validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}

	return oss.str();
}

//! Check for UNsigned integral types
std::string
dat_null_test1
	()
{
	std::ostringstream oss;

	{ // unsigned char
		unsigned char const gotNull{ dat::nullValue<unsigned char>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of unsigned char validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // unsigned short
		unsigned short const gotNull{ dat::nullValue<unsigned short>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of unsigned short validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // unsigned int
		unsigned int const gotNull{ dat::nullValue<unsigned int>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of unsigned int validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // unsigned long
		unsigned long const gotNull{ dat::nullValue<unsigned long>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of unsigned long validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // unsigned long long
		unsigned long long const gotNull
			{ dat::nullValue<unsigned long long>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of unsigned long long validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}

	// common special types

	{ // std::uint8_t
		std::uint8_t const gotNull{ dat::nullValue<std::uint8_t>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of std::uint8_t validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // std::uint16_t
		std::uint16_t const gotNull{ dat::nullValue<std::uint16_t>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of std::uint16_t validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // std::uint32_t
		std::uint32_t const gotNull{ dat::nullValue<std::uint32_t>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of std::uint16_t validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // std::size_t
		std::size_t const gotNull{ dat::nullValue<std::size_t>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of std::size_t validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}

	return oss.str();
}

//! Check for floating point types
std::string
dat_null_test2
	()
{
	std::ostringstream oss;

	{ // float
		float const gotNull{ dat::nullValue<float>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of float validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // double
		double const gotNull{ dat::nullValue<double>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of double validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}
	{ // long double
		long double const gotNull{ dat::nullValue<long double>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of long double validity test" << std::endl;
			oss << "got nullValue: " << gotNull << std::endl;
		}
	}

	return oss.str();
}

//! Check for various std::array<> types
std::string
dat_null_test3
	()
{
	std::ostringstream oss;

	using ArraySiz2 = std::array<std::size_t, 2u>;
	using ArrayDub2 = std::array<double, 2u>;
	using ArrayDub3 = std::array<double, 3u>;

	{ // ArraySiz2
		ArraySiz2 const gotNull{ dat::nullValue<ArraySiz2>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of ArraySiz2 validity test" << std::endl;
			oss << "got nullValue[0]: " << gotNull[0] << std::endl;
		}
	}
	{ // ArrayDub2
		ArrayDub2 const gotNull{ dat::nullValue<ArrayDub2>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of ArrayDub2 validity test" << std::endl;
			oss << "got nullValue[0]: " << gotNull[0] << std::endl;
		}
	}
	{ // ArrayDub3
		ArrayDub3 const gotNull{ dat::nullValue<ArrayDub3>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of ArrayDub3 validity test" << std::endl;
			oss << "got nullValue[0]: " << gotNull[0] << std::endl;
		}
	}

	return oss.str();
}

namespace
{
	struct Custom
	{
		static
		Custom
		null
			()
		{
			return {};
		}

		bool
		isValid
			() const
		{
			return {};
		}

	};
}

//! Check for custom class member implementation
std::string
dat_null_test4
	()
{
	std::ostringstream oss;

	{ // Custom
		Custom const gotNull{ dat::nullValue<Custom>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of Custom validity test" << std::endl;
		}
	}

	return oss.str();
}

//! Check for pair of values
std::string
dat_null_test5
	()
{
	std::ostringstream oss;

	using IDPair = std::pair<int, double>;
	{ // IDPair
		IDPair const gotNull{ dat::nullValue<int>(), dat::nullValue<double>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of IDPair validity test" << std::endl;
		}
	}

	// Example of keyvalue pairing
	using KeyVal = std::pair<std::string, Custom>;
	{ // KeyVal
		KeyVal const gotNull{ std::string{}, dat::nullValue<Custom>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of KeyVal validity test" << std::endl;
		}
	}

	return oss.str();
}

//! Check for particularly useful valid cases
std::string
dat_null_test6
	()
{
	std::ostringstream oss;

	if (! dat::isValid(true))
	{
		oss << "Failure of valid 'true' test" << std::endl;
	}
	if (! dat::isValid(false))
	{
		oss << "Failure of valid 'false' test" << std::endl;
	}

	if (! dat::isValid(char{0}))
	{
		oss << "Failure of valid char{0} test" << std::endl;
	}
	if (! dat::isValid(double{0.}))
	{
		oss << "Failure of valid double{0} test" << std::endl;
	}

	if (! dat::isValid(std::numeric_limits<double>::infinity()))
	{
		oss << "Failure of valid double{infinity} test" << std::endl;
	}


	return oss.str();
}


}

//! Unit test for dat::null
int
main
	( int const /*argc*/
	, char const * const * /*argv*/
	)
{
	std::ostringstream oss;

	// run tests
	oss << dat_null_test0();
	oss << dat_null_test1();
	oss << dat_null_test2();
	oss << dat_null_test3();
	oss << dat_null_test4();
	oss << dat_null_test5();
	oss << dat_null_test6();

	// check/report results
	std::string const errMessages(oss.str());
	if (! errMessages.empty())
	{
		io::err() << errMessages << std::endl;
		return 1;
	}
	return 0;
}
