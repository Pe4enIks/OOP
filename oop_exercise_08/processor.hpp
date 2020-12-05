#pragma once

template <typename T>
struct Processor
{
    using value_type = T;
    virtual void process(std::shared_ptr<std::vector<std::shared_ptr<Figure<T>>>> buffer) = 0;
};

template <typename T>
struct StreamProcessor : Processor<T>
{
    using value_type = T;
    void process(std::shared_ptr<std::vector<std::shared_ptr<Figure<T>>>> buffer) override;
};

template <typename T>
struct FileProcessor : Processor<T>
{
    using value_type = T;
    void process(std::shared_ptr<std::vector<std::shared_ptr<Figure<T>>>> buffer) override;
private:
    size_t cnt = 0;
};

template <typename T>
void StreamProcessor<T>::process(std::shared_ptr<std::vector<std::shared_ptr<Figure<T>>>> buffer)
{
    for (auto& figure : *buffer) { figure->print_figure(std::cout); }
}

template <typename T>
void FileProcessor<T>::process(std::shared_ptr<std::vector<std::shared_ptr<Figure<T>>>> buffer)
{
    std::ofstream fout;
    fout.open(std::to_string(cnt) + ".txt");
    ++cnt;
    if (!fout.is_open())
    {
        std::cout << "can't open\n";
        return;
    }
    for (auto figure : *buffer) { figure->print_figure(fout); }
}
