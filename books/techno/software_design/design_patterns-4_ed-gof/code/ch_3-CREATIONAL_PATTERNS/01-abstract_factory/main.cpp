#include <iostream>
using namespace std;

// base logic
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
        Door(Room* room1 = 0, Room* room2 = 0) {
            _room1 = room1;
            _room2 = room2;
        } 

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

// pattern declarations

// abstract factory
class MazeFactory {
    public:
        MazeFactory() {} 
        
        virtual Maze* MakeMaze() const 
        {
            return new Maze();
        }

        virtual Wall* MakeWall() const 
        {
            return new Wall();
        }

        virtual Room* MakeRoom(int number) const 
        {
            return new Room(number);
        }

        virtual Door* MakeDoor(Room* room1, Room* room2) const 
        {
            return new Door(room1, room2);
        }
};

// auxiliary logic classes
class Spell {
};

class EnchantedRoom : public Room {
    public:
        EnchantedRoom(int number, Spell *spell)
            : Room(number), _spell(spell)
        {

        }
        
    private:
        Spell* _spell;
};

class DoorNeedingSpell : public Door {
    public:
        DoorNeedingSpell(Room* room1, Room* room2) 
            : Door(room1, room2) 
        {
        }
};

// auxiliary factory
class EnchantedMazeFactory : public MazeFactory {
    public:
        EnchantedMazeFactory() { } 
        
        virtual Room* MakeRoom(int number) const 
        {
            return new EnchantedRoom(number, CastSpell());
        }

        virtual Door* MakeDoor(Room* room1, Room* room2) const
        {
            return new DoorNeedingSpell(room1, room2);
        }
    private:
        Spell* CastSpell() const 
        {
            return 0;
        }
};

// auxiliary logic
class BombedWall : public Wall {

};

class RoomWithABomb : public Room {
    public:
        RoomWithABomb(int number) 
            : Room(number) { } 
};

// auxiliary factory
class BombedMazeFactory : public MazeFactory {
    public:
        Wall* MakeWall() const 
        {
            return new BombedWall();
        }

        Room* MakeRoom(int number) const 
        {
            return new RoomWithABomb(number);
        }
};

// pattern using
class MazeGame {
    public:
        Maze* CreateMaze(MazeFactory& factory) 
        {
            Maze* aMaze = factory.MakeMaze();
            
            Room* room1 = factory.MakeRoom(1);
            Room* room2 = factory.MakeRoom(2);
            Door* aDoor = factory.MakeDoor(room1, room2);

            aMaze->AddRoom(room1);
            aMaze->AddRoom(room2);

            room1->SetSide(North, factory.MakeWall());
            room1->SetSide(East, aDoor);
            room1->SetSide(South, factory.MakeWall());
            room1->SetSide(West, factory.MakeWall());

            room2->SetSide(North, factory.MakeWall());
            room2->SetSide(East, factory.MakeWall());
            room2->SetSide(South, factory.MakeWall());
            room2->SetSide(West, aDoor);

            return aMaze;
        }
};

// the main procedure
int main()
{
    MazeGame game;

    MazeFactory mazeFactory;
    game.CreateMaze(mazeFactory);

    EnchantedMazeFactory enchantedMazeFactory;
    game.CreateMaze(enchantedMazeFactory);

    BombedMazeFactory bombedMazeFactory;
    game.CreateMaze(bombedMazeFactory);
  
    return 0;
}
