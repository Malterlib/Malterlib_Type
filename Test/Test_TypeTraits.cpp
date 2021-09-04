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
	static_assert(!NMib::NTraits::TCIsSame<int, int32>::mc_Value);
#else
	static_assert(NMib::NTraits::TCIsSame<int, int32>::mc_Value || NMib::NTraits::TCIsSame<int, smint>::mc_Value);
#endif

#ifdef DMibPUniqueType_uint
	static_assert(!NMib::NTraits::TCIsSame<unsigned int, uint32>::mc_Value);
	static_assert(!NMib::NTraits::TCIsSame<unsigned int, mint>::mc_Value);
#else
	static_assert(NMib::NTraits::TCIsSame<unsigned int, uint32>::mc_Value || NMib::NTraits::TCIsSame<unsigned int, mint>::mc_Value);
#endif

#ifdef DMibPUniqueType_mint
	static_assert(!NMib::NTraits::TCIsSame<mint, NMib::NTraits::TCUnsigned<NMib::NTraits::TCIntFromSize<sizeof(void *)>::CType>::CType>::mc_Value);
#else
	static_assert(NMib::NTraits::TCIsSame<mint, NMib::NTraits::TCUnsigned<NMib::NTraits::TCIntFromSize<sizeof(void *)>::CType>::CType>::mc_Value);
#endif

#ifdef DMibPUniqueType_smint
	static_assert(!NMib::NTraits::TCIsSame<smint, NMib::NTraits::TCIntFromSize<sizeof(void *)>::CType>::mc_Value);
#else
	static_assert(NMib::NTraits::TCIsSame<smint, NMib::NTraits::TCIntFromSize<sizeof(void *)>::CType>::mc_Value);
#endif

#ifdef DMibPUniqueType_ch8
	static_assert(!NMib::NTraits::TCIsSame<ch8, int8>::mc_Value);
	static_assert(!NMib::NTraits::TCIsSame<ch8, uint8>::mc_Value);
#else
	static_assert(NMib::NTraits::TCIsSame<ch8, int8>::mc_Value || NMib::NTraits::TCIsSame<ch8, uint8>::mc_Value);
#endif

#ifdef DMibPUniqueType_ch16
	static_assert(!NMib::NTraits::TCIsSame<ch16, int16>::mc_Value);
	static_assert(!NMib::NTraits::TCIsSame<ch16, uint16>::mc_Value);
#else
	static_assert(NMib::NTraits::TCIsSame<ch16, int16>::mc_Value || NMib::NTraits::TCIsSame<ch16, uint16>::mc_Value);
#endif

#ifdef DMibPUniqueType_ch32
	static_assert(!NMib::NTraits::TCIsSame<ch32, int32>::mc_Value);
	static_assert(!NMib::NTraits::TCIsSame<ch32, uint32>::mc_Value);
#else
	static_assert(NMib::NTraits::TCIsSame<ch32, int32>::mc_Value || NMib::NTraits::TCIsSame<ch32, uint32>::mc_Value);
#endif

template <typename t_CLeft, typename t_CRight>
class TCIsComparable
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
		ms_Both = !TCIsSame<CType, CDummy>::mc_Value
		, ms_Global = !TCIsSame<decltype(fg_Global(fs_Left(), fs_Right())), CDummy>::mc_Value
		, ms_Local = !TCIsSame<decltype(fg_Local(fs_Left(), fs_Right())), CDummy>::mc_Value
		, mc_Value = ms_Both
	};
};
#if 0
DMibStaticCheck((!TCIsComparable<CTesting, CTesting>::mc_Value));
DMibStaticCheck((!TCIsComparable<CTesting, CTesting2>::mc_Value));
DMibStaticCheck((!TCIsComparable<CTesting2, CTesting>::mc_Value));
DMibStaticCheck((TCIsComparable<CTesting, int>::mc_Value));
DMibStaticCheck((TCIsComparable<CTesting, int>::ms_Local));
DMibStaticCheck((TCIsComparable<CTesting, int>::ms_Both));
DMibStaticCheck((TCIsComparable<CTesting, int>::ms_Global));
DMibStaticCheck((TCIsComparable<int, CTesting>::mc_Value));
DMibStaticCheck((TCIsComparable<CTesting, float>::mc_Value));
DMibStaticCheck((TCIsComparable<float, CTesting>::mc_Value));
DMibStaticCheck((TCIsComparable<CTesting, float>::mc_Value));
DMibStaticCheck((!TCIsComparable<double, CTesting>::mc_Value));

DMibStaticCheck((TCIsComparable<int, CTesting4>::mc_Value));
DMibStaticCheck((TCIsComparable<CTesting4, int>::mc_Value));
DMibStaticCheck((TCIsComparable<CTesting4, float>::mc_Value));
DMibStaticCheck((TCIsComparable<float, CTesting4>::mc_Value));

//DMibStaticCheck((TCIsComparableLessThan<int, CTesting4>::mc_Value));
//DMibStaticCheck((TCIsComparableLessThan<CTesting4, int>::mc_Value));
//DMibStaticCheck((TCIsComparableLessThan<CTesting4, float>::mc_Value));
//DMibStaticCheck((TCIsComparableLessThan<float, CTesting4>::mc_Value));

DMibStaticCheck((TCIsComparable<int, CTesting3>::mc_Value));
DMibStaticCheck((TCIsComparable<CTesting3, int>::mc_Value));
DMibStaticCheck((TCIsComparable<int, int>::mc_Value));
DMibStaticCheck((!TCIsComparable<CTesting3, double>::mc_Value));

DMibStaticCheck((TCIsComparableLessThan<int, int>::mc_Value));


DMibStaticCheck((!TCIsComparableLessThan<CTesting, CTesting>::mc_Value));
DMibStaticCheck((!TCIsComparableLessThan<CTesting, CTesting2>::mc_Value));
DMibStaticCheck((!TCIsComparableLessThan<CTesting2, CTesting>::mc_Value));
DMibStaticCheck((TCIsComparableLessThan<CTesting, int>::mc_Value));
//DMibStaticCheck((TCIsComparableLessThan<int, CTesting>::mc_Value));
DMibStaticCheck((TCIsComparableLessThan<CTesting, float>::mc_Value));
//DMibStaticCheck((TCIsComparableLessThan<float, CTesting>::mc_Value));
DMibStaticCheck((TCIsComparableLessThan<CTesting, float>::mc_Value));
DMibStaticCheck((!TCIsComparableLessThan<double, CTesting>::mc_Value));
//DMibStaticCheck((!TCIsComparableLessThan<float, char *>::mc_Value));
#endif

namespace
{
	class CTypeTraits_Tests : public NMib::NTest::CTest
	{
	public:

		void f_DoTests()
		{

//			TCIsComparable<int, int>::CType Typeee;Typeee;
	//		TCIsComparable<float, char *>::CType Typeee5;Typeee5;
		//	TCIsComparable<CTesting, int>::CType Typeee6;Typeee6;
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

