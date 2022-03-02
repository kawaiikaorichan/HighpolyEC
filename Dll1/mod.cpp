#include "pch.h"
#include "EggCarrier.h"

#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");
NJS_MATERIAL* TemporaryMaterialArray[] = { nullptr };

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		HMODULE HDText = GetModuleHandle(L"AI_char_text");
		if (HDText)
		{
			ReplacePVM("mountain_carrier", "mountain_carrier_hphd");
			ReplacePVM("ec_light", "mountain_carrier_hphd");
		}
		else
		{
			ReplacePVM("mountain_carrier", "mountain_carrier_hp");
			ReplacePVM("ec_light", "mountain_carrier_hp");
		}
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}