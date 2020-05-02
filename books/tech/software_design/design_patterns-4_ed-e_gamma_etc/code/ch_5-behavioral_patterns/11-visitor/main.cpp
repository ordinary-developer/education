
class FloppyDisk;
class EquipmentVisitor {
    public:
        virtual ~EquipmentVisitor() = default;

        virtual void VisitFloppyDisk(FloppyDisk* disk) { }
};

class PricingVisitor : public EquipmentVisitor {
    public:
        virtual ~PricingVisitor() final override = default;

        virtual void VisitFloppyDisk(FloppyDisk* disk) final override { }
};

class InventoryVisitor : public EquipmentVisitor {
    public:
        virtual ~InventoryVisitor() final override = default;

        virtual void VisitFloppyDisk(FloppyDisk* disk) final override { }
};


class Watt { };
class Currency { };
class Equipment {
    public:
        virtual ~Equipment() { delete[] _name; }

        char* Name() { return _name; }

        virtual Watt Power() { return Watt(); }
        virtual Currency NetPrice() { return Currency(); }
        virtual Currency DiscountPrice() { return Currency(); }

        virtual void Accept(EquipmentVisitor& visitor) = 0;
    protected:
        Equipment(char* name) : _name(name) { }

    private:
        char* _name;
};

class FloppyDisk : public Equipment { 
    public:
        FloppyDisk(char* name) : Equipment(name) { }
        virtual ~FloppyDisk() final override = default;

        virtual void Accept(EquipmentVisitor& visitor) {
            visitor.VisitFloppyDisk(this);
        }
};

int main() {
    Equipment* component = new FloppyDisk("floppy");
    InventoryVisitor visitor;
    component->Accept(visitor);

    return 0;
}
