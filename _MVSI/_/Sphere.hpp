#pragma once

#include"RI.hpp"

#include"HitInformation.hpp"
#include"Hittable.hpp"

namespace NRI{
    class CSphere : public CHittable{
        private : CVector VCenter;
        private : float VRadius;

        public : CSphere(const CVector& PCenter , float PRadius) noexcept;
        public : bool FHit(const CRay& PRay , float PRayTimeMinimum , float PRayTimeMaximum , CHitInformation& PInformation) const noexcept override;
    };
}