#include"Vector.hpp"

namespace NRI{
    CVector::CVector() noexcept{
        VX = 0.0F;
        VY = 0.0F;
        VZ = 0.0F;
    }

    CVector::CVector(float PX , float PY , float PZ) noexcept{
        VX = PX;
        VY = PY;
        VZ = PZ;
    }

    CVector CVector::operator-() const noexcept{
        return CVector{-VX , -VY , -VZ};
    }

    float& CVector::operator[](std::uint8_t PIndex){
        switch(PIndex){
            case 0:
                return VX;
            break;
            case 1:
                return VY;
            break;
            case 2:
                return VZ;
            break;
            default:
                throw;
            break;
        }
    }

    float CVector::operator[](std::uint8_t PIndex) const{
        switch(PIndex){
            case 0:
                return VX;
            break;
            case 1:
                return VY;
            break;
            case 2:
                return VZ;
            break;
            default:
                throw;
            break;
        }
    }

    CVector& CVector::operator+=(float PValue) noexcept{
        *this = *this + PValue;
        return *this;
    }

    CVector& CVector::operator-=(float PValue) noexcept{
        *this = *this - PValue;
        return *this;
    }

    CVector& CVector::operator*=(float PValue) noexcept{
        *this = *this * PValue;
        return *this;
    }

    CVector& CVector::operator/=(float PValue){
        if(!PValue){
            throw;
        }
        *this = *this / PValue;
        return *this;
    }

    CVector CVector::operator+(const CVector& PVector) const noexcept{
        return CVector{VX + PVector.VX , VY + PVector.VY , VZ + PVector.VZ};
    }

    CVector CVector::operator-(const CVector& PVector) const noexcept{
        return CVector{VX - PVector.VX , VY - PVector.VY , VZ - PVector.VZ};
    }

    CVector CVector::operator*(const CVector& PVector) const noexcept{
        return CVector{VX * PVector.VX , VY * PVector.VY , VZ * PVector.VZ};
    }

    CVector CVector::operator/(const CVector& PVector) const{
        if(!PVector.VX || !PVector.VY || !PVector.VZ){
            throw;
        }
        return CVector{VX / PVector.VX , VY / PVector.VY , VZ / PVector.VZ};
    }

    CVector& CVector::operator+=(const CVector& PVector) noexcept{
        *this = *this + PVector;
        return *this;
    }

    CVector& CVector::operator-=(const CVector& PVector) noexcept{
        *this = *this - PVector;
        return *this;
    }

    CVector& CVector::operator*=(const CVector& PVector) noexcept{
        *this = *this * PVector;
        return *this;
    }

    CVector& CVector::operator/=(const CVector& PVector){
        if(!PVector.VX || !PVector.VY || !PVector.VZ){
            throw;
        }
        *this = *this / PVector;
        return *this;
    }

    std::ostream& CVector::operator<<(std::ostream& PStream) const noexcept{
        return PStream << VX << " " << VY << " " << VZ << "\n";
    }

    float CVector::FLengthSquared() const noexcept{
        return VX * VX + VY * VY + VZ * VZ;
    }

    float CVector::FLength() const noexcept{
        return std::sqrt(FLengthSquared());
    }
    

    float CVector::FDot(const CVector& PVector) const noexcept{
        return VX * PVector.VX + VY * PVector.VY + VZ * PVector.VZ;
    }

    CVector CVector::FCross(const CVector& PVector) const noexcept{
        return CVector{VY * PVector.VZ - VZ * PVector.VY , VZ * PVector.VX - VX * PVector.VZ , VX * PVector.VY - VY - PVector.VX};
    }

    CVector CVector::FUnit() const noexcept{
        return *this / FLength();
    }

    void CVector::FPrintAsColor() const noexcept{
        std::cout << static_cast<std::uint16_t>(255.999F * VX) << " " << static_cast<std::uint16_t>(255.999F * VY) << " " << static_cast<std::uint16_t>(255.999F * VZ) << "\n";
    }

    CVector operator+(const CVector& PVector , float PValue) noexcept{
        return CVector{PVector.VX + PValue , PVector.VY + PValue , PVector.VZ + PValue};
    }

    CVector operator-(const CVector& PVector , float PValue) noexcept{
        return CVector{PVector.VX - PValue , PVector.VY - PValue , PVector.VZ - PValue};
    }

    CVector operator*(const CVector& PVector , float PValue) noexcept{
        return CVector{PVector.VX * PValue , PVector.VY * PValue , PVector.VZ * PValue};
    }

    CVector operator/(const CVector& PVector , float PValue){
        if(!PValue){
            throw;
        }
        return CVector{PVector.VX / PValue , PVector.VY / PValue , PVector.VZ / PValue};
    }

    CVector operator+(float PValue , const CVector& PVector) noexcept{
        return CVector{PValue + PVector.VX , PValue + PVector.VY , PValue + PVector.VZ};
    }

    CVector operator-(float PValue , const CVector& PVector) noexcept{
        return CVector{PValue - PVector.VX , PValue - PVector.VY , PValue - PVector.VZ};
    }
    
    CVector operator*(float PValue , const CVector& PVector) noexcept{
        return CVector{PValue * PVector.VX , PValue * PVector.VY , PValue * PVector.VZ};
    }

    CVector operator/(float PValue , const CVector& PVector){
        if(!PVector.VX || !PVector.VY || !PVector.VZ){
            throw;
        }
        return CVector{PValue / PVector.VX , PValue / PVector.VY , PValue / PVector.VZ};
    }
}