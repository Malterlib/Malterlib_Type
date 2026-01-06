// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib::NTraits
{
	template <typename t_CType>
	concept cIsVolatile = std::is_volatile_v<t_CType>;

	template <typename t_CType>
	concept cIsConst = std::is_const_v<t_CType>;

	template <typename t_CType>
	using TCRemoveConst = std::remove_const_t<t_CType>;

	template <typename t_CType>
	using TCRemoveVolatile = std::remove_volatile_t<t_CType>;

	template <typename t_CType>
	using TCRemoveQualifiers = std::remove_cv_t<t_CType>;

	template <typename t_CType>
	using TCAddConst = std::add_const_t<t_CType>;

	template <typename t_CType>
	using TCAddVolatile = std::add_volatile_t<t_CType>;

	template <typename t_CType>
	using TCAddConstVolatile = std::add_cv_t<t_CType>;

	template <typename t_CType, bool t_bSetTo>
	using TCSetConst = TCConditional<t_bSetTo, TCAddConst<t_CType>, TCRemoveConst<t_CType>>;

	template <typename t_CType, bool t_bSetTo>
	using TCSetVolatile = TCConditional<t_bSetTo, TCAddVolatile<t_CType>, TCRemoveVolatile<t_CType>>;

	template <typename t_CCopyFrom, typename t_CCopyTo>
	using TCCopyConst = TCSetConst<t_CCopyTo, cIsConst<t_CCopyFrom>>;

	template <typename t_CCopyFrom, typename t_CCopyTo>
	using TCCopyVolatile = TCSetVolatile<t_CCopyTo, cIsVolatile<t_CCopyFrom>>;

	template <typename t_CCopyFrom, typename t_CCopyTo>
	using TCCopyQualifiers = TCSetConst<TCSetVolatile<t_CCopyTo, cIsVolatile<t_CCopyFrom>>, cIsConst<t_CCopyFrom>>;

	template <typename t_CCopyFrom, typename t_CCopyTo>
	using TCAddQualifiersFrom = TCConditional
		<
			cIsVolatile<t_CCopyFrom>
			, TCAddVolatile<TCConditional<cIsConst<t_CCopyFrom>, TCAddConst<t_CCopyTo>, t_CCopyTo>>
			, TCConditional<cIsConst<t_CCopyFrom>, TCAddConst<t_CCopyTo>, t_CCopyTo>
		>
	;
}
