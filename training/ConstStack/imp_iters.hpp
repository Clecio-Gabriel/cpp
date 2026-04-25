template <class Itr>
void Iters<Itr>::print_end() const{
    auto print_ptr {start};
    while (print_ptr!=end){
        std::cout << *print_ptr << " ";
        print_ptr++;
    }    
    std::cout << '\n';
}

template <class Itr>
void Iters<Itr>::print_run() const{
    auto print_ptr {start};
    while (print_ptr!=(runner+1)){
        std::cout << *print_ptr << " ";
        print_ptr++;
    }
    std::cout << '\n';

}

template <class Itr>
int Iters<Itr>::get_size() const{ return std::distance(start, end); };

template <class Itr>
void Iters<Itr>::shuffle(){
    std::random_device rd;
    auto seed { rd() };
    std::mt19937 gen(seed);
    std::shuffle(start, end, gen);
}

template <class Itr>
Itr Iters<Itr>::get_runner() const{ return runner; }

template <class Itr>
void Iters<Itr>::run_runner(){
    if (runner==start){
        runner = end - 1;
    }
    else{
        runner--;
    }
}