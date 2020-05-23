#
#
# MIT License
#
# Copyright (c) 2017 Stellacore Corporation.
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject
# to the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
# KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
# BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
# AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
# IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
#

target_sources_local(
	${local_LIBTARGET}
	PRIVATE

		Aligner.cpp
		Conform.cpp
		constructs.cpp
		groups.cpp
		io.cpp
		Pose.cpp
		quantities.cpp
		Rigid.cpp
		Spin1d.cpp
		spin.cpp

		Aligner.h
		comparisons.h
		Conform.h
		constructs.h
		derivative.h
		functions.h
		ga.h
		groups.h
		io.h
		multivector.h
		operators.h
		Pose.h
		quantities.h
		Rigid.h
		Spin1d.h
		spin.h

		Aligner.inl
		comparisons.inl
		Conform.inl
		constructs.inl
		derivative.inl
		functions.inl
		ga.inl
		operators.inl
		Pose.inl
		quantities.inl
		Rigid.inl

	)

