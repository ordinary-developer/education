#include <thread>
#include <iostream>

class widget_data {
    public:
        int value;
};

class widget_id { };

void update_data_for_widget(widget_id w, widget_data& data) {
    data.value++;
}

void display_widget_data(const widget_data& data) {
    std::cout << data.value << std::endl;
}

int main() {
    widget_id w;
    widget_data data;
    data.value = 0;
    display_widget_data(data);

    // will not compile
    // std::thread t(update_data_for_widget, w, data)
    
    // but the next will be compiled
    std::thread t(update_data_for_widget, w, std::ref(data));
    t.join();

    display_widget_data(data);
}
