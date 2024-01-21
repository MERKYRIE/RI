#pragma once

#include"RI.hpp"

#include"Vector.hpp"

namespace NRI{
    class CHittable;
    class CRay;
    
    class CCamera{
        private : float VWidth;
        private : float VHeight;
        private : float VRatio;
        private : CVector VOriginPixelLocation;
        private : CVector VPixelDeltaX;
        private : CVector VPixelDeltaY;
        private : std::uintmax_t VSamples;
        private : std::uintmax_t VBounces;

        private : CVector FColor(const CRay& PRay , std::uintmax_t PBounces , const CHittable& PWorld) const noexcept;

        public : CCamera() noexcept = default;
        public : CCamera(float PWidth , float PRatio , std::uintmax_t PSamples = 10 , std::uintmax_t PBounces = 10) noexcept;
        public : void FRender(const CHittable& PWorld) noexcept;
    };
}