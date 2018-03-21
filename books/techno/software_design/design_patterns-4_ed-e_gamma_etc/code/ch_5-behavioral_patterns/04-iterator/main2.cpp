#include <stdexcept>
#include <vector>
#include <iostream>

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
class AbstractList {
    public:
        virtual Iterator<Item>* CreateIterator() const = 0;

        virtual long Count() const = 0;
        // only copy here
        virtual Item Get(long index) const = 0;
        virtual void Add(Item item) = 0;
};


template <class Item>
class List;

template <class Item>
class ListIterator : public Iterator<Item> {
    public:
        ListIterator(const List<Item>* list);

        virtual void First() final override; 

        virtual void Next() final override;

        virtual bool IsDone() const final override;

        virtual Item CurrentItem() const final override;

    private:
        const List<Item>* _list; 
        long _current;
};

template <class Item>
class List : public AbstractList<Item> {
    public:
        List(long size = DEFAULT_LIST_CAPACITY) { }

        virtual Iterator<Item>* CreateIterator() const final override 
        {
            return new ListIterator<Item>(this);
        }

        virtual long Count() const final override {
            return _items.size(); 
        }
        // only get a copy here
        virtual Item Get(long index) const final override {
            return _items.at(index); 
        }

        virtual void Add(Item item) final override {
            _items.push_back(item);
        }

    private:
        std::vector<Item> _items;
        static const int DEFAULT_LIST_CAPACITY = 5;
};


template <class Item>
ListIterator<Item>::ListIterator(const List<Item>* list)
                                 : _list(list), _current(0) { }

template <class Item>
void ListIterator<Item>::First() { 
    _current = 0;
}

template <class Item>
void ListIterator<Item>::Next() { 
    _current++;
}

template <class Item>
bool ListIterator<Item>::IsDone() const { 
    return _current >= _list->Count();
}

template <class Item>
Item ListIterator<Item>::CurrentItem() const {
    if (IsDone()) {
        throw std::runtime_error("Iterator out of bounds");
    }
    return _list->Get(_current);
}

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
