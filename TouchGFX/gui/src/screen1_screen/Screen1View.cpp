#include <gui/screen1_screen/Screen1View.hpp>

extern "C"
{
	extern volatile uint16_t ocPeriod;
}

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}


void Screen1View::slider1ChangedCallback(int value)
{
	ocPeriod = 2100 - (slider1.getValue() * 20);
	this->updateSpeed(slider1.getValue());
}


void Screen1View::updateSpeed(int speed)
{
	Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "%u", speed);
	textArea3.invalidate();
}



