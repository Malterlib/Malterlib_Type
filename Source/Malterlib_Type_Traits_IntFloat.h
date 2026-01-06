// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include "Malterlib_Type_Traits_Qualifiers.h"
#include <Mib/Core/EnableIf>

namespace NMib::NTraits
{
	namespace NPrivate
	{
		template <typename t_CType0>
		struct TCIsInteger
		{
			constexpr static bool mc_bValue = std::is_integral_v<t_CType0>;
		};
	}

	template <typename t_CType0>
	concept cIsInteger = NPrivate::TCIsInteger<TCRemoveQualifiers<t_CType0>>::mc_bValue;

	namespace NPrivate
	{
		template <typename t_CType0>
		struct TCIsFloat
		{
			constexpr static bool mc_bValue = std::is_floating_point_v<t_CType0>;
		};
	}

	template <typename t_CType0>
	concept cIsFloat = NPrivate::TCIsFloat<TCRemoveQualifiers<t_CType0>>::mc_bValue;

	namespace NPrivate
	{
		template <typename t_CType0>
		struct TCIsFundamental
		{
			constexpr static bool mc_bValue = std::is_fundamental_v<t_CType0>;
		};
	}

	template <typename t_CType0>
	concept cIsFundamental = NPrivate::TCIsFundamental<TCRemoveQualifiers<t_CType0>>::mc_bValue;

	namespace NPrivate
	{
		template <typename t_CType0>
		struct TCIsArithmetic
		{
			constexpr static bool mc_bValue = std::is_arithmetic_v<t_CType0> || NTraits::cIsFloat<t_CType0> || NTraits::cIsInteger<t_CType0>;
		};
	}

	template <typename t_CType0>
	concept cIsArithmetic = NPrivate::TCIsArithmetic<TCRemoveQualifiers<t_CType0>>::mc_bValue;

	namespace NPrivate
	{
		template <typename t_CType0>
		struct TCIsCompound
		{
			constexpr static bool mc_bValue = std::is_compound_v<t_CType0>;
		};
	}

	template <typename t_CType0>
	concept cIsCompound = NPrivate::TCIsCompound<TCRemoveQualifiers<t_CType0>>::mc_bValue;

	template <typename t_CType>
	concept cIsScalar = std::is_scalar_v<t_CType>;

	// By size

	namespace NPrivate
	{
		template <typename t_CType0, typename t_CType1>
		struct TCLargestType
		{
			using CType = TCConditional<(sizeof(t_CType0) >= sizeof(t_CType1)), t_CType0, t_CType1>;
		};

		template <typename t_CType0, typename t_CType1>
		struct TCSmallestType
		{
			using CType = TCConditional<(sizeof(t_CType0) <= sizeof(t_CType1)), t_CType0, t_CType1>;
		};
	}

	template <typename t_CType0, typename t_CType1>
	using TCLargestType = typename NPrivate::TCLargestType<t_CType0, t_CType1>::CType;

	template <typename t_CType0, typename t_CType1>
	using TCSmallestType = typename NPrivate::TCSmallestType<t_CType0, t_CType1>::CType;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Signed/Unsigned																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CType>
		struct TCIsSigned
		{
			constexpr static bool mc_bValue = std::is_signed_v<t_CType>;
		};

		template <typename t_CType>
		struct TCUnsigned
		{
			using CType = t_CType;
		};

		template <typename t_CType>
		struct TCSigned
		{
			using CType = t_CType;
		};
	}

	template <typename t_CType>
	concept cIsSigned = NPrivate::TCIsSigned<TCRemoveQualifiers<t_CType>>::mc_bValue;

	template <typename t_CType>
	using TCUnsigned = TCCopyQualifiers<t_CType, typename NPrivate::TCUnsigned<TCRemoveQualifiers<t_CType>>::CType>;

	template <typename t_CType>
	using TCSigned = TCCopyQualifiers<t_CType, typename NPrivate::TCSigned<TCRemoveQualifiers<t_CType>>::CType>;

#	define DMibTraitsImplementSigned(d_Signed, d_Unsigned) \
		template <> \
		struct NMib::NTraits::NPrivate::TCSigned<d_Unsigned>\
		{\
			using CType = d_Signed;\
		};

#	define DMibTraitsImplementUnsigned(d_Signed, d_Unsigned) \
		template <>	\
		struct NMib::NTraits::NPrivate::TCUnsigned<d_Signed>\
		{\
			using CType = d_Unsigned;\
		};

