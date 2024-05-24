#ifndef LAYOUT_H
#define LAYOUT_H

#include <string>

class Layout
{
	private:
		string map;
		
	public:
		Layout(string);
		string loadLayout(string);
		void update(void);
		bool isOpen(float x, float y);
};

#include "layout.cpp"
#endif 
