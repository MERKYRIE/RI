#include"HitInformation.hpp"

namespace NRI{
    void CHitInformation::FSetFaceNormal(const CRay& PRay , const CVector& POutwardNormal) noexcept{
        VFrontFace = PRay.FDirection().FDot(POutwardNormal);
        VNormal = VFrontFace ? POutwardNormal : -POutwardNormal;
    }
}