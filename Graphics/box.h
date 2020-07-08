#pragma once

#include "shape.h"
#include <fstream>

class Box : public Shape
{
public:
	Box() {}

	// Inherited via Shape
	virtual bool Update(float dt) override;
	virtual void Draw(Core::Graphics& graphics) override;

	virtual void Load(std::ifstream& stream) override;
	virtual void Save(std::ofstream& stream) override;

	virtual eType Type() override { return eType::BOX; }
	static const char* TypeName() { return "Line"; }

private:
	float m_size{ 40 };
	gk::vector2 m_center;

	static const gk::vector2 s_points[];

};

