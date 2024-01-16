#include"Camera.hpp"

namespace NRI{
    CVector CCamera::FColor(const CRay& PRay , std::uint64_t PBounces , const CHittable& PWorld) const noexcept{
        if(!PBounces){
            return CVector{};
        }
        CInformation LInformation;
        if(PWorld.FHit(PRay , CInterval{0.001F , std::numeric_limits<float>::infinity()} , LInformation)){
            return 0.9F * FColor(CRay{LInformation.FCoordinates() , LInformation.FNormal() + CVector::FRandomUnit()} , PBounces - 1 , PWorld);
        }
        float LBlue{0.5F * (PRay.FDirection().FUnit()[1] + 1.0F)};
        return CVector{(1.0F - LBlue) * CVector{1.0F , 1.0F , 1.0F} + LBlue * CVector{0.5F , 0.7F , 1.0F}};
    }

    CCamera::CCamera(float PWidth , float PRatio , std::uint64_t PSamples , std::uint64_t PBounces) noexcept{
        VWidth = PWidth;
        VRatio = PRatio;
        VSamples = PSamples;
        VBounces = PBounces;
    }

    void CCamera::FRender(const CHittable& PWorld) noexcept{
        VHeight = VWidth / VRatio >= 1 ? VWidth / VRatio : 1;
        static constexpr float LHeight{2.0F};
        CVector LX{LHeight * (VWidth / VHeight) , 0.0F , 0.0F};
        CVector LY{0.0F , -LHeight, 0.0F};
        VPixelDeltaX = LX / VWidth;
        VPixelDeltaY = LY / VHeight;
        VOriginPixelLocation = VCenter - CVector{0.0F , 0.0F , 1.0F} - LX / 2.0F - LY / 2.0F + 0.5F * (VPixelDeltaX + VPixelDeltaY);
        std::cout << "P3" << "\n" << VWidth << " " << VHeight << "\n" << "255" << "\n";
	       for(float LX{0.0F} ; LX < VWidth ; LX++){
            for(float LY{0.0F} ; LY < VHeight ; LY++){
                CVector LPixel;
                for(std::uint64_t LSample{0} ; LSample < VSamples ; LSample++){
                    std::random_device LGenerator;
                    std::uniform_real_distribution<float> LDistributor(0.0F , std::numeric_limits<float>::max());
                    float LX{-0.5F + LDistributor(LGenerator)};
                    float LY{-0.5F + LDistributor(LGenerator)};
                    LPixel += FColor(CRay{
                        VCenter , CVector{VOriginPixelLocation + (static_cast<float>(LX) * VPixelDeltaX) + (static_cast<float>(LY) * VPixelDeltaY)} + (LX * VPixelDeltaX) + (LY * VPixelDeltaY) - VCenter
                    } , VBounces , PWorld);
                }
                LPixel.FPrintAsColor(VSamples);
		          }
		          std::clog << LX * 100.0F / VWidth << "\n";
	       }
    }
}