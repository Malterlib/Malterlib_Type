// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NTraits
{
	template <typename t_CType, t_CType t_Value>
	TCCompileTimeConstant<t_CType, t_Value>::operator bool ()
	{
		return mc_Value != 0;
	}
}
