class Watt { };
class Currency { };


class List { };
class Iterator { };



class Equipment {
    public:
        virtual ~Equipment() = default;

        const char* Name() { return _name; }

        virtual Watt Power() { return Watt(); }
        virtual Currency NetPrice() { return Currency(); }
        virtual Currency DiscountPrice() { return Currency(); }

        virtual void Add(Equipment*) { }
        virtual void Remove(Equipment*) { }
        virtual Iterator* CreateIterator() { return new Iterator(); }

    protected:
        Equipment(const char* name = "default") : _name(name) { }

    private:
        const char* _name;
};

class FloppyDisk : public Equipment {
    public:
        FloppyDisk(const char* name) : Equipment(name) { }

        virtual ~FloppyDisk() override = default;

        virtual Watt Power() override { return Watt(); }
        virtual Currency NetPrice() override { return Currency(); }
        virtual Currency DiscountPrice() override { return Currency(); }
};

class CompositeEquipment : public Equipment {
    public:
        virtual ~CompositeEquipment() override = default;

        virtual Watt Power() { return Watt(); }
        virtual Currency NetPrice() { return Currency(); }
        virtual Currency DiscountPrice() { return Currency(); }

        virtual void Add(Equipment*) { }
        virtual void Remove(Equipment*) { }
        virtual Iterator* CreateIterator() { return new Iterator(); }

    protected:
        CompositeEquipment(const char* name) : Equipment(name) { }

    private:
        List _equipment;
};

class Chassis : public CompositeEquipment {
    public:
        Chassis(const char* name) : CompositeEquipment(name) { }
        virtual ~Chassis() override = default;

        virtual Watt Power() override { return Watt(); }
        virtual Currency NetPrice() override { return Currency(); }
        virtual Currency DiscountPrice() override { return Currency(); }
};

class Cabinet : public CompositeEquipment {
    public:
        Cabinet(const char* name) : CompositeEquipment(name) { }
        virtual ~Cabinet() override = default;

        virtual Watt Power() override { return Watt(); }
        virtual Currency NetPrice() override { return Currency(); }
        virtual Currency DiscountPrice() override { return Currency(); }
};


#include <iostream>

int main() {
    Cabinet* cabinet = new Cabinet("PC cabinet");
    Chassis* chassis = new Chassis("PC Chassis");

    cabinet->Add(chassis);
    chassis->Add(new FloppyDisk("3.5 in Floppy"));


    return 0;
}
