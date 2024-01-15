#include"RI.hpp"

#include"Vector.hpp"

signed int main(){
	   constexpr std::uint64_t LWidth{256};
	   constexpr std::uint64_t LHeight{256};
	   std::cout << "P3" << "\n" << LWidth << " " << LHeight << "\n" << "255" << "\n";
	   for(std::uint64_t LX{0} ; LX < LWidth ; LX++){
		      std::clog << "Progress: " << LX * 100 / LWidth << "%" << "\n";
        for(std::uint64_t LY{0} ; LY < LHeight ; LY++){
            NRI::CVector LColor{
                static_cast<float>(LX) / static_cast<float>(LWidth - 1) ,
                static_cast<float>(LY) / static_cast<float>(LHeight - 1) ,
                1.0F / (static_cast<float>(LX) / static_cast<float>(LWidth - 1))
            };
            LColor.FPrintAsColor();
		      }
	   }
    std::clog << "Done!" << "\n";
	   return 0;
}