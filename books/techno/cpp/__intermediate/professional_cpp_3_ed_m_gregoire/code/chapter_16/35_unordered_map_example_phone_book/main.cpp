#include <iostream>
#include <string>
#include <unordered_map>


template <typename T>
void printMap(const T& m) {
    for (auto& p : m) {
        std::cout << p.first << " (Phone: " << p.second << ")" 
                  << std::endl;
    }
    std::cout << "--------" << std::endl;
}

auto main() -> int {
    std::unordered_map<std::string, std::string> um = {
        { "Macrc G.", "123-456789" },
        { "Scott K.", "654-987321" }
    };
    printMap(um);

    um.insert(std::make_pair("John D.", "321-987654"));
    um["Johan G."] = "963-258147";
    um["Freddy K."] = "999-256256";
    um.erase("Freddy K.");
    printMap(um);

    int bucket = um.bucket("Marc G.");
    std::cout << "Marc G. is in bucket " << bucket
              << " which contains the following "
              << um.bucket_size(bucket) << " elements: " << std::endl;

    auto iterator = um.cbegin(bucket);
    auto iteratorEnd = um.cend(bucket);
    while (iterator != iteratorEnd) {
        std::cout << "\t" << iterator->first << " (Phone: " 
                  << iterator->second << ")" << std::endl;
    }
    std::cout << "---------" << std::endl;

    std::cout << "There are " << um.bucket_count() << " buckets."
              << std::endl;
    std::cout << "Average number of elements in a bucket is "
              << um.load_factor() << std::endl;

    return 0;
}
