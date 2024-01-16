#pragma once

#include"RI.hpp"

#include"Information.hpp"

namespace NRI{
    class CSphere : public CHittable{
        private : CVector VCenter;
        private : float VRadius;

        public : CSphere(const CVector& PCenter , float PRadius) noexcept;
        public : bool FHit(const CRay& PRay , const CInterval& PTime , CInformation& PInformation) const noexcept override;
    };
}