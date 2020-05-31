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

//#include "libdat/info.h"
//#include "libdat/validity.h"
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

	using ArrayIS2 = std::array<int, 2u>;
	using ArrayID2 = std::array<double, 2u>;
	using ArrayD3 = std::array<double, 3u>;

	{ // ArrayIS2
		ArrayIS2 const gotNull{ dat::nullValue<ArrayIS2>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of ArrayIS2 validity test" << std::endl;
			oss << "got nullValue[0]: " << gotNull[0] << std::endl;
		}
	}
	{ // ArrayID2
		ArrayID2 const gotNull{ dat::nullValue<ArrayID2>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of ArrayID2 validity test" << std::endl;
			oss << "got nullValue[0]: " << gotNull[0] << std::endl;
		}
	}
	{ // ArrayD3
		ArrayD3 const gotNull{ dat::nullValue<ArrayD3>() };
		if (dat::isValid(gotNull))
		{
			oss << "Failure of ArrayD3 validity test" << std::endl;
			oss << "got nullValue[0]: " << gotNull[0] << std::endl;
		}
	}

oss << "Failure: implement std::array test!" << std::endl;
	return oss.str();
}

//! Check for custom class member implementation
std::string
dat_null_test4
	()
{
	std::ostringstream oss;

oss << "Failure: implement classmember test!" << std::endl;
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

	// check/report results
	std::string const errMessages(oss.str());
	if (! errMessages.empty())
	{
		io::err() << errMessages << std::endl;
		return 1;
	}
	return 0;
}
