#include "stdafx.h"
#include "Aquarium.hpp"


void Aquarium::init() const
{
	this->_frame.drawFrame(this->_frameThick);
	this->_bg(0,0,this->_w,this->_h).draw(this->_p);
}
