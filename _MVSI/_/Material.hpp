#pragma once

#include"RI.hpp"

namespace NRI{
    class CInformation;
    class CRay;
    class CVector;
    
    class CMaterial{
        private : ;

        public : virtual ~CMaterial() noexcept = default;
        public : virtual bool FScatter(const CRay& PInput , const CInformation& PHit , CVector& PAttenuation , CRay& POutput) const noexcept = 0;
    };
}