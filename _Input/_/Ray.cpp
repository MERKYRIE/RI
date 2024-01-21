#include"Ray.hpp"

namespace NRI{
    CRay::CRay(const CVector& POrigin , const CVector& PDirection) noexcept{
        VOrigin = POrigin;
        VDirection = PDirection;
    }

    const CVector& CRay::FOrigin() const noexcept{
        return VOrigin;
    }

    const CVector& CRay::FDirection() const noexcept{
        return VDirection;
    }

    CVector CRay::FAt(float PTime) const noexcept{
        return CVector{VOrigin + VDirection * PTime};
    }
}