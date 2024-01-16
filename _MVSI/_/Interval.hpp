#pragma once

#include"RI.hpp"

namespace NRI{
    class CInterval{
        private : float VMinimum;
        private : float VMaximum;

        public : CInterval() noexcept;
        public : CInterval(float PMinimum , float PMaximum) noexcept;
        public : float FMinimum() const noexcept;
        public : float FMaximum() const noexcept;
        public : bool FContains(float PX) const noexcept;
        public : bool FSurrounds(float PX) const noexcept;
        public : float FClamp(float PX) const noexcept;
    };
}