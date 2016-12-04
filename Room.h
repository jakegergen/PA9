#include "Object.h"
class Room {
public:
	Room() 
	{
		this->Left = nullptr;
		this->Right = nullptr;
	}

	void setLeftRoom(Room* LeftRoom) {
		this->Left = LeftRoom;
	}
	void setRightRoom(Room* RightRoom) {
		this->Right = RightRoom;
	}

	Room* getLeftRoom()
	{
		return this->Left;
	}
	Room* getRightRoom()
	{
		return this->Right;
	}

	//Insert platform in to vector
	void Add_Platform(Platform *&new_platform)
	{
		Room_Objs.push_back(*new_platform);
	}

	//Load a level from a .txt file, Example Level in Github : "Level1.txt"
	void Load_level(std::ifstream &infile)
{
	sf::Vector2<float> position;
	sf::Vector2<float> size;
	Platform *new_platform;
	std::string Shape, Color;
	float Positionx, Positiony, Sizex, Sizey;
	while (!infile.eof())
	{
		//Type Positionx Positiony Color Sizex Sizey
		infile >> Shape;
		infile >> Positionx;
		infile >> Positiony;
		infile >> Color;
		infile >> Sizex;
		infile >> Sizey;
		position.x = Positionx;
		position.y = Positiony;
		size.x = Sizex;
		size.y = Sizey;
		if (Shape == "Rectangle") {
			new_platform = new Platform(position, size);
		}
		this->Add_Platform(new_platform);
	}
		
}
	
		
	//Pass in a Pointer to a reference of the window to render all the objects in the room
	void render_room(sf::RenderWindow *&window_ptr)
	{
		vector<Platform> copy = this->Room_Objs;
		int i = 0;
		int size = copy.size();
		while (copy.size() != 0)
		{
			copy.back().draw(window_ptr);
			copy.pop_back();
		}
	
	}
	//add object
	//get/set right and left room

protected:
	Room* Left;
	Room* Right;
	vector<Platform> Room_Objs;
	
};
