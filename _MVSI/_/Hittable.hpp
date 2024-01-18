#pragma once

#include"RI.hpp"

#include"Information.hpp"
#include"Interval.hpp"

namespace NRI{
    class CInformation;
    class CRay;
    
    class CHittable{
        public : virtual bool FHit(const CRay& PRay , const CInterval& PTime , CInformation& PInformation) const noexcept = 0;
        public : virtual ~CHittable() noexcept = default;
    };
}