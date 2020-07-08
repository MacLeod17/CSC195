
#include "line.h"

bool Line::Update(float dt)
{
	//Get mouse position
	int x, y;
	Core::Input::GetMousePos(x, y);
	gk::vector2 point{ x, y };

	//Set start point when first started
	if (m_started == false)
	{
		m_started = true;
		m_start = point;
	}

	//Set end point
	m_end = point;

	//Place object when mouse button is not pressed
	bool place = (!Core::Input::IsPressed(Core::Input::BUTTON_LEFT));

	return place;
}

void Line::Draw(Core::Graphics& graphics)
{
	graphics.DrawLine(m_start.x, m_start.y, m_end.x, m_end.y);
}

void Line::Load(std::ifstream& stream)
{
	//<call Load() on Shape base class>
	Shape::Load(stream);
		// load points
	stream >> m_start;
	stream >> m_end;
}

void Line::Save(std::ofstream& stream)
{
	//<call Save() on Shape base class>
	Shape::Save(stream);
	
	// save points
	stream << m_start << ' ';
	stream << m_end << std::endl;
}