#	define DMibTraitsImplementIsSigned(d_Signed) \
		template <> \
		struct NMib::NTraits::NPrivate::TCIsSigned<d_Signed>\
		{\
			constexpr static bool mc_bValue = true; \
		};

#	define DMibTraitsImplementSignedPair(d_Signed, d_Unsigned) DMibTraitsImplementSigned(d_Signed, d_Unsigned) \
	DMibTraitsImplementUnsigned(d_Signed, d_Unsigned) \
	DMibTraitsImplementIsSigned(d_Signed)

#	if defined(DMibPCanDo_int8) && defined(DMibPCanDo_uint8)
		DMibTraitsImplementSignedPair(int8, uint8);
#	endif
#	if defined(DMibPCanDo_int16) && defined(DMibPCanDo_uint16)
		DMibTraitsImplementSignedPair(int16, uint16);
#	endif
#	if defined(DMibPCanDo_int32) && defined(DMibPCanDo_uint32)
		DMibTraitsImplementSignedPair(int32, uint32);
#	endif
#	if defined(DMibPCanDo_int64) && defined(DMibPCanDo_uint64)
		DMibTraitsImplementSignedPair(int64, uint64);
#	endif
#	if defined(DMibPCanDo_int80) && defined(DMibPCanDo_uint80)
		DMibTraitsImplementSignedPair(int80, uint80);
#	endif
#	if defined(DMibPCanDo_int96) && defined(DMibPCanDo_uint96)
		DMibTraitsImplementSignedPair(int96, uint96);
#	endif
#	if defined(DMibPCanDo_int128) && defined(DMibPCanDo_uint128)
		DMibTraitsImplementSignedPair(int128, uint128);
#	endif
#	if defined(DMibPCanDo_int160) && defined(DMibPCanDo_uint160)
		DMibTraitsImplementSignedPair(int160, uint160);
#	endif
#	if defined(DMibPCanDo_int192) && defined(DMibPCanDo_uint192)
		DMibTraitsImplementSignedPair(int192, uint192);
#	endif
#	if defined(DMibPCanDo_int256) && defined(DMibPCanDo_uint256)
		DMibTraitsImplementSignedPair(int256, uint256);
#	endif
#	if defined(DMibPCanDo_int320) && defined(DMibPCanDo_uint320)
		DMibTraitsImplementSignedPair(int320, uint320);
#	endif
#	if defined(DMibPCanDo_int384) && defined(DMibPCanDo_uint384)
		DMibTraitsImplementSignedPair(int384, uint384);
#	endif
#	if defined(DMibPCanDo_int512) && defined(DMibPCanDo_uint512)
		DMibTraitsImplementSignedPair(int512, uint512);
#	endif
#	if defined(DMibPCanDo_int1024) && defined(DMibPCanDo_uint1024)
		DMibTraitsImplementSignedPair(int1024, uint1024);
#	endif
#	if defined(DMibPCanDo_int2048) && defined(DMibPCanDo_uint2048)
		DMibTraitsImplementSignedPair(int2048, uint2048);
#	endif
#	if defined(DMibPCanDo_int4096) && defined(DMibPCanDo_uint4096)
		DMibTraitsImplementSignedPair(int4096, uint4096);
#	endif
#	if defined(DMibPCanDo_int8192) && defined(DMibPCanDo_uint8192)
		DMibTraitsImplementSignedPair(int8192, uint8192);
#	endif
#	if defined(DMibPCanDo_int16384) && defined(DMibPCanDo_uint16384)
		DMibTraitsImplementSignedPair(int16384, uint16384);
#	endif

#	if defined(DMibPCanDo_uint8)
		DMibTraitsImplementUnsigned(bool, uint8);
#	endif

#	ifdef DMibPUniqueType_mint
		DMibTraitsImplementSigned(smint, mint);
#	endif

#	ifdef DMibPUniqueType_smint
		DMibTraitsImplementUnsigned(smint, mint);
		DMibTraitsImplementIsSigned(smint);
#	endif

#	ifdef DMibPUniqueType_uint
		DMibTraitsImplementSigned(int, unsigned int);
#	endif

#	ifdef DMibPUniqueType_int
		DMibTraitsImplementUnsigned(int, unsigned int);
		DMibTraitsImplementIsSigned(int);
#	endif

#	ifdef DMibPUniqueType_uaint
		DMibTraitsImplementSigned(aint, uaint);
#	endif

#	ifdef DMibPUniqueType_aint
		DMibTraitsImplementUnsigned(aint, uaint);
		DMibTraitsImplementIsSigned(aint);
#	endif

