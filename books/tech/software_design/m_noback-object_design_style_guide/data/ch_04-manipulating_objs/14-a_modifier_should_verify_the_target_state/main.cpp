#include <stdexcept>
#include <cassert>
namespace workspace {

class DeliverSalesOrder {
public:
    DeliverSalesOrder() : isDelivered_(false), isCanceled_(false) {}

    void markAsDelivered() {
        if (isDelivered_)
            return;

        if (isCanceled_)
            throw std::domain_error("@isCanceled_ is true");

        isDelivered_ = true;
    }

    void cancel() {
        if (isCanceled_)
            return;

        if (isDelivered_)
            throw std::domain_error("@isCanceled_ is true");

        isCanceled_ = true;
    }

private:
    bool isDelivered_;
    bool isCanceled_;
};


void run() {
  {
    bool wasEx = false;
    try {
        DeliverSalesOrder().markAsDelivered();
        DeliverSalesOrder().cancel();
    }
    catch (...) { wasEx = true; }
    assert(!wasEx);
  }    

  {
    bool wasEx = false;
    try {
        DeliverSalesOrder order;
        order.markAsDelivered();
        order.cancel();    
    }      
    catch (const std::domain_error&) { wasEx = true; }
    assert(wasEx);
  }

  {
    bool wasEx = true;
    try {
        DeliverSalesOrder order;
        order.cancel();
        order.markAsDelivered();
    }      
    catch (const std::domain_error&) { wasEx = true; }
    assert(wasEx);
  }

}
} // workspace

#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl;
    workspace::run();
    std::cout << std::endl;

    
    return 0;
}
