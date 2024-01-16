#include"Interval.hpp"

namespace NRI{
    CInterval::CInterval() noexcept{
        VMinimum = +std::numeric_limits<float>::infinity();
        VMaximum = -std::numeric_limits<float>::infinity();
    }

    CInterval::CInterval(float PMinimum , float PMaximum) noexcept{
        VMinimum = PMinimum;
        VMaximum = PMaximum;
    }

    float CInterval::FMinimum() const noexcept{
        return VMinimum;
    }

    float CInterval::FMaximum() const noexcept{
        return VMaximum;
    }

    bool CInterval::FContains(float PX) const noexcept{
        return VMinimum <= PX && PX <= VMaximum;
    }

    bool CInterval::FSurrounds(float PX) const noexcept{
        return VMinimum < PX && PX < VMaximum;
    }

    float CInterval::FClamp(float PX) const noexcept{
        return std::clamp<float>(PX , VMinimum , VMaximum);
    }
}