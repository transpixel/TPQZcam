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

		cube.cpp
		intersect.cpp
		io.cpp
		LineSeg.cpp
		mesh.cpp
		Plane.cpp
		ProbRay.cpp
		Ray.cpp
		si.cpp
		Triangle.cpp
		VertGangle.cpp
		Wedge.cpp

		cube.h
		geo.h
		intersect.h
		io.h
		LineSeg.h
		mesh.h
		Plane.h
		ProbRay.h
		Ray.h
		si.h
		sphere.h
		stats.h
		Triangle.h
		Tube.h
		VertGangle.h
		Wedge.h
		xform.h

		cube.inl
		LineSeg.inl
		mesh.inl
		ProbRay.inl
		Ray.inl
		si.inl
		sphere.inl
		stats.inl
		VertGangle.inl
		Wedge.inl
		xform.inl

	)

