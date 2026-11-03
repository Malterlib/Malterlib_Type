// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Test_TypeTraits_TestTypes.h"

/***************************************************************************************************\
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
| Has Virtual Destructor																			|
|___________________________________________________________________________________________________|
\***************************************************************************************************/

#include "Test_TypeTraits_HasVirtualDestructor.h"

/***************************************************************************************************\
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
| Has New Operator																					|
|___________________________________________________________________________________________________|
\***************************************************************************************************/

#include "Test_TypeTraits_HasNewOperator.h"

namespace NHasVirtualDestrutor
{
	CTestClassWithVirtualDestructor::~CTestClassWithVirtualDestructor()
	{
	}
}

namespace NHasNewOperator
{
	void fg_Testing()
	{
		//void *pTest = CWithNew::operator new(5);
		//CWithDelete::operator delete(pTest);
	}
}
