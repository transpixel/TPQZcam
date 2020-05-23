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

		CdfForward.cpp
		CdfInverse.cpp
		Frac9.cpp
		Gauss.cpp
		Histogram.cpp
		pdf.cpp
		Remapper.cpp
		SampleEntropy.cpp
		SampleGen.cpp
		SampleStats.cpp
		Stats.cpp

		CdfForward.h
		CdfInverse.h
		distro.h
		Frac9.h
		Gauss.h
		Histogram.h
		histo.h
		io.h
		mean.h
		median.h
		pdf.h
		prob.h
		Remapper.h
		SampleEntropy.h
		SampleGen.h
		SampleStats.h
		Stats.h

		CdfForward.inl
		CdfInverse.inl
		distro.inl
		Frac9.inl
		Histogram.inl
		histo.inl
		io.inl
		mean.inl
		median.inl
		pdf.inl
		Remapper.inl
		SampleEntropy.inl
		SampleGen.inl
		SampleStats.inl
		Stats.inl

	)

