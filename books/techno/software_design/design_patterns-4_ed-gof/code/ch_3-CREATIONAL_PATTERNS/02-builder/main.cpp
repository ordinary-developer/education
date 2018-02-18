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

// ======================
// pattern implementation
// ======================
class MazeBuilder {
    public:
        virtual void BuildMaze() { }
        virtual void BuildRoom(int roomNumber) { }
        virtual void BuildDoor(int roomFrom, int roomTo) { }

        virtual Maze* GetMaze() { return 0; }
    protected:
        MazeBuilder() { }
};

class StandardMazeBuilder : public MazeBuilder {
    public:
        StandardMazeBuilder() 
        {
            _currentMaze = 0;                
        }

        virtual void BuildMaze() 
        {
            _currentMaze = new Maze;
        }

        virtual Maze* GetMaze() 
        {
            return _currentMaze;
        }

        virtual void BuildRoom(int roomNumber) 
        {
            if (!_currentMaze->RoomNumber(roomNumber)) {
                Room* room = new Room(roomNumber);
                _currentMaze->AddRoom(room);

                room->SetSide(North, new Wall);
                room->SetSide(South, new Wall);
                room->SetSide(East, new Wall);
                room->SetSide(West, new Wall);
            }
        }

        virtual void BuildDoor(int number1, int number2) 
        {
            Room* room1 = _currentMaze->RoomNumber(number1);
            Room* room2 = _currentMaze->RoomNumber(number2);
            Door* door = new Door(room1, room2);
            room1->SetSide(CommonWall(room1, room2), door);
            room2->SetSide(CommonWall(room2, room1), door);
        }

    private:
        Direction CommonWall(Room* room1, Room* room2) 
        {
            return North;
        }
        Maze* _currentMaze;
};

class CountingMazeBuilder : public MazeBuilder {
    public:
        CountingMazeBuilder() 
        { 
            _rooms = _doors = 0; 
        }

        virtual void BuildMaze() { } 

        virtual void BuildRoom(int roomNumber) 
        { 
            _rooms++;
        }

        virtual void BuildDoor(int number1, int number2)
        {
            _doors++;
        }

        void GetCounts(int& rooms, int& doors) const
        {
            rooms = _rooms;
            doors = _doors;
        }
    private:
        int _doors;
        int _rooms;
};

// ====================
// a lower cleint layer 
// ====================
class MazeGame {
    public:
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

        Maze* CreateMaze(MazeBuilder& builder) {
            builder.BuildMaze();

            builder.BuildRoom(1);
            builder.BuildRoom(2);
            builder.BuildDoor(1, 2);

            return builder.GetMaze();
        }
};


// ======================
// an upper client layer
// ======================
int main()
{
    MazeGame game;
    Maze* maze;

    StandardMazeBuilder builder;
    game.CreateMaze(builder);
    maze = builder.GetMaze();

    int rooms, doors;
    CountingMazeBuilder countingBuilder;
    game.CreateMaze(countingBuilder);
    countingBuilder.GetCounts(rooms, doors);
    std::cout << "The maze has " << rooms << " rooms and "
              << doors << " doors" << std::endl; 

    return 0;
}
