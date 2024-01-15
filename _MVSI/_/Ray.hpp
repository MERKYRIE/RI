#pragma once

#include"RI.hpp"

#include"HitInformation.hpp"
#include"Hittable.hpp"
#include"Vector.hpp"

namespace NRI{
    class CHittable;
    
    class CRay{
        private : CVector VOrigin;
        private : CVector VDirection;

        public : CRay() noexcept = default;
        public : CRay(const CVector& POrigin , const CVector& PDirection) noexcept;
        public : CVector FOrigin() const noexcept;
        public : CVector FDirection() const noexcept;
        public : CVector FAt(float PTime) const noexcept;
        public : CVector FColor(const CHittable& PWorld) const noexcept;
        public : float FHit(const CVector& PCenter , float PRadius) const noexcept;
    };
}