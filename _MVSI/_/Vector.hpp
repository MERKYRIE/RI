#pragma once

#include"RI.hpp"

namespace NRI{
    class CVector{
        private : float VX;
        private : float VY;
        private : float VZ;

        public : CVector() noexcept;
        public : CVector(float PX , float PY , float PZ) noexcept;
        public : CVector operator-() const noexcept;
        public : float& operator[](std::uint8_t PIndex);
        public : float operator[](std::uint8_t PIndex) const;
        public : CVector& operator+=(float PValue) noexcept;
        public : CVector& operator-=(float PValue) noexcept;
        public : CVector& operator*=(float PValue) noexcept;
        public : CVector& operator/=(float PValue);
        public : CVector operator+(const CVector& PVector) const noexcept;
        public : CVector operator-(const CVector& PVector) const noexcept;
        public : CVector operator*(const CVector& PVector) const noexcept;
        public : CVector operator/(const CVector& PVector) const;
        public : CVector& operator+=(const CVector& PVector) noexcept;
        public : CVector& operator-=(const CVector& PVector) noexcept;
        public : CVector& operator*=(const CVector& PVector) noexcept;
        public : CVector& operator/=(const CVector& PVector);
        public : std::ostream& operator<<(std::ostream& PStream) const noexcept;
        public : float FLengthSquared() const noexcept;
        public : float FLength() const noexcept;
        public : float FDot(const CVector& PVector) const noexcept;
        public : CVector FCross(const CVector& PVector) const noexcept;
        public : CVector FUnit() const noexcept;
        public : void FPrintAsColor() const noexcept;

        public : friend CVector operator+(const CVector& PVector , float PValue) noexcept;
        public : friend CVector operator-(const CVector& PVector , float PValue) noexcept;
        public : friend CVector operator*(const CVector& PVector , float PValue) noexcept;
        public : friend CVector operator/(const CVector& PVector , float PValue);
        public : friend CVector operator+(float PValue , const CVector& PVector) noexcept;
        public : friend CVector operator-(float PValue , const CVector& PVector) noexcept;
        public : friend CVector operator*(float PValue , const CVector& PVector) noexcept;
        public : friend CVector operator/(float PValue , const CVector& PVector);
    };
}