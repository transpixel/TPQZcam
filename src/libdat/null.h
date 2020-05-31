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

#ifndef dat_null_INCL_
#define dat_null_INCL_

/*! \file
\brief Declarations for dat::null
*/


//#include "libdat/template.h"
//#include "libdat/types.h"

#include <array>
#include <cmath>
#include <limits>
#include <type_traits>


namespace dat
{
	//
	// Type-specific null values
	//

	// (is_arithmetic) && (is_integral) && (is_signed) : limits::lowest()
	// (is_arithmetic) && (is_integral) && (! is_signed) : limits::max()
	// (is_arithmetic) && (is_floating_point) : limits::quiet_NaN()
	// (is_class) && specialization = null() : use null() return value
	// (is_class) && specialization = std::array : use data type nulls


	//
	// Arithmetic Integral Signed
	//

	//! Null for (YesArithmetic && YesIntegral && YesSigned)
	template <typename Type>
	typename std::enable_if
		< ( // std::is_arithmetic<Type>::value // implied by is_signed
		  // &&
		  	std::is_integral<Type>::value
		  &&
		  	std::is_signed<Type>::value
		  )
		, Type
		>::type
	nullValue
		()
	{
		return std::numeric_limits<Type>::lowest();
	}

	//! Check validity for (YesArithmetic && YesIntegral && YesSigned)
	template <typename Type>
	typename std::enable_if
		< ( // std::is_arithmetic<Type>::value // implied by is_signed
		  // &&
		  	std::is_integral<Type>::value
		  &&
		  	std::is_signed<Type>::value
		  )
		, bool
		>::type
	isValid
		( Type const & value
		)
	{
		return (nullValue<Type>() != value);
	}


	//
	// Arithmetic Integral Unsigned
	//

	//! Null for (YesArithmetic && YesIntegral && NotSigned)
	template <typename Type>
	typename std::enable_if
		< ( // std::is_arithmetic<Type>::value // implied by is_unsigned
		  // &&
		  	std::is_integral<Type>::value
		  &&
		  	std::is_unsigned<Type>::value
		  )
		, Type
		>::type
	nullValue
		()
	{
		return std::numeric_limits<Type>::max();
	}

	//! Check validity for (YesArithmetic && YesIntegral && NotSigned)
	template <typename Type>
	typename std::enable_if
		< ( //std::is_arithmetic<Type>::value // implied by is_unsigned
		  //&&
		  	std::is_integral<Type>::value
		  &&
		  	std::is_unsigned<Type>::value
		  )
		, bool
		>::type
	isValid
		( Type const & value
		)
	{
		return (nullValue<Type>() != value);
	}

	//
	// Arithmetic Floats
	//

	//! Null for (YesArithmetic && NotIntegral
	template <typename Type>
	typename std::enable_if
		< ( // std::is_arithmetic<Type>::value // implied by is_iec559
		  //&&
		  //	(! std::is_integral<Type>::value) // implied by iec559
		  // &&
		  	std::numeric_limits<Type>::is_iec559  // has quiet_NaN
		  )
		, Type
		>::type
	nullValue
		()
	{
		return std::numeric_limits<Type>::quiet_NaN();
	}

	//! Check validity for (YesArithmetic && NotIntegral
	template <typename Type>
	typename std::enable_if
		< ( // std::is_arithmetic<Type>::value // implied by is_iec559
		  // &&
		  //	(! std::is_integral<Type>::value) // implied by iec559
		  //&&
		  	std::numeric_limits<Type>::is_iec559  // has quiet_NaN
		  )
		, bool
		>::type
	isValid
		( Type const & value
		)
	{
		bool okay(0. == value); // allow zero
		if (! okay)
		{
			okay = (! std::isnan(value));
		}
		return okay;
	}

	//
	// General std::array types
	//

	using ArrayIS2_t = std::array<int, 2u>;
	using ArrayD2_t = std::array<double, 2u>;
	using ArrayD3_t = std::array<double, 3u>;

	// <int, 2u>

	//! Null for std::array<int, 2u>
	template <typename Type>
	typename std::enable_if
		< ( std::is_same<Type, ArrayIS2_t>::value
		  )
		, Type
		>::type
	nullValue
		()
	{
		return ArrayIS2_t{ nullValue<ArrayIS2_t::value_type>() };
	}

	//! Check validity for std::array<int, 2u>
	template <typename Type>
	typename std::enable_if
		< ( std::is_same<Type, ArrayIS2_t>::value
		  )
		, bool
		>::type
	isValid
		( Type const & value
		)
	{
		return isValid(value[0]);
	}

	// <double, 2u>

	//! Null for std::array<double, 2u>
	template <typename Type>
	typename std::enable_if
		< ( std::is_same<Type, ArrayD2_t>::value
		  )
		, Type
		>::type
	nullValue
		()
	{
		return ArrayD2_t{ nullValue<ArrayD2_t::value_type>() };
	}

