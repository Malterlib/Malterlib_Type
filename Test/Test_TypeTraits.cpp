// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

template <typename t_CGod>
class TCHula
{
	typedef typename t_CGod::CGot oeu;
};

template <mint t_Value>
class TCHelpeer
{
public:
};

struct CTesting
{
public:
NMib::COrdering_Weak operator <=> (int) const
{
	return NMib::COrdering_Weak::equivalent;
}
};

struct CTesting2
{
public:
};

struct CTesting3 : public CTesting
{
public:
};

struct CTesting4
{
public:
	operator int()
	{
		return 0;
	}
};

NMib::COrdering_Weak operator <=> (int ,const CTesting&)
{
	return NMib::COrdering_Weak::equivalent;
}
NMib::COrdering_Weak operator <=> (float ,const CTesting&)
{
	return NMib::COrdering_Weak::equivalent;
}
NMib::COrdering_Weak operator <=> (const CTesting&, float)
{
	return NMib::COrdering_Weak::equivalent;
}
/*
COrdering_Weak operator <=> (const CTesting&, int)
{
	return COrdering_Weak::equivalent;
}*/

#ifdef DMibPUniqueType_int
	static_assert(!NMib::NTraits::cIsSame<int, int32>);
#else
	static_assert(NMib::NTraits::cIsSame<int, int32> || NMib::NTraits::cIsSame<int, smint>);
#endif

#ifdef DMibPUniqueType_uint
	static_assert(!NMib::NTraits::cIsSame<unsigned int, uint32>);
	static_assert(!NMib::NTraits::cIsSame<unsigned int, mint>);
#else
	static_assert(NMib::NTraits::cIsSame<unsigned int, uint32> || NMib::NTraits::cIsSame<unsigned int, mint>);
#endif

#ifdef DMibPUniqueType_mint
	static_assert(!NMib::NTraits::cIsSame<mint, NMib::NTraits::TCUnsigned<NMib::NTraits::TCIntFromSize<sizeof(void *)>>>);
#else
	static_assert(NMib::NTraits::cIsSame<mint, NMib::NTraits::TCUnsigned<NMib::NTraits::TCIntFromSize<sizeof(void *)>>>);
#endif

#ifdef DMibPUniqueType_smint
	static_assert(!NMib::NTraits::cIsSame<smint, NMib::NTraits::TCIntFromSize<sizeof(void *)>>);
#else
	static_assert(NMib::NTraits::cIsSame<smint, NMib::NTraits::TCIntFromSize<sizeof(void *)>>);
#endif

#ifdef DMibPUniqueType_ch8
	static_assert(!NMib::NTraits::cIsSame<ch8, int8>);
	static_assert(!NMib::NTraits::cIsSame<ch8, uint8>);
#else
	static_assert(NMib::NTraits::cIsSame<ch8, int8> || NMib::NTraits::cIsSame<ch8, uint8>);
#endif

#ifdef DMibPUniqueType_ch16
	static_assert(!NMib::NTraits::cIsSame<ch16, int16>);
	static_assert(!NMib::NTraits::cIsSame<ch16, uint16>);
#else
	static_assert(NMib::NTraits::cIsSame<ch16, int16> || NMib::NTraits::cIsSame<ch16, uint16>);
#endif

#ifdef DMibPUniqueType_ch32
	static_assert(!NMib::NTraits::cIsSame<ch32, int32>);
	static_assert(!NMib::NTraits::cIsSame<ch32, uint32>);
#else
	static_assert(NMib::NTraits::cIsSame<ch32, int32> || NMib::NTraits::cIsSame<ch32, uint32>);
#endif

template <typename t_CLeft, typename t_CRight>
class cIsComparable
{
public:
	class CDummy {};

	template <typename t_CLeft2, typename t_CRight2>
	static auto fg_Both(t_CLeft2 &&_Left, t_CRight2 &&_Right) -> decltype(NMib::fg_Forward<t_CLeft2>(_Left) < NMib::fg_Forward<t_CRight2>(_Right));
	static CDummy fg_Both(...);

