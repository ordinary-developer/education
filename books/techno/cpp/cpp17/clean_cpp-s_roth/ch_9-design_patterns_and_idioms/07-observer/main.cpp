#include <memory>
#include <algorithm>
#include <vector>
#include <string_view>
#include <iostream>

class Observer {
    public:
        virtual ~Observer() = default;

        virtual int getId() = 0;
        virtual void update() = 0;
};
using ObserverPtr = std::shared_ptr<Observer>;

class IsEqualTo final {
    public:
        explicit IsEqualTo(ObserverPtr const& observer)
            : observer_{ observer } {}

        bool operator()(ObserverPtr const& observerToCompare) {
            return observerToCompare->getId() == observer_->getId();
        }

    private:
        ObserverPtr observer_;
};

class Subject {
    public:
        void addObserver(ObserverPtr& observerToAdd) {
            auto iter = std::find_if(std::begin(observers_),
                                     std::end(observers_),
                                     IsEqualTo{ observerToAdd });
            if (std::end(observers_) == iter)
                observers_.push_back(observerToAdd);
        }

        void removeObserver(ObserverPtr& observerToRemove) {
            observers_.erase(std::remove_if(std::begin(observers_),
                                            std::end(observers_),
                                            IsEqualTo(observerToRemove)),
                             std::end(observers_));
        }

    protected:
        void notifyAllObservers() const {
            for (auto const& observer : observers_)
                observer->update();
        }

    private:
        std::vector<ObserverPtr> observers_;
};

class SpreadSheetModel : public Subject {
    public:
        void changeCellValue(std::string_view column, 
                             int const row,
                             double const value)
        {
            std::cout << "Cell [" << column << ", " << row << "] = "
                      << value << std::endl;
            notifyAllObservers();
        }
};

class TableView : public Observer {
    public:
        explicit TableView(SpreadSheetModel& theModel)
            : model_{ theModel } {}

        virtual int getId() override {
            return 1;
        }

        virtual void update() override {
            std::cout << "Update of TableView." << std::endl;
        }

    private:
        SpreadSheetModel& model_;
};

class BarChartView : public Observer {
    public:
        explicit BarChartView(SpreadSheetModel& theModel)
            : model_{ theModel } {}

        virtual int getId() override {
            return 2;
        }

        virtual void update() override {
            std::cout << "Update of BarCharView." << std::endl;
        }

    private:
        SpreadSheetModel& model_;
};

class PieChartView : public Observer {
    public:
        explicit PieChartView(SpreadSheetModel& theModel)
            : model_{ theModel } {}

        virtual int getId() override {
            return 1;
        }

        virtual void update() override {
            std::cout << "Update of PieCharView." << std::endl;
        }

    private:
        SpreadSheetModel& model_;
};

int main() {
    SpreadSheetModel spreadSheetModel{};

    ObserverPtr observer1 = 
        std::make_shared<TableView>(spreadSheetModel);
    spreadSheetModel.addObserver(observer1);

    ObserverPtr observer2 = 
        std::make_shared<BarChartView>(spreadSheetModel);
    spreadSheetModel.addObserver(observer2);

    spreadSheetModel.changeCellValue("A", 1, 42);

    spreadSheetModel.removeObserver(observer1);

    spreadSheetModel.changeCellValue("B", 2, 23.1);

    ObserverPtr observer3 =
        std::make_shared<PieChartView>(spreadSheetModel);
    spreadSheetModel.addObserver(observer3);

    spreadSheetModel.changeCellValue("C", 3, 3.1415926);

    return 0;
}
