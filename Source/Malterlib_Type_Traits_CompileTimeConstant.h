// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include <Mib/Core/Platform>
#include <Mib/Core/EnableIf>

namespace NMib::NTraits
{
	template
	<
		typename t_CType
		, t_CType t_Value
	>
	struct TCCompileTimeConstant
	{
		using CType = t_CType;

		static constexpr t_CType mc_Value = t_Value;
		operator bool ()
		{
			return mc_Value != 0;
		}
	};

	template <bool t_bTrue>
	using TCCompileTimeTrue = TCCompileTimeConstant<bool, t_bTrue>;

	using CCompileTimeTrue = TCCompileTimeTrue<true>;
	using CCompileTimeFalse = TCCompileTimeTrue<false>;

	class CFalseBySize : public CCompileTimeFalse
	{
		uint8 m_Member[1];
	public:
	};

	class CTrueBySize : public CCompileTimeTrue
	{
		uint8 m_Member[2];
	public:
	};
}