	//! Check validity for std::array<double,2u>
	template <typename Type>
	typename std::enable_if
		< ( std::is_same<Type, ArrayD2_t>::value
		  )
		, bool
		>::type
	isValid
		( Type const & value
		)
	{
		return isValid(value[0]);
	}

	// <double, 3u>

	//! Null for std::array<double, 3u>
	template <typename Type>
	typename std::enable_if
		< ( std::is_same<Type, ArrayD3_t>::value
		  )
		, Type
		>::type
	nullValue
		()
	{
		return ArrayD3_t{ nullValue<ArrayD3_t::value_type>() };
	}

	//! Check validity for std::array<double,3u>
	template <typename Type>
	typename std::enable_if
		< ( std::is_same<Type, ArrayD3_t>::value
		  )
		, bool
		>::type
	isValid
		( Type const & value
		)
	{
		return isValid(value[0]);
	}


	//
	// Custom Type with ::null() member function
	//

	//! SFINAE test for ::null() member function
	template <typename Type>
	class has_null
	{
		// define structures of two different sizes (to test in enum below)
		using Yes = char; //!< Initializes data when member function IS present
		using Not = double; //!< Init data when member function NOT present

		//! Attempt to define function that should fail if no ::null
		template <typename AnyType> static Yes data( decltype(&AnyType::null) );
		//! Fall back function has return type of two bytes
		template <typename AnyType> static Not data( ... );

	public:

		//! Set bool 'value' depending on which member definition is created
		// data<Type>(0) will be of type Yes or type Not
		// in which case the size comparision will be True or False resp.
		static bool const value = (sizeof(data<Type>(0)) == sizeof(Yes));
	};

	//! Custom class return Type::null()
	template <typename Type>
	typename std::enable_if
		< ( std::is_class<Type>::value
		  &&
			has_null<Type>::value
		  )
		, Type
		>::type
	nullValue
		()
	{
		return Type::null();
	}

	//! Custom class isValid() test
	template <typename Type>
	typename std::enable_if
		< ( std::is_class<Type>::value
		  &&
			has_null<Type>::value
		  )
		, bool
		>::type
	isValid
		( Type const & type
		)
	{
		return {};
	}











/*
	//! Fall-through template - call member function
	template
		< typename CType
		, EnableIf
			< dat::has::null<CType, CType()> >...
		>
	inline
	CType
	nullValue
		()
	{
		return CType::null();
	}

	//
	// Data validity
	//

	template <typename FType, EnableIf< std::is_floating_point<FType> >...>
	constexpr //inline
	FType
	nullValue
		()
	{
		return std::numeric_limits<FType>::quiet_NaN();
	}

	template <typename IType, EnableIf< std::is_integral<IType> >...>
	constexpr //inline
	IType
	nullValue
		()
	{
		// what else to do for integral types?
		return std::numeric_limits<IType>::max();
	}

//	template <typename FType, EnableIf< std::is_same<FType, f16_t> >...>
//	constexpr //inline
//	FType
//	nullValue
//		()
//	{
//		return std::numeric_limits<FType>::quiet_NaN();
//	}

	template <typename AType, EnableIf< std::is_same<AType, RowCol> >...>
	constexpr //inline
	AType
	nullValue
		()
	{
		return RowCol
			{ std::numeric_limits<RowCol::value_type>::max()
			, std::numeric_limits<RowCol::value_type>::max()
			};
	}

	template <typename AType, EnableIf< std::is_same<AType, Spot> >...>
	constexpr //inline
	AType
	nullValue
		()
	{
		return Spot
			{ std::numeric_limits<Spot::value_type>::quiet_NaN()
			, std::numeric_limits<Spot::value_type>::quiet_NaN()
			};
	}



	//! Always true - (for compatibliity with other templates)
	constexpr //inline
	bool
	isValid
		( bool const & // value
		)
	{
		return true;
	}

	//! True if value is not one of (subnormal, infinite, NaN) zero is okay
	template <typename FType, EnableIf< std::is_floating_point<FType> >...>
	inline
	bool
	isValid
		( FType const & value
		);

	//! True if value is not one of (max possible)
	template <typename IType, EnableIf< std::is_integral<IType> >...>
	inline
	bool
	isValid
		( IType const & value
		);

	//! True if both members are valid
	template <typename Type1, typename Type2>
	inline
	bool
	isValid
		( std::pair<Type1, Type2> const & apair
		);

	//! Specialization
	inline
	bool
	isValid
		( std::string const & value
		);

	//! Fall-through template - call member function
	template
		< typename CType
		, EnableIf
			< dat::has::isValid<CType, bool()> >...
		>
	inline
	bool
	isValid
		( CType const & arg
		)
	{
		return arg.isValid();
	}
*/

}

// Inline definitions
// #include "libdat/null.inl"

#endif // dat_null_INCL_

