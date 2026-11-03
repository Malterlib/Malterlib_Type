// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Test_TypeTraits_TestTypes.h"

template <typename t_CGod>
struct TCHula
{
private:
	typedef typename t_CGod::CGot COeu;
};

template <umint t_Value>
struct TCHelpeer
{
};

struct CTesting
{
	NMib::COrdering_Weak operator <=> (int _Value) const noexcept
	{
		return NMib::COrdering_Weak::equivalent;
	}
};

struct CTesting2
{
};

struct CTesting3 : public CTesting
{
};

struct CTesting4
{
	operator int ()
	{
		return 0;
	}
};

NMib::COrdering_Weak operator <=> (int _Left, CTesting const &_Right) noexcept
{
	return NMib::COrdering_Weak::equivalent;
}

NMib::COrdering_Weak operator <=> (float _Left, CTesting const &_Right) noexcept
{
	return NMib::COrdering_Weak::equivalent;
}

NMib::COrdering_Weak operator <=> (CTesting const &_Left, float _Right) noexcept
{
	return NMib::COrdering_Weak::equivalent;
}

/*
COrdering_Weak operator <=> (const CTesting&, int) noexcept
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
static_assert(!NMib::NTraits::cIsSame<unsigned int, umint>);
#else
static_assert(NMib::NTraits::cIsSame<unsigned int, uint32> || NMib::NTraits::cIsSame<unsigned int, umint>);
#endif

#ifdef DMibPUniqueType_umint
static_assert(!NMib::NTraits::cIsSame<umint, NMib::NTraits::TCUnsigned<NMib::NTraits::TCIntFromSize<sizeof(void *)>>>);
#else
static_assert(NMib::NTraits::cIsSame<umint, NMib::NTraits::TCUnsigned<NMib::NTraits::TCIntFromSize<sizeof(void *)>>>);
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
struct TCIsComparable
{
	struct CDummy
	{
	};

	template <typename tf_CLeft2, typename tf_CRight2>
	static auto fs_Both(tf_CLeft2 &&_Left, tf_CRight2 &&_Right) -> decltype(NMib::fg_Forward<tf_CLeft2>(_Left) < NMib::fg_Forward<tf_CRight2>(_Right));
	static CDummy fs_Both(...);

	template <typename tf_CLeft2, typename tf_CRight2>
	static auto fs_Global(tf_CLeft2 &&_Left, tf_CRight2 &&_Right) -> decltype(operator < (NMib::fg_Forward<tf_CLeft2>(_Left), NMib::fg_Forward<tf_CRight2>(_Right)));
	static CDummy fs_Global(...);
	template <typename tf_CLeft2, typename tf_CRight2>
	static auto fs_Local(tf_CLeft2 &&_Left, tf_CRight2 &&_Right) -> decltype(NMib::fg_Forward<tf_CLeft2>(_Left).operator < (NMib::fg_Forward<tf_CRight2>(_Right)));
	static CDummy fs_Local(...);

	static t_CLeft fs_Left();
	static t_CRight fs_Right();

	typedef decltype(fs_Both(fs_Left(), fs_Right())) CType;
	static constexpr bool mc_bBoth = !cIsSame<CType, CDummy>;
	static constexpr bool mc_bGlobal = !cIsSame<decltype(fs_Global(fs_Left(), fs_Right())), CDummy>;
	static constexpr bool mc_bLocal = !cIsSame<decltype(fs_Local(fs_Left(), fs_Right())), CDummy>;
	static constexpr bool mc_Value = mc_bBoth;
};
#if 0
static_assert(!TCIsComparable<CTesting, CTesting>);
static_assert(!TCIsComparable<CTesting, CTesting2>);
static_assert(!TCIsComparable<CTesting2, CTesting>);
static_assert(TCIsComparable<CTesting, int>);
static_assert(TCIsComparable<CTesting, int>::mc_bLocal);
static_assert(TCIsComparable<CTesting, int>::mc_bBoth);
static_assert(TCIsComparable<CTesting, int>::mc_bGlobal);
static_assert(TCIsComparable<int, CTesting>);
static_assert(TCIsComparable<CTesting, float>);
static_assert(TCIsComparable<float, CTesting>);
static_assert(TCIsComparable<CTesting, float>);
static_assert(!TCIsComparable<double, CTesting>);

static_assert(TCIsComparable<int, CTesting4>);
static_assert(TCIsComparable<CTesting4, int>);
static_assert(TCIsComparable<CTesting4, float>);
static_assert(TCIsComparable<float, CTesting4>);

//static_assert(cIsComparableLessThan<int, CTesting4>);
//static_assert(cIsComparableLessThan<CTesting4, int>);
//static_assert(cIsComparableLessThan<CTesting4, float>);
//static_assert(cIsComparableLessThan<float, CTesting4>);

static_assert(TCIsComparable<int, CTesting3>);
static_assert(TCIsComparable<CTesting3, int>);
static_assert(TCIsComparable<int, int>);
static_assert(!TCIsComparable<CTesting3, double>);

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
	struct CTypeTraits_Tests : public NMib::NTest::CTest
	{
		void f_DoTests()
		{
			// TCIsComparable<int, int>::CType Typeee;Typeee;
			// TCIsComparable<float, char *>::CType Typeee5;Typeee5;
			// TCIsComparable<CTesting, int>::CType Typeee6;Typeee6;
			// auto Test = operator < (0, 0);
			// int x = 0;
			// DMibPDebugBreak;
			// Dubble < Test3;
			// 0.0f < CTesting();
			// 0 < CTesting();
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
