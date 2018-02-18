

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

// auxiliary logic
class BombedWall : public Wall {

};

class RoomWithABomb : public Room {
    public:
        RoomWithABomb(int number) 
            : Room(number) { } 
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



class MazeGame {
    public:
        virtual Maze* MakeMaze() const {            
            return new Maze;
        }
        
        virtual Room* MakeRoom(int n) const {
            std::cout << "MazeGame" << std::endl;
            return new Room(n);
        }

        virtual Wall* MakeWall() const {
            return new Wall;
        }

        virtual Door* MakeDoor(Room* r1, Room* r2) const {
            return new Door(r1, r2);
        }
        

        Maze* CreateMaze() {
            Maze* aMaze = MakeMaze();

            Room* room1 = MakeRoom(1);
            Room* room2 = MakeRoom(2);
            Door* theDoor = MakeDoor(room1, room2);  

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

class BombedMazeGame : public MazeGame {
public:
    BombedMazeGame() { }

    virtual Wall* MakeWall() const {       
        return new BombedWall;
    }

    virtual Room* MakeRoom(int n) const {
        std::cout << "BombedMazeGame" << std::endl;
        return new RoomWithABomb(n); 
    }
};

class EnchantedMazeGame : public MazeGame {
public:
    EnchantedMazeGame() { }

    virtual Room* MakeRoom(int n) const {
        std::cout << "EnchantedMazeGame" << std::endl;
        return new EnchantedRoom(n, CastSpell());
    }

    virtual Door* MakeDoor(Room* r1, Room* r2) const {
        return new DoorNeedingSpell(r1, r2);
    }
protected:
    Spell* CastSpell() const {
        return new Spell;
    }
};

int main()
{
    // with pointers
    MazeGame* pgame = nullptr;

    pgame = new MazeGame;
    pgame->CreateMaze();
    delete pgame;
    pgame = nullptr;

    pgame = new BombedMazeGame;
    pgame->CreateMaze();
    delete pgame;
    pgame = nullptr;
    
    pgame = new EnchantedMazeGame;
    pgame->CreateMaze();
    delete pgame;
    pgame = nullptr;

    std::cout << "---------------" << std::endl;

    // with references    
    MazeGame& game1 = MazeGame();
    game1.CreateMaze();

    MazeGame& game2 = BombedMazeGame();
    game2.CreateMaze();

    MazeGame& game3= EnchantedMazeGame();
    game3.CreateMaze();
    
    return 0;
}
