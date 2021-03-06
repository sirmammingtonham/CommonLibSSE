#pragma once

#include "RE/BSCore/BSString.h"
#include "RE/BSCore/BSTSingleton.h"
#include "RE/Scaleform/GFxPlayer/GFxMovieView.h"
#include "RE/Scaleform/GRefCount/GPtr.h"


namespace RE
{
	class BSScaleformImageLoader;
	class GFxDrawTextManager;
	class GFxLoader;
	class GFxMovieDef;
	class GFxRenderConfig;
	class IMenu;


	struct BSScaleformRenderer
	{
	public:
		// members
		GPtr<GFxRenderConfig> config;  // 0
	};
	STATIC_ASSERT(sizeof(BSScaleformRenderer) == 0x8);


	class BSScaleformManager : public BSTSingletonSDM<BSScaleformManager>
	{
	public:
		using ScaleModeType = GFxMovieView::ScaleModeType;


		static BSScaleformManager* GetSingleton();

		bool LoadMovie(IMenu* a_menu, GPtr<GFxMovieView>& a_viewOut, const char* a_fileName, ScaleModeType a_mode = ScaleModeType::kShowAll, float a_backGroundAlpha = 0.0);

		bool LoadMovieEx(IMenu* a_menu, std::string_view a_fileName, std::function<void(GFxMovieDef*)> a_callback);
		bool LoadMovieEx(IMenu* a_menu, std::string_view a_fileName, ScaleModeType a_mode, std::function<void(GFxMovieDef*)> a_callback);
		bool LoadMovieEx(IMenu* a_menu, std::string_view a_fileName, ScaleModeType a_mode, float a_backGroundAlpha, std::function<void(GFxMovieDef*)> a_callback);

		[[deprecated("Use LoadMovieEx")]] bool LoadMovieStd(IMenu* a_menu, const char* a_fileName, std::function<void(GFxMovieDef*)> a_callback, ScaleModeType a_mode = ScaleModeType::kShowAll, float a_backGroundAlpha = 0.0);

		bool LoadMovie_Impl(IMenu* a_menu, GPtr<GFxMovieView>& a_viewOut, const char* a_fileName, ScaleModeType a_mode = ScaleModeType::kShowAll, float a_backGroundAlpha = 0.0);


		// members
		UInt8						 pad01;			  // 01
		UInt16						 pad02;			  // 02
		UInt32						 pad04;			  // 04
		GFxLoader*					 loader;		  // 08
		BSScaleformRenderer*		 renderer;		  // 10
		GPtr<GFxDrawTextManager>	 textManager;	  // 18
		GPtr<BSScaleformImageLoader> imageLoader;	  // 20
		BSString					 validNameChars;  // 28
		UInt64						 unk38;			  // 38

	private:
		std::optional<std::string>				 BuildFilePath(std::string_view a_fileName);
		std::tuple<float, float, SInt32, SInt32> CollectDisplayInfo();
		bool									 FileExists(std::string_view a_fileName);
	};
	STATIC_ASSERT(sizeof(BSScaleformManager) == 0x40);
}
