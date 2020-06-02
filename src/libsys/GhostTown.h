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

#ifndef sys_GhostTown_INCL_
#define sys_GhostTown_INCL_

/*! \file
\brief Declarations for sys::GhostTown
*/


#include <mutex>
#include <set>


namespace sys
{

/*! \brief Mutex guarded set of identifiers.
*/
class GhostTown
{
	//! Guarded access
	std::mutex theMutex{};

	//! Arbitrary identifiers
	std::set<std::size_t> theIds{};

private: // disable

	//! Disable implicit copy and assignment
	GhostTown(GhostTown const &) = delete;
	GhostTown & operator=(GhostTown const &) = delete;

public: // methods

	//! Construct with empty collection of Ids.
	GhostTown
		() = default;

	//! (Atomically) add ghost Id to set
	inline
	void
	createGhost
		( std::size_t const & id
		);

	//! Copy of all current ghost IDs
	inline
	std::set<std::size_t>
	allGhosts
		();

	//! (Atomically) erase ghost Id to set
	inline
	void
	removeGhost
		( std::size_t const & id
		);

}; // GhostTown

} // sys

// Inline definitions
#include "libsys/GhostTown.inl"

#endif // sys_GhostTown_INCL_

