#pragma once

#include"RI.hpp"

#include"Information.hpp"

namespace NRI{
    class CCollection : public CHittable{
        private : std::vector<std::shared_ptr<CHittable>> VPool;

        public : CCollection() noexcept = default;
        public : CCollection(const std::shared_ptr<CHittable>& PHittable) noexcept;
        public : CCollection& FClear() noexcept;
        public : CCollection& FAdd(const std::shared_ptr<CHittable>& PHittable) noexcept;
        public : bool FHit(const CRay& PRay , const CInterval& PTime , CInformation& PInformation) const noexcept override;
    };
}