#include"Sphere.hpp"

namespace NRI{
    CSphere::CSphere(const CVector& PCenter , float PRadius) noexcept{
        VCenter = PCenter;
        VRadius = PRadius;
    }

    bool CSphere::FHit(const CRay& PRay , float PRayTimeMinimum , float PRayTimeMaximum , CHitInformation& PInformation) const noexcept{
        CVector LOMinusC{PRay.FOrigin() - VCenter};
        float LA{PRay.FDirection().FLengthSquared()};
        float LHalfB{LOMinusC.FDot(PRay.FDirection())};
        float LC{LOMinusC.FLengthSquared() - VRadius * VRadius};
        float LDiscriminant{LHalfB * LHalfB - LA * LC};
        if(LDiscriminant < 0.0F){
            return false;
        }
        float LDiscriminantSquareRoot{std::sqrt(LDiscriminant)};
        float LRoot{(-LHalfB - LDiscriminantSquareRoot) / LA};
        if(LRoot <= PRayTimeMinimum || PRayTimeMaximum <= LRoot){
            LRoot = (-LHalfB + LDiscriminantSquareRoot) / LA;
            if(LRoot <= PRayTimeMinimum || PRayTimeMaximum <= LRoot){
                return false;
            }
        }
        PInformation.VTime = LRoot;
        PInformation.VCoordinates = PRay.FAt(PInformation.VTime);
        CVector LOutwardNormal{(PInformation.VCoordinates - VCenter) / VRadius};
        PInformation.FSetFaceNormal(PRay , LOutwardNormal);
        return true;
    }
}