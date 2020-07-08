
#include "painter.h"

std::vector<gk::vector2> points;
float timer = 0;

Painter::~Painter()
{
    //Delete shapes
    for (Shape* shape : m_shapes)
    {
        delete shape;
    }

    //Clear shapes from container
    m_shapes.clear();
}

void Painter::Update(float dt)
{
	//Switch shapes
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT))
	{
		if (m_shape)
		{
			delete m_shape;
			m_shape = nullptr;
		}
		m_shapeType = Shape::eType::LINE;
	}
	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT))
	{
		if (m_shape)
		{
			delete m_shape;
			m_shape = nullptr;
		}
		m_shapeType = Shape::eType::BOX;
	}
	
	//Create shape
	if (m_shape == nullptr && Core::Input::IsPressed(Core::Input::BUTTON_LEFT))
	{
		m_shape = Shape::CreateShape(m_shapeType);
	}

	//Add current shape to shapes
	if (m_shape)
	{
		bool place = m_shape->Update(dt);
		if (place)
		{
			m_shapes.push_back(m_shape);
			m_shape = nullptr;
		}
	}
	
}

void Painter::Draw(Core::Graphics& graphics)
{
	//Draw current shape
	if (m_shape)
	{
		m_shape->Draw(graphics);
	}

	//Draw all shapes
	if (!m_shapes.empty())
	{
		for (Shape* shape : m_shapes)
		{
			shape->Draw(graphics);
		}
	}
}

void Painter::Load(const std::string& filename)
{
	// open file stream
	std::ifstream stream;
	stream.open(filename);
	if (stream.is_open())
	{
		// read shapes
		while (!stream.eof())
		{
			int itype;
			stream >> itype;

			if (stream.eof()) break;

			Shape::eType type = static_cast<Shape::eType>(itype);
			Shape* shape = Shape::CreateShape(type);
			shape->Load(stream);

			m_shapes.push_back(shape);
		}
	}
}


void Painter::Save(const std::string& filename)
{
	// open file stream
	std::ofstream stream;
	stream.open(filename);
	if (stream.is_open())
	{
		// save shapes
		for (Shape* shape : m_shapes)
		{
			shape->Save(stream);
		}
	}
}
