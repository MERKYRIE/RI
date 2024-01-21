#include"Collection.hpp"

namespace NRI{
    CCollection::CCollection(const std::shared_ptr<CHittable>& PHittable) noexcept{
        FAdd(PHittable);
    }

    CCollection& CCollection::FClear() noexcept{
        VPool.clear();
        return *this;
    }

    CCollection& CCollection::FAdd(const std::shared_ptr<CHittable>& PHittable) noexcept{
        VPool.push_back(PHittable);
        return *this;
    }

    bool CCollection::FHit(const CRay& PRay , const CInterval& PTime , CInformation& PInformation) const noexcept{
        float LClosest{PTime.FMaximum()};
        CInformation LInformation;
        bool LHit{false};
        for(const std::shared_ptr<CHittable>& LHittable : VPool){
            if(LHittable->FHit(PRay , CInterval{PTime.FMinimum() , LClosest} , LInformation)){
                LClosest = LInformation.FTime();
                PInformation = LInformation;
                LHit = true;
            }
        }
        return LHit;
    }
}