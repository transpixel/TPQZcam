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
		Extents.cpp
		ExtentsIterator.cpp
		IndexIterator.cpp
		iter.cpp
		Jump.cpp
		KeyedValues.cpp
		layout.cpp
		NdxBegEnd.cpp
		QuantumFrac.cpp
		SpotX.cpp
		SubExtents.cpp

		algorithm.h
		Area.h
		array.h
		BestOf.h
		bit.h
		cast.h
		compare.h
		dat.h
		discrete.h
		docIterExample.h
		Extents.h
		ExtentsIterator.h
		grid.h
		IndexIterator.h
		info.h
		io.h
		iter.h
		Jump.h
		KeyedValues.h
		Latice.h
		layout.h
		limits.h
		MinMax.h
		NdxBegEnd.h
		Offset2D.h
		ops.h
		QuantumFrac.h
		quantum.h
		random.h
		Range.h
		Region.h
		RowCol.h
		Spot.h
		SpotX.h
		SubExtents.h
		template.h
		types.h
		validity.h
		Volume.h
		xform.h

		algorithm.inl
		array.inl
		BestOf.inl
		compare.inl
		discrete.inl
		Extents.inl
		ExtentsIterator.inl
		grid.inl
		IndexIterator.inl
		info.inl
		io.inl
		iter.inl
		Jump.inl
		Latice.inl
		MinMax.inl
		ops.inl
		QuantumFrac.inl
		quantum.inl
		random.inl
		Range.inl
		Region.inl
		RowCol.inl
		SpotX.inl
		SubExtents.inl
		validity.inl

		)

