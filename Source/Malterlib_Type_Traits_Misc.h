// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include "Malterlib_Type_Traits_Properties.h"

namespace NMib::NTraits
{
	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Optimal pass																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CType0>
		class TCOptimalPass
		{
		public:
			typedef typename TCChooseType<TCSizeOf<t_CType0>::mc_Value <= sizeof(mint) && DMibPHasTrivialCopyConstructor(t_CType0), t_CType0, typename TCAddReference<typename TCAddConst<t_CType0>::CType>::CType>::CType CType;

		};
	}

	template <typename t_CType0>
	class TCOptimalPass : public NPrivate::TCOptimalPass<t_CType0>
	{
	public:

	};

	template <typename t_CType0, typename t_CRet = t_CType0>
	class TCOptimalPassByValue
		: public TCDisableIf<TCIsReference<typename TCOptimalPass<t_CType0>::CType>::mc_Value, t_CRet>
	{
	public:
		enum
		{
			mc_Value = !TCIsReference<typename TCOptimalPass<t_CType0>::CType>::mc_Value
		};

	};

	template <typename t_CType0, typename t_CRet = t_CType0>
	class TCOptimalPassByRef
		: public TCEnableIf<TCIsReference<typename TCOptimalPass<t_CType0>::CType>::mc_Value, t_CRet>
	{
	public:
		enum
		{
			mc_Value = TCIsReference<typename TCOptimalPass<t_CType0>::CType>::mc_Value
		};

	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Alignment																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		using CAlignmentHelperUnderlaying = int32;
		enum EAlignmentHelper
		{
			EAlignmentHelper_Normal,
			EAlignmentHelper_Function,
			EAlignmentHelper_FunctionRef,
			EAlignmentHelper_Class,
			EAlignmentHelper_Unbounded,
			EAlignmentHelper_Void,
		};
	}
#ifndef DMibPAlignmentOf
#ifdef DCompiler_MSVC
#pragma warning(push)
#pragma warning(disable:4624)
#endif	
	namespace NPrivate
	{

		template <typename t_CType, CAlignmentHelperUnderlaying t_Impl>
		struct TCAlignmentOfHelper
		{
			struct CFirst
			{
				int8 m_Padding;
				t_CType m_First;
				t_CType m_Second;
			};
			struct CSecond
			{
				t_CType m_First;
				t_CType m_Second;
			};
			enum
			{
				mc_Value = sizeof(CFirst) - sizeof(CSecond)
			};
		};
		template <typename t_CType>
		struct TCAlignmentOfHelper<t_CType, EAlignmentHelper_Unbounded>
		{
			typedef typename TCRemoveExtent<t_CType>::CType CType;
			struct CFirst
			{
				int8 m_Padding;
				CType m_First;
				CType m_Second;
			};
			struct CSecond
			{
				CType m_First;
				CType m_Second;
			};
			enum
			{
				mc_Value = sizeof(CFirst) - sizeof(CSecond)
			};
		};
		template <typename t_CType>
		struct TCAlignmentOfHelper<t_CType, EAlignmentHelper_Void>
		{
			enum
			{
				mc_Value = 0
			};
		};
		template <typename t_CType>
		struct TCAlignmentOfHelper<t_CType, EAlignmentHelper_Function>
		{
			enum
			{
				mc_Value = 0
			};
		};
	}
	template <typename t_CType>
	class TCAlignmentOf
		: public TCCompileTimeConstant
		<
			mint
			, NPrivate::TCAlignmentOfHelper
			<
				t_CType,
				TCIsVoid<t_CType>::mc_Value ? NPrivate::EAlignmentHelper_Void
				: TCIsFunction<t_CType>::mc_Value ? NPrivate::EAlignmentHelper_Function
				: TCIsArrayUnbounded<t_CType>::mc_Value ? NPrivate::EAlignmentHelper_Unbounded
				: NPrivate::EAlignmentHelper_Normal
			>::mc_Value
		>
	{
	public:
	};
