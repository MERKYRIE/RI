#pragma once

#include"RI.hpp"

#include"Information.hpp"

namespace NRI{
    class CMaterial;

    class CSphere : public CHittable{
        private : CVector VCenter;
        private : float VRadius;
        private : std::shared_ptr<CMaterial> VMaterial;

        public : CSphere(const CVector& PCenter , float PRadius , const std::shared_ptr<CMaterial>& PMaterial) noexcept;
        public : bool FHit(const CRay& PRay , const CInterval& PTime , CInformation& PInformation) const noexcept override;
    };
}