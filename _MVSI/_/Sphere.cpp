#include"Sphere.hpp"

namespace NRI{
    CSphere::CSphere(const CVector& PCenter , float PRadius , const std::shared_ptr<CMaterial>& PMaterial) noexcept{
        VCenter = PCenter;
        VRadius = PRadius;
        VMaterial = PMaterial;
    }

    bool CSphere::FHit(const CRay& PRay , const CInterval& PTime , CInformation& PInformation) const noexcept{
        CVector LOMinusC{PRay.FOrigin() - VCenter};
        float LA{PRay.FDirection().FLengthSquared()};
        float LHalfOfB{LOMinusC.FDot(PRay.FDirection())};
        float LC{LOMinusC.FLengthSquared() - VRadius * VRadius};
        float LDiscriminant{LHalfOfB * LHalfOfB - LA * LC};
        if(LDiscriminant < 0.0F){
            return false;
        }
        float LDiscriminantSquareRoot{std::sqrt(LDiscriminant)};
        float LRoot{(-LHalfOfB - LDiscriminantSquareRoot) / LA};
        if(!PTime.FSurrounds(LRoot)){
            LRoot = (-LHalfOfB + LDiscriminantSquareRoot) / LA;
            if(!PTime.FSurrounds(LRoot)){
                return false;
            }
        }
        PInformation.FTime(LRoot).FCoordinates(PRay.FAt(PInformation.FTime()));
        CVector LOutwardNormal{(PInformation.FCoordinates() - VCenter) / VRadius};
        PInformation.FFront(PRay , LOutwardNormal).FNormal(LOutwardNormal).FMaterial(VMaterial);
        return true;
    }
}