#ifdef DCompiler_MSVC	
#pragma warning(pop)
#endif
#else
	namespace NPrivate
	{

		template <typename t_CType, CAlignmentHelperUnderlaying t_Impl>
		struct TCAlignmentOfHelper
		{
			enum
			{
				mc_Value = DMibPAlignmentOf(t_CType)
			};
		};
		template <typename t_CType>
		struct TCAlignmentOfHelper<t_CType, EAlignmentHelper_Void>
		{
			enum
			{
				mc_Value = 0
			};
		};
		template <typename t_CType>
		struct TCAlignmentOfHelper<t_CType, EAlignmentHelper_Function>
		{
			enum
			{
				mc_Value = 0
			};
		};
		template <typename t_CType>
		struct TCAlignmentOfHelper<t_CType, EAlignmentHelper_FunctionRef>
		{
			enum
			{
				mc_Value = sizeof(void *)
			};
		};
	}
	template <typename t_CType>
	class TCAlignmentOf
		: public TCCompileTimeConstant
		<
			mint
			, NPrivate::TCAlignmentOfHelper
			<
				t_CType
				, TCIsVoid<t_CType>::mc_Value ? NPrivate::EAlignmentHelper_Void
				: TCIsFunction<t_CType>::mc_Value ? NPrivate::EAlignmentHelper_Function
				: TCIsFunction<typename TCRemoveReference<t_CType>::CType>::mc_Value ? NPrivate::EAlignmentHelper_FunctionRef
				: NPrivate::EAlignmentHelper_Normal
			>::mc_Value
		>
	{
	public:
	};
#endif


	namespace NPrivate
	{
		template <typename t_CData, mint t_Align, CAlignmentHelperUnderlaying t_Impl>
		class TCAlignHelper
		{
		public:
			//static_assert(t_Align < 0 || !t_bEnable, "Should not be here");
			typedef t_CData CType;
		};
	}

	template <typename t_CData, mint t_Align>
	class TCAlign
		: public NPrivate::TCAlignHelper
		<
			t_CData,
			t_Align,
			TCIsArrayUnbounded<t_CData>::mc_Value ? NPrivate::EAlignmentHelper_Unbounded :
			TCIsClass<t_CData>::mc_Value ? NPrivate::EAlignmentHelper_Class :
			TCIsFunction<t_CData>::mc_Value ? NPrivate::EAlignmentHelper_Function :
			TCIsVoid<t_CData>::mc_Value || TCIsFunction<t_CData>::mc_Value ? NPrivate::EAlignmentHelper_Void :
			NPrivate::EAlignmentHelper_Normal
		>
	{
	};

#ifndef DMibNoAggregateConstexpr
#define DMibImplementAlignNewTypeInit \
		{\
			CNewType(EAggregateInitialization _Init)\
				: t_CData{_Init}\
			{\
			}\
			CNewType()\
			{\
			}\
		}
#else
#define DMibImplementAlignNewTypeInit {}
#endif

