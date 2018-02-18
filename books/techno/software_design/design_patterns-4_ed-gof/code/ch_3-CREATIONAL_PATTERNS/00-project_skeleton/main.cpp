#include <iostream>
#include <unordered_map>

enum Direction { North, South, East, West };

class MapSite {
    public:
        virtual void Enter() = 0;
};



class Room : public MapSite {
    public:
        Room(unsigned int number) : _number(number) { }

        MapSite* GetSide(Direction direction) const {
            return _sides[direction];
        }

        void SetSide(Direction direction, MapSite* mapSite) {
            _sides[direction] = mapSite;
        }

        virtual void Enter() { }

        unsigned int GetNumber() const { return _number; }
        void SetNumber(unsigned int value) { _number = value; }

    private:
        MapSite* _sides[4];
        unsigned int _number;
};

class Spell { };

class EnchantedRoom : public Room {
    public:
        EnchantedRoom(unsigned int number, Spell *spell)
            : Room(number), _spell(spell) { }

    private:
        Spell* _spell;
};

class RoomWithABomb : public Room {
    public:
        RoomWithABomb(unsigned int number) 
            : Room(number) { }
};



class Wall : public MapSite {
    public:
        Wall() { }

        virtual void Enter() { }
};

class BombedWall : public Wall { };



class Door : public MapSite {
    public:
        Door(Room* room1 = 0, Room* room2 = 0)
            : _room1(room1), _room2(room2) { }

        virtual void Enter() { }

    private:
        Room* _room1;
        Room* _room2;
        bool _isOpen;
};

class DoorNeedingSpell : public Door {
    public:
        DoorNeedingSpell(Room* room1, Room* room2) 
            : Door(room1, room2) { }
};

class Maze {
    public: 
        Maze() { }

        void AddRoom(Room* room) { 
            _rooms[room->GetNumber()] = room;
        }

        Room* GetRoomByNumber(unsigned int number) {
            return _rooms[number];
        }

    private:
        std::unordered_map<unsigned int, Room*> _rooms;
};



class MazeGame {
    public:
        Maze* CreateMaze() {
            Maze* maze = new Maze();

            Room* room1 = new Room(1);
            Room* room2 = new Room(2);            

            Door* door = new Door(room1, room2);

            room1->SetSide(North, new Wall());
            room1->SetSide(East, door);
            room1->SetSide(South, new Wall());
            room1->SetSide(West, new Wall());

            room2->SetSide(North, new Wall());
            room2->SetSide(East, new Wall());
            room2->SetSide(South, new Wall());
            room2->SetSide(West, door);

            return maze;
        }
};



int main() {
    MazeGame game;
    game.CreateMaze();

    return 0;
}
