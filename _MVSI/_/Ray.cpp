#include"Ray.hpp"

namespace NRI{
    CRay::CRay(const CVector& POrigin , const CVector& PDirection) noexcept{
        VOrigin = POrigin;
        VDirection = PDirection;
    }

    CVector CRay::FOrigin() const noexcept{
        return VOrigin;
    }

    CVector CRay::FDirection() const noexcept{
        return VDirection;
    }

    CVector CRay::FAt(float PTime) const noexcept{
        return VOrigin + VDirection * PTime;
    }

    CVector CRay::FColor(const CHittable& PWorld) const noexcept{
        CHitInformation LHitInformation;
        if(PWorld.FHit(*this , 0.0F , std::numeric_limits<float>::infinity() , LHitInformation)){
            return 0.5F * (LHitInformation.VNormal + CVector{1.0F , 1.0F , 1.0F});
        }
        CVector LUnitDirection{VDirection.FUnit()};
        float LBlue{0.5F * (LUnitDirection[1] + 1.0F)};
        return CVector{(1.0F - LBlue) * CVector{1.0F , 1.0F , 1.0F} + LBlue * CVector{0.5F , 0.7F , 1.0F}};
    }

    float CRay::FHit(const CVector& PCenter , float PRadius) const noexcept{
        CVector LOMinusC{VOrigin - PCenter};
        float LA{VDirection.FLengthSquared()};
        float LHalfB{LOMinusC.FDot(VDirection)};
        float LC{LOMinusC.FLengthSquared() - PRadius * PRadius};
        float LDiscriminant{LHalfB * LHalfB - LA * LC};
        if(LDiscriminant < 0.0F){
            return -1.0F;
        }
        return (-LHalfB - std::sqrt(LDiscriminant)) / LA;
    }
}