	template <typename t_CLeft2, typename t_CRight2>
	static auto fg_Global(t_CLeft2 &&_Left, t_CRight2 &&_Right) -> decltype(operator < (NMib::fg_Forward<t_CLeft2>(_Left), NMib::fg_Forward<t_CRight2>(_Right)));
	static CDummy fg_Global(...);
	template <typename t_CLeft2, typename t_CRight2>
	static auto fg_Local(t_CLeft2 &&_Left, t_CRight2 &&_Right) -> decltype(NMib::fg_Forward<t_CLeft2>(_Left).operator < (NMib::fg_Forward<t_CRight2>(_Right)));
	static CDummy fg_Local(...);

	static t_CLeft fs_Left();
	static t_CRight fs_Right();

	typedef decltype(fg_Both(fs_Left(), fs_Right())) CType;
	enum
	{
		ms_Both = !cIsSame<CType, CDummy>
		, ms_Global = !cIsSame<decltype(fg_Global(fs_Left(), fs_Right())), CDummy>
		, ms_Local = !cIsSame<decltype(fg_Local(fs_Left(), fs_Right())), CDummy>
		, mc_Value = ms_Both
	};
};
#if 0
static_assert(!cIsComparable<CTesting, CTesting>);
static_assert(!cIsComparable<CTesting, CTesting2>);
static_assert(!cIsComparable<CTesting2, CTesting>);
static_assert(cIsComparable<CTesting, int>);
static_assert(cIsComparable<CTesting, int>::ms_Local);
static_assert(cIsComparable<CTesting, int>::ms_Both);
static_assert(cIsComparable<CTesting, int>::ms_Global);
static_assert(cIsComparable<int, CTesting>);
static_assert(cIsComparable<CTesting, float>);
static_assert(cIsComparable<float, CTesting>);
static_assert(cIsComparable<CTesting, float>);
static_assert(!cIsComparable<double, CTesting>);

static_assert(cIsComparable<int, CTesting4>);
static_assert(cIsComparable<CTesting4, int>);
static_assert(cIsComparable<CTesting4, float>);
static_assert(cIsComparable<float, CTesting4>);

//static_assert(cIsComparableLessThan<int, CTesting4>);
//static_assert(cIsComparableLessThan<CTesting4, int>);
//static_assert(cIsComparableLessThan<CTesting4, float>);
//static_assert(cIsComparableLessThan<float, CTesting4>);

static_assert(cIsComparable<int, CTesting3>);
static_assert(cIsComparable<CTesting3, int>);
static_assert(cIsComparable<int, int>);
static_assert(!cIsComparable<CTesting3, double>);

static_assert(cIsComparableLessThan<int, int>);


static_assert(!cIsComparableLessThan<CTesting, CTesting>);
static_assert(!cIsComparableLessThan<CTesting, CTesting2>);
static_assert(!cIsComparableLessThan<CTesting2, CTesting>);
static_assert(cIsComparableLessThan<CTesting, int>);
//static_assert(cIsComparableLessThan<int, CTesting>);
static_assert(cIsComparableLessThan<CTesting, float>);
//static_assert(cIsComparableLessThan<float, CTesting>);
static_assert(cIsComparableLessThan<CTesting, float>);
static_assert(!cIsComparableLessThan<double, CTesting>);
//static_assert(!cIsComparableLessThan<float, char *>);
#endif

namespace
{
	class CTypeTraits_Tests : public NMib::NTest::CTest
	{
	public:

		void f_DoTests()
		{

//			cIsComparable<int, int>::CType Typeee;Typeee;
	//		cIsComparable<float, char *>::CType Typeee5;Typeee5;
		//	cIsComparable<CTesting, int>::CType Typeee6;Typeee6;
			//auto Test = operator < (0, 0);
//			int x = 0;
			//DMibPDebugBreak;
		//	Dubble < Test3;
			//0.0f < CTesting();
			//0 < CTesting();

		}
	};

	DMibTestRegister(CTypeTraits_Tests, Malterlib::TypeTraits);
}

#ifndef DCompiler_MSVC
static constexpr ch8 const *gc_Tags[] =
	{
	}
;
#endif

static constexpr ch8 const *gc_Tags2[] =
	{
		"Test"
	}
;

#ifndef DCompiler_MSVC
static_assert(NMib::fg_ArraySize(gc_Tags) == 0);
#endif
static_assert(NMib::fg_ArraySize(gc_Tags2) == 1);
