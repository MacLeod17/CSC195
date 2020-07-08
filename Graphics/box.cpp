
#include "box.h"

const gk::vector2 Box::s_points[] = { {-1, -1}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1} };

bool Box::Update(float dt)
{
	//Get mouse position
	int x, y;
	Core::Input::GetMousePos(x, y);
	gk::vector2 point{ x, y };

	//Set center point
	Box::m_center = point;

	//Set place to true when mouse button is not pressed
	bool place = (!Core::Input::IsPressed(Core::Input::BUTTON_LEFT));
	
	return place;
}

void Box::Draw(Core::Graphics& graphics)
{
	for (size_t i = 0; i < 4; i++)
	{
		gk::vector2 p1 = m_center + s_points[i] * m_size;
		gk::vector2 p2 = m_center + s_points[i + 1] * m_size;
		graphics.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
}

void Box::Load(std::ifstream& stream)
{
	Shape::Load(stream);

	//Load center point and size
	stream >> m_center;
	stream >> m_size;
}

void Box::Save(std::ofstream& stream)
{
	Shape::Save(stream);

	//Save center point and size
	stream << m_center << ' ';
	stream << m_size << std::endl;
}
