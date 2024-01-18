#pragma once

#include"RI.hpp"

#include"Ray.hpp"
#include"Vector.hpp"

namespace NRI{
    class CHittable;
    class CMaterial;
    class CRay;
    
    class CInformation{
        private : CVector VCoordinates;
        private : float VTime;
        private : bool VFront;
        private : CVector VNormal;
        private : std::shared_ptr<CMaterial> VMaterial;

        public : const CVector& FCoordinates() const noexcept;
        public : CInformation& FCoordinates(const CVector& PCoordinates) noexcept;
        public : float FTime() const noexcept;
        public : CInformation& FTime(float PTime) noexcept;
        public : bool FFront() const noexcept;
        public : CInformation& FFront(const CRay& PRay , const CVector& POutward) noexcept;
        public : const CVector& FNormal() const noexcept;
        public : CInformation& FNormal(const CVector& POutward) noexcept;
        public : const std::shared_ptr<CMaterial>& FMaterial() const noexcept;
        public : CInformation& FMaterial(const std::shared_ptr<CMaterial>& PMaterial) noexcept;
    };
}