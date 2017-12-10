// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

// Is Int
	
#ifdef DMibPCanDo_int8192
DMibStaticCheck((	TCIsFundamental<int8192>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_int4096
DMibStaticCheck((	TCIsFundamental<int4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_int2048
DMibStaticCheck((	TCIsFundamental<int2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_int1024
DMibStaticCheck((	TCIsFundamental<int1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_int512
DMibStaticCheck((	TCIsFundamental<int512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int512>::mc_Value	));
#endif
#ifdef DMibPCanDo_int256
DMibStaticCheck((	TCIsFundamental<int256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int256>::mc_Value	));
#endif
#ifdef DMibPCanDo_int160
DMibStaticCheck((	TCIsFundamental<int160>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int160>::mc_Value	));
#endif
#ifdef DMibPCanDo_int128
DMibStaticCheck((	TCIsFundamental<int128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int128>::mc_Value	));
#endif
#ifdef DMibPCanDo_int80
DMibStaticCheck((	TCIsFundamental<int80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int80>::mc_Value	));
#endif
#ifdef DMibPCanDo_int64
DMibStaticCheck((	TCIsFundamental<int64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int64>::mc_Value	));
#endif
#ifdef DMibPCanDo_int32
DMibStaticCheck((	TCIsFundamental<int32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int32>::mc_Value	));
#endif
#ifdef DMibPCanDo_int16
DMibStaticCheck((	TCIsFundamental<int16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int16>::mc_Value	));
#endif
#ifdef DMibPCanDo_int8
DMibStaticCheck((	TCIsFundamental<int8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int8>::mc_Value	));
#endif


// These must always be fundamental
DMibStaticCheck((	TCIsFundamental<aint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<uaint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<smint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<mint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<int>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<unsigned int>::mc_Value	));

#ifdef DMibPCanDo_uint8192
DMibStaticCheck((	TCIsFundamental<uint8192>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint4096
DMibStaticCheck((	TCIsFundamental<uint4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint2048
DMibStaticCheck((	TCIsFundamental<uint2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint1024
DMibStaticCheck((	TCIsFundamental<uint1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint512
DMibStaticCheck((	TCIsFundamental<uint512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint512>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint256
DMibStaticCheck((	TCIsFundamental<uint256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint256>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint160
DMibStaticCheck((	TCIsFundamental<uint160>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint160>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint128
DMibStaticCheck((	TCIsFundamental<uint128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint128>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint80
DMibStaticCheck((	TCIsFundamental<uint80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint80>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint64
DMibStaticCheck((	TCIsFundamental<uint64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint64>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint32
DMibStaticCheck((	TCIsFundamental<uint32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint32>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint16
DMibStaticCheck((	TCIsFundamental<uint16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint16>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint8
DMibStaticCheck((	TCIsFundamental<uint8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint8>::mc_Value	));
#endif

#ifdef DMibPCanDo_fp4096
DMibStaticCheck((	TCIsFundamental<pfp4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp2048
DMibStaticCheck((	TCIsFundamental<pfp2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp1024
DMibStaticCheck((	TCIsFundamental<pfp1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp512
DMibStaticCheck((	TCIsFundamental<pfp512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp512>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp256
DMibStaticCheck((	TCIsFundamental<pfp256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp256>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp128
DMibStaticCheck((	TCIsFundamental<pfp128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp128>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp80
DMibStaticCheck((	TCIsFundamental<pfp80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp80>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp64
DMibStaticCheck((	TCIsFundamental<pfp64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp64>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp32
DMibStaticCheck((	TCIsFundamental<pfp32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp32>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp16
DMibStaticCheck((	TCIsFundamental<pfp16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp16>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp8
DMibStaticCheck((	TCIsFundamental<pfp8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp8>::mc_Value	));
#endif

#ifdef DMibPCanDo_int8192
DMibStaticCheck((	TCIsFundamental<const int8192>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_int4096
DMibStaticCheck((	TCIsFundamental<const int4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_int2048
DMibStaticCheck((	TCIsFundamental<const int2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_int1024
DMibStaticCheck((	TCIsFundamental<const int1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_int512
DMibStaticCheck((	TCIsFundamental<const int512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int512>::mc_Value	));
#endif
#ifdef DMibPCanDo_int256
DMibStaticCheck((	TCIsFundamental<const int256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int256>::mc_Value	));
#endif
#ifdef DMibPCanDo_int160
DMibStaticCheck((	TCIsFundamental<const int160>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int160>::mc_Value	));
#endif
#ifdef DMibPCanDo_int128
DMibStaticCheck((	TCIsFundamental<const int128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int128>::mc_Value	));
#endif
#ifdef DMibPCanDo_int80
DMibStaticCheck((	TCIsFundamental<const int80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int80>::mc_Value	));
#endif
#ifdef DMibPCanDo_int64
DMibStaticCheck((	TCIsFundamental<const int64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int64>::mc_Value	));
#endif
#ifdef DMibPCanDo_int32
DMibStaticCheck((	TCIsFundamental<const int32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int32>::mc_Value	));
#endif
#ifdef DMibPCanDo_int16
DMibStaticCheck((	TCIsFundamental<const int16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int16>::mc_Value	));
#endif
#ifdef DMibPCanDo_int8
DMibStaticCheck((	TCIsFundamental<const int8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int8>::mc_Value	));
#endif

// These must always be fundamental
DMibStaticCheck((	TCIsFundamental<const aint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<const uaint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<const smint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<const mint>::mc_Value	));

#ifdef DMibPCanDo_uint8192
DMibStaticCheck((	TCIsFundamental<const uint8192>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint4096
DMibStaticCheck((	TCIsFundamental<const uint4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint2048
DMibStaticCheck((	TCIsFundamental<const uint2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint1024
DMibStaticCheck((	TCIsFundamental<const uint1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint512
DMibStaticCheck((	TCIsFundamental<const uint512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint512>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint256
DMibStaticCheck((	TCIsFundamental<const uint256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint256>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint160
DMibStaticCheck((	TCIsFundamental<const uint160>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint160>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint128
DMibStaticCheck((	TCIsFundamental<const uint128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint128>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint80
DMibStaticCheck((	TCIsFundamental<const uint80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint80>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint64
DMibStaticCheck((	TCIsFundamental<const uint64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint64>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint32
DMibStaticCheck((	TCIsFundamental<const uint32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint32>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint16
DMibStaticCheck((	TCIsFundamental<const uint16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint16>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint8
DMibStaticCheck((	TCIsFundamental<const uint8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint8>::mc_Value	));
#endif

#ifdef DMibPCanDo_fp4096
DMibStaticCheck((	TCIsFundamental<const pfp4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp2048
DMibStaticCheck((	TCIsFundamental<const pfp2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp1024
DMibStaticCheck((	TCIsFundamental<const pfp1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp512
DMibStaticCheck((	TCIsFundamental<const pfp512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp512>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp256
DMibStaticCheck((	TCIsFundamental<const pfp256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp256>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp128
DMibStaticCheck((	TCIsFundamental<const pfp128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp128>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp80
DMibStaticCheck((	TCIsFundamental<const pfp80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp80>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp64
DMibStaticCheck((	TCIsFundamental<const pfp64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp64>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp32
DMibStaticCheck((	TCIsFundamental<const pfp32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp32>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp16
DMibStaticCheck((	TCIsFundamental<const pfp16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp16>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp8
DMibStaticCheck((	TCIsFundamental<const pfp8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp8>::mc_Value	));
#endif

#ifdef DMibPCanDo_int8192
DMibStaticCheck((	TCIsFundamental<volatile int8192>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_int4096
DMibStaticCheck((	TCIsFundamental<volatile int4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_int2048
DMibStaticCheck((	TCIsFundamental<volatile int2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_int1024
DMibStaticCheck((	TCIsFundamental<volatile int1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_int512
DMibStaticCheck((	TCIsFundamental<volatile int512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int512>::mc_Value	));
#endif
#ifdef DMibPCanDo_int256
DMibStaticCheck((	TCIsFundamental<volatile int256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int256>::mc_Value	));
#endif
#ifdef DMibPCanDo_int160
DMibStaticCheck((	TCIsFundamental<volatile int160>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int160>::mc_Value	));
#endif
#ifdef DMibPCanDo_int128
DMibStaticCheck((	TCIsFundamental<volatile int128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int128>::mc_Value	));
#endif
#ifdef DMibPCanDo_int80
DMibStaticCheck((	TCIsFundamental<volatile int80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int80>::mc_Value	));
#endif
#ifdef DMibPCanDo_int64
DMibStaticCheck((	TCIsFundamental<volatile int64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int64>::mc_Value	));
#endif
#ifdef DMibPCanDo_int32
DMibStaticCheck((	TCIsFundamental<volatile int32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int32>::mc_Value	));
#endif
#ifdef DMibPCanDo_int16
DMibStaticCheck((	TCIsFundamental<volatile int16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int16>::mc_Value	));
#endif
#ifdef DMibPCanDo_int8
DMibStaticCheck((	TCIsFundamental<volatile int8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile int8>::mc_Value	));
#endif

// These must always be fundamental
DMibStaticCheck((	TCIsFundamental<volatile aint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<volatile uaint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<volatile smint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<volatile mint>::mc_Value	));

#ifdef DMibPCanDo_uint8192
DMibStaticCheck((	TCIsFundamental<volatile uint8192>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint4096
DMibStaticCheck((	TCIsFundamental<volatile uint4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint2048
DMibStaticCheck((	TCIsFundamental<volatile uint2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint1024
DMibStaticCheck((	TCIsFundamental<volatile uint1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint512
DMibStaticCheck((	TCIsFundamental<volatile uint512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint512>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint256
DMibStaticCheck((	TCIsFundamental<volatile uint256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint256>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint160
DMibStaticCheck((	TCIsFundamental<volatile uint160>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint160>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint128
DMibStaticCheck((	TCIsFundamental<volatile uint128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint128>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint80
DMibStaticCheck((	TCIsFundamental<volatile uint80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint80>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint64
DMibStaticCheck((	TCIsFundamental<volatile uint64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint64>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint32
DMibStaticCheck((	TCIsFundamental<volatile uint32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint32>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint16
DMibStaticCheck((	TCIsFundamental<volatile uint16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint16>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint8
DMibStaticCheck((	TCIsFundamental<volatile uint8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile uint8>::mc_Value	));
#endif

#ifdef DMibPCanDo_fp4096
DMibStaticCheck((	TCIsFundamental<volatile pfp4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile fp4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp2048
DMibStaticCheck((	TCIsFundamental<volatile pfp2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile fp2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp1024
DMibStaticCheck((	TCIsFundamental<volatile pfp1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile fp1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp512
DMibStaticCheck((	TCIsFundamental<volatile pfp512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile fp512>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp256
DMibStaticCheck((	TCIsFundamental<volatile pfp256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile fp256>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp128
DMibStaticCheck((	TCIsFundamental<volatile pfp128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile fp128>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp80
DMibStaticCheck((	TCIsFundamental<volatile pfp80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile fp80>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp64
DMibStaticCheck((	TCIsFundamental<volatile pfp64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile fp64>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp32
DMibStaticCheck((	TCIsFundamental<volatile pfp32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile fp32>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp16
DMibStaticCheck((	TCIsFundamental<volatile pfp16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile fp16>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp8
DMibStaticCheck((	TCIsFundamental<volatile pfp8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<volatile fp8>::mc_Value	));
#endif


#ifdef DMibPCanDo_int8192
DMibStaticCheck((	TCIsFundamental<const volatile int8192>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_int4096
DMibStaticCheck((	TCIsFundamental<const volatile int4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_int2048
DMibStaticCheck((	TCIsFundamental<const volatile int2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_int1024
DMibStaticCheck((	TCIsFundamental<const volatile int1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_int512
DMibStaticCheck((	TCIsFundamental<const volatile int512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int512>::mc_Value	));
#endif
#ifdef DMibPCanDo_int256
DMibStaticCheck((	TCIsFundamental<const volatile int256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int256>::mc_Value	));
#endif
#ifdef DMibPCanDo_int160
DMibStaticCheck((	TCIsFundamental<const volatile int160>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int160>::mc_Value	));
#endif
#ifdef DMibPCanDo_int128
DMibStaticCheck((	TCIsFundamental<const volatile int128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int128>::mc_Value	));
#endif
#ifdef DMibPCanDo_int80
DMibStaticCheck((	TCIsFundamental<const volatile int80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int80>::mc_Value	));
#endif
#ifdef DMibPCanDo_int64
DMibStaticCheck((	TCIsFundamental<const volatile int64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int64>::mc_Value	));
#endif
#ifdef DMibPCanDo_int32
DMibStaticCheck((	TCIsFundamental<const volatile int32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int32>::mc_Value	));
#endif
#ifdef DMibPCanDo_int16
DMibStaticCheck((	TCIsFundamental<const volatile int16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int16>::mc_Value	));
#endif
#ifdef DMibPCanDo_int8
DMibStaticCheck((	TCIsFundamental<const volatile int8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile int8>::mc_Value	));
#endif

// These must always be fundamental
DMibStaticCheck((	TCIsFundamental<const volatile aint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<const volatile uaint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<const volatile smint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<const volatile mint>::mc_Value	));

#ifdef DMibPCanDo_uint8192
DMibStaticCheck((	TCIsFundamental<const volatile uint8192>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint4096
DMibStaticCheck((	TCIsFundamental<const volatile uint4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint2048
DMibStaticCheck((	TCIsFundamental<const volatile uint2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint1024
DMibStaticCheck((	TCIsFundamental<const volatile uint1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint512
DMibStaticCheck((	TCIsFundamental<const volatile uint512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint512>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint256
DMibStaticCheck((	TCIsFundamental<const volatile uint256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint256>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint160
DMibStaticCheck((	TCIsFundamental<const volatile uint160>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint160>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint128
DMibStaticCheck((	TCIsFundamental<const volatile uint128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint128>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint80
DMibStaticCheck((	TCIsFundamental<const volatile uint80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint80>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint64
DMibStaticCheck((	TCIsFundamental<const volatile uint64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint64>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint32
DMibStaticCheck((	TCIsFundamental<const volatile uint32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint32>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint16
DMibStaticCheck((	TCIsFundamental<const volatile uint16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint16>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint8
DMibStaticCheck((	TCIsFundamental<const volatile uint8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile uint8>::mc_Value	));
#endif

#ifdef DMibPCanDo_fp4096
DMibStaticCheck((	TCIsFundamental<const volatile pfp4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile fp4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp2048
DMibStaticCheck((	TCIsFundamental<const volatile pfp2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile fp2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp1024
DMibStaticCheck((	TCIsFundamental<const volatile pfp1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile fp1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp512
DMibStaticCheck((	TCIsFundamental<const volatile pfp512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile fp512>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp256
DMibStaticCheck((	TCIsFundamental<const volatile pfp256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile fp256>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp128
DMibStaticCheck((	TCIsFundamental<const volatile pfp128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile fp128>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp80
DMibStaticCheck((	TCIsFundamental<const volatile pfp80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile fp80>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp64
DMibStaticCheck((	TCIsFundamental<const volatile pfp64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile fp64>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp32
DMibStaticCheck((	TCIsFundamental<const volatile pfp32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile fp32>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp16
DMibStaticCheck((	TCIsFundamental<const volatile pfp16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile fp16>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp8
DMibStaticCheck((	TCIsFundamental<const volatile pfp8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const volatile fp8>::mc_Value	));
#endif



DMibStaticCheck((	!TCIsFundamental<CTestUnion>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestClass0>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestClass1>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestStruct0>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestStruct1>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<ETestEnum>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestClass>::mc_Value				));
DMibStaticCheck((	!TCIsFundamental<CTestC>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestV>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestCV>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestCPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestVPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestCVPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestVPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestCVPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestPtrV>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestCPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestVPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestCVPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestCPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestVPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestCVPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestRef>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestCRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestVRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestCVRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestRRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestCRRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestVRRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestCVRRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<PFFunc0>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<PFFunc1>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<PFFunc2>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc0Ref>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1Ref>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2Ref>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc0RRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1RRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2RRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc0Ptr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc1Ptr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc2Ptr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc0PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc0PtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1PtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2PtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc0PtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1PtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2PtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0Ptr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1Ptr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2Ptr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0PtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1PtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2PtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0PtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1PtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2PtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0CPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1CPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2CPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0CPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1CPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2CPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0CPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1CPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2CPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0CPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1CPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2CPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0VPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1VPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2VPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0VPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1VPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2VPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0VPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1VPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2VPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0VPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1VPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2VPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0CVPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1CVPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2CVPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0CVPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1CVPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2CVPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0CVPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1CVPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2CVPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0CVPtrCV>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<FMFunc1CVPtrCV>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<FMFunc2CVPtrCV>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<PFFunc0El>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<PFFunc1El>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<PFFunc2El>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc0ElRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1ElRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2ElRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc0ElRRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1ElRRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2ElRRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc0ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc0ElPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1ElPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2ElPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc0ElPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1ElPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2ElPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElCPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElCPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElCPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElCPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElCPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElCPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElVPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElVPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElVPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElVPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElVPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElVPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElVPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElVPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElVPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElVPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElVPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElVPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElCVPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElCVPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElCVPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElCVPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElCVPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElCVPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElCVPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElCVPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElCVPtrV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElCVPtrCV>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElCVPtrCV>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElCVPtrCV>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<CMPtr>::mc_Value				));
DMibStaticCheck((	!TCIsFundamental<CMCPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMVPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMCVPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMCPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMVPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMCVPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMPtrV>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMCPtrV>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMVPtrV>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMCVPtrV>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMPtrCV>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMCPtrCV>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMVPtrCV>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMCVPtrCV>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestArray2>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestArray2C>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestArray2V>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestArray2CV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestArray>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestArrayC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestArrayV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestArrayCV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest2DArray2>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest2DArray2C>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<CTest2DArray2V>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<CTest2DArray2CV>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<CTest2DArray>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest2DArrayC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest2DArrayV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest2DArrayCV>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<CTest3DArray2>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest3DArray2C>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<CTest3DArray2V>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<CTest3DArray2CV>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<CTest3DArray>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest3DArrayC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest3DArrayV>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest3DArrayCV>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<void *>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<void>::mc_Value				));

