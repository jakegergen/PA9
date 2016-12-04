
#include <vector>
#include <iostream>
#include <SFML\Graphics.hpp>
#include <fstream>

using std::vector;
using std::cout;
using std::endl;

class Object {
public:
	Object(float x_coord = 0.0, float y_coord = 0.0)
	{
		this->posistion.x = x_coord;
		this->posistion.y = y_coord;
	}
	virtual void draw(sf::RenderWindow *&window) {
		std::cout << "In Object class draw()" << std::endl;
	}

	virtual void move(sf::Vector2<float> new_pos) {
		std::cout << "In Object class move()" << std::endl;
	}
	virtual sf::RectangleShape getShape() {
		sf::RectangleShape temp;
		std::cout << "In Object class getShape()" << std::endl;
		return temp;
	}
protected:
	sf::Vector2<float> posistion;
};

class Platform : public Object {
public:
	
	Platform(float x_coord = 0.0, float y_coord = 0.0) : Object(x_coord, y_coord)
	{
		shape.setPosition(x_coord, y_coord);
	}
	Platform(sf::Vector2<float> position, sf::Vector2<float> size) : Object(position.x, position.y)
	{
		shape.setPosition(position);
		shape.setSize(size);
	}

	sf::RectangleShape getShape() {
		return this->shape;
	}

	//Returns type FloatRect containing Height and width of Shape
	sf::FloatRect getLocalBounds() {
		return this->getShape().getLocalBounds();
	}

	void move(sf::Vector2<float> new_pos) {
		this->shape.setPosition(new_pos);
	}

	void setSize(sf::Vector2<float> Size_dimentions) {
		shape.setSize(Size_dimentions);
	}

	
	void draw(sf::RenderWindow *&window) {

		window->draw(this->shape);
	}

	
protected:
	sf::RectangleShape shape;
};
