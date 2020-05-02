

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

        Room(const Room& other) {
            _roomNumber = other._roomNumber;
            for (int i = 0; i < 4; ++i) {
                _sides[i] = other._sides[i];
            }
        }

        MapSite* GetSide(Direction direction) const { return 0; }
        void SetSide(Direction direction, MapSite* mapSite) { }

        virtual void Initialize(int roomNumber) {
            _roomNumber = roomNumber;
        }

        virtual Room* Clone() const {
            return new Room(*this);
        }

        virtual void Enter() { } 
    private:
        MapSite* _sides[4];
        int _roomNumber;
};

class Wall : public MapSite {
    public:
        Wall() { } 

        virtual Wall* Clone() const {
            return new Wall(*this);
        }
        
        virtual void Enter() { } 
};

class Door : public MapSite {
    public:
        Door(Room* room1 = 0, Room* room2 = 0) 
            : _room1(room1), _room2(room2) { }

        Door(const Door& other) {
            _room1 = other._room1;
            _room2 = other._room2;
        }

        virtual void Enter() { }
        
        Room* OtherSideFrom(Room* room) { return 0; }

        virtual void Initialize(Room* room1, Room* room2) {
            _room1 = room1;
            _room2 = room2;
        }

        virtual Door* Clone() const {
            return new Door(*this);
        }

    private:
        Room* _room1;
        Room* _room2;
        bool _isOpen;
};

class BombedWall : public Wall {
    public:
        BombledWall() { }

        BombedWall(const BombedWall& other) {
            _bomb = other._bomb;
        }

        virtual Wall* Clone() const {
            return new BombedWall(*this);
        }

        bool HasBomb() { return _bomb; }
    private:
        bool _bomb;
};

class RoomWithABomb : public Room {
    public:
        RoomWithABomb(int number)
            : Room(number) { }
};

class Maze {
    public:
        Maze() { } 

        void AddRoom(Room* room) { } 

        Room* RoomNumber(int number) const { return 0; }

        virtual Maze* Clone() { 
            return new Maze(*this);
        }
};

class MazeFactory {
    public:
        virtual Maze* MakeMaze() const = 0;
        virtual Wall* MakeWall() const = 0;
        virtual Door* MakeDoor(Room* r1, Room* r2) const = 0;
        virtual Room* MakeRoom(int roomNumber) const = 0;
};

class MazePrototypeFactory : public MazeFactory {
    public:
        MazePrototypeFactory(Maze* maze, Wall* wall,
                             Room* room, Door* door) {
        {
            _protoMaze = maze;
            _protoWall = wall;
            _protoRoom = room;
            _protoDoor = door;
        }
        
        virtual Maze* MakeMaze() const {
            return _protoMaze->Clone();
        }

        virtual Wall* MakeWall() const {
            return _protoWall->Clone();
        }

        virtual Door* MakeDoor(Room* room1, Room* room2) {
            Door* door = _protoDoor->Clone();
            door->Initialize(room1, room2);
            return door;
        }

        virtual Room* MakeRoom(int roomNumber) {
            Room* room = _protoRoom->Clone();
            room->Initialize(roomNumber);
            return room;
        }

    private:
        Maze* _protoMaze;
        Wall* _protoWall;
        Door* _protoDoor;
        Room* _protoRoom;
};


class MazeGame {
    public:
        Maze* CreateMaze(MazeFactory& factory) {
            Maze* aMaze = factory.MakeMaze();

            Room* room1 = factory.MakeRoom(1);
            Room* room2 = factory.MakeRoom(2);

            Door* theDoor = factory.MakeDoor(room1, room2);

            room1->SetSide(North, new Wall());       
            room1->SetSide(East, theDoor);       
            room1->SetSide(South, new Wall());       
            room1->SetSide(West, new Wall());       

            room2->SetSide(North, new Wall());       
            room2->SetSide(East, new Wall());       
            room2->SetSide(South, new Wall());       
            room2->SetSide(West, theDoor);       

            aMaze.addRoom(room1);
            aMaze.addRoom(room2);

            return aMaze;
        }
};

int main()
{
    MazeGame game;

    MazePrototypeFactory simplePrototypeFactory(
        new Maze, new Wall, new Room, new Door);
    game.CreateMaze(simpelPrototypeFactory);

    MazePrototypeFactory bombedPrototypeFactory(
        new Maze, new BombedWall, new RoomWithABomb, new Door);
    game.CreateMaze(bombedPrototypeFactory);
  
    return 0;
}

