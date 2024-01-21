#include"Lambertian.hpp"

#include"Information.hpp"

namespace NRI{
    CLambertian::CLambertian(const CVector& PDiffuse) noexcept{
        VDiffuse = PDiffuse;
    }

    bool CLambertian::FScatter(const CRay& PInput , const CInformation& PHit , CVector& PAttenuation , CRay& POutput) const noexcept{
        CVector LDirection{PHit.FNormal() + CVector::FRandomUnit()};
        if(LDirection.FIsNearZero()){
            LDirection = PHit.FNormal();
        }
        POutput = CRay{PHit.FCoordinates() , LDirection};
        PAttenuation = VDiffuse;
        return true;
    }
}