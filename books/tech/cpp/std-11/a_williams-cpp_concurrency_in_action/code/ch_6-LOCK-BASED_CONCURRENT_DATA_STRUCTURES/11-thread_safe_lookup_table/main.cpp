#include <boost/thread/shared_mutex.hpp>

#include <mutex>
#include <future>
#include <thread>
#include <chrono>
#include <functional>
#include <utility>
#include <memory>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <cstddef>
#include <cstdlib>
#include <cstdint>
#include <iostream>


template <typename Key, typename Value, typename Hash=std::hash<Key>>
class threadsafe_lookup_table {
public:
    typedef Key key_type;
    typedef Value mapped_type;
    typedef Hash hash_type;

    threadsafe_lookup_table(unsigned num_buckets = 19,
                            const Hash& hasher_ = Hash())
        : buckets(num_buckets), hasher(hasher_)
    {
        for (unsigned i = 0; i < num_buckets; ++i)
            buckets[i].reset(new bucket_type);
    }
    threadsafe_lookup_table(const threadsafe_lookup_table&) = delete;
    threadsafe_lookup_table& operator=(
            const threadsafe_lookup_table&) = delete;

    Value value_for(const Key& key,
                    const Value& default_value = Value()) const
    {
        return get_bucket(key).value_for(key, default_value);
    }

    void add_or_update_mapping(const Key& key, const Value& value) {
        get_bucket(key).add_or_update_mapping(key, value);
    }

    void remove_mapping(const Key& key) {
        get_bucket(key).remove_mapping(key);
    }

    std::map<Key, Value> get_map() const {
        std::vector<std::unique_lock<boost::shared_mutex>> locks;
        for (unsigned i = 0; i < buckets.size(); ++i)
            locks.push_back(std::unique_lock<boost::shared_mutex>(
                    buckets[i].mutex));

        std::map<Key, Value> result;
        for (unsigned i = 0; i < buckets.size(); ++i)
            for (typename bucket_type::bucket_iterator iter
                    = std::begin(buckets[i].data);
                 std::end(buckets[i].data) != iter;
                 ++iter)
            {
                result.insert(*iter);
            }

        return result;
    }

private:

    class bucket_type {
    public:
        typedef std::pair<Key, Value> bucket_value;
        typedef std::list<bucket_value> bucket_data;
        typedef typename bucket_data::iterator bucket_iterator;

        mutable boost::shared_mutex mutex;
        bucket_data data;

        Value value_for(const Key& key, 
                        const Value& default_value) const 
        {
            boost::shared_lock<boost::shared_mutex> lock(mutex);
            const bucket_iterator found_entry = find_entry_for(key);
            return (std::end(data) == found_entry) 
                   ? default_value
                   : found_entry.second;
        }

        void add_or_update_mapping(const Key& key, 
                                   const Value& value) 
        {
            std::unique_lock<boost::shared_mutex> lock(mutex);
            const bucket_iterator found_entry = find_entry_for(key);
            if (std::end(data) == found_entry) 
                data.push_back(bucket_value(key, value));
            else
                found_entry->second = value;
        }

        void remove_mapping(const Key& key) {
            std::unique_lock<boost::shared_mutex> lock(mutex);
            const bucket_iterator found_entry = find_entry_for(key);
            if (std::end(data) != found_entry)
                data.erase(found_entry);
        }

    private:
        bucket_iterator find_entry_for(const Key& key) const {
            return std::find_if(std::begin(data),
                                std::end(data),
                                [&](const bucket_value& item) 
                                   { return key == item.first; }
                               );
        }

    };

    bucket_type& get_bucket(const Key& key) const {
        std::size_t bucket_index = hasher(key) % buckets.size();
        return *buckets[bucket_index];
    }

    std::vector<std::unique_ptr<bucket_type>> buckets;
    Hash hasher;
};


int get_random_int(int min, int max) {
    return min + (rand() % (int)(max - min + 1));
}


int main() {
    threadsafe_lookup_table<uint32_t, std::string> table;

    std::vector<std::future<void>> futures;
    for (uint32_t i = 0; i < 10; ++i)
        futures.emplace_back(
            std::async(std::launch::async,
                       [&table, &i]() -> void
                          {
                            //table.add_or_update_mapping(
                             //   i, std::to_string(i));
                            std::this_thread::sleep_for(
                                std::chrono::seconds(
                                    get_random_int(2, 7)));
                          }
                       ));

    for (auto& future : futures)
        future.get();
    std::cout << "[finish calculating]" << std::endl;

    auto contents = table.get_map();
    for (const auto& element : contents)
        std::cout << "[" << element.first << "] => " 
                  << element.second << std::endl;

    return 0;
}
