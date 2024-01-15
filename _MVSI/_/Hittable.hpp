#pragma once

#include"RI.hpp"

#include"HitInformation.hpp"
#include"Ray.hpp"
#include"Vector.hpp"

namespace NRI{
    class CRay;
    class CHitInformation;
    
    class CHittable{
        public :
        public : virtual ~CHittable() noexcept = default;
        public : virtual bool FHit(const CRay& PRay , float PRayTimeMinimum , float PRayTimeMaximum , CHitInformation& PInformation) const noexcept = 0;
    };
}