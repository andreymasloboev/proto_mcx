#pragma once

class Resource
{
public:
    void setStatus(const int status) noexcept
    {
        status_ = status;
    }

    auto getStatus() noexcept
    {
        return status_;
    }

private:
    int status_{};
};
