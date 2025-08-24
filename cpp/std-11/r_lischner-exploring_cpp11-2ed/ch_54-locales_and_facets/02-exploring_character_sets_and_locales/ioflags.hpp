#ifndef IOFLAGS_HPP_
#define IOFLAGS_HPP_

class ioflags {
    public:
        ioflags(std::basic_ios<char>& stream)
            : stream_{ stream }, flags_{ stream.flags() } { }

        ioflags(ioflags const&) = delete;
        ~ioflags() { stream_.flags(flags_); }

    private:
        std::basic_ios<char>& stream_;
        std::ios_base::fmtflags flags_;
};

#endif