#	ifdef DMibPUniqueType_ch8
#		ifdef DMibPSignedType_ch8
			DMibTraitsImplementUnsigned(ch8, uint8);
			DMibTraitsImplementIsSigned(ch8);
#		else
			DMibTraitsImplementSigned(int8, ch8);
#		endif
#	endif

#	ifdef DMibPUniqueType_ch16
#		ifdef DMibPSignedType_ch16
			DMibTraitsImplementUnsigned(ch16, uint16);
			DMibTraitsImplementIsSigned(ch16);
#		else
			DMibTraitsImplementSigned(int16, ch16);
#		endif
#	endif

#	ifdef DMibPUniqueType_ch32
#		ifdef DMibPSignedType_ch32
			DMibTraitsImplementUnsigned(ch32, uint32);
			DMibTraitsImplementIsSigned(ch32);
#		else
			DMibTraitsImplementSigned(int32, ch32);
#		endif
#	endif

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Larger/smaller type																				|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CType>
		class TCLargerType
		{
		public:
			using CType = t_CType; // Default to no larger type exists
		};

		template <typename t_CType>
		class TCSmallerType
		{
		public:
			using CType = t_CType; // Default to no smaller type exists
		};
	}

	template <typename t_CType>
	using TCLargerType = TCCopyQualifiers<t_CType, typename NPrivate::TCLargerType<TCRemoveQualifiers<t_CType>>::CType>;

	template <typename t_CType>
	using TCSmallerType = TCCopyQualifiers<t_CType, typename NPrivate::TCSmallerType<TCRemoveQualifiers<t_CType>>::CType>;

#	define DMibTraitsImplementSizeSmaller(_Smaller, _Larger) \
		template <>	\
		struct NMib::NTraits::NPrivate::TCSmallerType<_Larger> \
		{\
			using CType = _Smaller; \
		};

#	define DMibTraitsImplementSizeLarger(_Smaller, _Larger) \
		template <>	\
		struct NMib::NTraits::NPrivate::TCLargerType<_Smaller> \
		{\
			using CType = _Larger; \
		};


#	define DMibTraitsImplementSizePair(_Smaller, _Larger)  DMibTraitsImplementSizeSmaller(_Smaller, _Larger) DMibTraitsImplementSizeLarger(_Smaller, _Larger)

#	if defined(DMibPCanDo_uint8) && defined(DMibPCanDo_uint16)
		DMibTraitsImplementSizePair(uint8, uint16);
#	endif
#	if defined(DMibPCanDo_uint16) && defined(DMibPCanDo_uint32)
		DMibTraitsImplementSizePair(uint16, uint32);
#	endif
#	if defined(DMibPCanDo_uint32) && defined(DMibPCanDo_uint64)
		DMibTraitsImplementSizePair(uint32, uint64);
#	endif
#	if defined(DMibPCanDo_uint64) && defined(DMibPCanDo_uint128)
		DMibTraitsImplementSizePair(uint64, uint128);
#	endif
#	if defined(DMibPCanDo_uint80) && defined(DMibPCanDo_uint160)
		DMibTraitsImplementSizePair(uint80, uint160);
#	endif
#	if defined(DMibPCanDo_uint96) && defined(DMibPCanDo_uint192)
		DMibTraitsImplementSizePair(uint96, uint192);
#	endif
#	if defined(DMibPCanDo_uint128) && defined(DMibPCanDo_uint256)
		DMibTraitsImplementSizePair(uint128, uint256);
#	endif
#	if defined(DMibPCanDo_uint256) && defined(DMibPCanDo_uint512)
		DMibTraitsImplementSizePair(uint256, uint512);
#	endif
#	if defined(DMibPCanDo_uint512) && defined(DMibPCanDo_uint1024)
		DMibTraitsImplementSizePair(uint512, uint1024);
#	endif
#	if defined(DMibPCanDo_uint1024) && defined(DMibPCanDo_uint2048)
		DMibTraitsImplementSizePair(uint1024, uint2048);
#	endif
#	if defined(DMibPCanDo_uint2048) && defined(DMibPCanDo_uint4096)
		DMibTraitsImplementSizePair(uint2048, uint4096);
#	endif
#	if defined(DMibPCanDo_uint4096) && defined(DMibPCanDo_uint8192)
		DMibTraitsImplementSizePair(uint4096, uint8192);
#	endif
#	if defined(DMibPCanDo_uint8192) && defined(DMibPCanDo_uint16384)
		DMibTraitsImplementSizePair(uint8192, uint16384);
#	endif


#	if defined(DMibPCanDo_int8) && defined(DMibPCanDo_int16)
		DMibTraitsImplementSizePair(int8, int16);
