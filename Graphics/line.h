#pragma once

#include "shape.h"
#include <fstream>

class Line : public Shape
{
public:
	Line() : Shape() {};
	
	// Inherited via Shape
	virtual bool Update(float dt) override;
	virtual void Draw(Core::Graphics& graphics) override;

	virtual void Load(std::ifstream& stream) override;
	virtual void Save(std::ofstream& stream) override;
	
	virtual eType Type() override { return eType::LINE; }
	static const char* TypeName() { return "Line"; }

private:
	gk::vector2 m_start;
	gk::vector2 m_end;
	bool m_started{ false };

};

