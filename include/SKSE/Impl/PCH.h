#pragma once

#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0601	 // SSE requires minimum windows 7

#include <WinSock2.h>  // must come first

#include <KnownFolders.h>
#include <ShlObj.h>
#include <xmmintrin.h>

#include <DirectXMath.h>
#include <d3d9types.h>

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <istream>
#include <iterator>
#include <limits>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <optional>
#include <regex>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

#include <nonstd/span.hpp>

namespace RE
{
	namespace stl
	{
		using nonstd::span;
	}
}

#undef AddForm
#undef far
#undef GetClassName
#undef GetFileAttributes
#undef GetForm
#undef GetObject
#undef LoadIcon
#undef max
#undef min
#undef near
#undef PlaySound
#undef ReplaceText
#undef SetForm

#undef FAR
#undef NEAR
#define FAR
#define NEAR

#pragma warning(disable : 4200)	 // nonstandard extension used : zero-sized array in struct/union
#pragma warning(disable : 4514)	 // 'function' : unreferenced inline function has been removed
#pragma warning(disable : 4710)	 // 'function' : function not inlined
#pragma warning(disable : 4711)	 // function 'function' selected for inline expansion
#pragma warning(disable : 5045)	 // Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
#pragma warning(disable : 5053)	 // support for 'explicit(<expr>)' in C++17 and earlier is a vendor extension

#undef STATIC_ASSERT
#define STATIC_ASSERT(bool_constexpr) static_assert(bool_constexpr)

#undef __MACRO_JOIN__
#undef __MACRO_JOIN_2__
#undef __MACRO_JOIN_3__
#define __MACRO_JOIN__(a, b)   __MACRO_JOIN_2__(a, b)
#define __MACRO_JOIN_2__(a, b) __MACRO_JOIN_3__(a, b)
#define __MACRO_JOIN_3__(a, b) a##b

#undef XBYAK_NO_OP_NAMES
#define XBYAK_NO_OP_NAMES

using UInt8 = unsigned char;
using UInt16 = unsigned short;
using UInt32 = unsigned long;
using UInt64 = unsigned long long;

using SInt8 = signed char;
using SInt16 = signed short;
using SInt32 = signed long;
using SInt64 = signed long long;

#include "SKSE/Impl/Atomic.h"
#include "SKSE/Impl/Util.h"

#include "REL/Relocation.h"

#include "RE/BSCore/BSCoreTypes.h"
#include "RE/Offsets/Offsets.h"
#include "RE/Offsets/Offsets_NiRTTI.h"
#include "RE/Offsets/Offsets_RTTI.h"
#include "RE/Scaleform/GTypes/SFTypes.h"
