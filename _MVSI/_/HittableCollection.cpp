#include"HittableCollection.hpp"

namespace NRI{
    CHittableCollection::CHittableCollection(std::shared_ptr<CHittable> PHittable) noexcept{
        FAdd(PHittable);
    }

    void CHittableCollection::FClear() noexcept{
        VPool.clear();
    }

    void CHittableCollection::FAdd(std::shared_ptr<CHittable> PHittable) noexcept{
        VPool.push_back(PHittable);
    }

    bool CHittableCollection::FHit(const CRay& PRay , float PRayTimeMinimum , float PRayTimeMaximum , CHitInformation& PInformation) const noexcept{
        CHitInformation LTemporaryInformation;
        bool LHasHit{false};
        float LClosestHit{PRayTimeMaximum};
        for(const std::shared_ptr<CHittable>& LHittable : VPool){
            if(LHittable->FHit(PRay, PRayTimeMinimum , LClosestHit , LTemporaryInformation)){
                LHasHit = true;
                LClosestHit = LTemporaryInformation.VTime;
                PInformation = LTemporaryInformation;
            }
        }
        return LHasHit;
    }
}