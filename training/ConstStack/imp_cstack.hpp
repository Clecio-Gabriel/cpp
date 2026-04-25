template <typename T>
int ConstStack<T>::get_size() const{ return stored.size(); }

template <typename T>
T ConstStack<T>::get_last(){
    T ret{*this->get_runner()};
    this->run_runner();

    return ret;
}