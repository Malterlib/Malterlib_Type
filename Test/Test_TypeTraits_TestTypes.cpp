// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Test_TypeTraits_TestTypes.h"

int CTestStruct3::f_Member()
{
	return 0;
}

int CTestStruct4::f_Member(int _Value)
{
	return 1;
}

int CTestStruct5::fs_Member()
{
	return 0;
}

int CTestStruct6::fs_Member(int _Value)
{
	return 1;
}

int CTestStruct7::f_Member()
{
	return 0;
}

int CTestStruct7::f_Member(int _Value)
{
	return 1;
}

int CTestStruct8::fs_Member()
{
	return 0;
}

int CTestStruct8::fs_Member(int _Value)
{
	return 1;
}

int CTestStruct9::f_Member()
{
	return 0;
}

int CTestStruct9::fs_Member(int _Value)
{
	return 1;
}

int CTestUnion3::f_Member()
{
	return 0;
}

int CTestUnion4::f_Member(int _Value)
{
	return 1;
}

int CTestUnion5::fs_Member()
{
	return 0;
}

int CTestUnion6::fs_Member(int _Value)
{
	return 1;
}

int CTestUnion7::f_Member()
{
	return 1;
}

int CTestUnion7::fs_Member(int _Value)
{
	return 1;
}

void CTestClassVirtual::f_Test()
{
}

CTestClassWithDestructor::~CTestClassWithDestructor()
{
}

CTestClassWithDestructorNonTrivial::~CTestClassWithDestructorNonTrivial()
{
	m_Test = 2;
}

CTestClassWithConstructor::CTestClassWithConstructor()
{
}

CTestClassWithConstructorNonTrivial::CTestClassWithConstructorNonTrivial()
{
	m_Test = 3;
}

CTestClassWithCopyConstructor::CTestClassWithCopyConstructor(CTestClassWithCopyConstructor const &_Other)
	: m_Test(_Other.m_Test)
{
}

CTestClassWithCopyConstructorNonTrivial::CTestClassWithCopyConstructorNonTrivial(CTestClassWithCopyConstructorNonTrivial const &_Other)
{
	m_Test = _Other.m_Test + 1;
}

CTestClassWithMoveConstructor::CTestClassWithMoveConstructor(CTestClassWithCopyConstructor const &&_Other)
	: m_Test(_Other.m_Test)
{
}

CTestClassWithMoveConstructorNonTrivial::CTestClassWithMoveConstructorNonTrivial(CTestClassWithMoveConstructorNonTrivial const &&_Other)
{
	m_Test = _Other.m_Test + 1;
}

CTestClassWithPrivateConstructor::CTestClassWithPrivateConstructor()
{
}

CTestClassWithPrivateDestructor::CTestClassWithPrivateDestructor()
{
}

CTestNoDefaultConstruct::CTestNoDefaultConstruct(int &&_Value)
	: m_Value(_Value)
{
}
