#pragma once

#include"RI.hpp"

#include"Hittable.hpp"
#include"Vector.hpp"

namespace NRI{
    class CInformation;
    class CHittable;
    
    class CRay{
        private : CVector VOrigin;
        private : CVector VDirection;

        public : CRay() noexcept = default;
        public : CRay(const CVector& POrigin , const CVector& PDirection) noexcept;
        public : const CVector& FOrigin() const noexcept;
        public : const CVector& FDirection() const noexcept;
        public : CVector FAt(float PTime) const noexcept;
    };
}