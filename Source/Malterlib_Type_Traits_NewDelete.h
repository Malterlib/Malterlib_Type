// Copyright © 2025 Unbroken AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib::NTraits
{
	namespace NPrivate
	{
		template <typename t_CType>
		concept cHasOperator_New_0 = requires (std::size_t _Size)
			{
				t_CType::operator new(_Size);
			}
		;
		template <typename t_CType>
		concept cHasOperator_New_1 = requires (std::size_t _Size, std::align_val_t _Align)
			{
				t_CType::operator new(_Size, _Align);
			}
		;
		template <typename t_CType>
		concept cHasOperator_New_2 = requires (std::size_t _Size)
			{
				&t_CType::operator new;
			}
		;
		template <typename t_CType>
		concept cHasOperator_NewArray_0 = requires (std::size_t _Size)
			{
				t_CType::operator new [](_Size);
			}
		;
		template <typename t_CType>
		concept cHasOperator_NewArray_1 = requires (std::size_t _Size, std::align_val_t _Align)
			{
				t_CType::operator new [](_Size, _Align);
			}
		;
		template <typename t_CType>
		concept cHasOperator_NewArray_2 = requires (void *_pMemory, std::size_t _Size)
			{
				&t_CType::operator new [];
			}
		;
	}

	template <typename t_CType>
	concept cHasOperatorNewArray
		= NPrivate::cHasOperator_NewArray_0<t_CType>
		|| NPrivate::cHasOperator_NewArray_1<t_CType>
		|| NPrivate::cHasOperator_NewArray_2<t_CType>
	;

	template <typename t_CType>
	concept cHasOperatorNew
		= NPrivate::cHasOperator_New_0<t_CType>
		|| NPrivate::cHasOperator_New_1<t_CType>
		|| NPrivate::cHasOperator_New_2<t_CType>
	;

	template <typename t_CType>
	concept cHasOperatorNewAny = cHasOperatorNew<t_CType> || cHasOperatorNewArray<t_CType>;

	namespace NPrivate
	{
		template <typename t_CType>
		concept cHasOperator_Delete_0 = requires (void *_pMemory)
			{
				t_CType::operator delete(_pMemory);
			}
		;
		template <typename t_CType>
		concept cHasOperator_Delete_1 = requires (void *_pMemory, std::size_t _Size)
			{
				t_CType::operator delete(_pMemory, _Size);
			}
		;
		template <typename t_CType>
		concept cHasOperator_Delete_2 = requires (t_CType *_pMemory, std::destroying_delete_t)
			{
				t_CType::operator delete(_pMemory, std::destroying_delete);
			}
		;
		template <typename t_CType>
		concept cHasOperator_Delete_3 = requires (t_CType *_pMemory, std::destroying_delete_t, std::size_t _Size)
			{
				t_CType::operator delete(_pMemory, std::destroying_delete, _Size);
			}
		;
		template <typename t_CType>
		concept cHasOperator_Delete_4 = requires (void *_pMemory)
			{
				&t_CType::operator delete;
			}
		;
		template <typename t_CType>
		concept cHasOperator_DeleteArray_0 = requires (void *_pMemory)
			{
				t_CType::operator delete [](_pMemory);
			}
		;
		template <typename t_CType>
		concept cHasOperator_DeleteArray_1 = requires (void *_pMemory, std::size_t _Size)
			{
				t_CType::operator delete [](_pMemory, _Size);
			}
		;
		template <typename t_CType>
		concept cHasOperator_DeleteArray_2 = requires (void *_pMemory, std::size_t _Size)
			{
				&t_CType::operator delete [];
			}
		;
	}

	template <typename t_CType>
	concept cHasOperatorDeleteArray
		= NPrivate::cHasOperator_DeleteArray_0<t_CType>
		|| NPrivate::cHasOperator_DeleteArray_1<t_CType>
		|| NPrivate::cHasOperator_DeleteArray_2<t_CType>
	;

	template <typename t_CType>
	concept cHasOperatorDelete
		= NPrivate::cHasOperator_Delete_0<t_CType>
		|| NPrivate::cHasOperator_Delete_1<t_CType>
		|| NPrivate::cHasOperator_Delete_2<t_CType>
		|| NPrivate::cHasOperator_Delete_3<t_CType>
		|| NPrivate::cHasOperator_Delete_4<t_CType>
	;

	template <typename t_CType>
	concept cHasOperatorDeleteAny = cHasOperatorDelete<t_CType> || cHasOperatorDeleteArray<t_CType>;
}
