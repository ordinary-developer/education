

#include <iostream>
using namespace std;

enum Direction { North, South, East, West };

class MapSite {
    public:
        virtual void Enter() = 0;
};

class Room : public MapSite {
    public:
        Room(int roomNumber) { _roomNumber = roomNumber; }

        MapSite* GetSide(Direction direction) const { return 0; }
        void SetSide(Direction direction, MapSite* mapSite) { }

        virtual void Enter() { } 
    private:
        MapSite* _sides[4];
        int _roomNumber;
};

class Wall : public MapSite {
    public:
        Wall() { } 
        
        virtual void Enter() { } 
};

class Door : public MapSite {
    public:
        Door(Room* room1 = 0, Room* room2 = 0) 
            : _room1(room1), _room2(room2) { }

        virtual void Enter() { }
        
        Room* OtherSideFrom(Room* room) { return 0; }
    private:
        Room* _room1;
        Room* _room2;
        bool _isOpen;
};

class Maze {
    public:
        Maze() { } 

        void AddRoom(Room* room) { } 

        Room* RoomNumber(int number) const { return 0; }
};


class MazeFactory {
    public:
        static MazeFactory* Instance() {
            if (0 == _instance) {
                _instance = new MazeFactory;
            }
            return _instance;
        }

        virtual Wall* MakeWall() const {
            return new Wall;
        }

        virtual Room* MakeRoom(int roomNumber) const {
            return new Room(roomNumber);
        }

        virtual Door* MakeDoor(Room* room1, Room* room2) const {
            return new Door(room1, room2);
        }

        virtual Maze* MakeMaze() const {
            return new Maze;
        }

    protected:
        MazeFactory() { }

    private:
        static MazeFactory* _instance;

};

class MazeGame {
    public:
        Maze* CreateMaze(MazeFactory* factory) {
            Maze* aMaze = factory->MakeMaze();

            Room* room1 = factory->MakeRoom(1);
            Room* room2 = factory->MakeRoom(2);

            Door* theDoor = factory->MakeDoor(room1, room2);

            room1->SetSide(North, new Wall());       
            room1->SetSide(East, theDoor);       
            room1->SetSide(South, new Wall());       
            room1->SetSide(West, new Wall());       

            room2->SetSide(North, new Wall());       
            room2->SetSide(East, new Wall());       
            room2->SetSide(South, new Wall());       
            room2->SetSide(West, theDoor);       

            return aMaze;
        }
        Maze* CreateMaze() {
            Maze* aMaze = new Maze();

            Room* room1 = new Room(1);
            Room* room2 = new Room(2);

            Door* theDoor = new Door(room1, room2);     

            room1->SetSide(North, new Wall());       
            room1->SetSide(East, theDoor);       
            room1->SetSide(South, new Wall());       
            room1->SetSide(West, new Wall());       

            room2->SetSide(North, new Wall());       
            room2->SetSide(East, new Wall());       
            room2->SetSide(South, new Wall());       
            room2->SetSide(West, theDoor);       

            return aMaze;
        }
};

MazeFactory* MazeFactory::_instance = 0;
int main()
{
    MazeGame game;
    game.CreateMaze();

    game.CreateMaze(MazeFactory::Instance());
  
    return 0;
}
