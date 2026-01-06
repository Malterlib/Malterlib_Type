// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NNothrow
{
	struct CThrowsAssignment
	{
		CThrowsAssignment &operator =(CThrowsAssignment const&_Abstract);
	};
	struct CThrowsAssignmentInt
	{
		CThrowsAssignmentInt &operator = (int);
	};
	struct CThrowsAssignmentBoth
	{
		CThrowsAssignmentBoth &operator =(CThrowsAssignmentBoth const&_Abstract);
		CThrowsAssignmentBoth &operator = (int);
	};
	struct CThrowsAssignmentDerived : public CThrowsAssignment
	{
	};

	struct CThrowsAssignmentDerivedOverride : public CThrowsAssignment
	{
		CThrowsAssignmentDerivedOverride &operator =(CThrowsAssignmentDerivedOverride const&_Abstract) noexcept;

	};

	struct CThrowsCopy
	{
		CThrowsCopy() noexcept;
		CThrowsCopy(CThrowsCopy const&_Abstract);
	};
	struct CThrowsCopyInt
	{
		CThrowsCopyInt() noexcept;
		CThrowsCopyInt(int);
	};
	struct CThrowsCopyBoth
	{
		CThrowsCopyBoth() noexcept;
		CThrowsCopyBoth(CThrowsCopyBoth const&_Abstract);
		CThrowsCopyBoth(int);
	};
	struct CThrowsCopyDerived : public CThrowsCopy
	{
	};

	struct CThrowsCopyDerivedOverride : public CThrowsCopy
	{
		CThrowsCopyDerivedOverride() noexcept;
		CThrowsCopyDerivedOverride(CThrowsCopyDerivedOverride const&_Abstract) noexcept;
	};


	struct CThrowsConstruct
	{
		CThrowsConstruct();
	};
	struct CThrowsConstructDerived : public CThrowsConstruct
	{
	};

	struct CThrowsConstructDerivedOverride : public CThrowsConstruct
	{
		CThrowsConstructDerivedOverride() noexcept;
	};


	struct CNothrow
	{
	};

	struct CNothrowDefault
	{
		CNothrowDefault() noexcept;
	};

}
/***************************************************************************************************\
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
| Has Nothrow Assignment Operator																	|
|___________________________________________________________________________________________________|
\***************************************************************************************************/

#include "Test_TypeTraits_HasNothrowAssignmentOperator.h"

/***************************************************************************************************\
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
| Has Nothrow Copy Constructor																		|
|___________________________________________________________________________________________________|
\***************************************************************************************************/

#include "Test_TypeTraits_HasNothrowCopyConstructor.h"

/***************************************************************************************************\
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
| Has Nothrow Default Constructor																	|
|___________________________________________________________________________________________________|
\***************************************************************************************************/

#include "Test_TypeTraits_HasNothrowDefaultConstructor.h"
