#include"RI.hpp"

#include"Camera.hpp"
#include"Collection.hpp"
#include"Sphere.hpp"

std::int32_t main(){
    NRI::CCollection LWorld;
    LWorld.FAdd(std::make_shared<NRI::CSphere>(NRI::CVector{0.0F , 0.0F , -1.0F} , 0.5F)).FAdd(std::make_shared<NRI::CSphere>(NRI::CVector{0.0F , -100.5F , 0.0F} , 100.0F));
	   NRI::CCamera LCamera{400.0F , 16.0F / 9.0F , 100 , 50};
    LCamera.FRender(LWorld);
	   return 0;
}