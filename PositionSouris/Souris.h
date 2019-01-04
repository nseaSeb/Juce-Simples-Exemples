class Souris : public Component
{
public:
	Souris() {}
  
	void paint(Graphics& g) override
	{
		g.setColour(Colours::white);
		g.drawLine(0.0f, m_mousepos.getY(), getWidth(), m_mousepos.getY());
		g.drawLine(m_mousepos.getX(), 0.0f, m_mousepos.getX(), getHeight());
	}
	void mouseMove(const MouseEvent& event) override
	{
		m_mousepos = event.position;
		repaint();
	}
private:
	Point<float> m_mousepos;
};
