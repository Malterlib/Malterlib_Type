// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include "Malterlib_Type_Traits_Properties.h"

namespace NMib::NTraits
{
	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Optimal pass																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CType0>
		class TCOptimalPass
		{
		public:
			typedef typename TCChooseType<sizeof(t_CType0) <= sizeof(mint) && DMibPHasTrivialCopyConstructor(t_CType0), t_CType0, typename TCAddReference<typename TCAddConst<t_CType0>::CType>::CType>::CType CType;

		};
	}

	template <typename t_CType0>
	class TCOptimalPass : public NPrivate::TCOptimalPass<t_CType0>
	{
	public:

	};

	template <typename t_CType0, typename t_CRet = t_CType0>
	class TCOptimalPassByValue
		: public TCDisableIf<TCIsReference<typename TCOptimalPass<t_CType0>::CType>::mc_Value, t_CRet>
	{
	public:
		enum
		{
			mc_Value = !TCIsReference<typename TCOptimalPass<t_CType0>::CType>::mc_Value
		};

	};

	template <typename t_CType0, typename t_CRet = t_CType0>
	class TCOptimalPassByRef
		: public TCEnableIf<TCIsReference<typename TCOptimalPass<t_CType0>::CType>::mc_Value, t_CRet>
	{
	public:
		enum
		{
			mc_Value = TCIsReference<typename TCOptimalPass<t_CType0>::CType>::mc_Value
		};

	};
}
