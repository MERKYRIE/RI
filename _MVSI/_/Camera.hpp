#pragma once

#include"RI.hpp"

#include"Hittable.hpp"

namespace NRI{
    class CCamera{
        private : float VWidth;
        private : float VHeight;
        private : float VRatio;
        private : CVector VCenter;
        private : CVector VOriginPixelLocation;
        private : CVector VPixelDeltaX;
        private : CVector VPixelDeltaY;
        private : std::uint64_t VSamples;
        private : std::uint64_t VBounces;

        private : CVector FColor(const CRay& PRay , std::uint64_t PBounces , const CHittable& PWorld) const noexcept;

        public : CCamera() noexcept = default;
        public : CCamera(float PWidth , float PRatio , std::uint64_t PSamples = 10 , std::uint64_t PBounces = 10) noexcept;
        public : void FRender(const CHittable& PWorld) noexcept;
    };
}