#include <mutex>

struct connection_info { };
struct data_packet { };


struct connection_handle {
    void send_data(const data_packet&) { }
    data_packet receive_data() { return data_packet(); }
};

struct remote_connection_manager {
    connection_handle open(const connection_info&) {
        return connection_handle();
    }
} connection_manager;


class X {
    public:
        X(const connection_info& connection_details_)
            : connection_details(connection_details_) { }

        void send_data(const data_packet& data) {
            std::call_once(connection_init_flag, &X::open_connection, this);
            connection.send_data(data);
        }

        data_packet receive_data() {
            std::call_once(connection_init_flag, &X::open_connection, this);
        }
    private:
        void open_connection() {
            connection = connection_manager.open(connection_details);
        }

        connection_info connection_details;
        connection_handle connection;
        std::once_flag connection_init_flag;
};

int main() {
    return 0;
}
