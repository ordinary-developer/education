#include <stdexcept>
#include <vector>
#include <iostream>

template <class Item>
class List {
    public:
        List(long size = DEFAULT_LIST_CAPACITY) { }

        long Count() const { return _items.size(); }
        // only get a copy here
        Item Get(long index) const { return _items.at(index); }
        void Add(Item item) {
            _items.push_back(item);
        }

    private:
        std::vector<Item> _items;
        static const int DEFAULT_LIST_CAPACITY = 5;
};

template <class Item>
class Iterator {
    public:
        virtual ~Iterator() = default;

        virtual void First() = 0;
        virtual void Next() = 0;
        virtual bool IsDone() const = 0;
        virtual Item CurrentItem() const = 0;

    protected:
        Iterator() = default;
};

template <class Item>
class ListIterator : public Iterator<Item> {
    public:
        ListIterator(const List<Item>* list)
            : _list(list), _current(0) { }

        virtual void First() final override { 
            _current = 0;
        }

        virtual void Next() final override { 
            _current++;
        }

        virtual bool IsDone() const final override { 
            return _current >= _list->Count();
        }

        virtual Item CurrentItem() const final override {
            if (IsDone()) {
                throw std::runtime_error("Iterator out of bounds");
            }
            return _list->Get(_current);
        }

    private:
        const List<Item>* _list; 
        long _current;
};

class Employee {
    public:
        Employee(char* name = "default employee") : _name(name) { }

        void Print() {
            std::cout << _name << std::endl;
        }

    private:
        char* _name;
};

void PrintEmployees(Iterator<Employee*>& i) {
    for (i.First(); !i.IsDone(); i.Next()) {
        i.CurrentItem()->Print();
    }
}

int main() {
    List<Employee*> list;
    list.Add(new Employee("Jack"));
    list.Add(new Employee("Henry"));
    ListIterator<Employee*> forward(&list);
    PrintEmployees(forward);

    return 0;
}
