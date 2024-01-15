#include"RI.hpp"

#include"Ray.hpp"
#include"Vector.hpp"

std::int32_t main(){
	   constexpr float LResolution{16.0F / 9.0F};
    constexpr std::uint64_t LResolutionWidth{400};
    constexpr std::uint64_t LResolutionHeight{static_cast<std::uint64_t>(LResolutionWidth / LResolution) >= 1 ? static_cast<std::uint64_t>(LResolutionWidth / LResolution) : 1};
    constexpr float LViewportHeight{2.0F};
    constexpr float LViewportWidth{LViewportHeight * (static_cast<float>(LResolutionWidth) / static_cast<float>(LResolutionHeight))};
    constexpr float LFocalLength{1.0F};
    NRI::CVector LCameraCenter;
    NRI::CVector LViewportX{LViewportWidth , 0.0F , 0.0F};
    NRI::CVector LViewportY{0.0F , -LViewportHeight, 0.0F};
    NRI::CVector LPixelDeltaX{LViewportX / LResolutionWidth};
    NRI::CVector LPixelDeltaY{LViewportY / LResolutionHeight};
    NRI::CVector LViewportOrigin{LCameraCenter - NRI::CVector{0.0F , 0.0F , LFocalLength} - LViewportX / 2.0F - LViewportY / 2.0F};
    NRI::CVector LOriginPixelLocation{LViewportOrigin + 0.5F * (LPixelDeltaX + LPixelDeltaY)};
	   constexpr std::uint64_t LImageWidth{256};
	   constexpr std::uint64_t LImageHeight{256};
	   std::cout << "P3" << "\n" << LImageWidth << " " << LImageHeight << "\n" << "255" << "\n";
	   for(std::uint64_t LX{0} ; LX < LImageWidth ; LX++){
		      std::clog << "Progress: " << LX * 100 / LImageWidth << "%" << "\n";
        for(std::uint64_t LY{0} ; LY < LImageHeight ; LY++){
            NRI::CVector LPixelCenter{LOriginPixelLocation + (static_cast<float>(LX) * LPixelDeltaX) + (static_cast<float>(LY) * LPixelDeltaY)};
            NRI::CVector LRayDirection{LPixelCenter - LCameraCenter};
            NRI::CRay LRay{LCameraCenter , LRayDirection};
            NRI::CVector LPixelColor{LRay.FColor()};
            LPixelColor.FPrintAsColor();
		      }
	   }
    std::clog << "Done!" << "\n";
	   return 0;
}