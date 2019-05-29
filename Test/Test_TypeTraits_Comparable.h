// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

class CComparableTest0
{
public:
	bool operator < (CComparableTest0 const &_Other) const
	{
		return true;
	}


};

class CComparableTest1 : public CComparableTest0
{
public:
};

class CComparableTest2
{
public:
};


DMibStaticCheck((	TCIsComparableLessThan<CComparableTest0, CComparableTest0>::mc_Value											));
DMibStaticCheck((	TCIsComparableLessThan<CComparableTest1, CComparableTest0>::mc_Value											));
DMibStaticCheck((	TCIsComparableLessThan<CComparableTest0, CComparableTest1>::mc_Value											));
DMibStaticCheck((	TCIsComparableLessThan<CComparableTest1, CComparableTest1>::mc_Value											));
DMibStaticCheck((	!TCIsComparableLessThan<CComparableTest2, CComparableTest2>::mc_Value											));
DMibStaticCheck((	TCIsComparableLessThan<NMib::NContainer::CByteVector, NMib::NContainer::CByteVector>::mc_Value			));


