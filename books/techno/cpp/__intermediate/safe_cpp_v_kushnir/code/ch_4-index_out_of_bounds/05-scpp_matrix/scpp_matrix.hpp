#ifndef __SCPP_MATRIX_HPP_INCLUDED__
#define __SCPP_MATRIX_HPP_INCLUDED__

#include <ostream>
#include <vector>
#include "scpp_assert.hpp"

namespace scpp {

template <typename T>    
class matrix {
    public:
        typedef unsigned size_type;

        matrix(size_type num_rows, size_type num_cols)
            : rows_(num_rows), cols_(num_cols), 
              data_(num_rows * num_cols) { }




    private:
        size_type rows_, cols_;        
        std::vector<T> data_;

};

} // namespace scpp



#endif // __SCPP_MATRIX_HPP_INCLUDED__
