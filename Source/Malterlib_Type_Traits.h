// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	template <typename tf_CType>
	tf_CType fg_GetType() noexcept;
}
	

#include "Malterlib_Type_Traits_CompileTimeConstant.h"
#include "Malterlib_Type_Traits_Qualifiers.h"

#include "Malterlib_Type_Traits_Properties.h"
#include "Malterlib_Type_Traits_Misc.h"
#include "Malterlib_Type_Traits_IntFloat.h"

namespace NMib::NTraits
{
	template <typename t_CType>
	class TCIsString : public TCCompileTimeConstant<bool, false>
	{
	public:
	};

	template <>	class TCIsString<const ch8 *> : public TCCompileTimeConstant<bool, true>{};
	template <>	class TCIsString<ch8 *> : public TCCompileTimeConstant<bool, true>{};
	template <>	class TCIsString<const ch16 *> : public TCCompileTimeConstant<bool, true>{};
	template <>	class TCIsString<ch16 *> : public TCCompileTimeConstant<bool, true>{};
	template <>	class TCIsString<const ch32 *> : public TCCompileTimeConstant<bool, true>{};
	template <>	class TCIsString<ch32 *> : public TCCompileTimeConstant<bool, true>{};
}

#ifndef DMibPNoShortCuts
	using namespace NMib::NTraits;
#endif

