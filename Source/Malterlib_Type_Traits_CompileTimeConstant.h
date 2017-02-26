// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include <Mib/Core/Platform>
#include <Mib/Core/EnableIf>

namespace NMib
{
	namespace NTraits
	{
		template
			<
				typename t_CType
				, t_CType t_Value
			>
		struct TCCompileTimeConstant
		{
			typedef t_CType CType;

			static constexpr t_CType mc_Value = t_Value;
			operator bool ()
			{
				return mc_Value != 0;
			}
		};


		typedef TCCompileTimeConstant<bool, true> CCompileTimeTrue;
		typedef TCCompileTimeConstant<bool, false> CCompileTimeFalse;

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
}

