// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	template <typename tf_CType>
	tf_CType fg_GetType() noexcept;
}

#include "Malterlib_Type_Traits_CompileTimeConstant.h"

#include "Malterlib_Type_Traits_Standard.h"
#include "Malterlib_Type_Traits_Qualifiers.h"
#include "Malterlib_Type_Traits_IntFloat.h"

#include "Malterlib_Type_Traits_Function.h"
#include "Malterlib_Type_Traits_MemberFunction.h"
#include "Malterlib_Type_Traits_NewDelete.h"
#include "Malterlib_Type_Traits_Extensions.h"

#ifndef DMibPNoShortCuts
	using namespace NMib::NTraits;
#endif