#define DMibImplementAlign(_Align)\
	template <typename t_CData>\
	class TCAlignHelper<t_CData, _Align, EAlignmentHelper_Class>\
	{\
	public:\
		struct DMibPAlignType(CNewType, _Align) : public t_CData \
		DMibImplementAlignNewTypeInit; \
		typedef typename NMib::NTraits::TCCopyQualifiers<t_CData, CNewType>::CType CType;\
	};;\
	template <typename t_CData>\
	class TCAlignHelper<t_CData, _Align, EAlignmentHelper_Normal>\
	{\
	public:\
		struct DMibPAlignType(CNewType, _Align) {typename NMib::NTraits::TCRemoveQualifiers<t_CData>::CType m_Aligned;};\
		typedef typename NMib::NTraits::TCCopyQualifiers<t_CData, CNewType>::CType CType;\
	};;\
	template <typename t_CData>\
	class TCAlignHelper<t_CData, _Align, EAlignmentHelper_Unbounded>\
	{\
	public:\
		struct DMibPAlignType(CNewType, _Align) {typename NMib::NTraits::TCRemoveQualifiers<typename NMib::NTraits::TCRemoveExtent<t_CData>::CType>::CType m_Aligned;};\
		typedef typename NMib::NTraits::TCCopyQualifiers<typename NMib::NTraits::TCRemoveExtent<t_CData>::CType, CNewType>::CType CType [];\
	};;

	namespace NPrivate
	{
#	if DMibPMaxAlign >= (1 << 0)
		DMibImplementAlign(1);
#	endif
#	if DMibPMaxAlign >= (1 << 1)
		DMibImplementAlign(2);
#	endif
#	if DMibPMaxAlign >= (1 << 2)
		DMibImplementAlign(4);
#	endif
#	if DMibPMaxAlign >= (1 << 3)
		DMibImplementAlign(8);
#	endif
#	if DMibPMaxAlign >= (1 << 4)
		DMibImplementAlign(16);
#	endif
#	if DMibPMaxAlign >= (1 << 5)
		DMibImplementAlign(32);
#	endif
#	if DMibPMaxAlign >= (1 << 6)
		DMibImplementAlign(64);
#	endif
#	if DMibPMaxAlign >= (1 << 7)
		DMibImplementAlign(128);
#	endif
#	if DMibPMaxAlign >= (1 << 8)
		DMibImplementAlign(256);
#	endif
#	if DMibPMaxAlign >= (1 << 9)
		DMibImplementAlign(512);
#	endif
#	if DMibPMaxAlign >= (1 << 10)
		DMibImplementAlign(1024);
#	endif
#	if DMibPMaxAlign >= (1 << 11)
		DMibImplementAlign(2048);
#	endif
#	if DMibPMaxAlign >= (1 << 12)
		DMibImplementAlign(4096);
#	endif
#	if DMibPMaxAlign >= (1 << 13)
		DMibImplementAlign(8192);
#	endif
#	if DMibPMaxAlign >= (1 << 14)
		DMibImplementAlign(16384);
#	endif
#	if DMibPMaxAlign >= (1 << 15)
		DMibImplementAlign(32768);
#	endif
#	if DMibPMaxAlign >= (1 << 16)
		DMibImplementAlign(65536);
#	endif
#	if DMibPMaxAlign >= (1 << 17)
		DMibImplementAlign(131072);
#	endif
#	if DMibPMaxAlign >= (1 << 17)
		DMibImplementAlign(262144);
#	endif
#	if DMibPMaxAlign >= (1 << 18)
		DMibImplementAlign(524288);
#	endif
#	if DMibPMaxAlign >= (1 << 19)
		DMibImplementAlign(1048576);
#	endif
#	if DMibPMaxAlign >= (1 << 20)
		DMibImplementAlign(2097152);
#	endif
#	if DMibPMaxAlign >= (1 << 21)
		DMibImplementAlign(4194304);
#	endif
#	if DMibPMaxAlign >= (1 << 22)
		DMibImplementAlign(8388608);
#	endif
#	if DMibPMaxAlign >= (1 << 23)
		DMibImplementAlign(16777216);
#	endif
#	if DMibPMaxAlign >= (1 << 24)
		DMibImplementAlign(33554432);
#	endif
#	if DMibPMaxAlign >= (1 << 25)
		DMibImplementAlign(67108864);
#	endif
#	if DMibPMaxAlign >= (1 << 26)
		DMibImplementAlign(134217728);
#	endif
#	if DMibPMaxAlign >= (1 << 27)
		DMibImplementAlign(268435456);
#	endif
#	if DMibPMaxAlign >= (1 << 28)
		DMibImplementAlign(536870912);
#	endif
#	if DMibPMaxAlign >= (1 << 29)
		DMibImplementAlign(1073741824);
#	endif
#	if DMibPMaxAlign >= (1 << 30)
		DMibImplementAlign(2147483648);
#	endif
	}
}
