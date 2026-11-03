// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Test_TypeTraits_TestTypes.h"

/***************************************************************************************************\
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
| Is Standard Layout																				|
|___________________________________________________________________________________________________|
\***************************************************************************************************/

#include "Test_TypeTraits_IsStandardLayout.h"

/***************************************************************************************************\
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
| Is Constructor Callable With																		|
|___________________________________________________________________________________________________|
\***************************************************************************************************/

#include "Test_TypeTraits_IsConstructorCallableWith.h"

void fg_Blaha()
{
	struct CTestInherit : public CTestClass
	{
		int m_Test;
	};

	CTestInherit Test3;
	//CTestClass &Test2 = NMib::fg_Move(Test3);
	[[maybe_unused]] CTestClass &Test4 = Test3;
	[[maybe_unused]] CTestClass &&Test5 = NMib::fg_Move(Test3);
}

// Traits for all operators

// Traits for all comparisons (GCC only?)
