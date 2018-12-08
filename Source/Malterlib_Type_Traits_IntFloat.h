// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include "Malterlib_Type_Traits_Qualifiers.h"
#include <Mib/Core/EnableIf>

namespace NMib::NTraits
{
	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Size Of																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CType0, bint t_bZeroSize>
		class TCSizeOfHelper : public TCCompileTimeConstant<mint, sizeof(t_CType0)>
		{
		public:

		};

		template <typename t_CType0>
		class TCSizeOfHelper<t_CType0, 1> : public TCCompileTimeConstant<mint, 0>
		{
		public:

		};

		template <typename t_CType0>
		struct TCSizeOfHelper2 : public TCCompileTimeConstant<mint, TCSizeOfHelper<t_CType0, NTraits::TCIsFunction<typename NTraits::TCRemoveReference<t_CType0>::CType>::mc_Value || NTraits::TCIsVoid<t_CType0>::mc_Value || NTraits::TCIsArrayUnbounded<t_CType0>::mc_Value >::mc_Value>
		{
		};
	}

	template <typename t_CType0>
	class TCSizeOf : public TCCompileTimeConstant<mint, NPrivate::TCSizeOfHelper2<t_CType0>::mc_Value>
	{
	public:

	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| IsInteger																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NImplementation
	{
		template <typename t_CType0>
		class TCIsInteger
		{
		public:
			enum
			{
				EValue = false
			};
		};
	}

	template <typename t_CType0>

	class TCIsInteger : public TCCompileTimeConstant<bool, NImplementation::TCIsInteger<typename TCRemoveQualifiers<t_CType0>::CType>::EValue>
	{
	};

#	define DMibTraitsImplementIsInteger(_Type) \
		namespace NImplementation {\
		template <>	\
		class TCIsInteger<_Type>\
		{\
		public:\
			enum\
			{\
				EValue = true\
			};\
		};\
		}

	DMibTraitsImplementIsInteger(bool);
#	if defined(DMibPCanDo_int8)
		DMibTraitsImplementIsInteger(int8);
#	endif
#	if defined(DMibPCanDo_int16)
		DMibTraitsImplementIsInteger(int16);
#	endif
#	if defined(DMibPCanDo_int32)
		DMibTraitsImplementIsInteger(int32);
#	endif
#	if defined(DMibPCanDo_int64)
		DMibTraitsImplementIsInteger(int64);
#	endif
#	if defined(DMibPCanDo_int80)
		DMibTraitsImplementIsInteger(int80);
#	endif
#	if defined(DMibPCanDo_int128)
		DMibTraitsImplementIsInteger(int128);
#	endif
#	if defined(DMibPCanDo_int160)
		DMibTraitsImplementIsInteger(int160);
#	endif
#	if defined(DMibPCanDo_int256)
		DMibTraitsImplementIsInteger(int256);
#	endif
#	if defined(DMibPCanDo_int320)
		DMibTraitsImplementIsInteger(int320);
#	endif
#	if defined(DMibPCanDo_int512)
		DMibTraitsImplementIsInteger(int512);
#	endif
#	if defined(DMibPCanDo_int1024)
		DMibTraitsImplementIsInteger(int1024);
#	endif
#	if defined(DMibPCanDo_int2048)
		DMibTraitsImplementIsInteger(int2048);
#	endif
#	if defined(DMibPCanDo_int4096)
		DMibTraitsImplementIsInteger(int4096);
#	endif
#	if defined(DMibPCanDo_int8192)
		DMibTraitsImplementIsInteger(int8192);
#	endif

#	if defined(DMibPCanDo_uint8)
		DMibTraitsImplementIsInteger(uint8);
#	endif
#	if defined(DMibPCanDo_uint16)
		DMibTraitsImplementIsInteger(uint16);
#	endif
#	if defined(DMibPCanDo_uint32)
		DMibTraitsImplementIsInteger(uint32);
#	endif
#	if defined(DMibPCanDo_uint64)
		DMibTraitsImplementIsInteger(uint64);
#	endif
#	if defined(DMibPCanDo_uint80)
		DMibTraitsImplementIsInteger(uint80);
#	endif
#	if defined(DMibPCanDo_uint128)
		DMibTraitsImplementIsInteger(uint128);
#	endif
#	if defined(DMibPCanDo_uint160)
		DMibTraitsImplementIsInteger(uint160);
#	endif
#	if defined(DMibPCanDo_uint256)
		DMibTraitsImplementIsInteger(uint256);
#	endif
#	if defined(DMibPCanDo_uint512)
		DMibTraitsImplementIsInteger(uint512);
#	endif
#	if defined(DMibPCanDo_uint1024)
		DMibTraitsImplementIsInteger(uint1024);
#	endif
#	if defined(DMibPCanDo_uint2048)
		DMibTraitsImplementIsInteger(uint2048);
#	endif
#	if defined(DMibPCanDo_uint4096)
		DMibTraitsImplementIsInteger(uint4096);
#	endif
#	if defined(DMibPCanDo_uint8192)
		DMibTraitsImplementIsInteger(uint8192);
#	endif

#	ifdef DMibPUniqueType_ch8
		DMibTraitsImplementIsInteger(ch8);
#	endif
#	ifdef DMibPUniqueType_ch16
		DMibTraitsImplementIsInteger(ch16);
#	endif
#	ifdef DMibPUniqueType_ch32
		DMibTraitsImplementIsInteger(ch32);
#	endif
#	ifdef DMibPUniqueType_mint
		DMibTraitsImplementIsInteger(mint);
#	endif
#	ifdef DMibPUniqueType_smint
		DMibTraitsImplementIsInteger(smint);
#	endif
#	ifdef DMibPUniqueType_aint
		DMibTraitsImplementIsInteger(aint);
#	endif
#	ifdef DMibPUniqueType_uaint
		DMibTraitsImplementIsInteger(uaint);
#	endif

#	ifdef DMibPUniqueType_int
		DMibTraitsImplementIsInteger(int);
#	endif
#	ifdef DMibPUniqueType_uint
		DMibTraitsImplementIsInteger(unsigned int);
#	endif

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| IsFloat																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NImplementation
	{
		template <typename t_CType0>
		class TCIsFloat
		{
		public:
			enum
			{
				EValue = false
			};
		};
	}

	template <typename t_CType0>
	class TCIsFloat : public TCCompileTimeConstant<bool, NImplementation::TCIsFloat<typename TCRemoveQualifiers<t_CType0>::CType>::EValue>
	{
	};

#	define DMibTraitsImplementIsFloat(_Type) \
		namespace NImplementation {\
		template <>	\
		class TCIsFloat<_Type>\
		{\
		public:\
			enum\
			{\
				EValue = true\
			};\
		};\
		}

#	if defined(DMibPCanDo_fp8)
		DMibTraitsImplementIsFloat(pfp8);
#	endif
#	if defined(DMibPCanDo_fp16)
		DMibTraitsImplementIsFloat(pfp16);
#	endif
#	if defined(DMibPCanDo_fp32)
		DMibTraitsImplementIsFloat(pfp32);
#	endif
#	if defined(DMibPCanDo_fp64)
		DMibTraitsImplementIsFloat(pfp64);
#	endif
#	if defined(DMibPCanDo_fp80)
		DMibTraitsImplementIsFloat(pfp80);
#	endif
#	if defined(DMibPCanDo_fp128)
		DMibTraitsImplementIsFloat(pfp128);
#	endif
#	if defined(DMibPCanDo_fp256)
		DMibTraitsImplementIsFloat(pfp256);
#	endif
#	if defined(DMibPCanDo_fp512)
		DMibTraitsImplementIsFloat(pfp512);
#	endif
#	if defined(DMibPCanDo_fp1024)
		DMibTraitsImplementIsFloat(pfp1024);
#	endif
#	if defined(DMibPCanDo_fp2048)
		DMibTraitsImplementIsFloat(pfp2048);
#	endif
#	if defined(DMibPCanDo_fp4096)
		DMibTraitsImplementIsFloat(pfp4096);
#	endif
#	if defined(DMibPCanDo_fp8192)
		DMibTraitsImplementIsFloat(pfp8192);
#	endif

#	if defined(DMibPCanDo_ufp8)
		DMibTraitsImplementIsFloat(pufp8);
#	endif
#	if defined(DMibPCanDo_ufp16)
		DMibTraitsImplementIsFloat(pufp16);
#	endif
#	if defined(DMibPCanDo_ufp32)
		DMibTraitsImplementIsFloat(pufp32);
#	endif
#	if defined(DMibPCanDo_ufp64)
		DMibTraitsImplementIsFloat(pufp64);
#	endif
#	if defined(DMibPCanDo_ufp80)
		DMibTraitsImplementIsFloat(pufp80);
#	endif
#	if defined(DMibPCanDo_ufp128)
		DMibTraitsImplementIsFloat(pufp128);
#	endif
#	if defined(DMibPCanDo_ufp160)
		DMibTraitsImplementIsFloat(pufp160);
#	endif
#	if defined(DMibPCanDo_ufp256)
		DMibTraitsImplementIsFloat(pufp256);
#	endif
#	if defined(DMibPCanDo_ufp512)
		DMibTraitsImplementIsFloat(pufp512);
#	endif
#	if defined(DMibPCanDo_ufp1024)
		DMibTraitsImplementIsFloat(pufp1024);
#	endif
#	if defined(DMibPCanDo_ufp2048)
		DMibTraitsImplementIsFloat(pufp2048);
#	endif
#	if defined(DMibPCanDo_ufp4096)
		DMibTraitsImplementIsFloat(pufp4096);
#	endif
#	if defined(DMibPCanDo_ufp8192)
		DMibTraitsImplementIsFloat(pufp8192);
#	endif


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| IsFundamental																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NImplementation
	{
		template <typename t_CType0>
		class TCIsFundamental
		{
		public:
			enum
			{
				EValue = false
			};
		};
	}

	template <typename t_CType0>
	class TCIsFundamental : public TCCompileTimeConstant<bool, NImplementation::TCIsFundamental<typename TCRemoveQualifiers<t_CType0>::CType>::EValue>
	{
	};

#	define DMibTraitsImplementIsFundamental(_Type) \
		namespace NImplementation { \
		template <>	\
		class TCIsFundamental<_Type>\
		{\
		public:\
			enum\
			{\
				EValue = true\
			};\
		};\
		}

#	if defined(DMibPCanDo_fp8)
		DMibTraitsImplementIsFundamental(pfp8);
#	endif
#	if defined(DMibPCanDo_fp16)
		DMibTraitsImplementIsFundamental(pfp16);
#	endif
#	if defined(DMibPCanDo_fp32)
		DMibTraitsImplementIsFundamental(pfp32);
#	endif
#	if defined(DMibPCanDo_fp64)
		DMibTraitsImplementIsFundamental(pfp64);
#	endif
#	if defined(DMibPCanDo_fp80)
		DMibTraitsImplementIsFundamental(pfp80);
#	endif
#	if defined(DMibPCanDo_fp128)
		DMibTraitsImplementIsFundamental(pfp128);
#	endif
#	if defined(DMibPCanDo_fp256)
		DMibTraitsImplementIsFundamental(pfp256);
#	endif
#	if defined(DMibPCanDo_fp512)
		DMibTraitsImplementIsFundamental(pfp512);
#	endif
#	if defined(DMibPCanDo_fp1024)
		DMibTraitsImplementIsFundamental(pfp1024);
#	endif
#	if defined(DMibPCanDo_fp2048)
		DMibTraitsImplementIsFundamental(pfp2048);
#	endif
#	if defined(DMibPCanDo_fp4096)
		DMibTraitsImplementIsFundamental(pfp4096);
#	endif
#	if defined(DMibPCanDo_fp8192)
		DMibTraitsImplementIsFundamental(pfp8192);
#	endif

#	if defined(DMibPCanDo_ufp8)
		DMibTraitsImplementIsFundamental(pufp8);
#	endif
#	if defined(DMibPCanDo_ufp16)
		DMibTraitsImplementIsFundamental(pufp16);
#	endif
#	if defined(DMibPCanDo_ufp32)
		DMibTraitsImplementIsFundamental(pufp32);
#	endif
#	if defined(DMibPCanDo_ufp64)
		DMibTraitsImplementIsFundamental(pufp64);
#	endif
#	if defined(DMibPCanDo_ufp80)
		DMibTraitsImplementIsFundamental(pufp80);
#	endif
#	if defined(DMibPCanDo_ufp128)
		DMibTraitsImplementIsFundamental(pufp128);
#	endif
#	if defined(DMibPCanDo_ufp160)
		DMibTraitsImplementIsFundamental(pufp160);
#	endif
#	if defined(DMibPCanDo_ufp256)
		DMibTraitsImplementIsFundamental(pufp256);
#	endif
#	if defined(DMibPCanDo_ufp512)
		DMibTraitsImplementIsFundamental(pufp512);
#	endif
#	if defined(DMibPCanDo_ufp1024)
		DMibTraitsImplementIsFundamental(pufp1024);
#	endif
#	if defined(DMibPCanDo_ufp2048)
		DMibTraitsImplementIsFundamental(pufp2048);
#	endif
#	if defined(DMibPCanDo_ufp4096)
		DMibTraitsImplementIsFundamental(pufp4096);
#	endif
#	if defined(DMibPCanDo_ufp8192)
		DMibTraitsImplementIsFundamental(pufp8192);
#	endif

	DMibTraitsImplementIsFundamental(bool);
#	if defined(DMibPCanDo_int8)
		DMibTraitsImplementIsFundamental(int8);
#	endif
#	if defined(DMibPCanDo_int16)
		DMibTraitsImplementIsFundamental(int16);
#	endif
#	if defined(DMibPCanDo_int32)
		DMibTraitsImplementIsFundamental(int32);
#	endif
#	if defined(DMibPCanDo_int64)
		DMibTraitsImplementIsFundamental(int64);
#	endif
#	if defined(DMibPCanDo_int80)
		DMibTraitsImplementIsFundamental(int80);
#	endif
#	if defined(DMibPCanDo_int128)
		DMibTraitsImplementIsFundamental(int128);
#	endif
#	if defined(DMibPCanDo_int160)
		DMibTraitsImplementIsFundamental(int160);
#	endif
#	if defined(DMibPCanDo_int256)
		DMibTraitsImplementIsFundamental(int256);
#	endif
#	if defined(DMibPCanDo_int320)
		DMibTraitsImplementIsFundamental(int320);
#	endif
#	if defined(DMibPCanDo_int512)
		DMibTraitsImplementIsFundamental(int512);
#	endif
#	if defined(DMibPCanDo_int1024)
		DMibTraitsImplementIsFundamental(int1024);
#	endif
#	if defined(DMibPCanDo_int2048)
		DMibTraitsImplementIsFundamental(int2048);
#	endif
#	if defined(DMibPCanDo_int4096)
		DMibTraitsImplementIsFundamental(int4096);
#	endif
#	if defined(DMibPCanDo_int8192)
		DMibTraitsImplementIsFundamental(int8192);
#	endif

#	if defined(DMibPCanDo_uint8)
		DMibTraitsImplementIsFundamental(uint8);
#	endif
#	if defined(DMibPCanDo_uint16)
		DMibTraitsImplementIsFundamental(uint16);
#	endif
#	if defined(DMibPCanDo_uint32)
		DMibTraitsImplementIsFundamental(uint32);
#	endif
#	if defined(DMibPCanDo_uint64)
		DMibTraitsImplementIsFundamental(uint64);
#	endif
#	if defined(DMibPCanDo_uint80)
		DMibTraitsImplementIsFundamental(uint80);
#	endif
#	if defined(DMibPCanDo_uint128)
		DMibTraitsImplementIsFundamental(uint128);
#	endif
#	if defined(DMibPCanDo_uint160)
		DMibTraitsImplementIsFundamental(uint160);
#	endif
#	if defined(DMibPCanDo_uint256)
		DMibTraitsImplementIsFundamental(uint256);
#	endif
#	if defined(DMibPCanDo_uint512)
		DMibTraitsImplementIsFundamental(uint512);
#	endif
#	if defined(DMibPCanDo_uint1024)
		DMibTraitsImplementIsFundamental(uint1024);
#	endif
#	if defined(DMibPCanDo_uint2048)
		DMibTraitsImplementIsFundamental(uint2048);
#	endif
#	if defined(DMibPCanDo_uint4096)
		DMibTraitsImplementIsFundamental(uint4096);
#	endif
#	if defined(DMibPCanDo_uint8192)
		DMibTraitsImplementIsFundamental(uint8192);
#	endif

#	ifdef DMibPUniqueType_ch8
		DMibTraitsImplementIsFundamental(ch8);
#	endif
#	ifdef DMibPUniqueType_ch16
		DMibTraitsImplementIsFundamental(ch16);
#	endif
#	ifdef DMibPUniqueType_ch32
		DMibTraitsImplementIsFundamental(ch32);
#	endif
#	ifdef DMibPUniqueType_mint
		DMibTraitsImplementIsFundamental(mint);
#	endif
#	ifdef DMibPUniqueType_smint
		DMibTraitsImplementIsFundamental(smint);
#	endif
#	ifdef DMibPUniqueType_aint
		DMibTraitsImplementIsFundamental(aint);
#	endif
#	ifdef DMibPUniqueType_uaint
		DMibTraitsImplementIsFundamental(uaint);
#	endif
#	ifdef DMibPUniqueType_int
		DMibTraitsImplementIsFundamental(int);
#	endif
#	ifdef DMibPUniqueType_uint
		DMibTraitsImplementIsFundamental(unsigned int);
#	endif

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| IsArithmetic																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NImplementation
	{
		template <typename t_CType0>
		class TCIsArithmetic
		{
		public:
			enum
			{
				EValue = NTraits::TCIsFloat<t_CType0>::mc_Value || NTraits::TCIsInteger<t_CType0>::mc_Value
			};
		};
	}

	template <typename t_CType0>
	class TCIsArithmetic : public TCCompileTimeConstant<bool, NImplementation::TCIsArithmetic<typename TCRemoveQualifiers<t_CType0>::CType>::EValue>
	{
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| IsCompound																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NImplementation
	{
		template <typename t_CType0>
		class TCIsCompound
		{
		public:
			enum
			{
				EValue = !NTraits::TCIsFundamental<t_CType0>::mc_Value
			};
		};
	}

	template <typename t_CType0>
	class TCIsCompound : public TCCompileTimeConstant<bool, NImplementation::TCIsCompound<typename TCRemoveQualifiers<t_CType0>::CType>::EValue>
	{
	};


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| IsScalar																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NImplementation
	{
		template <typename t_CType0>
		class TCIsScalar
		{
		public:
			enum
			{
				EValue = NTraits::TCIsArithmetic<t_CType0>::mc_Value || NTraits::TCIsEnum<t_CType0>::mc_Value || NTraits::TCIsPointer<t_CType0>::mc_Value || NTraits::TCIsMemberPointer<t_CType0>::mc_Value
			};
		};
	}

	template <typename t_CType0>
	class TCIsScalar : public TCCompileTimeConstant<bool, NImplementation::TCIsScalar<typename TCRemoveQualifiers<t_CType0>::CType>::EValue>
	{
	};


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| TCIsBuiltIn																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/
	// Temporary type trait. Maybe TCIsCompileTimeConstant would be a better name
	namespace NImplementation
	{
		template <typename t_CType0>
		class TCIsBuiltIn
		{
		public:
			enum
			{
				EValue = NTraits::TCIsFundamental<t_CType0>::mc_Value || NTraits::TCIsEnum<t_CType0>::mc_Value || NTraits::TCIsPointer<t_CType0>::mc_Value || NTraits::TCIsMemberPointer<t_CType0>::mc_Value
			};
		};
	}

	template <typename t_CType0>
	class TCIsBuiltIn : public TCCompileTimeConstant<bool, NImplementation::TCIsBuiltIn<typename TCRemoveQualifiers<t_CType0>::CType>::EValue>
	{
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Largest type																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CType0, typename t_CType1>
	class TCLargestType
	{
	public:
		typedef typename TCChooseType<(TCSizeOf<t_CType0>::mc_Value >= TCSizeOf<t_CType1>::mc_Value), t_CType0, t_CType1>::CType CType;
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Smallest type																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CType0, typename t_CType1>
	class TCSmallestType
	{
	public:

		typedef typename TCChooseType<(TCSizeOf<t_CType0>::mc_Value <= TCSizeOf<t_CType1>::mc_Value), t_CType0, t_CType1>::CType CType;
	};


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Signed/Unsigned																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NImplementation
	{
		template <typename t_CType>
		class TCIsSigned
		{
		public:
			enum
			{
				EValue = false
			};
		};

		template <typename t_CType>
		class TCUnsigned
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCSigned
		{
		public:
			typedef t_CType CType;
		};
	}

	template <typename t_CType>
	class TCIsSigned : public TCCompileTimeConstant<bool, NImplementation::TCIsSigned<typename TCRemoveQualifiers<t_CType>::CType >::EValue >
	{
	};

	template <typename t_CType>
	class TCUnsigned
	{
	public:
		typedef typename TCCopyQualifiers<t_CType, typename NImplementation::TCUnsigned<typename TCRemoveQualifiers<t_CType>::CType>::CType>::CType CType;
	};

	template <typename t_CType>
	class TCSigned
	{
	public:
		typedef typename TCCopyQualifiers<t_CType, typename NImplementation::TCSigned<typename TCRemoveQualifiers<t_CType>::CType>::CType>::CType CType;
	};

#	define DMibTraitsImplementSigned(_Signed, _Unsigned) \
		namespace NImplementation {\
		template <> \
		class TCSigned<_Unsigned>\
		{\
		public:\
			typedef _Signed CType;\
		};\
		}

#	define DMibTraitsImplementUnsigned(_Signed, _Unsigned) \
		namespace NImplementation {\
		template <>	\
		class TCUnsigned<_Signed>\
		{\
		public:\
			typedef _Unsigned CType;\
		};\
		}

#	define DMibTraitsImplementIsSigned(_Signed) \
		namespace NImplementation {\
		template <> \
		class TCIsSigned<_Signed>\
		{\
		public:\
			enum\
			{\
				EValue = true\
			};\
		};\
		}

#	define DMibTraitsImplementSignedPair(_Signed, _Unsigned) DMibTraitsImplementSigned(_Signed, _Unsigned) DMibTraitsImplementUnsigned(_Signed, _Unsigned) DMibTraitsImplementIsSigned(_Signed)

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
#	if defined(DMibPCanDo_int128) && defined(DMibPCanDo_uint128)
		DMibTraitsImplementSignedPair(int128, uint128);
#	endif
#	if defined(DMibPCanDo_int160) && defined(DMibPCanDo_uint160)
		DMibTraitsImplementSignedPair(int160, uint160);
#	endif
#	if defined(DMibPCanDo_int256) && defined(DMibPCanDo_uint256)
		DMibTraitsImplementSignedPair(int256, uint256);
#	endif
#	if defined(DMibPCanDo_int320) && defined(DMibPCanDo_uint320)
		DMibTraitsImplementSignedPair(int320, uint320);
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

	namespace NImplementation
	{
		template <typename t_CType>
		class TCLargerType
		{
		public:
			typedef t_CType CType; // Default to no larger type exists
		};

		template <typename t_CType>
		class TCSmallerType
		{
		public:
			typedef t_CType CType; // Default to no smaller type exists
		};
	}

	template <typename t_CType>
	class TCLargerType
	{
	public:
		typedef typename TCCopyQualifiers<t_CType, typename NImplementation::TCLargerType<typename TCRemoveQualifiers<t_CType>::CType>::CType>::CType CType;
	};

	template <typename t_CType>
	class TCSmallerType
	{
	public:
		typedef typename TCCopyQualifiers<t_CType, typename NImplementation::TCSmallerType<typename TCRemoveQualifiers<t_CType>::CType>::CType>::CType CType;
	};

#	define DMibTraitsImplementSizeSmaller(_Smaller, _Larger) \
		namespace NImplementation {\
		template <>	\
		class TCSmallerType<_Larger>\
		{\
		public:\
			typedef _Smaller CType;\
		};\
		}

#	define DMibTraitsImplementSizeLarger(_Smaller, _Larger) \
		namespace NImplementation {\
		template <>	\
		class TCLargerType<_Smaller>\
		{\
		public:\
			typedef _Larger CType;\
		};\
		}


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
#	if defined(DMibPCanDo_int128) && defined(DMibPCanDo_int256)
		DMibTraitsImplementSizePair(int128, int256);
#	endif
#	if defined(DMibPCanDo_int160) && defined(DMibPCanDo_int320)
		DMibTraitsImplementSizePair(int160, int320);
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


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Integer from size																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <mint t_VariableSize, bint t_bFundamental = false>
	class TCIntFromSize
	{
	public:
		typedef void CType;
	};

	template <mint t_VariableSize, bint t_bFundamental = false>
	class TCIntFromSizeLarger
	{
	public:
		typedef typename TCIntFromSizeLarger<t_VariableSize + 1, t_bFundamental>::CType CType;
	};

	template <mint t_VariableSize, bint t_bFundamental = false>
	class TCIntFromSizeSmaller
	{
	public:
		typedef typename TCIntFromSizeSmaller<t_VariableSize - 1, t_bFundamental>::CType CType;
	};

#	define DMibTraitsImplementIntegerFromSize(_Type) \
		template <>	\
		class TCIntFromSize<sizeof(_Type), false>\
		{\
		public:\
			typedef _Type CType;\
		};\
		template <>	\
		class TCIntFromSizeSmaller<sizeof(_Type), false>\
		{\
		public:\
			typedef _Type CType;\
		};\
		template <>	\
		class TCIntFromSizeLarger<sizeof(_Type), false>\
		{\
		public:\
			typedef _Type CType;\
		};

#	define DMibTraitsImplementIntegerFromSizeFundamental(_Type) \
		template <>	\
		class TCIntFromSize<sizeof(_Type), false>\
		{\
		public:\
			typedef _Type CType;\
		};\
		template <>	\
		class TCIntFromSizeSmaller<sizeof(_Type), false>\
		{\
		public:\
			typedef _Type CType;\
		};\
		template <>	\
		class TCIntFromSizeLarger<sizeof(_Type), false>\
		{\
		public:\
			typedef _Type CType;\
		};\
		template <>	\
		class TCIntFromSize<sizeof(_Type), true>\
		{\
		public:\
			typedef _Type CType;\
		};\
		template <>	\
		class TCIntFromSizeSmaller<sizeof(_Type), true>\
		{\
		public:\
			typedef _Type CType;\
		};\
		template <>	\
		class TCIntFromSizeLarger<sizeof(_Type), true>\
		{\
		public:\
			typedef _Type CType;\
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
#	if defined(DMibPCanDo_int128)
		DMibTraitsImplementIntegerFromSizeFundamental(int128);
#	endif
#	if defined(DMibPCanDo_int160)
		DMibTraitsImplementIntegerFromSizeFundamental(int160);
#	endif
#	if defined(DMibPCanDo_int256)
		DMibTraitsImplementIntegerFromSizeFundamental(int256);
#	endif
#	if defined(DMibPCanDo_int320)
		DMibTraitsImplementIntegerFromSizeFundamental(int320);
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


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Fload from size																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <mint t_VariableSize>
	class TCFloatFromSize
	{
	public:
		typedef typename TCFloatFromSize<t_VariableSize + 1>::CType CType;
	};

#	define DMibTraitsImplementFloatFromSize(_Type) \
		template <>	\
		class TCFloatFromSize<sizeof(_Type)>\
		{\
		public:\
			typedef _Type CType;\
		};
}
