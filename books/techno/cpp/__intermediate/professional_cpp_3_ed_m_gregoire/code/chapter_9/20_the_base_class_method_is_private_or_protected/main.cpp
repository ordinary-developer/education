#include <iostream>
#include <string>

class MilesEstimator {
    public:
        virtual int getMilesLeft() const {
            return getMilesPerGallon() * getGallonsLeft();
        }
        virtual void setGallonsLeft(int inValue) {
            mGallonsLeft = inValue;
        }
        virtual int getGallonsLeft() const {
            return mGallonsLeft;
        }
    private:
        int mGallonsLeft;
        virtual int getMilesPerGallon() const { return 20; }
};

class EfficientCarMilesEstimator : public MilesEstimator {
    private:
        virtual int getMilesPerGallon() const override { return 35; }
};

auto main() -> int {
    MilesEstimator myMilesEstimator;
    myMilesEstimator.setGallonsLeft(2);
    std::cout << "I can go " << myMilesEstimator.getMilesLeft() 
              << " more miles." << std::endl;

    EfficientCarMilesEstimator myEstimator;
    myEstimator.setGallonsLeft(2);
    std::cout << "I can go " << myEstimator.getMilesLeft() 
              << " more miles." << std::endl;

    return 0;
}
