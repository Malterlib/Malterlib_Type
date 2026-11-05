// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

#include <Mib/Core/Platform>
#include <Mib/Core/EnableIf>

namespace NMib::NTraits
{
	template <typename t_CType, t_CType t_Value>
	struct TCCompileTimeConstant
	{
		using CType = t_CType;

		operator bool ();

		static constexpr t_CType mc_Value = t_Value;
	};

	template <bool t_bTrue>
	using TCCompileTimeTrue = TCCompileTimeConstant<bool, t_bTrue>;

	using CCompileTimeTrue = TCCompileTimeTrue<true>;
	using CCompileTimeFalse = TCCompileTimeTrue<false>;

	struct CFalseBySize : public CCompileTimeFalse
	{
	private:
		uint8 mp_Member[1];
	};

	struct CTrueBySize : public CCompileTimeTrue
	{
	private:
		uint8 mp_Member[2];
	};
}

#include "Malterlib_Type_Traits_CompileTimeConstant.hpp"
