#include <list>

class Subject; 

class Observer {
    public:
        virtual ~Observer() = default;
        virtual void Update(Subject* theChangedSubject) = 0;
    protected:
        Observer() = default;
};

class Subject {
    public:
        virtual ~Subject() = default;

        virtual void Attach(Observer* observer) { 
            _observers.push_back(observer);
        }

        virtual void Detach(Observer*) { 
            // deleting the observer from the list
        }

        virtual void Notify() {
            for (auto& observer: _observers) {
                observer->Update(this);
            }
        }

    protected:
        Subject() = default;
    private:
        std::list<Observer*> _observers;
};

class ClockTimer : public Subject {
    public:
        ClockTimer() = default;
        virtual ~ClockTimer() final override = default;

        // dumb functions
        virtual int GetHour() { return 0; }
        virtual int GetMinute() { return 0; }
        virtual int GetSecond() { return 0; }

        void Tick() {
            Notify();
        }
};

class Widget { };

class DigitalClock : public Widget, public Observer {
    public:
        explicit DigitalClock(ClockTimer* subject)
            : _subject(subject) 
        {
            _subject->Attach(this);
        }
        virtual ~DigitalClock() final override {
            _subject->Detach(this);
        }

        void Update(Subject* subject) final override { 
            if (subject == _subject) 
                Draw();
        }

        virtual void Draw() { 
            int hour = _subject->GetHour();
            int minute = _subject->GetMinute();
        }

    private:
        ClockTimer* _subject;
};

int main() {
    ClockTimer* timer = new ClockTimer();
    DigitalClock clock(timer);
    timer->Tick();

    return 0;
}
