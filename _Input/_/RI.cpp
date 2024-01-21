#include"RI.hpp"

#include"Camera.hpp"
#include"Collection.hpp"
#include"Lambertian.hpp"
#include"Material.hpp"
#include"Metal.hpp"
#include"Sphere.hpp"

std::int32_t main(){
    NRI::CCollection LWorld;
    std::shared_ptr<NRI::CMaterial> LGround{std::make_shared<NRI::CLambertian>(NRI::CVector{0.8F , 0.8F , 0.0F})};
    std::shared_ptr<NRI::CMaterial> LCenter{std::make_shared<NRI::CLambertian>(NRI::CVector{0.7F , 0.3F , 0.3F})};
    std::shared_ptr<NRI::CMaterial> LLeft{std::make_shared<NRI::CMetal>(NRI::CVector{0.8F , 0.8F , 0.8F})};
    std::shared_ptr<NRI::CMaterial> LRight{std::make_shared<NRI::CMetal>(NRI::CVector{0.8F , 0.6F , 0.2F})};
    LWorld.FAdd(std::make_shared<NRI::CSphere>(NRI::CVector{0.0F , -100.5F , -1.0F} , 100.0F , LGround)).FAdd(std::make_shared<NRI::CSphere>(NRI::CVector{0.0F , 0.0F , -1.0F} , 0.5F , LCenter))
        .FAdd(std::make_shared<NRI::CSphere>(NRI::CVector{-1.0F , 0.0F , -1.0F} , 0.5F , LLeft)).FAdd(std::make_shared<NRI::CSphere>(NRI::CVector{-1.0F , 0.0F , -1.0F} , 0.5F , LRight));
	   NRI::CCamera LCamera{400.0F , 16.0F / 9.0F , 100 , 50};
    LCamera.FRender(LWorld);
	   return 0;
}