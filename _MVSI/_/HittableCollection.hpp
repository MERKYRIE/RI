#pragma once

#include"RI.hpp"

#include"HitInformation.hpp"
#include"Hittable.hpp"

namespace NRI{
    class CHittableCollection : public CHittable{
        private : std::vector<std::shared_ptr<CHittable>> VPool;

        public : CHittableCollection() noexcept = default;
        public : CHittableCollection(std::shared_ptr<CHittable> PHittable) noexcept;
        public : void FClear() noexcept;
        public : void FAdd(std::shared_ptr<CHittable> PHittable) noexcept;
        public : bool FHit(const CRay& PRay , float PRayTimeMinimum , float PRayTimeMaximum , CHitInformation& PInformation) const noexcept override;
    };
}