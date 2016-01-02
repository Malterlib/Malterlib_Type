// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NTrivial
{
	class CNonTrivialAssignment
	{
		CNonTrivialAssignment &operator =(CNonTrivialAssignment const&_Abstract);
	};
	class CNonTrivialAssignmentInt
	{
		CNonTrivialAssignmentInt &operator = (int);
	};
	class CNonTrivialAssignmentBoth
	{
		CNonTrivialAssignmentBoth &operator =(CNonTrivialAssignmentBoth const&_Abstract);
		CNonTrivialAssignmentBoth &operator = (int);
	};
	class CNonTrivialAssignmentDerived : public CNonTrivialAssignment
	{
	};

	class CNonTrivialAssignmentDerivedOverride : public CNonTrivialAssignment
	{
		CNonTrivialAssignmentDerivedOverride &operator =(CNonTrivialAssignmentDerivedOverride const&_Abstract);
		
	};

	class CNonTrivialCopy
	{
		CNonTrivialCopy(CNonTrivialCopy const&_Abstract);
	};
	class CNonTrivialCopyInt
	{
		CNonTrivialCopyInt(int);
	};
	class CNonTrivialCopyBoth
	{
		CNonTrivialCopyBoth(CNonTrivialCopyBoth const&_Abstract);
		CNonTrivialCopyBoth(int);
	};
	class CNonTrivialCopyDerived : public CNonTrivialCopy
	{
	};

	class CNonTrivialCopyDerivedOverride : public CNonTrivialCopy
	{
		CNonTrivialCopyDerivedOverride(CNonTrivialCopyDerivedOverride const&_Abstract);
	};


	class CNonTrivialConstruct
	{
		CNonTrivialConstruct();
	};
	class CNonTrivialConstructDerived : public CNonTrivialConstruct
	{
	};

	class CNonTrivialConstructDerivedOverride : public CNonTrivialConstruct
	{
		CNonTrivialConstructDerivedOverride();
	};


	class CTrivial
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