#	endif
#	if defined(DMibPCanDo_int16) && defined(DMibPCanDo_int32)
		DMibTraitsImplementSizePair(int16, int32);
#	endif
#	if defined(DMibPCanDo_int32) && defined(DMibPCanDo_int64)
		DMibTraitsImplementSizePair(int32, int64);
#	endif
#	if defined(DMibPCanDo_int64) && defined(DMibPCanDo_int128)
		DMibTraitsImplementSizePair(int64, int128);
#	endif
#	if defined(DMibPCanDo_int80) && defined(DMibPCanDo_int160)
		DMibTraitsImplementSizePair(int80, int160);
#	endif
#	if defined(DMibPCanDo_int96) && defined(DMibPCanDo_int192)
		DMibTraitsImplementSizePair(int96, int192);
#	endif
#	if defined(DMibPCanDo_int128) && defined(DMibPCanDo_int256)
		DMibTraitsImplementSizePair(int128, int256);
#	endif
#	if defined(DMibPCanDo_int160) && defined(DMibPCanDo_int320)
		DMibTraitsImplementSizePair(int160, int320);
#	endif
#	if defined(DMibPCanDo_int192) && defined(DMibPCanDo_int384)
		DMibTraitsImplementSizePair(int192, int384);
#	endif
#	if defined(DMibPCanDo_int256) && defined(DMibPCanDo_int512)
		DMibTraitsImplementSizePair(int256, int512);
#	endif
#	if defined(DMibPCanDo_int512) && defined(DMibPCanDo_int1024)
		DMibTraitsImplementSizePair(int512, int1024);
#	endif
#	if defined(DMibPCanDo_int1024) && defined(DMibPCanDo_int2048)
		DMibTraitsImplementSizePair(int1024, int2048);
#	endif
#	if defined(DMibPCanDo_int2048) && defined(DMibPCanDo_int4096)
		DMibTraitsImplementSizePair(int2048, int4096);
#	endif
#	if defined(DMibPCanDo_int4096) && defined(DMibPCanDo_int8192)
		DMibTraitsImplementSizePair(int4096, int8192);
#	endif
#	if defined(DMibPCanDo_int8192) && defined(DMibPCanDo_int16384)
		DMibTraitsImplementSizePair(int8192, int16384);
#	endif


#	ifdef DMibPUniqueType_ch8
		DMibTraitsImplementSizeLarger(ch8, ch16);
#	endif
#	ifdef DMibPUniqueType_ch16
		DMibTraitsImplementSizeSmaller(ch8, ch16);
		DMibTraitsImplementSizeLarger(ch16, ch32);
#	endif

#	ifdef DMibPUniqueType_ch32
		DMibTraitsImplementSizeSmaller(ch16, ch32);
#		ifdef DMibPSignedType_ch32
			DMibTraitsImplementSizeLarger(ch32, int64);
#		else
			DMibTraitsImplementSizeLarger(ch32, uint64);
#		endif
#	endif

	// Integer from size

	namespace NPrivate
	{
		template <mint t_VariableSize, bool t_bFundamental>
		struct TCIntFromSize
		{
			using CType = void;
		};

		template <mint t_VariableSize, bool t_bFundamental>
		struct TCIntFromSizeLarger
		{
			using CType = typename TCIntFromSizeLarger<t_VariableSize + 1, t_bFundamental>::CType;
		};

		template <mint t_VariableSize, bool t_bFundamental>
		struct TCIntFromSizeSmaller
		{
			using CType = typename TCIntFromSizeSmaller<t_VariableSize - 1, t_bFundamental>::CType;
		};
	}

	template <mint t_VariableSize, bool t_bFundamental = false>
	using TCIntFromSize = typename NPrivate::TCIntFromSize<t_VariableSize, t_bFundamental>::CType;

	template <mint t_VariableSize, bool t_bFundamental = false>
	using TCIntFromSizeLarger = typename NPrivate::TCIntFromSizeLarger<t_VariableSize, t_bFundamental>::CType;

	template <mint t_VariableSize, bool t_bFundamental = false>
	using TCIntFromSizeSmaller = typename NPrivate::TCIntFromSizeSmaller<t_VariableSize, t_bFundamental>::CType;

