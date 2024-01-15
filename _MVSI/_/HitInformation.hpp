#pragma once

#include"RI.hpp"

#include"Ray.hpp"
#include"Vector.hpp"

namespace NRI{
    class CRay;
    
    class CHitInformation{
        public : CVector VCoordinates;
        public : CVector VNormal;
        public : float VTime;
        public : bool VFrontFace;

        public : void FSetFaceNormal(const CRay& PRay , const CVector& POutwardNormal) noexcept;
    };
}