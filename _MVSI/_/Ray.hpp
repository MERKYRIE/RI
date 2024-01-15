#pragma once

#include"RI.hpp"

#include"Vector.hpp"

namespace NRI{
    class CRay{
        private : CVector VOrigin;
        private : CVector VDirection;

        public : CRay() noexcept = default;
        public : CRay(const CVector& POrigin , const CVector& PDirection) noexcept;
        public : CVector FOrigin() const noexcept;
        public : CVector FDirection() const noexcept;
        public : CVector FAt(float PTime) const noexcept;
    };
}