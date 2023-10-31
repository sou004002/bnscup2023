#include "stdafx.h"
#include "Aquarium.hpp"

void Aquarium::init() const
{
	this->_frame.drawFrame(this->_frameThick);
	this->_bg(0, 0, this->_w, this->_h).draw(this->_p);
}

int32 Aquarium::p_getter_x() const
{
	return this->_p.x;
}
int32 Aquarium::p_getter_y() const
{
	return this->_p.y;
}
int32  Aquarium::h_getter() const
{
	return this->_h;
}
int32  Aquarium::w_getter() const
{
	return this->_w;
}
