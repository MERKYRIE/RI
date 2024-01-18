#include"Information.hpp"

namespace NRI{
    const CVector& CInformation::FCoordinates() const noexcept{
        return VCoordinates;
    }

    CInformation& CInformation::FCoordinates(const CVector& PCoordinates) noexcept{
        VCoordinates = PCoordinates;
        return *this;
    }

    float CInformation::FTime() const noexcept{
        return VTime;
    }

    CInformation& CInformation::FTime(float PTime) noexcept{
        VTime = PTime;
        return *this;
    }

    bool CInformation::FFront() const noexcept{
        return VFront;
    }
    
    CInformation& CInformation::FFront(const CRay& PRay , const CVector& POutward) noexcept{
        VFront = PRay.FDirection().FDot(POutward);
        return *this;
    }

    const CVector& CInformation::FNormal() const noexcept{
        return VNormal;
    }

    CInformation& CInformation::FNormal(const CVector& POutward) noexcept{
        VNormal = VFront ? POutward : -POutward;
        return *this;
    }

    const std::shared_ptr<CMaterial>& CInformation::FMaterial() const noexcept{
        return VMaterial;
    }

    CInformation& CInformation::FMaterial(const std::shared_ptr<CMaterial>& PMaterial) noexcept{
        VMaterial = PMaterial;
        return *this;
    }
}