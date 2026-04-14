#include <iterator>
#include <optional>

template <typename Itr, typename T>
Itr binarysearch(Itr first, Itr last, T search){
    auto start{first};
    auto end {last};
    

    return start;
}

template <typename Itr, typename T>
std::optional <Itr> linearsearch(Itr first, Itr last, T search){
    auto runner{first};
    bool found = false;
    while (runner!=last){
        if (*runner==search){
            found = true;
            break;
        }
        runner++;
    }

    if (not found){
        return {};
    }
    return {runner};
}