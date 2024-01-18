#include"Metal.hpp"

#include"Information.hpp"

namespace NRI{
    CMetal::CMetal(const CVector& PDiffuse) noexcept{
        VDiffuse = PDiffuse;
    }

    bool CMetal::FScatter(const CRay& PInput , const CInformation& PHit , CVector& PAttenuation , CRay& POutput) const noexcept{
        CVector LReflected{CVector::FReflect(PInput.FDirection().FUnit() , PHit.FNormal())};
        POutput = CRay{PHit.FCoordinates() , LReflected};
        PAttenuation = VDiffuse;
        return true;
    }
}