// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Test_TypeTraits_TestTypes.h"

namespace NTrivial
{
	struct CNonTrivialAssignment
	{
	private:
		CNonTrivialAssignment &operator = (CNonTrivialAssignment const &_Abstract);
	};

	struct CNonTrivialAssignmentInt
	{
	private:
		CNonTrivialAssignmentInt &operator = (int _Value);
	};

	struct CNonTrivialAssignmentBoth
	{
	private:
		CNonTrivialAssignmentBoth &operator = (CNonTrivialAssignmentBoth const &_Abstract);
		CNonTrivialAssignmentBoth &operator = (int _Value);
	};

	struct CNonTrivialAssignmentDerived : public CNonTrivialAssignment
	{
	};

	struct CNonTrivialAssignmentDerivedOverride : public CNonTrivialAssignment
	{
	private:
		CNonTrivialAssignmentDerivedOverride &operator = (CNonTrivialAssignmentDerivedOverride const &_Abstract);
	};

	struct CNonTrivialCopy
	{
	private:
		CNonTrivialCopy(CNonTrivialCopy const &_Abstract);
	};

	struct CNonTrivialCopyInt
	{
	private:
		CNonTrivialCopyInt(int _Value);
	};

	struct CNonTrivialCopyBoth
	{
	private:
		CNonTrivialCopyBoth(CNonTrivialCopyBoth const &_Abstract);
		CNonTrivialCopyBoth(int _Value);
	};

	struct CNonTrivialCopyDerived : public CNonTrivialCopy
	{
	};

	struct CNonTrivialCopyDerivedOverride : public CNonTrivialCopy
	{
	private:
		CNonTrivialCopyDerivedOverride(CNonTrivialCopyDerivedOverride const &_Abstract);
	};

	struct CNonTrivialConstruct
	{
	private:
		CNonTrivialConstruct();
	};

	struct CNonTrivialConstructDerived : public CNonTrivialConstruct
	{
	};

	struct CNonTrivialConstructDerivedOverride : public CNonTrivialConstruct
	{
	private:
		CNonTrivialConstructDerivedOverride();
	};

	struct CTrivial
	{
	};
}
/***************************************************************************************************\
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
| Has Trivial Assignment Operator																	|
|___________________________________________________________________________________________________|
\***************************************************************************************************/

#include "Test_TypeTraits_HasTrivialAssignmentOperator.h"

/***************************************************************************************************\
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
| Has Trivial Copy Constructor																		|
|___________________________________________________________________________________________________|
\***************************************************************************************************/

#include "Test_TypeTraits_HasTrivialCopyConstructor.h"

/***************************************************************************************************\
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
| Has Trivial Default Constructor																	|
|___________________________________________________________________________________________________|
\***************************************************************************************************/

#include "Test_TypeTraits_HasTrivialDefaultConstructor.h"

/***************************************************************************************************\
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
| Has Trivial Destructor																			|
|___________________________________________________________________________________________________|
\***************************************************************************************************/

#include "Test_TypeTraits_HasTrivialDestructor.h"
