#pragma once
#include <Siv3D.hpp>

class Aquarium
{
public:
	Rect _frame;
	int32 _frameThick;
	Aquarium(Texture bg,Vec2 p,int32 w,int32 h,int32 fT)
		:_bg(bg),_p(p),_w(w),_h(h),_frame(p.x,p.y,w,h),_frameThick(fT){};
	void init() const;

private:
	Texture _bg;
	Vec2 _p;//右上座標
	int32 _h;
	int32 _w;

};