#	define DMibTraitsImplementIntegerFromSize(d_Type) \
		template <>	\
		struct NMib::NTraits::NPrivate::TCIntFromSize<sizeof(d_Type), false>\
		{\
			using CType = d_Type;\
		};\
		template <>	\
		struct NMib::NTraits::NPrivate::TCIntFromSizeSmaller<sizeof(d_Type), false>\
		{\
			using CType = d_Type;\
		};\
		template <>	\
		struct NMib::NTraits::NPrivate::TCIntFromSizeLarger<sizeof(d_Type), false>\
		{\
			using CType = d_Type;\
		};

#	define DMibTraitsImplementIntegerFromSizeFundamental(d_Type) \
		template <>	\
		struct NMib::NTraits::NPrivate::TCIntFromSize<sizeof(d_Type), false>\
		{\
			using CType = d_Type;\
		};\
		template <>	\
		struct NMib::NTraits::NPrivate::TCIntFromSizeSmaller<sizeof(d_Type), false>\
		{\
			using CType = d_Type;\
		};\
		template <>	\
		struct NMib::NTraits::NPrivate::TCIntFromSizeLarger<sizeof(d_Type), false>\
		{\
			using CType = d_Type;\
		};\
		template <>	\
		struct NMib::NTraits::NPrivate::TCIntFromSize<sizeof(d_Type), true>\
		{\
			using CType = d_Type;\
		};\
		template <>	\
		struct NMib::NTraits::NPrivate::TCIntFromSizeSmaller<sizeof(d_Type), true>\
		{\
			using CType = d_Type;\
		};\
		template <>	\
		struct NMib::NTraits::NPrivate::TCIntFromSizeLarger<sizeof(d_Type), true>\
		{\
			using CType = d_Type;\
		};

#	if defined(DMibPCanDo_int8)
		DMibTraitsImplementIntegerFromSizeFundamental(int8);
#	endif
#	if defined(DMibPCanDo_int16)
		DMibTraitsImplementIntegerFromSizeFundamental(int16);
#	endif
#	if defined(DMibPCanDo_int32)
		DMibTraitsImplementIntegerFromSizeFundamental(int32);
#	endif
#	if defined(DMibPCanDo_int64)
		DMibTraitsImplementIntegerFromSizeFundamental(int64);
#	endif
#	if defined(DMibPCanDo_int80)
		DMibTraitsImplementIntegerFromSizeFundamental(int80);
#	endif
#	if defined(DMibPCanDo_int96)
		DMibTraitsImplementIntegerFromSizeFundamental(int96);
#	endif
#	if defined(DMibPCanDo_int128)
		DMibTraitsImplementIntegerFromSizeFundamental(int128);
#	endif
#	if defined(DMibPCanDo_int160)
		DMibTraitsImplementIntegerFromSizeFundamental(int160);
#	endif
#	if defined(DMibPCanDo_int192)
		DMibTraitsImplementIntegerFromSizeFundamental(int192);
#	endif
#	if defined(DMibPCanDo_int256)
		DMibTraitsImplementIntegerFromSizeFundamental(int256);
#	endif
#	if defined(DMibPCanDo_int320)
		DMibTraitsImplementIntegerFromSizeFundamental(int320);
#	endif
#	if defined(DMibPCanDo_int384)
		DMibTraitsImplementIntegerFromSizeFundamental(int384);
#	endif
#	if defined(DMibPCanDo_int512)
		DMibTraitsImplementIntegerFromSizeFundamental(int512);
#	endif
#	if defined(DMibPCanDo_int1024)
		DMibTraitsImplementIntegerFromSizeFundamental(int1024);
#	endif
#	if defined(DMibPCanDo_int2048)
		DMibTraitsImplementIntegerFromSizeFundamental(int2048);
#	endif
#	if defined(DMibPCanDo_int4096)
		DMibTraitsImplementIntegerFromSizeFundamental(int4096);
#	endif
#	if defined(DMibPCanDo_int8192)
		DMibTraitsImplementIntegerFromSizeFundamental(int8192);
#	endif
#	if defined(DMibPCanDo_int16384)
		DMibTraitsImplementIntegerFromSizeFundamental(int16384);
#	endif


	// Float from size

	namespace NPrivate
	{
		template <mint t_VariableSize>
		struct TCFloatFromSize
		{
			using CType = typename TCFloatFromSize<t_VariableSize + 1>::CType;
		};
	}

	template <mint t_VariableSize>
	using TCFloatFromSize = typename NPrivate::TCFloatFromSize<t_VariableSize>::CType;

#	define DMibTraitsImplementFloatFromSize(d_Type) \
		template <>	\
		struct NMib::NTraits::NPrivate::TCFloatFromSize<sizeof(typename d_Type::CUnsignedInteger)>\
		{\
			using CType = d_Type;\
		};
}
