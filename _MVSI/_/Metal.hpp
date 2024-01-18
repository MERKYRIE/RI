#pragma once

#include"RI.hpp"

#include"Material.hpp"
#include"Vector.hpp"

namespace NRI{
    class CInformation;
    class CRay;
    
    class CMetal : public CMaterial{
        private : CVector VDiffuse;

        public : CMetal(const CVector& PDiffuse) noexcept;
        public : bool FScatter(const CRay& PInput , const CInformation& PHit , CVector& PAttenuation , CRay& POutput) const noexcept override;
    };
}